/**
 * @file dunker.h
 * @author Alexander Miller (alexander.miller@fh-dortmund.de)
 * @brief Dunker Motoren CANOpen
 * @version 0.1
 * @date 2020-04-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef DUNKER_H_
#define DUNKER_H_

#include <stdint.h>
#include "CANopen.h"
#include "CO_OD.h"

class Dunker
{
private:
    /*Constants*/
    static constexpr int16_t CTRL_SHUTDOWN = 0x0E;                   //Change to "Ready to Switch on"
    static constexpr int16_t CTRL_SWITCH_ON = 0x07;                  //Change to "Switched on"
    static constexpr int16_t CTRL_SWITCH_ON_ENABLE_OPERATION = 0x0F; //Change to "Operation enabled"
    static constexpr int16_t CTRL_DISABLE_VOLTAGE = 0x00;            //Change to "Switch on disabled"
    static constexpr int16_t CTRL_QUICK_STOP = 0x02;                 //Change to "Quick stop active" while in "Operation enabled" or "Switch on disabled"
    static constexpr int16_t CTRL_DISABLE_OPERATION = 0x07;          //Change to "Switched on"
    static constexpr int16_t CTRL_ENABLE_OPERATION = 0x0F;           //Change to "Operation enabled"
    static constexpr int16_t CTRL_FAULT_RESET = 0x80;                //Acknowledge "Fault" and change to "Switch on disabled" (Rising Edge)

    static constexpr int16_t BM_STATUS_NOT_READY_TO_SWITCH_ON = 0x4F; //Bitmask status "NOT_READY_TO_SWITCH_ON"
    static constexpr int16_t BM_STATUS_SWITCH_ON_DISABLED = 0x4F;     //Bitmask status "SWITCH_ON_DISABLED"
    static constexpr int16_t BM_STATUS_READY_TO_SWITCH_ON = 0x6F;     //Bitmask status "READY_TO_SWITCH_ON"
    static constexpr int16_t BM_STATUS_SWITCHED_ON = 0x6F;            //Bitmask status "SWITCHED_ON"
    static constexpr int16_t BM_STATUS_OPERATION_ENABLED = 0x6F;      //Bitmask status "OPERATION_ENABLED"
    static constexpr int16_t BM_STATUS_QUICK_STOP_ACTIVE = 0x6F;      //Bitmask status "QUICK_STOP_ACTIVE"
    static constexpr int16_t BM_STATUS_FAULT_REACTION_ACTIVE = 0x4F;  //Bitmask status "FAULT_REACTION_ACTIVE"
    static constexpr int16_t BM_STATUS_FAULT = 0x4F;                  //Bitmask status "FAULT"

    static constexpr int16_t STATUS_NOT_READY_TO_SWITCH_ON = 0x00; //Statuscode "NOT_READY_TO_SWITCH_ON"
    static constexpr int16_t STATUS_SWITCH_ON_DISABLED = 0x40;     //Statuscode "SWITCH_ON_DISABLED"
    static constexpr int16_t STATUS_READY_TO_SWITCH_ON = 0x21;     //Statuscode "READY_TO_SWITCH_ON"
    static constexpr int16_t STATUS_SWITCHED_ON = 0x23;            //Statuscode "SWITCHED_ON"
    static constexpr int16_t STATUS_OPERATION_ENABLED = 0x27;      //Statuscode "OPERATION_ENABLED"
    static constexpr int16_t STATUS_QUICK_STOP_ACTIVE = 0x07;      //Statuscode "QUICK_STOP_ACTIVE"
    static constexpr int16_t STATUS_FAULT_REACTION_ACTIVE = 0x0F;  //Statuscode "FAULT_REACTION_ACTIVE"
    static constexpr int16_t STATUS_FAULT = 0x08;                  //Statuscode "FAULT"

    static constexpr int16_t OPERATION_MODE = 0x02; //Operation Mode 2 "Velocity Mode"

    static constexpr uint8_t MAX_MOTORS = 2; //Maximum number of motors

    /**
     * @brief Struct for all nessesary registers in the object-dictionary
     * 
     */
    struct motorRegister
    {
        uint16_t *control;
        uint16_t *status;
        int8_t *mode;
        int16_t *velocity;
    };

    static motorRegister motor[MAX_MOTORS];

public:
    CO_t *_CO;

    /*Functions*/

    /**
     * @brief Construct a new Dunker object
     * 
     */
    Dunker();

    /**
     * @brief Initialize motor by setting the RPDO- and TPDO-Mapping
     * 
     * @param CO Pointer to CANopen object
     * @return int8_t 0 = No Error, -n = Errorcode of mapRPDO + mapTPDO
     */
    int8_t init(CO_t *CO);

    /**
     * @brief Change motor status to "Operation enabled" or "Switch on disabled"
     * 
     * @param value 1 = "Operation enabled" ; 0 = "Switch on disabled"
     * @return int8_t 0 = No Error, -1 = Motor in "FAULT"
     */
    int8_t setEnable(uint8_t value);

    /**
     * @brief Set the motor velocity
     * 
     * @param speed Motor velocity
     * @return int8_t 0 = No Error, -1 = Motor in "FAULT"
     */
    int8_t setSpeed(int16_t speed);

    /**
     * @brief Process pending SDO-Download
     * 
     * @return int8_t 0 = No Error, -n = Errorcode of "CO_SDOclientDownload()"
     */
    int8_t coProcessDownloadSDO();

    /**
     * @brief Process pending SDO-Upload
     * 
     * @return int8_t 0 = No Error, -n = Errorcode of "CO_SDOclientUpload()"
     */
    int8_t coProcessUploadSDO();

    /**
     * @brief Changes the PDO-Mapping of given RPDO
     * 
     * @param pdoNumber PDO to change (0-n)
     * @param nodeId Node ID
     * @param mappedObjects Array with objects to be mapped 
     * @param numMappedObjects Nummber of mapped objects
     * @return int8_t 0 = No Error, -n = Errorcode of "coProcessDownloadSDO()"
     */
    int8_t mapRPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects);

    /**
     * @brief Changes the PDO-Mapping of given TPDO
     * 
     * @param pdoNumber PDO to change (0-n)
     * @param nodeId Node ID
     * @param mappedObjects Array with objects to be mapped 
     * @param numMappedObjects Nummber of mapped objects
     * @param eventTime TPDO event time in 100us steps
     * @param inhibitTime TPDO inhibit time in 100us steps
     * @return int8_t 0 = No Error, -n = Errorcode of "coProcessDownloadSDO()"
     */
    int8_t mapTPDO(uint8_t pdoNumber, uint8_t nodeId, uint32_t *mappedObjects, uint8_t numMappedObjects, uint16_t eventTime, uint16_t inhibitTime);
};

#endif /* DUNKER_H_ */