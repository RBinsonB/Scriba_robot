#ifndef _ROS_SERVICE_ClosestState_h
#define _ROS_SERVICE_ClosestState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltl_automaton_msgs
{

static const char CLOSESTSTATE[] = "ltl_automaton_msgs/ClosestState";

  class ClosestStateRequest : public ros::Msg
  {
    public:
      typedef const char* _action_input_type;
      _action_input_type action_input;

    ClosestStateRequest():
      action_input("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_action_input = strlen(this->action_input);
      varToArr(outbuffer + offset, length_action_input);
      offset += 4;
      memcpy(outbuffer + offset, this->action_input, length_action_input);
      offset += length_action_input;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_action_input;
      arrToVar(length_action_input, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_action_input; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_action_input-1]=0;
      this->action_input = (char *)(inbuffer + offset-1);
      offset += length_action_input;
     return offset;
    }

    virtual const char * getType() override { return CLOSESTSTATE; };
    virtual const char * getMD5() override { return "986e9eb8d2d73f546f5ff2d18ac5064f"; };

  };

  class ClosestStateResponse : public ros::Msg
  {
    public:
      typedef const char* _closest_state_type;
      _closest_state_type closest_state;
      typedef float _metric_type;
      _metric_type metric;

    ClosestStateResponse():
      closest_state(""),
      metric(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_closest_state = strlen(this->closest_state);
      varToArr(outbuffer + offset, length_closest_state);
      offset += 4;
      memcpy(outbuffer + offset, this->closest_state, length_closest_state);
      offset += length_closest_state;
      offset += serializeAvrFloat64(outbuffer + offset, this->metric);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_closest_state;
      arrToVar(length_closest_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_closest_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_closest_state-1]=0;
      this->closest_state = (char *)(inbuffer + offset-1);
      offset += length_closest_state;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->metric));
     return offset;
    }

    virtual const char * getType() override { return CLOSESTSTATE; };
    virtual const char * getMD5() override { return "38402db1494b5e88e10d23f596fc1591"; };

  };

  class ClosestState {
    public:
    typedef ClosestStateRequest Request;
    typedef ClosestStateResponse Response;
  };

}
#endif
