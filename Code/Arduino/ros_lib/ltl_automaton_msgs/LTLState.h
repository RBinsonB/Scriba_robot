#ifndef _ROS_ltl_automaton_msgs_LTLState_h
#define _ROS_ltl_automaton_msgs_LTLState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ltl_automaton_msgs/TransitionSystemState.h"

namespace ltl_automaton_msgs
{

  class LTLState : public ros::Msg
  {
    public:
      typedef ltl_automaton_msgs::TransitionSystemState _ts_state_type;
      _ts_state_type ts_state;
      typedef const char* _buchi_state_type;
      _buchi_state_type buchi_state;

    LTLState():
      ts_state(),
      buchi_state("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->ts_state.serialize(outbuffer + offset);
      uint32_t length_buchi_state = strlen(this->buchi_state);
      varToArr(outbuffer + offset, length_buchi_state);
      offset += 4;
      memcpy(outbuffer + offset, this->buchi_state, length_buchi_state);
      offset += length_buchi_state;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->ts_state.deserialize(inbuffer + offset);
      uint32_t length_buchi_state;
      arrToVar(length_buchi_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_buchi_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_buchi_state-1]=0;
      this->buchi_state = (char *)(inbuffer + offset-1);
      offset += length_buchi_state;
     return offset;
    }

    virtual const char * getType() override { return "ltl_automaton_msgs/LTLState"; };
    virtual const char * getMD5() override { return "fe76b659fb53a1215105d9e18915eb3c"; };

  };

}
#endif
