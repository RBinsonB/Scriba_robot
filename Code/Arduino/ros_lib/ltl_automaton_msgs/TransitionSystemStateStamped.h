#ifndef _ROS_ltl_automaton_msgs_TransitionSystemStateStamped_h
#define _ROS_ltl_automaton_msgs_TransitionSystemStateStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ltl_automaton_msgs/TransitionSystemState.h"

namespace ltl_automaton_msgs
{

  class TransitionSystemStateStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef ltl_automaton_msgs::TransitionSystemState _ts_state_type;
      _ts_state_type ts_state;

    TransitionSystemStateStamped():
      header(),
      ts_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->ts_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->ts_state.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "ltl_automaton_msgs/TransitionSystemStateStamped"; };
    virtual const char * getMD5() override { return "a36ddd35c022bbaae30e7c1cfbc2f386"; };

  };

}
#endif
