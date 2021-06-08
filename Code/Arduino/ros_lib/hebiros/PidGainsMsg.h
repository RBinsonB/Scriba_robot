#ifndef _ROS_hebiros_PidGainsMsg_h
#define _ROS_hebiros_PidGainsMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hebiros
{

  class PidGainsMsg : public ros::Msg
  {
    public:
      uint32_t name_length;
      typedef char* _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t kp_length;
      typedef float _kp_type;
      _kp_type st_kp;
      _kp_type * kp;
      uint32_t ki_length;
      typedef float _ki_type;
      _ki_type st_ki;
      _ki_type * ki;
      uint32_t kd_length;
      typedef float _kd_type;
      _kd_type st_kd;
      _kd_type * kd;
      uint32_t feed_forward_length;
      typedef float _feed_forward_type;
      _feed_forward_type st_feed_forward;
      _feed_forward_type * feed_forward;
      uint32_t dead_zone_length;
      typedef float _dead_zone_type;
      _dead_zone_type st_dead_zone;
      _dead_zone_type * dead_zone;
      uint32_t i_clamp_length;
      typedef float _i_clamp_type;
      _i_clamp_type st_i_clamp;
      _i_clamp_type * i_clamp;
      uint32_t punch_length;
      typedef float _punch_type;
      _punch_type st_punch;
      _punch_type * punch;
      uint32_t min_target_length;
      typedef float _min_target_type;
      _min_target_type st_min_target;
      _min_target_type * min_target;
      uint32_t max_target_length;
      typedef float _max_target_type;
      _max_target_type st_max_target;
      _max_target_type * max_target;
      uint32_t target_lowpass_length;
      typedef float _target_lowpass_type;
      _target_lowpass_type st_target_lowpass;
      _target_lowpass_type * target_lowpass;
      uint32_t min_output_length;
      typedef float _min_output_type;
      _min_output_type st_min_output;
      _min_output_type * min_output;
      uint32_t max_output_length;
      typedef float _max_output_type;
      _max_output_type st_max_output;
      _max_output_type * max_output;
      uint32_t output_lowpass_length;
      typedef float _output_lowpass_type;
      _output_lowpass_type st_output_lowpass;
      _output_lowpass_type * output_lowpass;
      uint32_t d_on_error_length;
      typedef bool _d_on_error_type;
      _d_on_error_type st_d_on_error;
      _d_on_error_type * d_on_error;

    PidGainsMsg():
      name_length(0), st_name(), name(nullptr),
      kp_length(0), st_kp(), kp(nullptr),
      ki_length(0), st_ki(), ki(nullptr),
      kd_length(0), st_kd(), kd(nullptr),
      feed_forward_length(0), st_feed_forward(), feed_forward(nullptr),
      dead_zone_length(0), st_dead_zone(), dead_zone(nullptr),
      i_clamp_length(0), st_i_clamp(), i_clamp(nullptr),
      punch_length(0), st_punch(), punch(nullptr),
      min_target_length(0), st_min_target(), min_target(nullptr),
      max_target_length(0), st_max_target(), max_target(nullptr),
      target_lowpass_length(0), st_target_lowpass(), target_lowpass(nullptr),
      min_output_length(0), st_min_output(), min_output(nullptr),
      max_output_length(0), st_max_output(), max_output(nullptr),
      output_lowpass_length(0), st_output_lowpass(), output_lowpass(nullptr),
      d_on_error_length(0), st_d_on_error(), d_on_error(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      varToArr(outbuffer + offset, length_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->kp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->kp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->kp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kp_length);
      for( uint32_t i = 0; i < kp_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->kp[i]);
      }
      *(outbuffer + offset + 0) = (this->ki_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ki_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ki_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ki_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ki_length);
      for( uint32_t i = 0; i < ki_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->ki[i]);
      }
      *(outbuffer + offset + 0) = (this->kd_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->kd_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->kd_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->kd_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->kd_length);
      for( uint32_t i = 0; i < kd_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->kd[i]);
      }
      *(outbuffer + offset + 0) = (this->feed_forward_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->feed_forward_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->feed_forward_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->feed_forward_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->feed_forward_length);
      for( uint32_t i = 0; i < feed_forward_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->feed_forward[i]);
      }
      *(outbuffer + offset + 0) = (this->dead_zone_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dead_zone_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dead_zone_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dead_zone_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dead_zone_length);
      for( uint32_t i = 0; i < dead_zone_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->dead_zone[i]);
      }
      *(outbuffer + offset + 0) = (this->i_clamp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->i_clamp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->i_clamp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->i_clamp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i_clamp_length);
      for( uint32_t i = 0; i < i_clamp_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->i_clamp[i]);
      }
      *(outbuffer + offset + 0) = (this->punch_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->punch_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->punch_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->punch_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->punch_length);
      for( uint32_t i = 0; i < punch_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->punch[i]);
      }
      *(outbuffer + offset + 0) = (this->min_target_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_target_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_target_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_target_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_target_length);
      for( uint32_t i = 0; i < min_target_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->min_target[i]);
      }
      *(outbuffer + offset + 0) = (this->max_target_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_target_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_target_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_target_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_target_length);
      for( uint32_t i = 0; i < max_target_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->max_target[i]);
      }
      *(outbuffer + offset + 0) = (this->target_lowpass_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->target_lowpass_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->target_lowpass_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->target_lowpass_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->target_lowpass_length);
      for( uint32_t i = 0; i < target_lowpass_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->target_lowpass[i]);
      }
      *(outbuffer + offset + 0) = (this->min_output_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->min_output_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->min_output_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->min_output_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_output_length);
      for( uint32_t i = 0; i < min_output_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->min_output[i]);
      }
      *(outbuffer + offset + 0) = (this->max_output_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_output_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_output_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_output_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_output_length);
      for( uint32_t i = 0; i < max_output_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->max_output[i]);
      }
      *(outbuffer + offset + 0) = (this->output_lowpass_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->output_lowpass_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->output_lowpass_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->output_lowpass_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->output_lowpass_length);
      for( uint32_t i = 0; i < output_lowpass_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->output_lowpass[i]);
      }
      *(outbuffer + offset + 0) = (this->d_on_error_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->d_on_error_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->d_on_error_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->d_on_error_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->d_on_error_length);
      for( uint32_t i = 0; i < d_on_error_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_d_on_errori;
      u_d_on_errori.real = this->d_on_error[i];
      *(outbuffer + offset + 0) = (u_d_on_errori.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->d_on_error[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      name_length = name_lengthT;
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      arrToVar(length_st_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint32_t kp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      kp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      kp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      kp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->kp_length);
      if(kp_lengthT > kp_length)
        this->kp = (float*)realloc(this->kp, kp_lengthT * sizeof(float));
      kp_length = kp_lengthT;
      for( uint32_t i = 0; i < kp_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_kp));
        memcpy( &(this->kp[i]), &(this->st_kp), sizeof(float));
      }
      uint32_t ki_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ki_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ki_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ki_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ki_length);
      if(ki_lengthT > ki_length)
        this->ki = (float*)realloc(this->ki, ki_lengthT * sizeof(float));
      ki_length = ki_lengthT;
      for( uint32_t i = 0; i < ki_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_ki));
        memcpy( &(this->ki[i]), &(this->st_ki), sizeof(float));
      }
      uint32_t kd_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      kd_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      kd_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      kd_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->kd_length);
      if(kd_lengthT > kd_length)
        this->kd = (float*)realloc(this->kd, kd_lengthT * sizeof(float));
      kd_length = kd_lengthT;
      for( uint32_t i = 0; i < kd_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_kd));
        memcpy( &(this->kd[i]), &(this->st_kd), sizeof(float));
      }
      uint32_t feed_forward_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      feed_forward_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      feed_forward_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      feed_forward_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->feed_forward_length);
      if(feed_forward_lengthT > feed_forward_length)
        this->feed_forward = (float*)realloc(this->feed_forward, feed_forward_lengthT * sizeof(float));
      feed_forward_length = feed_forward_lengthT;
      for( uint32_t i = 0; i < feed_forward_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_feed_forward));
        memcpy( &(this->feed_forward[i]), &(this->st_feed_forward), sizeof(float));
      }
      uint32_t dead_zone_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dead_zone_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dead_zone_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dead_zone_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dead_zone_length);
      if(dead_zone_lengthT > dead_zone_length)
        this->dead_zone = (float*)realloc(this->dead_zone, dead_zone_lengthT * sizeof(float));
      dead_zone_length = dead_zone_lengthT;
      for( uint32_t i = 0; i < dead_zone_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_dead_zone));
        memcpy( &(this->dead_zone[i]), &(this->st_dead_zone), sizeof(float));
      }
      uint32_t i_clamp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      i_clamp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      i_clamp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      i_clamp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->i_clamp_length);
      if(i_clamp_lengthT > i_clamp_length)
        this->i_clamp = (float*)realloc(this->i_clamp, i_clamp_lengthT * sizeof(float));
      i_clamp_length = i_clamp_lengthT;
      for( uint32_t i = 0; i < i_clamp_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_i_clamp));
        memcpy( &(this->i_clamp[i]), &(this->st_i_clamp), sizeof(float));
      }
      uint32_t punch_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      punch_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      punch_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      punch_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->punch_length);
      if(punch_lengthT > punch_length)
        this->punch = (float*)realloc(this->punch, punch_lengthT * sizeof(float));
      punch_length = punch_lengthT;
      for( uint32_t i = 0; i < punch_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_punch));
        memcpy( &(this->punch[i]), &(this->st_punch), sizeof(float));
      }
      uint32_t min_target_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      min_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      min_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      min_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->min_target_length);
      if(min_target_lengthT > min_target_length)
        this->min_target = (float*)realloc(this->min_target, min_target_lengthT * sizeof(float));
      min_target_length = min_target_lengthT;
      for( uint32_t i = 0; i < min_target_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_min_target));
        memcpy( &(this->min_target[i]), &(this->st_min_target), sizeof(float));
      }
      uint32_t max_target_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      max_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      max_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      max_target_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->max_target_length);
      if(max_target_lengthT > max_target_length)
        this->max_target = (float*)realloc(this->max_target, max_target_lengthT * sizeof(float));
      max_target_length = max_target_lengthT;
      for( uint32_t i = 0; i < max_target_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_max_target));
        memcpy( &(this->max_target[i]), &(this->st_max_target), sizeof(float));
      }
      uint32_t target_lowpass_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      target_lowpass_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      target_lowpass_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      target_lowpass_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->target_lowpass_length);
      if(target_lowpass_lengthT > target_lowpass_length)
        this->target_lowpass = (float*)realloc(this->target_lowpass, target_lowpass_lengthT * sizeof(float));
      target_lowpass_length = target_lowpass_lengthT;
      for( uint32_t i = 0; i < target_lowpass_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_target_lowpass));
        memcpy( &(this->target_lowpass[i]), &(this->st_target_lowpass), sizeof(float));
      }
      uint32_t min_output_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      min_output_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      min_output_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      min_output_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->min_output_length);
      if(min_output_lengthT > min_output_length)
        this->min_output = (float*)realloc(this->min_output, min_output_lengthT * sizeof(float));
      min_output_length = min_output_lengthT;
      for( uint32_t i = 0; i < min_output_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_min_output));
        memcpy( &(this->min_output[i]), &(this->st_min_output), sizeof(float));
      }
      uint32_t max_output_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      max_output_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      max_output_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      max_output_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->max_output_length);
      if(max_output_lengthT > max_output_length)
        this->max_output = (float*)realloc(this->max_output, max_output_lengthT * sizeof(float));
      max_output_length = max_output_lengthT;
      for( uint32_t i = 0; i < max_output_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_max_output));
        memcpy( &(this->max_output[i]), &(this->st_max_output), sizeof(float));
      }
      uint32_t output_lowpass_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      output_lowpass_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      output_lowpass_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      output_lowpass_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->output_lowpass_length);
      if(output_lowpass_lengthT > output_lowpass_length)
        this->output_lowpass = (float*)realloc(this->output_lowpass, output_lowpass_lengthT * sizeof(float));
      output_lowpass_length = output_lowpass_lengthT;
      for( uint32_t i = 0; i < output_lowpass_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_output_lowpass));
        memcpy( &(this->output_lowpass[i]), &(this->st_output_lowpass), sizeof(float));
      }
      uint32_t d_on_error_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      d_on_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      d_on_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      d_on_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->d_on_error_length);
      if(d_on_error_lengthT > d_on_error_length)
        this->d_on_error = (bool*)realloc(this->d_on_error, d_on_error_lengthT * sizeof(bool));
      d_on_error_length = d_on_error_lengthT;
      for( uint32_t i = 0; i < d_on_error_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_d_on_error;
      u_st_d_on_error.base = 0;
      u_st_d_on_error.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_d_on_error = u_st_d_on_error.real;
      offset += sizeof(this->st_d_on_error);
        memcpy( &(this->d_on_error[i]), &(this->st_d_on_error), sizeof(bool));
      }
     return offset;
    }

    virtual const char * getType() override { return "hebiros/PidGainsMsg"; };
    virtual const char * getMD5() override { return "409cfb8df90bde199674774f996b26c5"; };

  };

}
#endif
