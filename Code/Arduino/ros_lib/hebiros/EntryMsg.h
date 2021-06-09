#ifndef _ROS_hebiros_EntryMsg_h
#define _ROS_hebiros_EntryMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

  class EntryMsg : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _family_type;
      _family_type family;
      typedef int64_t _mac_address_type;
      _mac_address_type mac_address;

    EntryMsg():
      name(""),
      family(""),
      mac_address(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_family = strlen(this->family);
      varToArr(outbuffer + offset, length_family);
      offset += 4;
      memcpy(outbuffer + offset, this->family, length_family);
      offset += length_family;
      union {
        int64_t real;
        uint64_t base;
      } u_mac_address;
      u_mac_address.real = this->mac_address;
      *(outbuffer + offset + 0) = (u_mac_address.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mac_address.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mac_address.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mac_address.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mac_address.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mac_address.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mac_address.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mac_address.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mac_address);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_family;
      arrToVar(length_family, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_family; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_family-1]=0;
      this->family = (char *)(inbuffer + offset-1);
      offset += length_family;
      union {
        int64_t real;
        uint64_t base;
      } u_mac_address;
      u_mac_address.base = 0;
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mac_address.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mac_address = u_mac_address.real;
      offset += sizeof(this->mac_address);
     return offset;
    }

    virtual const char * getType() override { return "hebiros/EntryMsg"; };
    virtual const char * getMD5() override { return "0ef1a1bc0bda92a32c695657f945626a"; };

  };

}
#endif
