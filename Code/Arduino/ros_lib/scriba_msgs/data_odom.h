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
      typedef int32_t _steerAngleStepsStart_type;
      _steerAngleStepsStart_type steerAngleStepsStart;
      typedef int32_t _steerAngleStepsEnd_type;
      _steerAngleStepsEnd_type steerAngleStepsEnd;
      typedef int16_t _steerAnglePotStart_type;
      _steerAnglePotStart_type steerAnglePotStart;
      typedef int16_t _steerAnglePotEnd_type;
      _steerAnglePotEnd_type steerAnglePotEnd;
      typedef int32_t _tractionSteps_type;
      _tractionSteps_type tractionSteps;
      typedef uint16_t _durationMillis_type;
      _durationMillis_type durationMillis;

    data_odom():
      header(),
      steerAngleStepsStart(0),
      steerAngleStepsEnd(0),
      steerAnglePotStart(0),
      steerAnglePotEnd(0),
      tractionSteps(0),
      durationMillis(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_steerAngleStepsStart;
      u_steerAngleStepsStart.real = this->steerAngleStepsStart;
      *(outbuffer + offset + 0) = (u_steerAngleStepsStart.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steerAngleStepsStart.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steerAngleStepsStart.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steerAngleStepsStart.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steerAngleStepsStart);
      union {
        int32_t real;
        uint32_t base;
      } u_steerAngleStepsEnd;
      u_steerAngleStepsEnd.real = this->steerAngleStepsEnd;
      *(outbuffer + offset + 0) = (u_steerAngleStepsEnd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steerAngleStepsEnd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_steerAngleStepsEnd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_steerAngleStepsEnd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steerAngleStepsEnd);
      union {
        int16_t real;
        uint16_t base;
      } u_steerAnglePotStart;
      u_steerAnglePotStart.real = this->steerAnglePotStart;
      *(outbuffer + offset + 0) = (u_steerAnglePotStart.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steerAnglePotStart.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steerAnglePotStart);
      union {
        int16_t real;
        uint16_t base;
      } u_steerAnglePotEnd;
      u_steerAnglePotEnd.real = this->steerAnglePotEnd;
      *(outbuffer + offset + 0) = (u_steerAnglePotEnd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_steerAnglePotEnd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->steerAnglePotEnd);
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

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_steerAngleStepsStart;
      u_steerAngleStepsStart.base = 0;
      u_steerAngleStepsStart.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steerAngleStepsStart.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steerAngleStepsStart.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steerAngleStepsStart.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steerAngleStepsStart = u_steerAngleStepsStart.real;
      offset += sizeof(this->steerAngleStepsStart);
      union {
        int32_t real;
        uint32_t base;
      } u_steerAngleStepsEnd;
      u_steerAngleStepsEnd.base = 0;
      u_steerAngleStepsEnd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steerAngleStepsEnd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_steerAngleStepsEnd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_steerAngleStepsEnd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->steerAngleStepsEnd = u_steerAngleStepsEnd.real;
      offset += sizeof(this->steerAngleStepsEnd);
      union {
        int16_t real;
        uint16_t base;
      } u_steerAnglePotStart;
      u_steerAnglePotStart.base = 0;
      u_steerAnglePotStart.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steerAnglePotStart.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->steerAnglePotStart = u_steerAnglePotStart.real;
      offset += sizeof(this->steerAnglePotStart);
      union {
        int16_t real;
        uint16_t base;
      } u_steerAnglePotEnd;
      u_steerAnglePotEnd.base = 0;
      u_steerAnglePotEnd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_steerAnglePotEnd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->steerAnglePotEnd = u_steerAnglePotEnd.real;
      offset += sizeof(this->steerAnglePotEnd);
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

    virtual const char * getType() override { return "scriba_msgs/data_odom"; };
    virtual const char * getMD5() override { return "36e182bc927b98f5674540747694f02b"; };

  };

}
#endif
