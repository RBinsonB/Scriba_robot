#ifndef _ROS_SERVICE_AddTwoInts_h
#define _ROS_SERVICE_AddTwoInts_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace scriba_msgs
{

static const char ADDTWOINTS[] = "scriba_msgs/AddTwoInts";

  class AddTwoIntsRequest : public ros::Msg
  {
    public:
      typedef int64_t _A_type;
      _A_type A;
      typedef int64_t _B_type;
      _B_type B;

    AddTwoIntsRequest():
      A(0),
      B(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_A;
      u_A.real = this->A;
      *(outbuffer + offset + 0) = (u_A.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_A.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_A.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_A.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_A.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_A.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_A.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_A.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->A);
      union {
        int64_t real;
        uint64_t base;
      } u_B;
      u_B.real = this->B;
      *(outbuffer + offset + 0) = (u_B.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_B.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_B.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_B.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_B.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_B.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_B.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_B.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->B);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_A;
      u_A.base = 0;
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->A = u_A.real;
      offset += sizeof(this->A);
      union {
        int64_t real;
        uint64_t base;
      } u_B;
      u_B.base = 0;
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->B = u_B.real;
      offset += sizeof(this->B);
     return offset;
    }

    const char * getType(){ return ADDTWOINTS; };
    const char * getMD5(){ return "02f05bb5bde9ff0aeeed7cca0d2e13fc"; };

  };

  class AddTwoIntsResponse : public ros::Msg
  {
    public:
      typedef int64_t _Sum_type;
      _Sum_type Sum;

    AddTwoIntsResponse():
      Sum(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_Sum;
      u_Sum.real = this->Sum;
      *(outbuffer + offset + 0) = (u_Sum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Sum.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Sum.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Sum.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_Sum.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_Sum.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_Sum.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_Sum.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->Sum);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_Sum;
      u_Sum.base = 0;
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_Sum.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->Sum = u_Sum.real;
      offset += sizeof(this->Sum);
     return offset;
    }

    const char * getType(){ return ADDTWOINTS; };
    const char * getMD5(){ return "055d509888d173367b1b9f94491341fd"; };

  };

  class AddTwoInts {
    public:
    typedef AddTwoIntsRequest Request;
    typedef AddTwoIntsResponse Response;
  };

}
#endif
