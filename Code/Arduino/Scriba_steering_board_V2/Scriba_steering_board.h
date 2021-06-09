#include <AccelStepper.h>
#include <MultiStepper.h>
#include <ros.h>
#include <scriba_msgs/mot_cmd.h>
#include <scriba_msgs/data_odom.h>
#include <scriba_msgs/front_wheel_calibration.h>
#include <std_msgs/String.h>
#include <ros/time.h>
#include "scriba_drive_log_msgs.h"

using scriba_msgs::front_wheel_calibration;

//Start ROS node handle
ros::NodeHandle nh; //ROS buffer size /!\ an high buffer size can fill the Arduino's memory. Optimizing the buffer size is capital

int angleStepCmd = 0;
int tractionSpeedCmd = 0;
long steerAngleStepsStart = 0;
long steerAngleStepsEnd = 0;
long steerAnglePotStart;
long steerAnglePotEnd;
int angleStep = 0;              //Front wheel angle in steps
int tractionSpeed = 800;        //Traction stepper motor speed in steps/second
int steeringSpeed = 400;        //Steering stepper motor speed in steps/second
int tractionAcc = 350;    //Traction stepper motor acceleration in steps/second/second
int steeringAcc = 200;    //Traction stepper motor acceleration in steps/second/second

//----------------
// Time variables
//----------------
const int looptime = 100;             //Looptime in millisecond
unsigned long lastMilli = 0;
unsigned long lastCommMillis = 0;
const unsigned long noCommDurationMax = 1500;   //Set the max time for the robot to run without motor commands

//-------------
// Pin numbers
//-------------
const int tractionDirPin = 7;
const int steeringDirPin = 6;
const int tractionStepPin = 10;
const int steeringStepPin = 9;
const int tractionSleepPin = A1;
const int steeringSleepPin = A0;
const int tractionEnablePin = A4;
const int steeringEnablePin = 8;
const int tractionResetPin = 13;
const int steeringResetPin = 12;
const int steeringMSLeftPin = A2;   //Steering left microswitch pin
const int steeringMSRightPin = A3;  //Steering right microswitch pin
const int EMStopPin = A5;           //Emergency stop signal pin
const int steeringPotPin = A7;      //Steering angle potentiometer data pin

byte mode = 0;                      /* Driving mode. 0 is for standard mode (ajust front wheel angle while moving)
                                      and 1 for printing mode (ajust front wheel angle and then move) */
                    
long minSteeringStep = -2000;       //End position right step value
long maxSteeringStep = 2000;        //End position left step value
float microstepSteeringRatio = 0.5; //Microstepping configuration for steering motor
float microstepTractionRatio = 0.5; //Microstepping configuration for traction motor
float potSteeringRatio = 251;       //Potentiometer ticks per rad
const float wheelRadius = 0.025;    //Front wheel radius in meters
const float pi = 3.14159;           //It's just Pi, what did you expect?
//Compute ratio from potentiometer value to steering motor step
float stepsPerTick = (180/(0.12 * microstepSteeringRatio * pi)) / potSteeringRatio;robot

//Create stepper objects for steering and traction stepper motor
AccelStepper tractionStepper = AccelStepper(1, tractionStepPin, tractionDirPin);
AccelStepper steeringStepper = AccelStepper(1, steeringStepPin, steeringDirPin);

