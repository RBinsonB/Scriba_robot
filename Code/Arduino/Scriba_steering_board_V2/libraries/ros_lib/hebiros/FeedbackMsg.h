#ifndef _ROS_hebiros_FeedbackMsg_h
#define _ROS_hebiros_FeedbackMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"
#include "std_msgs/ColorRGBA.h"

namespace hebiros
{

  class FeedbackMsg : public ros::Msg
  {
    public:
      uint32_t name_length;
      typedef char* _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t position_length;
      typedef float _position_type;
      _position_type st_position;
      _position_type * position;
      uint32_t velocity_length;
      typedef float _velocity_type;
      _velocity_type st_velocity;
      _velocity_type * velocity;
      uint32_t effort_length;
      typedef float _effort_type;
      _effort_type st_effort;
      _effort_type * effort;
      uint32_t position_command_length;
      typedef float _position_command_type;
      _position_command_type st_position_command;
      _position_command_type * position_command;
      uint32_t velocity_command_length;
      typedef float _velocity_command_type;
      _velocity_command_type st_velocity_command;
      _velocity_command_type * velocity_command;
      uint32_t effort_command_length;
      typedef float _effort_command_type;
      _effort_command_type st_effort_command;
      _effort_command_type * effort_command;
      uint32_t accelerometer_length;
      typedef geometry_msgs::Vector3 _accelerometer_type;
      _accelerometer_type st_accelerometer;
      _accelerometer_type * accelerometer;
      uint32_t gyro_length;
      typedef geometry_msgs::Vector3 _gyro_type;
      _gyro_type st_gyro;
      _gyro_type * gyro;
      uint32_t orientation_length;
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type st_orientation;
      _orientation_type * orientation;
      uint32_t deflection_length;
      typedef float _deflection_type;
      _deflection_type st_deflection;
      _deflection_type * deflection;
      uint32_t deflection_velocity_length;
      typedef float _deflection_velocity_type;
      _deflection_velocity_type st_deflection_velocity;
      _deflection_velocity_type * deflection_velocity;
      uint32_t motor_velocity_length;
      typedef float _motor_velocity_type;
      _motor_velocity_type st_motor_velocity;
      _motor_velocity_type * motor_velocity;
      uint32_t motor_current_length;
      typedef float _motor_current_type;
      _motor_current_type st_motor_current;
      _motor_current_type * motor_current;
      uint32_t motor_winding_current_length;
      typedef float _motor_winding_current_type;
      _motor_winding_current_type st_motor_winding_current;
      _motor_winding_current_type * motor_winding_current;
      uint32_t motor_sensor_temperature_length;
      typedef float _motor_sensor_temperature_type;
      _motor_sensor_temperature_type st_motor_sensor_temperature;
      _motor_sensor_temperature_type * motor_sensor_temperature;
      uint32_t motor_winding_temperature_length;
      typedef float _motor_winding_temperature_type;
      _motor_winding_temperature_type st_motor_winding_temperature;
      _motor_winding_temperature_type * motor_winding_temperature;
      uint32_t motor_housing_temperature_length;
      typedef float _motor_housing_temperature_type;
      _motor_housing_temperature_type st_motor_housing_temperature;
      _motor_housing_temperature_type * motor_housing_temperature;
      uint32_t board_temperature_length;
      typedef float _board_temperature_type;
      _board_temperature_type st_board_temperature;
      _board_temperature_type * board_temperature;
      uint32_t processor_temperature_length;
      typedef float _processor_temperature_type;
      _processor_temperature_type st_processor_temperature;
      _processor_temperature_type * processor_temperature;
      uint32_t voltage_length;
      typedef float _voltage_type;
      _voltage_type st_voltage;
      _voltage_type * voltage;
      uint32_t led_color_length;
      typedef std_msgs::ColorRGBA _led_color_type;
      _led_color_type st_led_color;
      _led_color_type * led_color;
      uint32_t sequence_number_length;
      typedef uint64_t _sequence_number_type;
      _sequence_number_type st_sequence_number;
      _sequence_number_type * sequence_number;
      uint32_t receive_time_length;
      typedef uint64_t _receive_time_type;
      _receive_time_type st_receive_time;
      _receive_time_type * receive_time;
      uint32_t transmit_time_length;
      typedef uint64_t _transmit_time_type;
      _transmit_time_type st_transmit_time;
      _transmit_time_type * transmit_time;
      uint32_t hardware_receive_time_length;
      typedef uint64_t _hardware_receive_time_type;
      _hardware_receive_time_type st_hardware_receive_time;
      _hardware_receive_time_type * hardware_receive_time;
      uint32_t hardware_transmit_time_length;
      typedef uint64_t _hardware_transmit_time_type;
      _hardware_transmit_time_type st_hardware_transmit_time;
      _hardware_transmit_time_type * hardware_transmit_time;

