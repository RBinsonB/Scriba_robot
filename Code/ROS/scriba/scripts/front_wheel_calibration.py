#!/usr/bin/env python

import sys
import rospy
import collections
from scriba_msgs.srv import *

valid_microstep_categories = ['1', '1/2', '1/4', '1/8', '1/16']

def front_wheel_calib_client(angle_offset, steeringMicrostepRatio):
    rospy.wait_for_service('fw_cal')
    try:
        front_wheel_angle_calib = rospy.ServiceProxy('fw_cal', front_wheel_calibration)
        resp1 = front_wheel_angle_calib(angle_offset, steeringMicrostepRatio)
        return resp1
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

if __name__ == "__main__":
	while True:
		angle_offset = float(input("Enter front wheel angle offset in radians (comprised between -1.57080 and 1.57080): "))
		if (angle_offset > -1.57080) and (angle_offset < 1.57080):
			break
		else:
			print "Entered value is not correct"
	while True:
		response = raw_input("Enter steering motor microstep selection (1, 1/2, 1/4, 1/8 or 1/16): ")
		if response in valid_microstep_categories:         
			if response == '1':
				steeringMicrostepRatio = float(1)
				break
			elif response == '1/2':
				steeringMicrostepRatio = float(0.5)
				break
			elif response == '1/4':
				steeringMicrostepRatio = float(0.25)
				break        
			elif response == '1/8':
				steeringMicrostepRatio = float(0.125)
				break  
			elif response == '1/16':
				steeringMicrostepRatio = float(0.0625)
				break
		else:
			print "Entered value is not correct"  
	print "Sending calibration request with front wheel angle offset of %s rad and steering motor microstep selection: %s"%(angle_offset, steeringMicrostepRatio)
	resp2 = front_wheel_calib_client(angle_offset, steeringMicrostepRatio)
	if resp2.result:
		print "Calibration successful"
		print "min angle: %s"%(resp2.minAngle)
		print "max angle: %s"%(resp2.maxAngle)
	else:
		print "Calibration failed"
    