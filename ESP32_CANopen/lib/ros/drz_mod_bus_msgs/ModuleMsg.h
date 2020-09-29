#ifndef _ROS_drz_mod_bus_msgs_ModuleMsg_h
#define _ROS_drz_mod_bus_msgs_ModuleMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace drz_mod_bus_msgs
{

  class ModuleMsg : public ros::Msg
  {
    public:
      typedef const char* _from_type;
      _from_type from;
      typedef const char* _to_type;
      _to_type to;
      typedef const char* _command_type;
      _command_type command;
      typedef int32_t _i1_type;
      _i1_type i1;
      typedef int32_t _i2_type;
      _i2_type i2;
      typedef int32_t _i3_type;
      _i3_type i3;
      typedef int32_t _i4_type;
      _i4_type i4;
      typedef float _d1_type;
      _d1_type d1;
      typedef float _d2_type;
      _d2_type d2;
      typedef float _d3_type;
      _d3_type d3;
      typedef float _d4_type;
      _d4_type d4;

    ModuleMsg():
      from(""),
      to(""),
      command(""),
      i1(0),
      i2(0),
      i3(0),
      i4(0),
      d1(0),
      d2(0),
      d3(0),
      d4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_from = strlen(this->from);
      varToArr(outbuffer + offset, length_from);
      offset += 4;
      memcpy(outbuffer + offset, this->from, length_from);
      offset += length_from;
      uint32_t length_to = strlen(this->to);
      varToArr(outbuffer + offset, length_to);
      offset += 4;
      memcpy(outbuffer + offset, this->to, length_to);
      offset += length_to;
      uint32_t length_command = strlen(this->command);
      varToArr(outbuffer + offset, length_command);
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
      union {
        int32_t real;
        uint32_t base;
      } u_i1;
      u_i1.real = this->i1;
      *(outbuffer + offset + 0) = (u_i1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i1);
      union {
        int32_t real;
        uint32_t base;
      } u_i2;
      u_i2.real = this->i2;
      *(outbuffer + offset + 0) = (u_i2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i2);
      union {
        int32_t real;
        uint32_t base;
      } u_i3;
      u_i3.real = this->i3;
      *(outbuffer + offset + 0) = (u_i3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i3);
      union {
        int32_t real;
        uint32_t base;
      } u_i4;
      u_i4.real = this->i4;
      *(outbuffer + offset + 0) = (u_i4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_i4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_i4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_i4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->i4);
      offset += serializeAvrFloat64(outbuffer + offset, this->d1);
      offset += serializeAvrFloat64(outbuffer + offset, this->d2);
      offset += serializeAvrFloat64(outbuffer + offset, this->d3);
      offset += serializeAvrFloat64(outbuffer + offset, this->d4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_from;
      arrToVar(length_from, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_from; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_from-1]=0;
      this->from = (char *)(inbuffer + offset-1);
      offset += length_from;
      uint32_t length_to;
      arrToVar(length_to, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_to; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_to-1]=0;
      this->to = (char *)(inbuffer + offset-1);
      offset += length_to;
      uint32_t length_command;
      arrToVar(length_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
      union {
        int32_t real;
        uint32_t base;
      } u_i1;
      u_i1.base = 0;
      u_i1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->i1 = u_i1.real;
      offset += sizeof(this->i1);
      union {
        int32_t real;
        uint32_t base;
      } u_i2;
      u_i2.base = 0;
      u_i2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->i2 = u_i2.real;
      offset += sizeof(this->i2);
      union {
        int32_t real;
        uint32_t base;
      } u_i3;
      u_i3.base = 0;
      u_i3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->i3 = u_i3.real;
      offset += sizeof(this->i3);
      union {
        int32_t real;
        uint32_t base;
      } u_i4;
      u_i4.base = 0;
      u_i4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_i4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_i4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_i4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->i4 = u_i4.real;
      offset += sizeof(this->i4);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d1));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d2));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d3));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d4));
     return offset;
    }

    const char * getType(){ return "drz_mod_bus_msgs/ModuleMsg"; };
    const char * getMD5(){ return "50fe68f67d69aa43a1797462747f3d52"; };

  };

}
#endif
