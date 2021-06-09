#ifndef _ROS_SERVICE_AddGroupFromNamesSrv_h
#define _ROS_SERVICE_AddGroupFromNamesSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

static const char ADDGROUPFROMNAMESSRV[] = "hebiros/AddGroupFromNamesSrv";

  class AddGroupFromNamesSrvRequest : public ros::Msg
  {
    public:
      typedef const char* _group_name_type;
      _group_name_type group_name;
      uint32_t names_length;
      typedef char* _names_type;
      _names_type st_names;
      _names_type * names;
      uint32_t families_length;
      typedef char* _families_type;
      _families_type st_families;
      _families_type * families;

    AddGroupFromNamesSrvRequest():
      group_name(""),
      names_length(0), names(NULL),
      families_length(0), families(NULL)
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
      *(outbuffer + offset + 0) = (this->names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->names_length);
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_namesi = strlen(this->names[i]);
      varToArr(outbuffer + offset, length_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_namesi);
      offset += length_namesi;
      }
      *(outbuffer + offset + 0) = (this->families_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->families_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->families_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->families_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->families_length);
      for( uint32_t i = 0; i < families_length; i++){
      uint32_t length_familiesi = strlen(this->families[i]);
      varToArr(outbuffer + offset, length_familiesi);
      offset += 4;
      memcpy(outbuffer + offset, this->families[i], length_familiesi);
      offset += length_familiesi;
      }
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
      uint32_t names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->names_length);
      if(names_lengthT > names_length)
        this->names = (char**)realloc(this->names, names_lengthT * sizeof(char*));
      names_length = names_lengthT;
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_st_names;
      arrToVar(length_st_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_names-1]=0;
      this->st_names = (char *)(inbuffer + offset-1);
      offset += length_st_names;
        memcpy( &(this->names[i]), &(this->st_names), sizeof(char*));
      }
      uint32_t families_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      families_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      families_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      families_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->families_length);
      if(families_lengthT > families_length)
        this->families = (char**)realloc(this->families, families_lengthT * sizeof(char*));
      families_length = families_lengthT;
      for( uint32_t i = 0; i < families_length; i++){
      uint32_t length_st_families;
      arrToVar(length_st_families, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_families; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_families-1]=0;
      this->st_families = (char *)(inbuffer + offset-1);
      offset += length_st_families;
        memcpy( &(this->families[i]), &(this->st_families), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return ADDGROUPFROMNAMESSRV; };
    const char * getMD5(){ return "a31d701a4ec2a831130fc40890ab943d"; };

  };

  class AddGroupFromNamesSrvResponse : public ros::Msg
  {
    public:

    AddGroupFromNamesSrvResponse()
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

    const char * getType(){ return ADDGROUPFROMNAMESSRV; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class AddGroupFromNamesSrv {
    public:
    typedef AddGroupFromNamesSrvRequest Request;
    typedef AddGroupFromNamesSrvResponse Response;
  };

}
#endif
