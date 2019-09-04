//This program is driving the Scriba robot according to received motor commands
//The robot first follows a steering calibration procedure before driving
//The program also includes an emergency button stop function that will prevent the robot from moving if the emergency signal is low
//Author: Robin Baran
//Email: r-baran@hotmail.fr

#include <AccelStepper.h>
#include <MultiStepper.h>
#include <ros.h>
#include <scriba_msgs/mot_cmd.h>
#include <scriba_msgs/data_odom.h>
#include <scriba_msgs/front_wheel_calibration.h>
#include <std_msgs/String.h>
#include <ros/time.h>

// Define pin connections & motor's steps per revolution
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

#define LOOPTIME                      100     //Looptime in millisecond
unsigned long lastMilli = 0;
unsigned long lastCommMillis = 0;
const unsigned long noCommDurationMax = 1500; //Set the max time for the robot to run without motor commands
long stepAngleStart = 0;
long stepAngleEnd = 0;

long minSteeringStep = -2000;       //End position right step value
long maxSteeringStep = 2000;        //End position left step value
float microstepSteeringRatio = 0.5;   //Microstepping configuration for steering motor
float microstepTractionRatio = 0.5;   //Microstepping configuration for traction motor
const float pi = 3.14159;             //It's just Pi, what did you expect?

//Create stepper objects for steering and traction stepper motor
AccelStepper tractionStepper = AccelStepper(1, tractionStepPin, tractionDirPin);
AccelStepper steeringStepper = AccelStepper(1, steeringStepPin, steeringDirPin);

byte mode = 0;                  //Driving mode. 0 is for standard mode (ajust front wheel angle while moving)and 1 for printing mode (ajust front wheel angle and then move)
double angle = 0;               //Front wheel angle in rad
float wheel_radius = 0.025;     //Front wheel radius in meters
int angleStep = 0;              //Front wheel angle in steps
int tractionSpeed = 800;        //Traction stepper motor speed in steps/second
int steeringSpeed = 400;        //Steering stepper motor speed in steps/second
const int tractionAcc = 350;    //Traction stepper motor acceleration in steps/second/second
const int steeringAcc = 200;    //Traction stepper motor acceleration in steps/second/second

//Start ROS node handle
ros::NodeHandle_<ArduinoHardware, 3, 3, 128, 200> nh; //ROS buffer size /!\ an high buffer size can fill the Arduino's memory. Optimizing the buffer size is capital
using scriba_msgs::front_wheel_calibration;

//function that will be called when receiving command from host
void handle_cmd (const scriba_msgs::mot_cmd& mot_cmd_msg) {
  mode = 0;                                                                       //Standard driving mode because data received as mot_cmd
  lastCommMillis = millis();                                                      //Set last communication time
  
  //Get front wheel angle command (in rad) & convert radian angle to steps according to microstepping configuration and gear and stepper motor ratio
  angleStep = (mot_cmd_msg.angle*(180/pi))/(microstepSteeringRatio*0.12);
  
//Get front wheel speed command (in m/s & convert m/s speed to step/s speed according to microstepping configuration and motor angle/step ratio
  tractionSpeed = (mot_cmd_msg.tractionSpeed/wheel_radius)*(200/(microstepTractionRatio*pi));
  
  angleStep = min(angleStep, maxSteeringStep);         //Bound the step angle to the max calibrated value
  angleStep = max(angleStep, minSteeringStep);         //Bound the step angle to the min calibrated value
  nh.spinOnce();
}

//Create motor command subscriber (custom message type)
ros::Subscriber<scriba_msgs::mot_cmd> cmd_mot("cmd_mot", handle_cmd);

//Create a "odom_data" ROS message (custom message type)
scriba_msgs::data_odom odom_data_msg;

//Create a odometry data publisher
ros::Publisher odom_data_pub("odom_data", &odom_data_msg);

//Create front wheel angle calibration service server
ros::ServiceServer<front_wheel_calibration::Request, front_wheel_calibration::Response> front_wheel_calib("fw_cal",&front_wheel_calib_callback);

