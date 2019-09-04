# Scriba robot
More information (such as components used, robot building and so on) can be found on the [Hackster page of the project.](https://www.hackster.io/robinb/scriba-robot-a-printing-robot-0048fa)
## Concept
Scriba is a printing robot. It prints on its wake, using the sheet edges and the printing in process as a reference for its navigation. It uses multiple cameras to correct its trajectory and printing alignment through a SLAM algorithm

<a href="url"><img src="/Documentation/Pictures/Picture1.png" align="center" height="322" width="454"></a>

*Robot concept*

The robot was supposed to be light and portable but grew in sized as the project progressed. It is designed to print on medium and large surfaces.

<a href="url"><img src="/Documentation/Pictures/Picture2.png" align="center" height="261" width="337"></a>
<a href="url"><img src="/Documentation/Pictures/Picture3.png" align="center" height="262" width="333"></a>

## Project advancement
WORK IN PROGRESS

Done:
```diff
+ Mechanical Design
+ Electrical Design
+ Components printing/machining
+ Robot assembly
+ PCB assembly
+ ROS serial communication with Arduinos
+ Standard motor command
+ Odometry
+ Odometry and motor command calibration
```
To do:
```diff
- Printhead test
- Low voltage disconnect board
- Step motor command
- Printing command
- Localization by camera
```
<a href="url"><img src="/Documentation/Pictures/Scriba1.jpg" align="center" height="300" width="400"></a>
<a href="url"><img src="/Documentation/Pictures/Scriba2.jpg" align="center" height="300" width="400"></a>

### Video: Scriba drive & odometry test
[![Scriba odometry test](https://img.youtube.com/vi/UUCUU0tR3d4/0.jpg)](https://www.youtube.com/watch?v=UUCUU0tR3d4)
### Video: Scriba front wheel calibration 
[![Scriba front wheel angle calibration](https://img.youtube.com/vi/NhuQ65PKyDQ/0.jpg)](https://www.youtube.com/watch?v=NhuQ65PKyDQ)

## System overview
The detailed [technical design description can be found here.](https://raw.githubusercontent.com/RBinsonB/Scriba_robot/master/Technical_Design_Scriba.pdf)

<a href="url"><img src="/Documentation/Pictures/Picture4.png" align="center" height="426" width="800"></a>

*Scriba robot bottom view*

<a href="url"><img src="/Documentation/Pictures/ElectricalControlDiagram.png" align="center" height="432" width="800"></a>

*Overall electric & controls diagram*

[The diagram can be found here in higher resolution](https://raw.githubusercontent.com/RBinsonB/Scriba_robot/master/Overall_Electrical_&_Controls_Diagram_Scriba_Robot.pdf)

### Controls
The main computer of the robot is an Odroid-XU4 running Ubuntu 18.04 and mainly relying on a ROS (Robot Operating System) program to run the robot. Computer vision tasks are carried out by OpenCV programs interfaced with the ROS main program.

Actuator control is carried out by two Arduinos Nano, as they can handle real-time operation and GPIO control better than the main computer. They are connected to serial node on the ROS main program.
The robot can be controlled by WiFi from a remote computer by connecting to the Odroid-XU4 via SSH.

### Drive configuration
The robot has a steer drive configuration (also called steerable driving wheel configuration) with one powered and steering wheel at the front and 2 wheel for support at the rear (like a tricycle). This configuration was chosen because of the high driving accuracy it provides when following a navigation path.

<a href="url"><img src="/Documentation/Pictures/Picture5.png" align="center" height="307" width="400"></a>

*Steer Drive configuration*

### Navigation & Localization system
The robot uses a SLAM algorithm (Simultaneous Localization And Mapping) to navigate. It localize itself by using the printing in process as a reference.

Cameras are located at the front and at the rear of the robot. Their location allows the robot to see the printing in process (with the rear camera) and the previous printing. Being able to see the previous printing after a turn is crucial to correct localization because turns generate a lot of imprecisions in the odometry.

<a href="url"><img src="/Documentation/Pictures/Picture6.png" align="center" height="307" width="800"></a>

A light source near the camera ensures a correct and uniform lighting of the scanned surface. Inclination of the camera images is corrected by a homographic algorithm.

### Printing system
The printhead is placed on a sweeping system. Both have to stay perpendicular to the printing direction even when the robot is correcting its trajectory. The printing system is therefor able to rotate around the kinematic center of the robot.

<a href="url"><img src="/Documentation/Pictures/Picture7.png" align="center" height="429" width="600"></a>

*Printing system schematics*

## ROS Package description:
* scriba_description: includes Scriba URDF model and launch files for display in RViz
  * Launch files:
    * *scriba_rviz.launch*: Displays the URDF robot model in Rviz with a GUI to configure joint values.
* scriba_msgs: includes Scriba custom messages
  * Messages files:
    * *data_odom.msg*: Custom message for odometry data sent by the Arduino of the drive unit.
    * *mot_cmd.msg*: Custom message for the motor command sent to the Arduino of the drive unit.
  * Service files
    * *front_wheel_calibration.srv*: Custom service for calibration of the front wheel angle. Service server hosted by the Arduino of the drive unit.
* scriba: includes Scriba main nodes and launch files
  * Nodes:
    * *scriba_base_controller.cpp*: Converts velocity commands (vel_cmd) to custom motor command (mot_cmd) to be sent to the Arduino of the drive unit.
    * *scriba_odometry_broadcaster.cpp*: Receives odometry data from the custom data_odom message type and computes the odometry accordingly.
  * Launch files:
    * *scriba_bringup.launch*: Launches all required components for basic odometry and motor command.
    * *sriba_odom.launch*: Launches all required components for basic odometry.
    * *scriba_rviz_remote.launch*: Launches RViz with all required parameters for a remote display of the odometry
  * Scripts:
    * *front_wheel_calibration.py*: Script for calibration of the front wheel angle. Uses a custom front_wheel_calibration service type.
* Arduino: includes Arduino programs.
  * Programs:
    * *Scriba_steering_board_V1*: Program for the arduino of the drive unit. Uses custom message type to receive and execute motor commands, send odometry data and perform calibration operations.
    
    
:bangbang: Services don't work on Arduino with the last rosserial_python and rosserial_arduino packages (0.8.0). Building an older version from source is required in order to use services. Older packages are included in the repository and can be built after uninstalling the repo packages.

:bangbang: There is a bug in the lastest ROS versions (Melodic and Lunar) preventing the correct display on robot models in RViz if you have a local setting other than US. A quick fix working for me was to type the following command before launching RViz:
```
export LC_NUMERIC="en_US.UTF-8"
```

## Authors

* **Robin Baran** - *Initial work*

## License

This project is licensed under the GNU General Public License version 3

## Acknowledgments

* [Inkjet Printer For the Reprap](https://reprap.org/mediawiki/images/1/1a/Inkjet.pdf) by Amberish Jaipuria
* [DIY Inkjet Printer](https://www.thingiverse.com/thing:8542/) by Patrick Hannan, Jared Knutzen, Nicholas C Lewis, Joy Markham
