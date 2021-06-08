#ifndef _ROS_ltl3_pose_h
#define _ROS_ltl3_pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltl3
{

  class pose : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _psi_type;
      _psi_type psi;

    pose():
      x(0),
      y(0),
      psi(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->psi);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->psi));
     return offset;
    }

    virtual const char * getType() override { return "ltl3/pose"; };
    virtual const char * getMD5() override { return "ab0fcbcba728d875f75d94c9f07819ee"; };

  };

}
#endif
