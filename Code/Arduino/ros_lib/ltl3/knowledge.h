#ifndef _ROS_ltl3_knowledge_h
#define _ROS_ltl3_knowledge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltl3
{

  class knowledge : public ros::Msg
  {
    public:
      typedef const char* _object_type;
      _object_type object;
      typedef const char* _region_type;
      _region_type region;

    knowledge():
      object(""),
      region("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_object = strlen(this->object);
      varToArr(outbuffer + offset, length_object);
      offset += 4;
      memcpy(outbuffer + offset, this->object, length_object);
      offset += length_object;
      uint32_t length_region = strlen(this->region);
      varToArr(outbuffer + offset, length_region);
      offset += 4;
      memcpy(outbuffer + offset, this->region, length_region);
      offset += length_region;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_object;
      arrToVar(length_object, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_object; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_object-1]=0;
      this->object = (char *)(inbuffer + offset-1);
      offset += length_object;
      uint32_t length_region;
      arrToVar(length_region, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_region; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_region-1]=0;
      this->region = (char *)(inbuffer + offset-1);
      offset += length_region;
     return offset;
    }

    virtual const char * getType() override { return "ltl3/knowledge"; };
    virtual const char * getMD5() override { return "681b3f0d852da87b4e6900153cbe9c26"; };

  };

}
#endif