//----------------------------------------------------------------------------------------------------------
//Emergency stop function. emergencyCase variable states the reason for which the emergency signal was sent
//----------------------------------------------------------------------------------------------------------
void emergencyStop(byte emergencyCase){ 
  nh.logerror(ScribaDriveLogMsgs::emMsg1);     //"EMERGENCY STOP ACTIVE";
  switch (emergencyCase){
    case 1:   //Emergency stop triggered by emergency button pressed (signal missing)
      nh.logwarn(ScribaDriveLogMsgs::emMsg3);  //"Emergency button pressed"
//       while(digitalRead( EMStopPin) == LOW){
//        nh.spinOnce(); /*wait until emergency signal is resumed*/
//       }
      nh.logwarn(ScribaDriveLogMsgs::emMsg2);  //"EMERGENCY STOP DEACTIVATED"
      break;
    case 2:   //Emergency stop triggered by defective or missing microswitch
      nh.logwarn(ScribaDriveLogMsgs::emMsg4);  //"Steering end position microswitch missing/defective"
      nh.logwarn(ScribaDriveLogMsgs::emMsg5);  //"Please check microswitch wiring and state"
      nh.loginfo(ScribaDriveLogMsgs::emMsg6);  //"PUSH AND RELEASE EMERGENCY STOP BUTTON TO RESET"
       while(digitalRead( EMStopPin) == HIGH){
        nh.spinOnce(); /*wait until emergency signal is pushed*/
      }  
      while(digitalRead( EMStopPin) == LOW){
        nh.spinOnce(); /*wait until emergency signal is resumed*/
      }
      nh.logwarn(ScribaDriveLogMsgs::emMsg2);  //"EMERGENCY STOP DEACTIVATED"
      break;
    default:
      nh.logwarn(ScribaDriveLogMsgs::emMsg7);  //"Unspecified reason for emergency stop"
      nh.loginfo(ScribaDriveLogMsgs::emMsg6);  //"PUSH AND RELEASE EMERGENCY STOP BUTTON TO RESET"
       while(digitalRead( EMStopPin) == HIGH){
        nh.spinOnce(); /*wait until emergency signal is pushed*/
      }  
      while(digitalRead( EMStopPin) == LOW){
        nh.spinOnce(); /*wait until emergency signal is resumed*/
      }
      nh.logwarn(ScribaDriveLogMsgs::emMsg2);  //"EMERGENCY STOP DEACTIVATED"
  }
}

//-------------------------------
// Return angle of potentiometer
//-------------------------------
float potentiometerAngle(){
  return analogRead(steeringPotPin); //TODO conversion to angle
}

//---------------------
// Run motors function
//---------------------
void runMotors(int tractionSpeed, int tractionAcc, int steeringSpeed, int SteeringAcc){
  if(digitalRead( EMStopPin) == LOW){                                                  //Check if emergency signal is absent (emergency button pressed)
    emergencyStop(1);
  }
  else if(digitalRead( steeringMSLeftPin) && digitalRead( steeringMSRightPin) == HIGH){  //Check if both steering end position microswitch active at the same time (indicating a missing or defective microswitch)
    emergencyStop(2);
  }
  else{
    // Set the speed in steps per second:
    tractionStepper.setSpeed(tractionSpeed);
    steeringStepper.setSpeed(steeringSpeed);
    tractionStepper.setAcceleration(tractionAcc);
    steeringStepper.setAcceleration(steeringAcc); 
    
    // Step the motors with the set speed
    tractionStepper.runSpeed();
    steeringStepper.runSpeed();
  }
}

//--------------------------------------------------------------
//function that will be called when receiving command from host
//--------------------------------------------------------------
void handleCmd (const scriba_msgs::mot_cmd& motCmdMsg) {
  mode = 0;                              //Standard driving mode because data received as mot_cmd
  lastCommMillis = millis();             //Set last communication time
  
  //Get front wheel angle command (in rad) & convert radian angle to steps according to microstepping configuration and gear and stepper motor ratio
  angleStepCmd = (motCmdMsg.angle*(180/pi))/( microstepSteeringRatio*0.12);
  
  //Get front wheel speed command (in m/s & convert m/s speed to step/s speed according to microstepping configuration and motor angle/step ratio
  tractionSpeedCmd = (motCmdMsg.tractionSpeed/wheelRadius)*(200/( microstepTractionRatio*pi));
  
  angleStepCmd = min( angleStepCmd, maxSteeringStep);         //Bound the step angle to the max calibrated value
  angleStepCmd = max( angleStepCmd, minSteeringStep);         //Bound the step angle to the min calibrated value
  nh.spinOnce();
}

