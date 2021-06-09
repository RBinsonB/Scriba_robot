#ifndef _ROS_SERVICE_SetFeedbackFrequencySrv_h
#define _ROS_SERVICE_SetFeedbackFrequencySrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

static const char SETFEEDBACKFREQUENCYSRV[] = "hebiros/SetFeedbackFrequencySrv";

  class SetFeedbackFrequencySrvRequest : public ros::Msg
  {
    public:
      typedef int32_t _feedback_frequency_type;
      _feedback_frequency_type feedback_frequency;

    SetFeedbackFrequencySrvRequest():
      feedback_frequency(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_feedback_frequency;
      u_feedback_frequency.real = this->feedback_frequency;
      *(outbuffer + offset + 0) = (u_feedback_frequency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_feedback_frequency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_feedback_frequency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_feedback_frequency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->feedback_frequency);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_feedback_frequency;
      u_feedback_frequency.base = 0;
      u_feedback_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_feedback_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_feedback_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_feedback_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->feedback_frequency = u_feedback_frequency.real;
      offset += sizeof(this->feedback_frequency);
     return offset;
    }

    virtual const char * getType() override { return SETFEEDBACKFREQUENCYSRV; };
    virtual const char * getMD5() override { return "89e470a7bc482c7199fa75ef40009369"; };

  };

  class SetFeedbackFrequencySrvResponse : public ros::Msg
  {
    public:

    SetFeedbackFrequencySrvResponse()
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

    virtual const char * getType() override { return SETFEEDBACKFREQUENCYSRV; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetFeedbackFrequencySrv {
    public:
    typedef SetFeedbackFrequencySrvRequest Request;
    typedef SetFeedbackFrequencySrvResponse Response;
  };

}
#endif
