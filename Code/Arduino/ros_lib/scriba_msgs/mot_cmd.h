#ifndef _ROS_scriba_msgs_mot_cmd_h
#define _ROS_scriba_msgs_mot_cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace scriba_msgs
{

  class mot_cmd : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _angle_type;
      _angle_type angle;
      typedef float _tractionSpeed_type;
      _tractionSpeed_type tractionSpeed;

    mot_cmd():
      header(),
      angle(0),
      tractionSpeed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->tractionSpeed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tractionSpeed));
     return offset;
    }

    virtual const char * getType() override { return "scriba_msgs/mot_cmd"; };
    virtual const char * getMD5() override { return "83fb2e7aa7b1bff70e028fe6d289e91a"; };

  };

}
#endif
