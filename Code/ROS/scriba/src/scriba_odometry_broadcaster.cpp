#include "ros/ros.h"
#include "nav_msgs/Odometry.h"  
#include "scriba_msgs/data_odom.h"
#include "tf/transform_broadcaster.h"
#include "sensor_msgs/JointState.h"
#include <cmath>
#include "angle_kalman_filter.h"

double length = 0.2156;						//Length between front wheel and rear wheels, in meters					
double wheel_radius = 0.025;				//Front wheel radius in meters
float microstepSteeringRatio = 0.5;  	//Microstepping configuration for steering motor
float microstepTractionRatio = 1;  	//Microstepping configuration for traction motor
float angleStepper = 0;
float angleStepperPrev = 0;
const float pi = 3.14159;	  			//It's just Pi, what did you expect?
const float two_pi = 6.28318;				//And it's 2 times Pi...

double frontWheelDistance = 0;			//Front wheel traveled distance in meters
double tractionSteps = 0;					//Front wheel traveled steps
double phi = 0;								//Front wheel steer angle in rad

double potentiometerOffset = 0;
double potentiometerRatio = 0.0123;
double rate = 10.0;
bool publish_tf = true;
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
char base_link[] = "/base_link";
char odom[] = "/odom";

AngleKalmanFilter angleEstimator(0.4, 0.05);


class SubscribeAndPublish
{
public:
  	SubscribeAndPublish()
  	{
		//Topic you want to publish
		odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
		odom_joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1); //Create joint publisher	
		
		//Topic you want to subscribe
		odom_data_sub = n.subscribe("odom_data", 1000, &SubscribeAndPublish::callback, this);
		
		current_time = ros::Time::now();

		//Init steering angle estimator
		angleEstimator.init(0);
	}

	//Convert step to radians according according to microstepping configuration, gear ratio and stepper motor ratio
	float stepToAngle(float steps){
  		return (steps * 0.12 * microstepSteeringRatio * pi)/180;
	}

	float potentiometerToAngle(int potValue){
		return (potentiometerRatio * potValue) + potentiometerOffset;
  	}

	void callback(const scriba_msgs::data_odom& odom_data_msg)
	{
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
		joints.name.resize(17);
		joints.position.resize(17);
		joints.name[0] = "base_link_to_carter";
		joints.name[1] = "base_link_to_front_wheel_support";
		joints.name[2] = "front_wheel_support_to_motor";
		joints.name[3] = "front_wheel_support_to_front_wheel";
		joints.name[4] = "base_link_to_left_rear_wheel";
		joints.name[5] = "base_link_to_right_rear_wheel";
		joints.name[6] = "base_link_to_front_camera_support";
		joints.name[7] = "front_camera_support_to_front_camera";
		joints.name[8] = "front_camera_to_front_camera_img_origin";
		joints.name[9] = "base_link_to_rear_camera_support";
		joints.name[10] = "rear_camera_support_to_rear_camera";
		joints.name[11] = "rear_camera_to_rear_camera_img_origin";
		joints.name[12] = "base_link_to_slider_base";
		joints.name[13] = "slider_base_to_slider";
		joints.name[14] = "slider_to_slider_camera_support";
		joints.name[15] = "slider_camera_support_to_slider_camera";
		joints.name[16] = "slider_camera_to_slider_camera_img_origin";
		//Init joint message
		joints.position[0] = 0;				//"base_link_to_carter", fixed
		joints.position[1] = phi;			//base_link_to_front_wheel_support"; front wheel angle Phi  
		joints.position[2] = 0;				//"front_wheel_support_to_motor", fixed
		joints.position[3] = 0;				//"front_wheel_support_to_front_wheel", fixed
		joints.position[4] = 0;				//"base_link_to_left_rear_wheel", fixed
		joints.position[5] = 0;				//"base_link_to_right_rear_wheel", fixed	
		joints.position[6] = 0;				//"base_link_to_front_camera_support", fixed
		joints.position[7] = 0;				//"front_camera_support_to_front_camera", fixed
		joints.position[8] = 0;				//"front_camera_to_front_camera_img_origin", fixed
		joints.position[9] = 0;				//"base_link_to_rear_camera_support", fixed
		joints.position[10] = 0;			//"rear_camera_support_to_rear_camera", fixed
		joints.position[11] = 0;			//"rear_camera_to_rear_camera_img_origin", fixed  
		joints.position[12] = 0;			//"base_link_to_slider_base", TODO
		joints.position[13] = 0;			//"slider_base_to_slider", TODO
		joints.position[14] = 0;			//"slider_to_slider_camera_support", fixed
		joints.position[15] = 0;			//"slider_camera_support_to_slider_camera", fixed
		joints.position[16] = 0;			//"slider_camera_to_slider_camera_img_origin", fixed
		
		//Publish joint message to joint state publisher
		odom_joint_pub.publish(joints);

	}

private:
	ros::NodeHandle n; 
	ros::Publisher odom_pub;							//Create odometry publisher
	ros::Subscriber odom_data_sub;					//Create odometry data subcriber
	tf::TransformBroadcaster odom_broadcaster;	//Create odometry transform broadcaster
	ros::Publisher odom_joint_pub;
		
	//Create joint publisher message
	sensor_msgs::JointState joints;
	
	ros::Time current_time;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
	ros::init(argc, argv, "scriba_odometry_broadcaster");
	
	//Create an object of class SubscribeAndPublish that will take care of everything
	SubscribeAndPublish SAPObject;
	
	ros::Rate r(rate);
	ros::spin();

	return 0;
}