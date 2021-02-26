#ifndef _ROS_SERVICE_SendCommandWithAcknowledgementSrv_h
#define _ROS_SERVICE_SendCommandWithAcknowledgementSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hebiros/CommandMsg.h"

namespace hebiros
{

static const char SENDCOMMANDWITHACKNOWLEDGEMENTSRV[] = "hebiros/SendCommandWithAcknowledgementSrv";

  class SendCommandWithAcknowledgementSrvRequest : public ros::Msg
  {
    public:
      typedef hebiros::CommandMsg _command_type;
      _command_type command;

    SendCommandWithAcknowledgementSrvRequest():
      command()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->command.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->command.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SENDCOMMANDWITHACKNOWLEDGEMENTSRV; };
    const char * getMD5(){ return "dc4cfbf8596ddaff00c6c17ca78326b7"; };

  };

  class SendCommandWithAcknowledgementSrvResponse : public ros::Msg
  {
    public:

    SendCommandWithAcknowledgementSrvResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SENDCOMMANDWITHACKNOWLEDGEMENTSRV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SendCommandWithAcknowledgementSrv {
    public:
    typedef SendCommandWithAcknowledgementSrvRequest Request;
    typedef SendCommandWithAcknowledgementSrvResponse Response;
  };

}
#endif
