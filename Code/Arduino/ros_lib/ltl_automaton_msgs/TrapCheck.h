#ifndef _ROS_SERVICE_TrapCheck_h
#define _ROS_SERVICE_TrapCheck_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ltl_automaton_msgs/TransitionSystemState.h"

namespace ltl_automaton_msgs
{

static const char TRAPCHECK[] = "ltl_automaton_msgs/TrapCheck";

  class TrapCheckRequest : public ros::Msg
  {
    public:
      typedef ltl_automaton_msgs::TransitionSystemState _ts_state_type;
      _ts_state_type ts_state;

    TrapCheckRequest():
      ts_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->ts_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->ts_state.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return TRAPCHECK; };
    virtual const char * getMD5() override { return "181f0b665f7687d714857e4b16173cec"; };

  };

  class TrapCheckResponse : public ros::Msg
  {
    public:
      typedef bool _is_connected_type;
      _is_connected_type is_connected;
      typedef bool _is_trap_type;
      _is_trap_type is_trap;

    TrapCheckResponse():
      is_connected(0),
      is_trap(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_connected;
      u_is_connected.real = this->is_connected;
      *(outbuffer + offset + 0) = (u_is_connected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_connected);
      union {
        bool real;
        uint8_t base;
      } u_is_trap;
      u_is_trap.real = this->is_trap;
      *(outbuffer + offset + 0) = (u_is_trap.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_trap);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_connected;
      u_is_connected.base = 0;
      u_is_connected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_connected = u_is_connected.real;
      offset += sizeof(this->is_connected);
      union {
        bool real;
        uint8_t base;
      } u_is_trap;
      u_is_trap.base = 0;
      u_is_trap.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_trap = u_is_trap.real;
      offset += sizeof(this->is_trap);
     return offset;
    }

    virtual const char * getType() override { return TRAPCHECK; };
    virtual const char * getMD5() override { return "605cdf51f520f8f96e4e330d9afccf91"; };

  };

  class TrapCheck {
    public:
    typedef TrapCheckRequest Request;
    typedef TrapCheckResponse Response;
  };

}
#endif