//----------------------------------------------------------------------------
//Function that will be called when receiving the calibration service request
//----------------------------------------------------------------------------
void frontWheelCalibCallback(const front_wheel_calibration::Request & req, front_wheel_calibration::Response & res){
  long steeringRangeSteps = 0;                                  //numbers of step for the steering range
  float front_wheel_offset = 0;                                 //Front wheel offset angle
  front_wheel_offset = req.front_wheel_offset;                  //Get front wheel offset angle from calibration request
  microstepSteeringRatio = req.microstepSteeringRatio;          //Get steering stepper motor microstep setting from calibration request
  
  //====================================
  //   Steering calibration procedure
  //====================================
  digitalWrite(steeringSleepPin, HIGH);                         //Enable steering motor
  digitalWrite(tractionSleepPin, HIGH);                         //Enable traction motor
  nh.loginfo(ScribaDriveLogMsgs::clbMsg1);                  //"Steer calibration starting"
  // Spin motor until triggering left microswitch  
  nh.loginfo(ScribaDriveLogMsgs::clbMsg2);                  //"Rotating to left end position switch..."
  while (digitalRead(steeringMSLeftPin) == LOW){
    runMotors(0, 0, 400, 150);
  }
  // When left end-of-course microswitch triggered
  steeringStepper.setCurrentPosition(0);                    // Setting steering motor to zero
  res.minSteerPotValue = analogRead(steeringPotPin);        // Save steering potentiometer value
  nh.logdebug(ScribaDriveLogMsgs::clbMsg3);                 //"Left end position detected"
  delay(500); // Wait

  // Spin motor until triggering right microswitch  
  nh.logdebug(ScribaDriveLogMsgs::clbMsg4);                 //"Rotating to right end position switch..."                                     
  while (digitalRead(steeringMSRightPin) == LOW){
    runMotors(0, 0, -400, 150);
  }
  steeringRangeSteps = steeringStepper.currentPosition();
  res.maxSteerPotValue = analogRead(steeringPotPin);        // Save steering potentiometer value
  nh.logdebug(ScribaDriveLogMsgs::clbMsg5);                 //"Right end position detected"
  nh.loginfo(ScribaDriveLogMsgs::clbMsg6);
  Serial.print(abs(steeringRangeSteps));
  nh.logdebug(ScribaDriveLogMsgs::clbMsg7);                 //"Going now to middle position... "
  Serial.print(steeringRangeSteps/2);
  delay(500); // Wait

  //Go to middle position and register it as reference
  //Middle position being half the range plus offset angle
  //(converted from radian angle to steps according to microstepping configuration and gear and stepper motor ratio)
  while(steeringStepper.currentPosition() != (steeringRangeSteps/2)+((req.front_wheel_offset*(180/pi))/(microstepSteeringRatio*0.12))){ 
    runMotors(0, 0, 400, 150);
    nh.spinOnce();
  }
  steeringStepper.setCurrentPosition(0);
  steeringRangeSteps = abs(steeringRangeSteps);
  minSteeringStep = ceil((-steeringRangeSteps/2)-((req.front_wheel_offset*(180/pi))/(microstepSteeringRatio*0.12)));    //Right end position step value
  maxSteeringStep = floor((steeringRangeSteps/2)-((req.front_wheel_offset*(180/pi))/(microstepSteeringRatio*0.12)));    //Left end position step value
  nh.loginfo(ScribaDriveLogMsgs::clbMsg8);                                  //"Calibration complete"

  res.minAngle = minSteeringStep*(microstepSteeringRatio*0.12)*(pi/180);  //Write min front wheel angle (in rad) to calibration request response
  res.maxAngle = maxSteeringStep*(microstepSteeringRatio*0.12)*(pi/180);  //Write max front wheel angle (in rad) to calibration request response
  res.result = true;
  delay(1000);
}


//---------------
// ROS variables
//---------------
//Create a "odom_data" ROS message (custom message type)
scriba_msgs::data_odom odom_data_msg;
//Create a odometry data publisher
ros::Publisher odom_data_pub("odom_data", &odom_data_msg);
//Create String msg
std_msgs::String status_msg;
//Create controller status publisher
ros::Publisher status_pub("steering_board_status", &status_msg);
//Create motor command subscriber (custom message type)
ros::Subscriber<scriba_msgs::mot_cmd> cmd_mot("cmd_mot", &handleCmd);
//Create front wheel angle calibration service server
ros::ServiceServer<front_wheel_calibration::Request, front_wheel_calibration::Response> front_wheel_calib("fw_cal", &frontWheelCalibCallback);


void setupRosNode()
{
  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.subscribe(cmd_mot);
  nh.advertise(odom_data_pub);
  nh.advertise(status_pub);
  nh.advertiseService(front_wheel_calib);
  nh.spinOnce();
  delay(3000);
  nh.spinOnce();
  status_msg.data = "initialized";
  status_pub.publish(&status_msg);
  nh.spinOnce();
}

