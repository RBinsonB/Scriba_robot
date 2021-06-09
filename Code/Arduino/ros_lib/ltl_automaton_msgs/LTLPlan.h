#ifndef _ROS_ltl_automaton_msgs_LTLPlan_h
#define _ROS_ltl_automaton_msgs_LTLPlan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ltl_automaton_msgs/TransitionSystemState.h"

namespace ltl_automaton_msgs
{

  class LTLPlan : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t action_sequence_length;
      typedef char* _action_sequence_type;
      _action_sequence_type st_action_sequence;
      _action_sequence_type * action_sequence;
      uint32_t ts_state_sequence_length;
      typedef ltl_automaton_msgs::TransitionSystemState _ts_state_sequence_type;
      _ts_state_sequence_type st_ts_state_sequence;
      _ts_state_sequence_type * ts_state_sequence;

    LTLPlan():
      header(),
      action_sequence_length(0), st_action_sequence(), action_sequence(nullptr),
      ts_state_sequence_length(0), st_ts_state_sequence(), ts_state_sequence(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->action_sequence_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->action_sequence_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->action_sequence_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->action_sequence_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action_sequence_length);
      for( uint32_t i = 0; i < action_sequence_length; i++){
      uint32_t length_action_sequencei = strlen(this->action_sequence[i]);
      varToArr(outbuffer + offset, length_action_sequencei);
      offset += 4;
      memcpy(outbuffer + offset, this->action_sequence[i], length_action_sequencei);
      offset += length_action_sequencei;
      }
      *(outbuffer + offset + 0) = (this->ts_state_sequence_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ts_state_sequence_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ts_state_sequence_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ts_state_sequence_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ts_state_sequence_length);
      for( uint32_t i = 0; i < ts_state_sequence_length; i++){
      offset += this->ts_state_sequence[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t action_sequence_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      action_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      action_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      action_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->action_sequence_length);
      if(action_sequence_lengthT > action_sequence_length)
        this->action_sequence = (char**)realloc(this->action_sequence, action_sequence_lengthT * sizeof(char*));
      action_sequence_length = action_sequence_lengthT;
      for( uint32_t i = 0; i < action_sequence_length; i++){
      uint32_t length_st_action_sequence;
      arrToVar(length_st_action_sequence, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_action_sequence; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_action_sequence-1]=0;
      this->st_action_sequence = (char *)(inbuffer + offset-1);
      offset += length_st_action_sequence;
        memcpy( &(this->action_sequence[i]), &(this->st_action_sequence), sizeof(char*));
      }
      uint32_t ts_state_sequence_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ts_state_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ts_state_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ts_state_sequence_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ts_state_sequence_length);
      if(ts_state_sequence_lengthT > ts_state_sequence_length)
        this->ts_state_sequence = (ltl_automaton_msgs::TransitionSystemState*)realloc(this->ts_state_sequence, ts_state_sequence_lengthT * sizeof(ltl_automaton_msgs::TransitionSystemState));
      ts_state_sequence_length = ts_state_sequence_lengthT;
      for( uint32_t i = 0; i < ts_state_sequence_length; i++){
      offset += this->st_ts_state_sequence.deserialize(inbuffer + offset);
        memcpy( &(this->ts_state_sequence[i]), &(this->st_ts_state_sequence), sizeof(ltl_automaton_msgs::TransitionSystemState));
      }
     return offset;
    }

    virtual const char * getType() override { return "ltl_automaton_msgs/LTLPlan"; };
    virtual const char * getMD5() override { return "adae4bc6c721b5855606e4cea3d53447"; };

  };

}
#endif
