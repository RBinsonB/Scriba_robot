#include "ros/ros.h"
#include "nav_msgs/Odometry.h"  
#include "scriba_msgs/data_odom.h"
#include "tf/transform_broadcaster.h"
#include "sensor_msgs/JointState.h"
#include <cmath>
#include "angle_kalman_filter.h"

class OdometryBroadcaster
{
public:
	OdometryBroadcaster();

private:
	//Functions
	void loadParams();
	void initJointStateMsg();
	void setupSubPub();
	float stepToAngle(float steps);
	float potentiometerToAngle(int potValue);
	void odomDataCallback(const scriba_msgs::data_odom& odom_data_msg);

	//ROS-related
	ros::NodeHandle nh; 
	ros::Publisher odom_pub;					//Odometry publisher
	ros::Subscriber odom_data_sub;				//Oodometry data subcriber
	tf::TransformBroadcaster odom_broadcaster;	//Odometry transform broadcaster
	ros::Publisher odom_joint_pub;				//joint value publisher	
	sensor_msgs::JointState joint_state_msg; 	//Joint publisher message
	ros::Time current_time;

	//Robot specific elements
	double length = 0.2156;			//Length between front wheel and rear wheels, in meters					
	double wheel_radius = 0.025;	//Front wheel radius in meters
	float microstepSteeringRatio;  	//Microstepping configuration for steering motor
	float microstepTractionRatio;  	//Microstepping configuration for traction motor
	float potentiometerOffset;		//Steering potentiometer offset
	float potentiometerRatio;		//Steering potentiometer ratio to convert from measured integer to angle (rad)

	float angleStepper = 0;
	float angleStepperPrev = 0;
	const float pi = 3.14159;	  			//It's just Pi, what did you expect?
	const float two_pi = 6.28318;				//And it's 2 times Pi...

	double frontWheelDistance = 0;			//Front wheel traveled distance in meters
	double tractionSteps = 0;					//Front wheel traveled steps
	double phi = 0;								//Front wheel steer angle in rad

	double x_pos = 0.0;
	double y_pos = 0.0;
	double dt = 0.0;
	double dx = 0.0;
	double dy = 0.0;
	double alpha = 0.0;
	double omega = 0.0;
	double vx = 0.0;
	double vy = 0.0;
	double vth = 0.0;

	std::string base_link = "/base_link";
	std::string odom = "/odom";

	//Steering angle Kalman filter
	float potentiometerVariance;							//Variance for the potentiometer reading
	float stepperCountVariance;								//Variance for the stepper motor step count
	AngleKalmanFilter angleEstimator;	//Kalman filter estimator
};


OdometryBroadcaster::OdometryBroadcaster()
{
	//Load parameters
	loadParams();

	//Initialize joint state message
	initJointStateMsg();

	//Setup subscribers and publishers
	setupSubPub();
	
	//Init ROS time
	current_time = ros::Time::now();

	//Init steering angle estimator
	angleEstimator.init(potentiometerVariance, stepperCountVariance, 0);
}

//Setup ROS subscribers and publishers
void OdometryBroadcaster::setupSubPub(){
	//Set odometry message pusblisher
	odom_pub = nh.advertise<nav_msgs::Odometry>("odom", 50);

	//Set joint state publisher
	odom_joint_pub = nh.advertise<sensor_msgs::JointState>("joint_states", 1);
	
	//Set odometry data subscriber
	odom_data_sub = nh.subscribe("odom_data", 1000, &OdometryBroadcaster::odomDataCallback, this);
}

