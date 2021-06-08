#ifndef _ROS_ltl_automaton_msgs_TransitionSystemState_h
#define _ROS_ltl_automaton_msgs_TransitionSystemState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltl_automaton_msgs
{

  class TransitionSystemState : public ros::Msg
  {
    public:
      uint32_t states_length;
      typedef char* _states_type;
      _states_type st_states;
      _states_type * states;
      uint32_t state_dimension_names_length;
      typedef char* _state_dimension_names_type;
      _state_dimension_names_type st_state_dimension_names;
      _state_dimension_names_type * state_dimension_names;

    TransitionSystemState():
      states_length(0), st_states(), states(nullptr),
      state_dimension_names_length(0), st_state_dimension_names(), state_dimension_names(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      uint32_t length_statesi = strlen(this->states[i]);
      varToArr(outbuffer + offset, length_statesi);
      offset += 4;
      memcpy(outbuffer + offset, this->states[i], length_statesi);
      offset += length_statesi;
      }
      *(outbuffer + offset + 0) = (this->state_dimension_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state_dimension_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state_dimension_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state_dimension_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_dimension_names_length);
      for( uint32_t i = 0; i < state_dimension_names_length; i++){
      uint32_t length_state_dimension_namesi = strlen(this->state_dimension_names[i]);
      varToArr(outbuffer + offset, length_state_dimension_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->state_dimension_names[i], length_state_dimension_namesi);
      offset += length_state_dimension_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (char**)realloc(this->states, states_lengthT * sizeof(char*));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      uint32_t length_st_states;
      arrToVar(length_st_states, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_states; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_states-1]=0;
      this->st_states = (char *)(inbuffer + offset-1);
      offset += length_st_states;
        memcpy( &(this->states[i]), &(this->st_states), sizeof(char*));
      }
      uint32_t state_dimension_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      state_dimension_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      state_dimension_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      state_dimension_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->state_dimension_names_length);
      if(state_dimension_names_lengthT > state_dimension_names_length)
        this->state_dimension_names = (char**)realloc(this->state_dimension_names, state_dimension_names_lengthT * sizeof(char*));
      state_dimension_names_length = state_dimension_names_lengthT;
      for( uint32_t i = 0; i < state_dimension_names_length; i++){
      uint32_t length_st_state_dimension_names;
      arrToVar(length_st_state_dimension_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_state_dimension_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_state_dimension_names-1]=0;
      this->st_state_dimension_names = (char *)(inbuffer + offset-1);
      offset += length_st_state_dimension_names;
        memcpy( &(this->state_dimension_names[i]), &(this->st_state_dimension_names), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "ltl_automaton_msgs/TransitionSystemState"; };
    virtual const char * getMD5() override { return "dd3e4c545328096144494d2c86ca4058"; };

  };

}
#endif
