#ifndef _ROS_SERVICE_AddModelFromURDFSrv_h
#define _ROS_SERVICE_AddModelFromURDFSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

static const char ADDMODELFROMURDFSRV[] = "hebiros/AddModelFromURDFSrv";

  class AddModelFromURDFSrvRequest : public ros::Msg
  {
    public:
      typedef const char* _model_name_type;
      _model_name_type model_name;
      typedef const char* _description_param_type;
      _description_param_type description_param;

    AddModelFromURDFSrvRequest():
      model_name(""),
      description_param("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_name = strlen(this->model_name);
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_model_name);
      offset += length_model_name;
      uint32_t length_description_param = strlen(this->description_param);
      varToArr(outbuffer + offset, length_description_param);
      offset += 4;
      memcpy(outbuffer + offset, this->description_param, length_description_param);
      offset += length_description_param;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      uint32_t length_description_param;
      arrToVar(length_description_param, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description_param; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description_param-1]=0;
      this->description_param = (char *)(inbuffer + offset-1);
      offset += length_description_param;
     return offset;
    }

    const char * getType(){ return ADDMODELFROMURDFSRV; };
    const char * getMD5(){ return "7503667ca5355c5a12e4de26d45dcf94"; };

  };

  class AddModelFromURDFSrvResponse : public ros::Msg
  {
    public:

    AddModelFromURDFSrvResponse()
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

    const char * getType(){ return ADDMODELFROMURDFSRV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddModelFromURDFSrv {
    public:
    typedef AddModelFromURDFSrvRequest Request;
    typedef AddModelFromURDFSrvResponse Response;
  };

}
#endif
