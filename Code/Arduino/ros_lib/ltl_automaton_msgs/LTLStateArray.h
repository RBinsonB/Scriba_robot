#ifndef _ROS_ltl_automaton_msgs_LTLStateArray_h
#define _ROS_ltl_automaton_msgs_LTLStateArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ltl_automaton_msgs/LTLState.h"

namespace ltl_automaton_msgs
{

  class LTLStateArray : public ros::Msg
  {
    public:
      uint32_t ltl_states_length;
      typedef ltl_automaton_msgs::LTLState _ltl_states_type;
      _ltl_states_type st_ltl_states;
      _ltl_states_type * ltl_states;

    LTLStateArray():
      ltl_states_length(0), st_ltl_states(), ltl_states(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->ltl_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ltl_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ltl_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ltl_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ltl_states_length);
      for( uint32_t i = 0; i < ltl_states_length; i++){
      offset += this->ltl_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t ltl_states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ltl_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ltl_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ltl_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ltl_states_length);
      if(ltl_states_lengthT > ltl_states_length)
        this->ltl_states = (ltl_automaton_msgs::LTLState*)realloc(this->ltl_states, ltl_states_lengthT * sizeof(ltl_automaton_msgs::LTLState));
      ltl_states_length = ltl_states_lengthT;
      for( uint32_t i = 0; i < ltl_states_length; i++){
      offset += this->st_ltl_states.deserialize(inbuffer + offset);
        memcpy( &(this->ltl_states[i]), &(this->st_ltl_states), sizeof(ltl_automaton_msgs::LTLState));
      }
     return offset;
    }

    virtual const char * getType() override { return "ltl_automaton_msgs/LTLStateArray"; };
    virtual const char * getMD5() override { return "64b88dffe0e11b827686475cd403f633"; };

  };

}
#endif
