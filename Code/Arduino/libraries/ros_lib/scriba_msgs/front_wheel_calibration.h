#ifndef _ROS_SERVICE_front_wheel_calibration_h
#define _ROS_SERVICE_front_wheel_calibration_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace scriba_msgs
{

static const char FRONT_WHEEL_CALIBRATION[] = "scriba_msgs/front_wheel_calibration";

  class front_wheel_calibrationRequest : public ros::Msg
  {
    public:
      typedef float _front_wheel_offset_type;
      _front_wheel_offset_type front_wheel_offset;
      typedef float _microstepSteeringRatio_type;
      _microstepSteeringRatio_type microstepSteeringRatio;

    front_wheel_calibrationRequest():
      front_wheel_offset(0),
      microstepSteeringRatio(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_front_wheel_offset;
      u_front_wheel_offset.real = this->front_wheel_offset;
      *(outbuffer + offset + 0) = (u_front_wheel_offset.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_front_wheel_offset.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_front_wheel_offset.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_front_wheel_offset.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->front_wheel_offset);
      union {
        float real;
        uint32_t base;
      } u_microstepSteeringRatio;
      u_microstepSteeringRatio.real = this->microstepSteeringRatio;
      *(outbuffer + offset + 0) = (u_microstepSteeringRatio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_microstepSteeringRatio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_microstepSteeringRatio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_microstepSteeringRatio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->microstepSteeringRatio);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_front_wheel_offset;
      u_front_wheel_offset.base = 0;
      u_front_wheel_offset.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_front_wheel_offset.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_front_wheel_offset.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_front_wheel_offset.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->front_wheel_offset = u_front_wheel_offset.real;
      offset += sizeof(this->front_wheel_offset);
      union {
        float real;
        uint32_t base;
      } u_microstepSteeringRatio;
      u_microstepSteeringRatio.base = 0;
      u_microstepSteeringRatio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_microstepSteeringRatio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_microstepSteeringRatio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_microstepSteeringRatio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->microstepSteeringRatio = u_microstepSteeringRatio.real;
      offset += sizeof(this->microstepSteeringRatio);
     return offset;
    }

    const char * getType(){ return FRONT_WHEEL_CALIBRATION; };
    const char * getMD5(){ return "9502674d71f53e4b2d22e0ae3b556cbd"; };

  };

  class front_wheel_calibrationResponse : public ros::Msg
  {
    public:
      typedef float _minAngle_type;
      _minAngle_type minAngle;
      typedef float _maxAngle_type;
      _maxAngle_type maxAngle;
      typedef bool _result_type;
      _result_type result;

    front_wheel_calibrationResponse():
      minAngle(0),
      maxAngle(0),
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_minAngle;
      u_minAngle.real = this->minAngle;
      *(outbuffer + offset + 0) = (u_minAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_minAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_minAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_minAngle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->minAngle);
      union {
        float real;
        uint32_t base;
      } u_maxAngle;
      u_maxAngle.real = this->maxAngle;
      *(outbuffer + offset + 0) = (u_maxAngle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_maxAngle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_maxAngle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_maxAngle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->maxAngle);
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_minAngle;
      u_minAngle.base = 0;
      u_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_minAngle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->minAngle = u_minAngle.real;
      offset += sizeof(this->minAngle);
      union {
        float real;
        uint32_t base;
      } u_maxAngle;
      u_maxAngle.base = 0;
      u_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_maxAngle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->maxAngle = u_maxAngle.real;
      offset += sizeof(this->maxAngle);
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
     return offset;
    }

    const char * getType(){ return FRONT_WHEEL_CALIBRATION; };
    const char * getMD5(){ return "533c97a516c78bb92c7089b29b6c94c9"; };

  };

  class front_wheel_calibration {
    public:
    typedef front_wheel_calibrationRequest Request;
    typedef front_wheel_calibrationResponse Response;
  };

}
#endif