//Define all log strings in prog memory to save SRAM
//emergency function logs
const char PROGMEM em_msg_1[22]= "EMERGENCY STOP ACTIVE";
const char PROGMEM em_msg_2[27]= "EMERGENCY STOP DEACTIVATED";
const char PROGMEM em_msg_3[25]= "Emergency button pressed";
const char PROGMEM em_msg_4[52]= "Steering end position microswitch missing/defective";
const char PROGMEM em_msg_5[42]= "Please check microswitch wiring and state";
const char PROGMEM em_msg_6[48]= "PUSH AND RELEASE EMERGENCY STOP BUTTON TO RESET";
const char PROGMEM em_msg_7[38]= "Unspecified reason for emergency stop";
//Calibration logs
const char PROGMEM clb_msg_1[27]= "Steer calibration starting";
const char PROGMEM clb_msg_2[40]= "Rotating to left end position switch...";
const char PROGMEM clb_msg_3[27]= "Left end position detected";
const char PROGMEM clb_msg_4[41]= "Rotating to right end position switch...";
const char PROGMEM clb_msg_5[28]= "Right end position detected";
const char PROGMEM clb_msg_6[36]= "Number of steps in steering range: ";
const char PROGMEM clb_msg_7[33]= "Going now to middle position... ";
const char PROGMEM clb_msg_8[21]= "Calibration complete";

//______________________________________________________________

//Function that will be called when receiving the calibration service request
void front_wheel_calib_callback(const front_wheel_calibration::Request & req, front_wheel_calibration::Response & res){
  long steeringRangeSteps = 0;                                  //numbers of step for the steering range
  float front_wheel_offset = 0;                                 //Front wheel offset angle
  front_wheel_offset = req.front_wheel_offset;                  //Get front wheel offset angle from calibration request
  microstepSteeringRatio = req.microstepSteeringRatio;          //Get steering stepper motor microstep setting from calibration request
  
  //====================================
  //   Steering calibration procedure
  //====================================
  digitalWrite(steeringSleepPin, HIGH);                         //Enable steering motor
  digitalWrite(tractionSleepPin, HIGH);                         //Enable traction motor
  nh.loginfo(clb_msg_1);                                        //"Steer calibration starting"
  // Spin motor until triggering left microswitch  
  nh.loginfo(clb_msg_2);                                        //"Rotating to left end position switch..."
  while (digitalRead(steeringMSLeftPin) == LOW){
    runMotors(0, 0, 400, 150);
  }
  steeringStepper.setCurrentPosition(0);
  nh.logdebug(clb_msg_3);                                       //"Left end position detected"
  delay(500); // Wait

  // Spin motor until triggering right microswitch  
  nh.logdebug(clb_msg_4);                                       //"Rotating to right end position switch..."                                     
  while (digitalRead(steeringMSRightPin) == LOW){
    runMotors(0, 0, -400, 150);
  }
  steeringRangeSteps = steeringStepper.currentPosition();
  nh.logdebug(clb_msg_5);                                       //"Right end position detected"
  nh.loginfo(clb_msg_6);
  Serial.print(abs(steeringRangeSteps));
  nh.logdebug(clb_msg_7);                                       //"Going now to middle position... "
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
  nh.loginfo(clb_msg_8);                                  //"Calibration complete"

  res.minAngle = minSteeringStep*(microstepSteeringRatio*0.12)*(pi/180);  //Write min front wheel angle (in rad) to calibration request response
  res.maxAngle = maxSteeringStep*(microstepSteeringRatio*0.12)*(pi/180);  //Write max front wheel angle (in rad) to calibration request response
  res.result = true;
  delay(1000);
}

//Robot run function
void robotRun(byte mod, int tracSpeed, int tracAcc, int steerSpeed, int angStep){
  if(digitalRead(EMStopPin) == LOW){                                                  //Check if emergency signal is absent (emergency button pressed)
    emergencyStop(1);
  }
  else if(digitalRead(steeringMSLeftPin) && digitalRead(steeringMSRightPin) == HIGH){  //Check if both steering end position microswitch active at the same time (indicating a missing or defective microswitch)
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
    nh.spinOnce();
  }
}

//Run motors function
void runMotors(int tractionSpeed, int tractionAcc, int steeringSpeed, int SteeringAcc){
  if(digitalRead(EMStopPin) == LOW){                                                  //Check if emergency signal is absent (emergency button pressed)
    emergencyStop(1);
  }
  else if(digitalRead(steeringMSLeftPin) && digitalRead(steeringMSRightPin) == HIGH){  //Check if both steering end position microswitch active at the same time (indicating a missing or defective microswitch)
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
    nh.spinOnce();
  }
}