void enableInputsOutputs()
{
  //Declare pins as Outputs
  pinMode(tractionStepPin, OUTPUT);
  pinMode(steeringStepPin, OUTPUT);
  pinMode(tractionDirPin, OUTPUT);
  pinMode(steeringDirPin, OUTPUT);
  pinMode(tractionSleepPin, OUTPUT);
  pinMode(steeringSleepPin, OUTPUT); 
  pinMode(tractionEnablePin, OUTPUT);
  pinMode(steeringEnablePin, OUTPUT);
  pinMode(tractionResetPin, OUTPUT);
  pinMode(steeringResetPin, OUTPUT);

  //Declare pins as Inputs
  pinMode(steeringMSLeftPin, INPUT);
  pinMode(steeringMSRightPin, INPUT);
  pinMode(EMStopPin, INPUT);

  //Enable the motor drivers
  digitalWrite( tractionEnablePin, LOW);
  digitalWrite( steeringEnablePin, LOW);
  digitalWrite( tractionSleepPin, HIGH);
  digitalWrite( steeringSleepPin, HIGH);
  digitalWrite( tractionResetPin, HIGH);
  digitalWrite( steeringResetPin, HIGH);
}

void setupController(){
  //Setup pins
  enableInputsOutputs();
  // Set the maximum speed in steps per second:
  tractionStepper.setMaxSpeed(1000);
  steeringStepper.setMaxSpeed(1000);
  //Setup the ROS node
  setupRosNode();
}

void motorSleep(){
  //angleStepCmd = 0;
  tractionSpeedCmd = 0;
  digitalWrite( tractionSleepPin, LOW);      //Disable traction motor
  digitalWrite( steeringSleepPin, LOW);      //Disable steering motor
}

void motorWake(){
  digitalWrite( tractionSleepPin, HIGH);      //Enable traction motor
  digitalWrite( steeringSleepPin, HIGH);      //Enable steering motor
}

//Robot run function
void robotRun(byte& mod, int& tracSpeed, int& tracAcc, int& steerSpeed, int& angStep){
  if(digitalRead( EMStopPin) == LOW){                                                  //Check if emergency signal is absent (emergency button pressed)
    emergencyStop(1);
  }
  else if(digitalRead( steeringMSLeftPin) && digitalRead( steeringMSRightPin) == HIGH){  //Check if both steering end position microswitch active at the same time (indicating a missing or defective microswitch)
    emergencyStop(2);
  }
  else{
    // Set the speed in steps per second:
    tractionStepper.setAcceleration(tracAcc);
    steeringStepper.moveTo(angStep);
    tractionStepper.setSpeed(tracSpeed);
    steeringStepper.setSpeed(steerSpeed);  
    
    // Step the motors with the set speed
    tractionStepper.runSpeed();
    steeringStepper.runSpeedToPosition();
  }
}

void runController(){
  lastMilli = millis();
  //Populate odometry data message
  odom_data_msg.steerAngleStepsStart = steerAngleStepsStart;               //Angle steps at start of the loop
  odom_data_msg.steerAngleStepsEnd = steerAngleStepsEnd;                   //Angle steps at end of the loop
  odom_data_msg.steerAnglePotStart = steerAnglePotStart;                 //Steering angle potentiometer value at start of the loop
  odom_data_msg.steerAnglePotEnd = steerAnglePotEnd;                     //Steering angle potentiometer value at end of the loop
  odom_data_msg.tractionSteps = tractionStepper.currentPosition();  //Traveled steps of traction motor
  tractionStepper.setCurrentPosition(0);                            //Set traveled steps back to 0
  odom_data_msg.header.stamp = nh.now();                             //Time stamp
  odom_data_pub.publish(&odom_data_msg);                            //Publish odometry data
  nh.spinOnce();
    
  if(millis()-lastCommMillis < noCommDurationMax){                        //Check that a motor command has been received recently
    motorWake();
    robotRun( mode, tractionSpeedCmd, tractionAcc, steeringSpeed, angleStepCmd); //Run robot with received commands
    //status_msg.data = "wake & run motors";
  } 
  else{                                                   //Stops robot if no communication with host (no motor command received)
    motorSleep();
    //status_msg.data = "motors sleep";
    //status_pub.publish(&status_msg);
  }
  nh.spinOnce();
  while((millis()-lastMilli) < looptime){                  //run motors (or no if no communication) while waiting end of looptime
    robotRun( mode, tractionSpeedCmd, tractionAcc, steeringSpeed, angleStepCmd);
    //status_msg.data = "run motors";
  }
  steerAngleStepsStart = steerAngleStepsEnd;                    //Set next angle steps at start as previous end angle
  steerAngleStepsEnd = steeringStepper.currentPosition();       //Get angle steps at end of the loop
  steerAnglePotStart = steerAnglePotEnd;
  steerAnglePotEnd = analogRead(steeringPotPin);
  //status_pub.publish(&status_msg);
  nh.spinOnce();
}
