#ifndef _ROS_SERVICE_SetCommandLifetimeSrv_h
#define _ROS_SERVICE_SetCommandLifetimeSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

static const char SETCOMMANDLIFETIMESRV[] = "hebiros/SetCommandLifetimeSrv";

  class SetCommandLifetimeSrvRequest : public ros::Msg
  {
    public:
      typedef int32_t _command_lifetime_type;
      _command_lifetime_type command_lifetime;

    SetCommandLifetimeSrvRequest():
      command_lifetime(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command_lifetime;
      u_command_lifetime.real = this->command_lifetime;
      *(outbuffer + offset + 0) = (u_command_lifetime.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_command_lifetime.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_command_lifetime.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_command_lifetime.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->command_lifetime);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_command_lifetime;
      u_command_lifetime.base = 0;
      u_command_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_command_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_command_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_command_lifetime.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->command_lifetime = u_command_lifetime.real;
      offset += sizeof(this->command_lifetime);
     return offset;
    }

    virtual const char * getType() override { return SETCOMMANDLIFETIMESRV; };
    virtual const char * getMD5() override { return "9e6d0becb75f24a1f3c269f4469e5d38"; };

  };

  class SetCommandLifetimeSrvResponse : public ros::Msg
  {
    public:

    SetCommandLifetimeSrvResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return SETCOMMANDLIFETIMESRV; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetCommandLifetimeSrv {
    public:
    typedef SetCommandLifetimeSrvRequest Request;
    typedef SetCommandLifetimeSrvResponse Response;
  };

}
#endif
