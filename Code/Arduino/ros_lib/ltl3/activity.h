#ifndef _ROS_ltl3_activity_h
#define _ROS_ltl3_activity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltl3
{

  class activity : public ros::Msg
  {
    public:
      typedef int64_t _header_type;
      _header_type header;
      typedef const char* _type_type;
      _type_type type;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _psi_type;
      _psi_type psi;

    activity():
      header(0),
      type(""),
      x(0),
      y(0),
      psi(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_header;
      u_header.real = this->header;
      *(outbuffer + offset + 0) = (u_header.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_header.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_header.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_header.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_header.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_header.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_header.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_header.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->header);
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->psi);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_header;
      u_header.base = 0;
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_header.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->header = u_header.real;
      offset += sizeof(this->header);
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->psi));
     return offset;
    }

    virtual const char * getType() override { return "ltl3/activity"; };
    virtual const char * getMD5() override { return "04ae85828ad85e50ecef4b644363d806"; };

  };

}
#endif
