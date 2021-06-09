#ifndef _ROS_hebiros_EntryListMsg_h
#define _ROS_hebiros_EntryListMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hebiros/EntryMsg.h"

namespace hebiros
{

  class EntryListMsg : public ros::Msg
  {
    public:
      typedef int32_t _size_type;
      _size_type size;
      uint32_t entries_length;
      typedef hebiros::EntryMsg _entries_type;
      _entries_type st_entries;
      _entries_type * entries;

    EntryListMsg():
      size(0),
      entries_length(0), st_entries(), entries(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.real = this->size;
      *(outbuffer + offset + 0) = (u_size.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size);
      *(outbuffer + offset + 0) = (this->entries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entries_length);
      for( uint32_t i = 0; i < entries_length; i++){
      offset += this->entries[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_size;
      u_size.base = 0;
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->size = u_size.real;
      offset += sizeof(this->size);
      uint32_t entries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entries_length);
      if(entries_lengthT > entries_length)
        this->entries = (hebiros::EntryMsg*)realloc(this->entries, entries_lengthT * sizeof(hebiros::EntryMsg));
      entries_length = entries_lengthT;
      for( uint32_t i = 0; i < entries_length; i++){
      offset += this->st_entries.deserialize(inbuffer + offset);
        memcpy( &(this->entries[i]), &(this->st_entries), sizeof(hebiros::EntryMsg));
      }
     return offset;
    }

    virtual const char * getType() override { return "hebiros/EntryListMsg"; };
    virtual const char * getMD5() override { return "ce4dffca09542f7d73eaedf72b9274c0"; };

  };

}
#endif
