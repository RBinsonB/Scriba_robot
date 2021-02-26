#ifndef _ROS_SERVICE_AddGroupFromURDFSrv_h
#define _ROS_SERVICE_AddGroupFromURDFSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

static const char ADDGROUPFROMURDFSRV[] = "hebiros/AddGroupFromURDFSrv";

  class AddGroupFromURDFSrvRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;

    AddGroupFromURDFSrvRequest():
      group_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
     return offset;
    }

    const char * getType(){ return ADDGROUPFROMURDFSRV; };
    const char * getMD5(){ return "967d0b0c0d858ded8a6a69abbce0c981"; };

  };

  class AddGroupFromURDFSrvResponse : public ros::Msg
  {
    public:

    AddGroupFromURDFSrvResponse()
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

    const char * getType(){ return ADDGROUPFROMURDFSRV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddGroupFromURDFSrv {
    public:
    typedef AddGroupFromURDFSrvRequest Request;
    typedef AddGroupFromURDFSrvResponse Response;
  };

}
#endif
