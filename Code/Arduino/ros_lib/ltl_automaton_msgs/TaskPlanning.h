#ifndef _ROS_SERVICE_TaskPlanning_h
#define _ROS_SERVICE_TaskPlanning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ltl_automaton_msgs
{

static const char TASKPLANNING[] = "ltl_automaton_msgs/TaskPlanning";

  class TaskPlanningRequest : public ros::Msg
  {
    public:
      typedef const char* _hard_task_type;
      _hard_task_type hard_task;
      typedef const char* _soft_task_type;
      _soft_task_type soft_task;

    TaskPlanningRequest():
      hard_task(""),
      soft_task("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_hard_task = strlen(this->hard_task);
      varToArr(outbuffer + offset, length_hard_task);
      offset += 4;
      memcpy(outbuffer + offset, this->hard_task, length_hard_task);
      offset += length_hard_task;
      uint32_t length_soft_task = strlen(this->soft_task);
      varToArr(outbuffer + offset, length_soft_task);
      offset += 4;
      memcpy(outbuffer + offset, this->soft_task, length_soft_task);
      offset += length_soft_task;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_hard_task;
      arrToVar(length_hard_task, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hard_task; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hard_task-1]=0;
      this->hard_task = (char *)(inbuffer + offset-1);
      offset += length_hard_task;
      uint32_t length_soft_task;
      arrToVar(length_soft_task, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_soft_task; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_soft_task-1]=0;
      this->soft_task = (char *)(inbuffer + offset-1);
      offset += length_soft_task;
     return offset;
    }

    virtual const char * getType() override { return TASKPLANNING; };
    virtual const char * getMD5() override { return "8fd9063cdce6d34e93bf49764bb202f5"; };

  };

  class TaskPlanningResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    TaskPlanningResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return TASKPLANNING; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class TaskPlanning {
    public:
    typedef TaskPlanningRequest Request;
    typedef TaskPlanningResponse Response;
  };

}
#endif
