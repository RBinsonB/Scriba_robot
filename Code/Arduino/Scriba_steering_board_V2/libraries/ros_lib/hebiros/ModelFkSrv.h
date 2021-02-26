#ifndef _ROS_SERVICE_ModelFkSrv_h
#define _ROS_SERVICE_ModelFkSrv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

static const char MODELFKSRV[] = "hebiros/ModelFkSrv";

  class ModelFkSrvRequest : public ros::Msg
  {
    public:
      uint32_t positions_length;
      typedef float _positions_type;
      _positions_type st_positions;
      _positions_type * positions;
      typedef int32_t _frame_type_type;
      _frame_type_type frame_type;
      enum { FrameTypeCenterOfMass =  0 };
      enum { FrameTypeOutput =  1 };

    ModelFkSrvRequest():
      positions_length(0), positions(NULL),
      frame_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->positions[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_frame_type;
      u_frame_type.real = this->frame_type;
      *(outbuffer + offset + 0) = (u_frame_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frame_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frame_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frame_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frame_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_positions));
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_frame_type;
      u_frame_type.base = 0;
      u_frame_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frame_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frame_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frame_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frame_type = u_frame_type.real;
      offset += sizeof(this->frame_type);
     return offset;
    }

    const char * getType(){ return MODELFKSRV; };
    const char * getMD5(){ return "dd146385f1eb1d3268bc4b0516bec43a"; };

  };

  class ModelFkSrvResponse : public ros::Msg
  {
    public:
      uint32_t frames_length;
      typedef float _frames_type;
      _frames_type st_frames;
      _frames_type * frames;

    ModelFkSrvResponse():
      frames_length(0), frames(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->frames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frames_length);
      for( uint32_t i = 0; i < frames_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->frames[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t frames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      frames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      frames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      frames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->frames_length);
      if(frames_lengthT > frames_length)
        this->frames = (float*)realloc(this->frames, frames_lengthT * sizeof(float));
      frames_length = frames_lengthT;
      for( uint32_t i = 0; i < frames_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_frames));
        memcpy( &(this->frames[i]), &(this->st_frames), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return MODELFKSRV; };
    const char * getMD5(){ return "c2dbcb8d5fc4b1d0fa7d1af4a1a7dc9b"; };

  };

  class ModelFkSrv {
    public:
    typedef ModelFkSrvRequest Request;
    typedef ModelFkSrvResponse Response;
  };

}
#endif
