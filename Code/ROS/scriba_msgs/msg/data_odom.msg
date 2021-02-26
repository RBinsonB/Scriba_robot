# Raw data from sensors and steering controller
# Used to compute odometry

Header header
int32 steerAngleStepsStart    # Steering stepper motor position (in steps) at start of loop
int32 steerAngleStepsEnd      # Steering stepper motor position (in steps) at end of loop
int16 steerAnglePotStart      # Steering angle potentiometer position (10 bits int) at start of loop
int16 steerAnglePotEnd        # Steering angle potentiometer position (10 bits int) at end of loop
int32 tractionSteps           # Number of traction stepper motor steps executed during loop
uint16 durationMillis         # Loop duration in milliseconds