//Emergency stop function. emergencyCase variable states the reason for which the emergency signal was sent.
void emergencyStop(byte emergencyCase){ 
  nh.logerror(em_msg_1);                                                                    //"EMERGENCY STOP ACTIVE";
  switch (emergencyCase){
    case 1:   //Emergency stop triggered by emergency button pressed (signal missing)
      nh.logwarn(em_msg_3);                                                                 //"Emergency button pressed"
      while(digitalRead(EMStopPin) == LOW){
        nh.spinOnce(); /*wait until emergency signal is resumed*/
      }
      nh.logwarn(em_msg_2);                                                                 //"EMERGENCY STOP DEACTIVATED"
      break;
    case 2:   //Emergency stop triggered by defective or missing microswitch
      nh.logwarn(em_msg_4);                                                                 //"Steering end position microswitch missing/defective"
      nh.logwarn(em_msg_5);                                                                 //"Please check microswitch wiring and state"
      nh.loginfo(em_msg_6);                                                                 //"PUSH AND RELEASE EMERGENCY STOP BUTTON TO RESET"
       while(digitalRead(EMStopPin) == HIGH){
        nh.spinOnce(); /*wait until emergency signal is pushed*/
      }  
      while(digitalRead(EMStopPin) == LOW){
        nh.spinOnce(); /*wait until emergency signal is resumed*/
      }
      nh.logwarn(em_msg_2);                                                                 //"EMERGENCY STOP DEACTIVATED"
      break;
    default:
      nh.logwarn(em_msg_7);                                                                 //"Unspecified reason for emergency stop"
      nh.loginfo(em_msg_6);                                                                 //"PUSH AND RELEASE EMERGENCY STOP BUTTON TO RESET"
       while(digitalRead(EMStopPin) == HIGH){
        nh.spinOnce(); /*wait until emergency signal is pushed*/
      }  
      while(digitalRead(EMStopPin) == LOW){
        nh.spinOnce(); /*wait until emergency signal is resumed*/
      }
      nh.logwarn(em_msg_2);                                                                //"EMERGENCY STOP DEACTIVATED"
  }
}

//____________________________________________________

void setup()
{
  nh.initNode();
  nh.getHardware()->setBaud(57600);
  nh.subscribe(cmd_mot);
  nh.advertise(odom_data_pub);
  nh.advertiseService(front_wheel_calib);
  nh.spinOnce();
  delay(3000);
  
  // Declare pins as Outputs
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

  //Enable the motor controllers
  digitalWrite(tractionEnablePin, LOW);
  digitalWrite(steeringEnablePin, LOW);
  digitalWrite(tractionSleepPin, HIGH);
  digitalWrite(steeringSleepPin, HIGH);
  digitalWrite(tractionResetPin, HIGH);
  digitalWrite(steeringResetPin, HIGH);

  // Set the maximum speed in steps per second:
  tractionStepper.setMaxSpeed(1000);
  steeringStepper.setMaxSpeed(1000);
}

void loop()
{                                                         // enter timed loop
  lastMilli = millis();
  //Populate odometry data message
  odom_data_msg.stepAngleSteerStart = stepAngleStart;               //Angle at start of the loop
  odom_data_msg.stepAngleSteerEnd = stepAngleEnd;                   //Angle at end of the loop
  odom_data_msg.tractionSteps = tractionStepper.currentPosition();  //Traveled steps of traction motor
  odom_data_msg.header.stamp = nh.now();                            //Time stamp
  tractionStepper.setCurrentPosition(0);                            //Set traveled steps back to 0
  odom_data_pub.publish(&odom_data_msg);                            //Publish odometry data
  nh.spinOnce();
    
  if(millis()-lastCommMillis < noCommDurationMax){                        //Check that a motor command has been received recently
    digitalWrite(tractionSleepPin, HIGH);                                 //Enable traction motor
    digitalWrite(steeringSleepPin, HIGH);                                 //Enable steering motor
    robotRun(mode, tractionSpeed, tractionAcc, steeringSpeed, angleStep); //Run robot with received commands
  } 
  else{                                                   //Stops robot if no communication with host (no motor command received)
    angleStep = 0;
    tractionSpeed = 0;
    digitalWrite(tractionSleepPin, LOW);
    digitalWrite(steeringSleepPin, LOW);
  }
  nh.spinOnce();
  while((millis()-lastMilli) < LOOPTIME){                  //run motors (or no if no communication) while waiting end of looptime
    robotRun(mode, tractionSpeed, tractionAcc, steeringSpeed, angleStep);
  }
  stepAngleStart = stepAngleEnd;                          //Set next angle at start as previous end angle
  stepAngleEnd = steeringStepper.currentPosition();       //Get angle at end of the loop
}
