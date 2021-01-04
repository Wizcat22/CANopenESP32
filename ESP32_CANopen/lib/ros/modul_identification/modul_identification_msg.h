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
      typedef const char* _modul_id_type;
      _modul_id_type modul_id;
      typedef const char* _modul_name_type;
      _modul_name_type modul_name;
      typedef uint8_t _power_type;
      _power_type power;
      typedef uint8_t _modul_size_type;
      _modul_size_type modul_size;
      typedef uint8_t _connectors_used_type;
      _connectors_used_type connectors_used;

    modul_identification_msg():
      header(),
      modul_id(""),
      modul_name(""),
      power(0),
      modul_size(0),
      connectors_used(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_modul_id = strlen(this->modul_id);
      varToArr(outbuffer + offset, length_modul_id);
      offset += 4;
      memcpy(outbuffer + offset, this->modul_id, length_modul_id);
      offset += length_modul_id;
      uint32_t length_modul_name = strlen(this->modul_name);
      varToArr(outbuffer + offset, length_modul_name);
      offset += 4;
      memcpy(outbuffer + offset, this->modul_name, length_modul_name);
      offset += length_modul_name;
      *(outbuffer + offset + 0) = (this->power >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power);
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
      uint32_t length_modul_id;
      arrToVar(length_modul_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modul_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modul_id-1]=0;
      this->modul_id = (char *)(inbuffer + offset-1);
      offset += length_modul_id;
      uint32_t length_modul_name;
      arrToVar(length_modul_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_modul_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_modul_name-1]=0;
      this->modul_name = (char *)(inbuffer + offset-1);
      offset += length_modul_name;
      this->power =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->power);
      this->modul_size =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->modul_size);
      this->connectors_used =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->connectors_used);
     return offset;
    }

    const char * getType(){ return "modul_identification/modul_identification_msg"; };
    const char * getMD5(){ return "9c711196583e3a60f6fef49c1390d591"; };

  };

}
#endif