//Initialize joint state message by setting array size and populating them
void OdometryBroadcaster::initJointStateMsg(){
	//Resize array
	joint_state_msg.name.resize(17);
	joint_state_msg.position.resize(17);
	//Set name fields
	joint_state_msg.name[0] = "base_link_to_carter";
	joint_state_msg.name[1] = "base_link_to_front_wheel_support";
	joint_state_msg.name[2] = "front_wheel_support_to_motor";
	joint_state_msg.name[3] = "front_wheel_support_to_front_wheel";
	joint_state_msg.name[4] = "base_link_to_left_rear_wheel";
	joint_state_msg.name[5] = "base_link_to_right_rear_wheel";
	joint_state_msg.name[6] = "base_link_to_front_camera_support";
	joint_state_msg.name[7] = "front_camera_support_to_front_camera";
	joint_state_msg.name[8] = "front_camera_to_front_camera_img_origin";
	joint_state_msg.name[9] = "base_link_to_rear_camera_support";
	joint_state_msg.name[10] = "rear_camera_support_to_rear_camera";
	joint_state_msg.name[11] = "rear_camera_to_rear_camera_img_origin";
	joint_state_msg.name[12] = "base_link_to_slider_base";
	joint_state_msg.name[13] = "slider_base_to_slider";
	joint_state_msg.name[14] = "slider_to_slider_camera_support";
	joint_state_msg.name[15] = "slider_camera_support_to_slider_camera";
	joint_state_msg.name[16] = "slider_camera_to_slider_camera_img_origin";
	//Init joint message
	joint_state_msg.position[0] = 0;	//"base_link_to_carter", fixed
	joint_state_msg.position[1] = 0;	//base_link_to_front_wheel_support"; front wheel angle Phi  
	joint_state_msg.position[2] = 0;	//"front_wheel_support_to_motor", fixed
	joint_state_msg.position[3] = 0;	//"front_wheel_support_to_front_wheel", fixed
	joint_state_msg.position[4] = 0;	//"base_link_to_left_rear_wheel", fixed
	joint_state_msg.position[5] = 0;	//"base_link_to_right_rear_wheel", fixed	
	joint_state_msg.position[6] = 0;	//"base_link_to_front_camera_support", fixed
	joint_state_msg.position[7] = 0;	//"front_camera_support_to_front_camera", fixed
	joint_state_msg.position[8] = 0;	//"front_camera_to_front_camera_img_origin", fixed
	joint_state_msg.position[9] = 0;	//"base_link_to_rear_camera_support", fixed
	joint_state_msg.position[10] = 0;	//"rear_camera_support_to_rear_camera", fixed
	joint_state_msg.position[11] = 0;	//"rear_camera_to_rear_camera_img_origin", fixed  
	joint_state_msg.position[12] = 0;	//"base_link_to_slider_base", TODO
	joint_state_msg.position[13] = 0;	//"slider_base_to_slider", TODO
	joint_state_msg.position[14] = 0;	//"slider_to_slider_camera_support", fixed
	joint_state_msg.position[15] = 0;	//"slider_camera_support_to_slider_camera", fixed
	joint_state_msg.position[16] = 0;	//"slider_camera_to_slider_camera_img_origin", fixed
}

//Loads parameters from ROS parameter server
void OdometryBroadcaster::loadParams(){
	//Load node frequency
	if(!nh.param<float>("steering_microstep_ratio", microstepSteeringRatio, 50)){
		ROS_WARN("Failed to get steering stepper motor microstep ratio from ROS parameter server, using default value: %f", microstepSteeringRatio);
	}

	//Load microstepping ratio for steering stepper motor
	if(!nh.param<float>("steering_microstep_ratio", microstepSteeringRatio, 0.5)){
		ROS_WARN("Failed to get steering stepper motor microstep ratio from ROS parameter server, using default value: %f", microstepSteeringRatio);
	}

	//Load microstepping ratio for traction stepper motor
	if(!nh.param<float>("steering_microstep_ratio", microstepTractionRatio, 1)){
		ROS_WARN("Failed to get traction stepper motor microstep ratio from ROS parameter server, using default value: %f", microstepTractionRatio);
	}

	//Load steering potentiometer conversion ratio
	if(!nh.param<float>("steering_potentiometer_ratio", potentiometerRatio, 0.0123)){
		ROS_WARN("Failed to get steering potentiometer conversion ratio from ROS parameter server, using default value: %f", potentiometerRatio);
	}

	//Load steering potentiometer offset
	if(!nh.param<float>("steering_potentiometer_offset", potentiometerOffset, 0)){
		ROS_WARN("Failed to get steering potentiometer offset from ROS parameter server, using default value: %f", potentiometerOffset);
	}

	//Load potentiometer variance for angle kalman filter
	if(!nh.param<float>("steering_angle_kalman_filter/potentiometer_variance", potentiometerVariance, 0.4)){
		ROS_WARN("Failed to get steering potentiometer variance from ROS parameter server, using default value: %f", potentiometerVariance);
	}

	//Load stepper count variance for angle kalman filter
	if(!nh.param<float>("steering_angle_kalman_filter/stepper_variance", stepperCountVariance, 0.4)){
		ROS_WARN("Failed to get steering stepper count variance from ROS parameter server, using default value: %f", stepperCountVariance);
	}
}

