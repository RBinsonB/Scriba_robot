#ifndef _ROS_ltl_automaton_msgs_LTLStateRuns_h
#define _ROS_ltl_automaton_msgs_LTLStateRuns_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ltl_automaton_msgs/LTLStateArray.h"

namespace ltl_automaton_msgs
{

  class LTLStateRuns : public ros::Msg
  {
    public:
      uint32_t runs_length;
      typedef ltl_automaton_msgs::LTLStateArray _runs_type;
      _runs_type st_runs;
      _runs_type * runs;

    LTLStateRuns():
      runs_length(0), st_runs(), runs(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->runs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->runs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->runs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->runs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->runs_length);
      for( uint32_t i = 0; i < runs_length; i++){
      offset += this->runs[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t runs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      runs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      runs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      runs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->runs_length);
      if(runs_lengthT > runs_length)
        this->runs = (ltl_automaton_msgs::LTLStateArray*)realloc(this->runs, runs_lengthT * sizeof(ltl_automaton_msgs::LTLStateArray));
      runs_length = runs_lengthT;
      for( uint32_t i = 0; i < runs_length; i++){
      offset += this->st_runs.deserialize(inbuffer + offset);
        memcpy( &(this->runs[i]), &(this->st_runs), sizeof(ltl_automaton_msgs::LTLStateArray));
      }
     return offset;
    }

    virtual const char * getType() override { return "ltl_automaton_msgs/LTLStateRuns"; };
    virtual const char * getMD5() override { return "c82bbf2ada000830aab380b4b879217f"; };

  };

}
#endif
