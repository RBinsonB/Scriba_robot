#ifndef _ROS_hebiros_SettingsMsg_h
#define _ROS_hebiros_SettingsMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hebiros/PidGainsMsg.h"

namespace hebiros
{

  class SettingsMsg : public ros::Msg
  {
    public:
      uint32_t name_length;
      typedef char* _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t save_current_settings_length;
      typedef bool _save_current_settings_type;
      _save_current_settings_type st_save_current_settings;
      _save_current_settings_type * save_current_settings;
      uint32_t control_strategy_length;
      typedef int8_t _control_strategy_type;
      _control_strategy_type st_control_strategy;
      _control_strategy_type * control_strategy;
      typedef hebiros::PidGainsMsg _position_gains_type;
      _position_gains_type position_gains;
      typedef hebiros::PidGainsMsg _velocity_gains_type;
      _velocity_gains_type velocity_gains;
      typedef hebiros::PidGainsMsg _effort_gains_type;
      _effort_gains_type effort_gains;

    SettingsMsg():
      name_length(0), st_name(), name(nullptr),
      save_current_settings_length(0), st_save_current_settings(), save_current_settings(nullptr),
      control_strategy_length(0), st_control_strategy(), control_strategy(nullptr),
      position_gains(),
      velocity_gains(),
      effort_gains()
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
      *(outbuffer + offset + 0) = (this->save_current_settings_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->save_current_settings_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->save_current_settings_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->save_current_settings_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->save_current_settings_length);
      for( uint32_t i = 0; i < save_current_settings_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_save_current_settingsi;
      u_save_current_settingsi.real = this->save_current_settings[i];
      *(outbuffer + offset + 0) = (u_save_current_settingsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->save_current_settings[i]);
      }
      *(outbuffer + offset + 0) = (this->control_strategy_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->control_strategy_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->control_strategy_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->control_strategy_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->control_strategy_length);
      for( uint32_t i = 0; i < control_strategy_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_control_strategyi;
      u_control_strategyi.real = this->control_strategy[i];
      *(outbuffer + offset + 0) = (u_control_strategyi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_strategy[i]);
      }
      offset += this->position_gains.serialize(outbuffer + offset);
      offset += this->velocity_gains.serialize(outbuffer + offset);
      offset += this->effort_gains.serialize(outbuffer + offset);
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
      uint32_t save_current_settings_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      save_current_settings_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      save_current_settings_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      save_current_settings_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->save_current_settings_length);
      if(save_current_settings_lengthT > save_current_settings_length)
        this->save_current_settings = (bool*)realloc(this->save_current_settings, save_current_settings_lengthT * sizeof(bool));
      save_current_settings_length = save_current_settings_lengthT;
      for( uint32_t i = 0; i < save_current_settings_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_save_current_settings;
      u_st_save_current_settings.base = 0;
      u_st_save_current_settings.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_save_current_settings = u_st_save_current_settings.real;
      offset += sizeof(this->st_save_current_settings);
        memcpy( &(this->save_current_settings[i]), &(this->st_save_current_settings), sizeof(bool));
      }
      uint32_t control_strategy_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      control_strategy_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      control_strategy_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      control_strategy_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->control_strategy_length);
      if(control_strategy_lengthT > control_strategy_length)
        this->control_strategy = (int8_t*)realloc(this->control_strategy, control_strategy_lengthT * sizeof(int8_t));
      control_strategy_length = control_strategy_lengthT;
      for( uint32_t i = 0; i < control_strategy_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_control_strategy;
      u_st_control_strategy.base = 0;
      u_st_control_strategy.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_control_strategy = u_st_control_strategy.real;
      offset += sizeof(this->st_control_strategy);
        memcpy( &(this->control_strategy[i]), &(this->st_control_strategy), sizeof(int8_t));
      }
      offset += this->position_gains.deserialize(inbuffer + offset);
      offset += this->velocity_gains.deserialize(inbuffer + offset);
      offset += this->effort_gains.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "hebiros/SettingsMsg"; };
    virtual const char * getMD5() override { return "4333c3b24c39f74ad09d675d9b50f596"; };

  };

}
#endif
