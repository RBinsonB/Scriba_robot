#ifndef _ROS_scriba_msgs_data_odom_h
#define _ROS_scriba_msgs_data_odom_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace scriba_msgs
{

  class data_odom : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int32_t _stepAngleSteerStart_type;
      _stepAngleSteerStart_type stepAngleSteerStart;
      typedef int32_t _stepAngleSteerEnd_type;
      _stepAngleSteerEnd_type stepAngleSteerEnd;
      typedef int32_t _tractionSteps_type;
      _tractionSteps_type tractionSteps;
      typedef uint16_t _durationMillis_type;
      _durationMillis_type durationMillis;

    data_odom():
      header(),
      stepAngleSteerStart(0),
      stepAngleSteerEnd(0),
      tractionSteps(0),
      durationMillis(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_stepAngleSteerStart;
      u_stepAngleSteerStart.real = this->stepAngleSteerStart;
      *(outbuffer + offset + 0) = (u_stepAngleSteerStart.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stepAngleSteerStart.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stepAngleSteerStart.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stepAngleSteerStart.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepAngleSteerStart);
      union {
        int32_t real;
        uint32_t base;
      } u_stepAngleSteerEnd;
      u_stepAngleSteerEnd.real = this->stepAngleSteerEnd;
      *(outbuffer + offset + 0) = (u_stepAngleSteerEnd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stepAngleSteerEnd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stepAngleSteerEnd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stepAngleSteerEnd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stepAngleSteerEnd);
      union {
        int32_t real;
        uint32_t base;
      } u_tractionSteps;
      u_tractionSteps.real = this->tractionSteps;
      *(outbuffer + offset + 0) = (u_tractionSteps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tractionSteps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tractionSteps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tractionSteps.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tractionSteps);
      *(outbuffer + offset + 0) = (this->durationMillis >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->durationMillis >> (8 * 1)) & 0xFF;
      offset += sizeof(this->durationMillis);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_stepAngleSteerStart;
      u_stepAngleSteerStart.base = 0;
      u_stepAngleSteerStart.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stepAngleSteerStart.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stepAngleSteerStart.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stepAngleSteerStart.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stepAngleSteerStart = u_stepAngleSteerStart.real;
      offset += sizeof(this->stepAngleSteerStart);
      union {
        int32_t real;
        uint32_t base;
      } u_stepAngleSteerEnd;
      u_stepAngleSteerEnd.base = 0;
      u_stepAngleSteerEnd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stepAngleSteerEnd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stepAngleSteerEnd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stepAngleSteerEnd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stepAngleSteerEnd = u_stepAngleSteerEnd.real;
      offset += sizeof(this->stepAngleSteerEnd);
      union {
        int32_t real;
        uint32_t base;
      } u_tractionSteps;
      u_tractionSteps.base = 0;
      u_tractionSteps.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tractionSteps.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tractionSteps.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tractionSteps.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tractionSteps = u_tractionSteps.real;
      offset += sizeof(this->tractionSteps);
      this->durationMillis =  ((uint16_t) (*(inbuffer + offset)));
      this->durationMillis |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->durationMillis);
     return offset;
    }

    const char * getType(){ return "scriba_msgs/data_odom"; };
    const char * getMD5(){ return "52939c23ccd1d7940ab806f11eae8f77"; };

  };

}
#endif