//Convert step to radians according according to microstepping configuration, gear ratio and stepper motor ratio
float OdometryBroadcaster::stepToAngle(float steps){
		return (steps * 0.12 * microstepSteeringRatio * pi)/180;
}

float OdometryBroadcaster::potentiometerToAngle(int potValue){
	return (potentiometerRatio * potValue) + potentiometerOffset;
	}

void OdometryBroadcaster::odomDataCallback(const scriba_msgs::data_odom& odom_data_msg){
	//Get data from message and compute displacement
	current_time = odom_data_msg.header.stamp;													//Get odometry data time stamp
	dt = odom_data_msg.durationMillis/1000;														//Get odometry data sample durations and converts from milliseconds to seconds
	tractionSteps = odom_data_msg.tractionSteps;													//Get front wheel traveled distance in steps
	
	angleStepper = ( stepToAngle(odom_data_msg.stepAngleSteerStart) + stepToAngle(odom_data_msg.stepAngleSteerEnd) )/2;									//Get average front wheel steer angle (in steps)
	angleEstimator.predictAngle(angleStepper-angleStepperPrev);
	angleStepperPrev = angleStepper;

	angleEstimator.updateAngle(potentiometerToAngle((odom_data_msg.potAngleSteerStart + odom_data_msg.potAngleSteerStart)/2));

	phi = angleEstimator.estimatedAngle;

	ROS_INFO_STREAM("Estimated angle is " << phi);
 	
 	if(phi == 0){ //If not angular displacement
		//Calculate displacement in the robot base frame 		
 		frontWheelDistance = (tractionSteps * wheel_radius * microstepTractionRatio * pi)/200; //Front wheel distance, converted in meters
 		omega = 0.0;
 		dx = frontWheelDistance;
  		dy = 0.0;
 	}
 	else{
 		//Calculate displacement in the robot base frame
  		frontWheelDistance = (tractionSteps * wheel_radius * microstepTractionRatio * pi)/200;	//Front wheel distance, converted in meters
  		omega = frontWheelDistance * (sin(phi)/length);
		dx = length * (cos(phi)/sin(phi)) * sin(omega);
  		dy = length * (cos(phi)/sin(phi)) * (1-cos(omega));
 	}

 	ROS_INFO_STREAM("Front wheel distance is " << frontWheelDistance);
 	ROS_INFO_STREAM("Omega angle is " << omega);

  	//Add displacement to global displacement in the odometry frame
	x_pos += (cos(alpha) * dx - sin(alpha) * dy);
	y_pos += (sin(alpha) * dx + cos(alpha) * dy);
	alpha += omega; 

	if(alpha >= two_pi) alpha -= two_pi;
	if(alpha <= -two_pi) alpha += two_pi;
	
	//Calculate speeds
	vx = dx/dt;
	vy = dy/dt;
	vth = omega/dt;	
	
	geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(alpha);

	//Publish the transform over tf
	geometry_msgs::TransformStamped odom_trans;
	odom_trans.header.stamp = current_time;
	odom_trans.header.frame_id = "odom";
	odom_trans.child_frame_id = "base_link";

	odom_trans.transform.translation.x = x_pos;
	odom_trans.transform.translation.y = y_pos;
	odom_trans.transform.translation.z = 0.025;
	odom_trans.transform.rotation = odom_quat;

	//send the transform
	odom_broadcaster.sendTransform(odom_trans);

	//Publish the odometry message over ROS
	nav_msgs::Odometry odom;
	odom.header.stamp = current_time;
	odom.header.frame_id = "odom";

	//set the position
	odom.pose.pose.position.x = x_pos;
	odom.pose.pose.position.y = y_pos;
	odom.pose.pose.position.z = 0.025;
	odom.pose.pose.orientation = odom_quat;

	//set the velocity
	odom.child_frame_id = "base_link";
	odom.twist.twist.linear.x = vx;
	odom.twist.twist.linear.y = vy;
	odom.twist.twist.angular.z = vth;

	//publish the message
	odom_pub.publish(odom); 
	
	//Set the joint message
	joint_state_msg.position[1] = phi;			//base_link_to_front_wheel_support"; front wheel angle Phi  
	
	//Publish joint message to joint state publisher
	odom_joint_pub.publish(joint_state_msg);
}

int main(int argc, char **argv)
{
	//Init ROS node
	ros::init(argc, argv, "scriba_odometry_broadcaster");
	
	//Odometry broadcaster
	OdometryBroadcaster odometry_broadcaster;
	
	ros::spin();

	return 0;
}