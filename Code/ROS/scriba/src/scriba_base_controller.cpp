//==============================================================
//                    SCRIBA BASE CONTROLLER
//==============================================================
// The controller translates velocity commands into front wheel
// angle and front wheel speed commands
//==============================================================
#include <ros/ros.h>
#include <cmath>
#include <geometry_msgs/Twist.h>
#include <ros/time.h>
#include "scriba_msgs/mot_cmd.h"

class SubscribeAndPublish
{
public:
	SubscribeAndPublish()
	{
		//Topic you want to publish
		mot_pub = n.advertise<scriba_msgs::mot_cmd>("cmd_mot", 50);		//Create motor command publisher

		//Topic you want to subscribe
		vel_cmd_sub = n.subscribe("cmd_vel", 50, &SubscribeAndPublish::handle_vel_cmd, this);
	
		current_time = ros::Time::now();
		last_time = ros::Time::now();
	}
	void handle_vel_cmd (const geometry_msgs::Twist& cmd_vel) {
	
		speed_req = cmd_vel.linear.x;										//Extract the commanded linear speed from the message
		angular_speed_req = cmd_vel.angular.z;							//Extract the commanded angular speed from the message
  
		if (speed_req == 0){																					//Special case if only angular speed
			if (angular_speed_req > 0){																	//If positive angle rotation
				angle_req_steer = pi/2;																		//Turn front wheel left
				speed_req_traction = abs((angular_speed_req*length)/sin(angle_req_steer));	//Front wheel speed
			}
			else if (angular_speed_req < 0){																//If negative angle rotation
				angle_req_steer = -pi/2;																	//Turn front wheel right
				speed_req_traction = abs((angular_speed_req*length)/sin(angle_req_steer));	//Front wheel speed			
			}
			else{																									//If no speed at all
				//Doesn't define angle_req_steer to send previous value
				speed_req_traction = 0;																		//Front wheel speed to 0
			}									
		}
		else if (angular_speed_req == 0){																//Special case if only forward/backward speed
			angle_req_steer = 0;																				//Front wheel in middle position
			speed_req_traction = speed_req;																//Front wheel speed
		}
		else{																										//"Standard" case
			angle_req_steer = atan((angular_speed_req*length)/speed_req);						//Calculate the required angle for the steering motor to comply with commanded linear and angular speeds
			speed_req_traction = (speed_req/(cos(angle_req_steer)));								//Calculate the required speed for the traction motor to comply with commanded linear and angular speeds
		}
		ROS_INFO("front wheel angle : %f", angle_req_steer);									//info log
		ROS_INFO("front wheel speed : %f", speed_req_traction);								//info log
		
		scriba_msgs::mot_cmd mot_cmd_msg;																	//Create motor command message
		mot_cmd_msg.angle = angle_req_steer;														//Set front wheel angle in message
		mot_cmd_msg.tractionSpeed = speed_req_traction;											//Set front wheel speed in message
		mot_pub.publish(mot_cmd_msg);																	//Publish msg
	}
private:
	ros::NodeHandle n;
	ros::Publisher mot_pub;
	ros::Subscriber vel_cmd_sub;
	double wheel_radius = 0.025;               	//Wheel radius, in m
	double length = 0.2156;                      //Length, in m
	double pi = 3.14159;
	double speed_req = 0;                        //Desired linear speed for the robot, in m/s
	double angular_speed_req = 0;                //Desired angular speed for the robot, in rad/s
	double angle_req_steer = 0;						//Steering motor required angle, in rad
	double speed_req_traction = 0;					//Traction motor required speed, in m/s
	ros::Time current_time, last_time;
};//End of class SubscribeAndPublish
  

int main(int argc, char** argv){
	ros::init(argc, argv, "scriba_base_controller");
	
	//Create an object of class SubscribeAndPublish that will take care of everything
	SubscribeAndPublish SAPObject;
	
	ros::spin();

	return 0;
}
