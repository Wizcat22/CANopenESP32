#ifndef _ROS_modul_identification_modul_identification_msg_h
#define _ROS_modul_identification_modul_identification_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace modul_identification
{

  class modul_identification_msg : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _modul_id_type;
      _modul_id_type modul_id;
      typedef const char* _robot_name_type;
      _robot_name_type robot_name;
      typedef uint8_t _slot_id_type;
      _slot_id_type slot_id;
      typedef uint8_t _power_type;
      _power_type power;
      typedef float _offset_x_type;
      _offset_x_type offset_x;
      typedef float _offset_y_type;
      _offset_y_type offset_y;
      typedef float _offset_z_type;
      _offset_z_type offset_z;
      typedef uint8_t _modul_size_type;
      _modul_size_type modul_size;
      typedef uint8_t _connectors_used_type;
      _connectors_used_type connectors_used;

    modul_identification_msg():
      header(),
      modul_id(0),
      robot_name(""),
      slot_id(0),
      power(0),
      offset_x(0),
      offset_y(0),
      offset_z(0),
      modul_size(0),
      connectors_used(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->modul_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modul_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->modul_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->modul_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->modul_id);
      uint32_t length_robot_name = strlen(this->robot_name);
      varToArr(outbuffer + offset, length_robot_name);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_name, length_robot_name);
      offset += length_robot_name;
      *(outbuffer + offset + 0) = (this->slot_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->slot_id);
      *(outbuffer + offset + 0) = (this->power >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power);
      union {
        float real;
        uint32_t base;
      } u_offset_x;
      u_offset_x.real = this->offset_x;
      *(outbuffer + offset + 0) = (u_offset_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset_x);
      union {
        float real;
        uint32_t base;
      } u_offset_y;
      u_offset_y.real = this->offset_y;
      *(outbuffer + offset + 0) = (u_offset_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset_y);
      union {
        float real;
        uint32_t base;
      } u_offset_z;
      u_offset_z.real = this->offset_z;
      *(outbuffer + offset + 0) = (u_offset_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset_z);
      *(outbuffer + offset + 0) = (this->modul_size >> (8 * 0)) & 0xFF;
      offset += sizeof(this->modul_size);
      *(outbuffer + offset + 0) = (this->connectors_used >> (8 * 0)) & 0xFF;
      offset += sizeof(this->connectors_used);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->modul_id =  ((uint32_t) (*(inbuffer + offset)));
      this->modul_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->modul_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->modul_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->modul_id);
      uint32_t length_robot_name;
      arrToVar(length_robot_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_name-1]=0;
      this->robot_name = (char *)(inbuffer + offset-1);
      offset += length_robot_name;
      this->slot_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->slot_id);
      this->power =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->power);
      union {
        float real;
        uint32_t base;
      } u_offset_x;
      u_offset_x.base = 0;
      u_offset_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->offset_x = u_offset_x.real;
      offset += sizeof(this->offset_x);
      union {
        float real;
        uint32_t base;
      } u_offset_y;
      u_offset_y.base = 0;
      u_offset_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->offset_y = u_offset_y.real;
      offset += sizeof(this->offset_y);
      union {
        float real;
        uint32_t base;
      } u_offset_z;
      u_offset_z.base = 0;
      u_offset_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_offset_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_offset_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_offset_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->offset_z = u_offset_z.real;
      offset += sizeof(this->offset_z);
      this->modul_size =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->modul_size);
      this->connectors_used =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->connectors_used);
     return offset;
    }

    const char * getType(){ return "modul_identification/modul_identification_msg"; };
    const char * getMD5(){ return "b750818e6b2147b38247972f8f0f93ce"; };

  };

}
#endif
