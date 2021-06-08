#ifndef _ROS_SERVICE_EntryListSrv_h
#define _ROS_SERVICE_EntryListSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hebiros/EntryListMsg.h"

namespace hebiros
{

static const char ENTRYLISTSRV[] = "hebiros/EntryListSrv";

  class EntryListSrvRequest : public ros::Msg
  {
    public:

    EntryListSrvRequest()
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

    virtual const char * getType() override { return ENTRYLISTSRV; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class EntryListSrvResponse : public ros::Msg
  {
    public:
      typedef hebiros::EntryListMsg _entry_list_type;
      _entry_list_type entry_list;

    EntryListSrvResponse():
      entry_list()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->entry_list.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->entry_list.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ENTRYLISTSRV; };
    virtual const char * getMD5() override { return "019fcca877608da550bd2d6857203482"; };

  };

  class EntryListSrv {
    public:
    typedef EntryListSrvRequest Request;
    typedef EntryListSrvResponse Response;
  };

}
#endif