    FeedbackMsg():
      name_length(0), name(NULL),
      position_length(0), position(NULL),
      velocity_length(0), velocity(NULL),
      effort_length(0), effort(NULL),
      position_command_length(0), position_command(NULL),
      velocity_command_length(0), velocity_command(NULL),
      effort_command_length(0), effort_command(NULL),
      accelerometer_length(0), accelerometer(NULL),
      gyro_length(0), gyro(NULL),
      orientation_length(0), orientation(NULL),
      deflection_length(0), deflection(NULL),
      deflection_velocity_length(0), deflection_velocity(NULL),
      motor_velocity_length(0), motor_velocity(NULL),
      motor_current_length(0), motor_current(NULL),
      motor_winding_current_length(0), motor_winding_current(NULL),
      motor_sensor_temperature_length(0), motor_sensor_temperature(NULL),
      motor_winding_temperature_length(0), motor_winding_temperature(NULL),
      motor_housing_temperature_length(0), motor_housing_temperature(NULL),
      board_temperature_length(0), board_temperature(NULL),
      processor_temperature_length(0), processor_temperature(NULL),
      voltage_length(0), voltage(NULL),
      led_color_length(0), led_color(NULL),
      sequence_number_length(0), sequence_number(NULL),
      receive_time_length(0), receive_time(NULL),
      transmit_time_length(0), transmit_time(NULL),
      hardware_receive_time_length(0), hardware_receive_time(NULL),
      hardware_transmit_time_length(0), hardware_transmit_time(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
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
      *(outbuffer + offset + 0) = (this->position_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_length);
      for( uint32_t i = 0; i < position_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->position[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_length);
      for( uint32_t i = 0; i < effort_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->effort[i]);
      }
      *(outbuffer + offset + 0) = (this->position_command_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_command_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_command_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_command_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_command_length);
      for( uint32_t i = 0; i < position_command_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->position_command[i]);
      }
      *(outbuffer + offset + 0) = (this->velocity_command_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_command_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_command_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_command_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_command_length);
      for( uint32_t i = 0; i < velocity_command_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity_command[i]);
      }
      *(outbuffer + offset + 0) = (this->effort_command_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_command_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_command_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_command_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_command_length);
      for( uint32_t i = 0; i < effort_command_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->effort_command[i]);
      }
      *(outbuffer + offset + 0) = (this->accelerometer_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerometer_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accelerometer_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accelerometer_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelerometer_length);
      for( uint32_t i = 0; i < accelerometer_length; i++){
      offset += this->accelerometer[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->gyro_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gyro_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gyro_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gyro_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gyro_length);
      for( uint32_t i = 0; i < gyro_length; i++){
      offset += this->gyro[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->orientation_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->orientation_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->orientation_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->orientation_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation_length);
      for( uint32_t i = 0; i < orientation_length; i++){
      offset += this->orientation[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->deflection_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deflection_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deflection_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deflection_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deflection_length);
      for( uint32_t i = 0; i < deflection_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->deflection[i]);
      }
      *(outbuffer + offset + 0) = (this->deflection_velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deflection_velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deflection_velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deflection_velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deflection_velocity_length);
      for( uint32_t i = 0; i < deflection_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->deflection_velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_velocity_length);
      for( uint32_t i = 0; i < motor_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_current_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_current_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_current_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_current_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_current_length);
      for( uint32_t i = 0; i < motor_current_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_current[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_winding_current_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_winding_current_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_winding_current_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_winding_current_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_winding_current_length);
      for( uint32_t i = 0; i < motor_winding_current_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_winding_current[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_sensor_temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_sensor_temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_sensor_temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_sensor_temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_sensor_temperature_length);
      for( uint32_t i = 0; i < motor_sensor_temperature_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_sensor_temperature[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_winding_temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_winding_temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_winding_temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_winding_temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_winding_temperature_length);
      for( uint32_t i = 0; i < motor_winding_temperature_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_winding_temperature[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_housing_temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_housing_temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_housing_temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_housing_temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_housing_temperature_length);
      for( uint32_t i = 0; i < motor_housing_temperature_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_housing_temperature[i]);
      }
      *(outbuffer + offset + 0) = (this->board_temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->board_temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->board_temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->board_temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->board_temperature_length);
      for( uint32_t i = 0; i < board_temperature_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->board_temperature[i]);
      }
      *(outbuffer + offset + 0) = (this->processor_temperature_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->processor_temperature_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->processor_temperature_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->processor_temperature_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->processor_temperature_length);
      for( uint32_t i = 0; i < processor_temperature_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->processor_temperature[i]);
      }
      *(outbuffer + offset + 0) = (this->voltage_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->voltage_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->voltage_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage_length);
      for( uint32_t i = 0; i < voltage_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->voltage[i]);
      }
      *(outbuffer + offset + 0) = (this->led_color_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->led_color_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->led_color_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->led_color_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->led_color_length);
      for( uint32_t i = 0; i < led_color_length; i++){
      offset += this->led_color[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->sequence_number_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequence_number_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sequence_number_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sequence_number_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequence_number_length);
      for( uint32_t i = 0; i < sequence_number_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_sequence_numberi;
      u_sequence_numberi.real = this->sequence_number[i];
      *(outbuffer + offset + 0) = (u_sequence_numberi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sequence_numberi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sequence_numberi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sequence_numberi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequence_number[i]);
      }
      *(outbuffer + offset + 0) = (this->receive_time_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->receive_time_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->receive_time_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->receive_time_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->receive_time_length);
      for( uint32_t i = 0; i < receive_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_receive_timei;
      u_receive_timei.real = this->receive_time[i];
      *(outbuffer + offset + 0) = (u_receive_timei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_receive_timei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_receive_timei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_receive_timei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->receive_time[i]);
      }
      *(outbuffer + offset + 0) = (this->transmit_time_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transmit_time_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transmit_time_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transmit_time_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transmit_time_length);
      for( uint32_t i = 0; i < transmit_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_transmit_timei;
      u_transmit_timei.real = this->transmit_time[i];
      *(outbuffer + offset + 0) = (u_transmit_timei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transmit_timei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transmit_timei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transmit_timei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transmit_time[i]);
      }
      *(outbuffer + offset + 0) = (this->hardware_receive_time_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hardware_receive_time_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hardware_receive_time_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hardware_receive_time_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hardware_receive_time_length);
      for( uint32_t i = 0; i < hardware_receive_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_hardware_receive_timei;
      u_hardware_receive_timei.real = this->hardware_receive_time[i];
      *(outbuffer + offset + 0) = (u_hardware_receive_timei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hardware_receive_timei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hardware_receive_timei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hardware_receive_timei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hardware_receive_time[i]);
      }
      *(outbuffer + offset + 0) = (this->hardware_transmit_time_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hardware_transmit_time_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hardware_transmit_time_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hardware_transmit_time_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hardware_transmit_time_length);
      for( uint32_t i = 0; i < hardware_transmit_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_hardware_transmit_timei;
      u_hardware_transmit_timei.real = this->hardware_transmit_time[i];
      *(outbuffer + offset + 0) = (u_hardware_transmit_timei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hardware_transmit_timei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hardware_transmit_timei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hardware_transmit_timei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hardware_transmit_time[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
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
      uint32_t position_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_length);
      if(position_lengthT > position_length)
        this->position = (float*)realloc(this->position, position_lengthT * sizeof(float));
      position_length = position_lengthT;
      for( uint32_t i = 0; i < position_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_position));
        memcpy( &(this->position[i]), &(this->st_position), sizeof(float));
      }
      uint32_t velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_length);
      if(velocity_lengthT > velocity_length)
        this->velocity = (float*)realloc(this->velocity, velocity_lengthT * sizeof(float));
      velocity_length = velocity_lengthT;
      for( uint32_t i = 0; i < velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_velocity));
        memcpy( &(this->velocity[i]), &(this->st_velocity), sizeof(float));
      }
      uint32_t effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_length);
      if(effort_lengthT > effort_length)
        this->effort = (float*)realloc(this->effort, effort_lengthT * sizeof(float));
      effort_length = effort_lengthT;
      for( uint32_t i = 0; i < effort_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_effort));
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(float));
      }
      uint32_t position_command_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_command_length);
      if(position_command_lengthT > position_command_length)
        this->position_command = (float*)realloc(this->position_command, position_command_lengthT * sizeof(float));
      position_command_length = position_command_lengthT;
      for( uint32_t i = 0; i < position_command_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_position_command));
        memcpy( &(this->position_command[i]), &(this->st_position_command), sizeof(float));
      }
      uint32_t velocity_command_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_command_length);
      if(velocity_command_lengthT > velocity_command_length)
        this->velocity_command = (float*)realloc(this->velocity_command, velocity_command_lengthT * sizeof(float));
      velocity_command_length = velocity_command_lengthT;
      for( uint32_t i = 0; i < velocity_command_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_velocity_command));
        memcpy( &(this->velocity_command[i]), &(this->st_velocity_command), sizeof(float));
      }
      uint32_t effort_command_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_command_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_command_length);
      if(effort_command_lengthT > effort_command_length)
        this->effort_command = (float*)realloc(this->effort_command, effort_command_lengthT * sizeof(float));
      effort_command_length = effort_command_lengthT;
      for( uint32_t i = 0; i < effort_command_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_effort_command));
        memcpy( &(this->effort_command[i]), &(this->st_effort_command), sizeof(float));
      }
      uint32_t accelerometer_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accelerometer_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerometer_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerometer_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->accelerometer_length);
      if(accelerometer_lengthT > accelerometer_length)
        this->accelerometer = (geometry_msgs::Vector3*)realloc(this->accelerometer, accelerometer_lengthT * sizeof(geometry_msgs::Vector3));
      accelerometer_length = accelerometer_lengthT;
      for( uint32_t i = 0; i < accelerometer_length; i++){
      offset += this->st_accelerometer.deserialize(inbuffer + offset);
        memcpy( &(this->accelerometer[i]), &(this->st_accelerometer), sizeof(geometry_msgs::Vector3));
      }
      uint32_t gyro_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gyro_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gyro_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gyro_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gyro_length);
      if(gyro_lengthT > gyro_length)
        this->gyro = (geometry_msgs::Vector3*)realloc(this->gyro, gyro_lengthT * sizeof(geometry_msgs::Vector3));
      gyro_length = gyro_lengthT;
      for( uint32_t i = 0; i < gyro_length; i++){
      offset += this->st_gyro.deserialize(inbuffer + offset);
        memcpy( &(this->gyro[i]), &(this->st_gyro), sizeof(geometry_msgs::Vector3));
      }
      uint32_t orientation_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->orientation_length);
      if(orientation_lengthT > orientation_length)
        this->orientation = (geometry_msgs::Quaternion*)realloc(this->orientation, orientation_lengthT * sizeof(geometry_msgs::Quaternion));
      orientation_length = orientation_lengthT;
      for( uint32_t i = 0; i < orientation_length; i++){
      offset += this->st_orientation.deserialize(inbuffer + offset);
        memcpy( &(this->orientation[i]), &(this->st_orientation), sizeof(geometry_msgs::Quaternion));
      }
      uint32_t deflection_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      deflection_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      deflection_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      deflection_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->deflection_length);
      if(deflection_lengthT > deflection_length)
        this->deflection = (float*)realloc(this->deflection, deflection_lengthT * sizeof(float));
      deflection_length = deflection_lengthT;
      for( uint32_t i = 0; i < deflection_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_deflection));
        memcpy( &(this->deflection[i]), &(this->st_deflection), sizeof(float));
      }
      uint32_t deflection_velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      deflection_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      deflection_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      deflection_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->deflection_velocity_length);
      if(deflection_velocity_lengthT > deflection_velocity_length)
        this->deflection_velocity = (float*)realloc(this->deflection_velocity, deflection_velocity_lengthT * sizeof(float));
      deflection_velocity_length = deflection_velocity_lengthT;
      for( uint32_t i = 0; i < deflection_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_deflection_velocity));
        memcpy( &(this->deflection_velocity[i]), &(this->st_deflection_velocity), sizeof(float));
      }
      uint32_t motor_velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_velocity_length);
      if(motor_velocity_lengthT > motor_velocity_length)
        this->motor_velocity = (float*)realloc(this->motor_velocity, motor_velocity_lengthT * sizeof(float));
      motor_velocity_length = motor_velocity_lengthT;
      for( uint32_t i = 0; i < motor_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor_velocity));
        memcpy( &(this->motor_velocity[i]), &(this->st_motor_velocity), sizeof(float));
      }
      uint32_t motor_current_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_current_length);
      if(motor_current_lengthT > motor_current_length)
        this->motor_current = (float*)realloc(this->motor_current, motor_current_lengthT * sizeof(float));
      motor_current_length = motor_current_lengthT;
      for( uint32_t i = 0; i < motor_current_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor_current));
        memcpy( &(this->motor_current[i]), &(this->st_motor_current), sizeof(float));
      }
      uint32_t motor_winding_current_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_winding_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_winding_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_winding_current_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_winding_current_length);
      if(motor_winding_current_lengthT > motor_winding_current_length)
        this->motor_winding_current = (float*)realloc(this->motor_winding_current, motor_winding_current_lengthT * sizeof(float));
      motor_winding_current_length = motor_winding_current_lengthT;
      for( uint32_t i = 0; i < motor_winding_current_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor_winding_current));
        memcpy( &(this->motor_winding_current[i]), &(this->st_motor_winding_current), sizeof(float));
      }
      uint32_t motor_sensor_temperature_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_sensor_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_sensor_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_sensor_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_sensor_temperature_length);
      if(motor_sensor_temperature_lengthT > motor_sensor_temperature_length)
        this->motor_sensor_temperature = (float*)realloc(this->motor_sensor_temperature, motor_sensor_temperature_lengthT * sizeof(float));
      motor_sensor_temperature_length = motor_sensor_temperature_lengthT;
      for( uint32_t i = 0; i < motor_sensor_temperature_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor_sensor_temperature));
        memcpy( &(this->motor_sensor_temperature[i]), &(this->st_motor_sensor_temperature), sizeof(float));
      }
      uint32_t motor_winding_temperature_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_winding_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_winding_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_winding_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_winding_temperature_length);
      if(motor_winding_temperature_lengthT > motor_winding_temperature_length)
        this->motor_winding_temperature = (float*)realloc(this->motor_winding_temperature, motor_winding_temperature_lengthT * sizeof(float));
      motor_winding_temperature_length = motor_winding_temperature_lengthT;
      for( uint32_t i = 0; i < motor_winding_temperature_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor_winding_temperature));
        memcpy( &(this->motor_winding_temperature[i]), &(this->st_motor_winding_temperature), sizeof(float));
      }
      uint32_t motor_housing_temperature_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_housing_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_housing_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_housing_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_housing_temperature_length);
      if(motor_housing_temperature_lengthT > motor_housing_temperature_length)
        this->motor_housing_temperature = (float*)realloc(this->motor_housing_temperature, motor_housing_temperature_lengthT * sizeof(float));
      motor_housing_temperature_length = motor_housing_temperature_lengthT;
      for( uint32_t i = 0; i < motor_housing_temperature_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor_housing_temperature));
        memcpy( &(this->motor_housing_temperature[i]), &(this->st_motor_housing_temperature), sizeof(float));
      }
      uint32_t board_temperature_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      board_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      board_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      board_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->board_temperature_length);
      if(board_temperature_lengthT > board_temperature_length)
        this->board_temperature = (float*)realloc(this->board_temperature, board_temperature_lengthT * sizeof(float));
      board_temperature_length = board_temperature_lengthT;
      for( uint32_t i = 0; i < board_temperature_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_board_temperature));
        memcpy( &(this->board_temperature[i]), &(this->st_board_temperature), sizeof(float));
      }
      uint32_t processor_temperature_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      processor_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      processor_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      processor_temperature_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->processor_temperature_length);
      if(processor_temperature_lengthT > processor_temperature_length)
        this->processor_temperature = (float*)realloc(this->processor_temperature, processor_temperature_lengthT * sizeof(float));
      processor_temperature_length = processor_temperature_lengthT;
      for( uint32_t i = 0; i < processor_temperature_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_processor_temperature));
        memcpy( &(this->processor_temperature[i]), &(this->st_processor_temperature), sizeof(float));
      }
      uint32_t voltage_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->voltage_length);
      if(voltage_lengthT > voltage_length)
        this->voltage = (float*)realloc(this->voltage, voltage_lengthT * sizeof(float));
      voltage_length = voltage_lengthT;
      for( uint32_t i = 0; i < voltage_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_voltage));
        memcpy( &(this->voltage[i]), &(this->st_voltage), sizeof(float));
      }
      uint32_t led_color_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      led_color_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      led_color_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      led_color_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->led_color_length);
      if(led_color_lengthT > led_color_length)
        this->led_color = (std_msgs::ColorRGBA*)realloc(this->led_color, led_color_lengthT * sizeof(std_msgs::ColorRGBA));
      led_color_length = led_color_lengthT;
      for( uint32_t i = 0; i < led_color_length; i++){
      offset += this->st_led_color.deserialize(inbuffer + offset);
        memcpy( &(this->led_color[i]), &(this->st_led_color), sizeof(std_msgs::ColorRGBA));
      }
      uint32_t sequence_number_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sequence_number_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sequence_number_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sequence_number_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sequence_number_length);
      if(sequence_number_lengthT > sequence_number_length)
        this->sequence_number = (uint64_t*)realloc(this->sequence_number, sequence_number_lengthT * sizeof(uint64_t));
      sequence_number_length = sequence_number_lengthT;
      for( uint32_t i = 0; i < sequence_number_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_sequence_number;
      u_st_sequence_number.base = 0;
      u_st_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_sequence_number.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_sequence_number = u_st_sequence_number.real;
      offset += sizeof(this->st_sequence_number);
        memcpy( &(this->sequence_number[i]), &(this->st_sequence_number), sizeof(uint64_t));
      }
      uint32_t receive_time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      receive_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      receive_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      receive_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->receive_time_length);
      if(receive_time_lengthT > receive_time_length)
        this->receive_time = (uint64_t*)realloc(this->receive_time, receive_time_lengthT * sizeof(uint64_t));
      receive_time_length = receive_time_lengthT;
      for( uint32_t i = 0; i < receive_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_receive_time;
      u_st_receive_time.base = 0;
      u_st_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_receive_time = u_st_receive_time.real;
      offset += sizeof(this->st_receive_time);
        memcpy( &(this->receive_time[i]), &(this->st_receive_time), sizeof(uint64_t));
      }
      uint32_t transmit_time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transmit_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transmit_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transmit_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->transmit_time_length);
      if(transmit_time_lengthT > transmit_time_length)
        this->transmit_time = (uint64_t*)realloc(this->transmit_time, transmit_time_lengthT * sizeof(uint64_t));
      transmit_time_length = transmit_time_lengthT;
      for( uint32_t i = 0; i < transmit_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_transmit_time;
      u_st_transmit_time.base = 0;
      u_st_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_transmit_time = u_st_transmit_time.real;
      offset += sizeof(this->st_transmit_time);
        memcpy( &(this->transmit_time[i]), &(this->st_transmit_time), sizeof(uint64_t));
      }
      uint32_t hardware_receive_time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hardware_receive_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hardware_receive_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hardware_receive_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hardware_receive_time_length);
      if(hardware_receive_time_lengthT > hardware_receive_time_length)
        this->hardware_receive_time = (uint64_t*)realloc(this->hardware_receive_time, hardware_receive_time_lengthT * sizeof(uint64_t));
      hardware_receive_time_length = hardware_receive_time_lengthT;
      for( uint32_t i = 0; i < hardware_receive_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_hardware_receive_time;
      u_st_hardware_receive_time.base = 0;
      u_st_hardware_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_hardware_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_hardware_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_hardware_receive_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_hardware_receive_time = u_st_hardware_receive_time.real;
      offset += sizeof(this->st_hardware_receive_time);
        memcpy( &(this->hardware_receive_time[i]), &(this->st_hardware_receive_time), sizeof(uint64_t));
      }
      uint32_t hardware_transmit_time_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hardware_transmit_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hardware_transmit_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hardware_transmit_time_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hardware_transmit_time_length);
      if(hardware_transmit_time_lengthT > hardware_transmit_time_length)
        this->hardware_transmit_time = (uint64_t*)realloc(this->hardware_transmit_time, hardware_transmit_time_lengthT * sizeof(uint64_t));
      hardware_transmit_time_length = hardware_transmit_time_lengthT;
      for( uint32_t i = 0; i < hardware_transmit_time_length; i++){
      union {
        uint64_t real;
        uint32_t base;
      } u_st_hardware_transmit_time;
      u_st_hardware_transmit_time.base = 0;
      u_st_hardware_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_hardware_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_hardware_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_hardware_transmit_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_hardware_transmit_time = u_st_hardware_transmit_time.real;
      offset += sizeof(this->st_hardware_transmit_time);
        memcpy( &(this->hardware_transmit_time[i]), &(this->st_hardware_transmit_time), sizeof(uint64_t));
      }
     return offset;
    }

    const char * getType(){ return "hebiros/FeedbackMsg"; };
    const char * getMD5(){ return "f4e368b929bb5d796beb629cf975333e"; };

  };

}
#endif