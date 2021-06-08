#ifndef _ROS_ltl3_confirmation_h
#define _ROS_ltl3_confirmation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltl3
{

  class confirmation : public ros::Msg
  {
    public:
      typedef int64_t _confheader_type;
      _confheader_type confheader;
      typedef const char* _name_type;
      _name_type name;
      typedef int8_t _done_type;
      _done_type done;

    confirmation():
      confheader(0),
      name(""),
      done(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_confheader;
      u_confheader.real = this->confheader;
      *(outbuffer + offset + 0) = (u_confheader.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confheader.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confheader.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confheader.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_confheader.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_confheader.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_confheader.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_confheader.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->confheader);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        int8_t real;
        uint8_t base;
      } u_done;
      u_done.real = this->done;
      *(outbuffer + offset + 0) = (u_done.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->done);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_confheader;
      u_confheader.base = 0;
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_confheader.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->confheader = u_confheader.real;
      offset += sizeof(this->confheader);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        int8_t real;
        uint8_t base;
      } u_done;
      u_done.base = 0;
      u_done.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done = u_done.real;
      offset += sizeof(this->done);
     return offset;
    }

    virtual const char * getType() override { return "ltl3/confirmation"; };
    virtual const char * getMD5() override { return "b0c00349f1ad673c875e47dda36ad063"; };

  };

}
#endif
