//This program is driving the Scriba robot according to received motor commands
//The robot first follows a steering calibration procedure before driving
//The program also includes an emergency button stop function that will prevent the robot from moving if the emergency signal is low
//Author: Robin Baran
//Email: r-baran@hotmail.fr

#include "Scriba_steering_board.h"

//____________________________________________________

void setup(){
  // Start motor control and ROS node
  setupController();
}

void loop(){
  // Run controller at set looprate
  runController();
}  
