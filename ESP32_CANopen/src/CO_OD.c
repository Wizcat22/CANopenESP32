// clang-format off
/*******************************************************************************

   File - CO_OD.c/CO_OD.h
   CANopen Object Dictionary.

   This file was automatically generated with libedssharp Object
   Dictionary Editor v0.8-0-gb60f4eb   DON'T EDIT THIS FILE MANUALLY !!!!
*******************************************************************************/


#include "CO_driver.h"
#include "CO_OD.h"
#include "CO_SDO.h"

/*******************************************************************************
   DEFINITION AND INITIALIZATION OF OBJECT DICTIONARY VARIABLES
*******************************************************************************/


/***** Definition for ROM variables ********************************************/
struct sCO_OD_ROM CO_OD_ROM = {
           CO_OD_FIRST_LAST_WORD,


           CO_OD_FIRST_LAST_WORD,
};


/***** Definition for RAM variables ********************************************/
struct sCO_OD_RAM CO_OD_RAM = {
           CO_OD_FIRST_LAST_WORD,

/*1000*/ 0xf0191L,
/*1001*/ 0x0L,
/*1003*/ {0, 0, 0, 0, 0, 0, 0, 0},
/*1005*/ 0x0080L,
/*1006*/ 0x0000L,
/*1007*/ 0x0000L,
/*1008*/ {'I', 'M', 'S', 'L', '-', 'E', 'S', 'P', '-', 'N', 'o', 'd', 'e'},
/*1009*/ {'1', '.', '0', '0'},
/*100a*/ {'1', '.', '0', '0'},
/*1014*/ 0x0080L,
/*1015*/ 0x64,
/*1016*/ {0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1017*/ 0x00,
/*1018*/ {0x4L, 0x494d534cL, 0xaffeL, 0x0001L, 0x0001L},
/*1019*/ 0x0L,
/*1029*/ {0x0L, 0x1L, 0x0L, 0x0L, 0x0L, 0x0L},
/*1200*/ {{0x2L, 0x0600L, 0x0580L}},
/*1400*/ {{0x2L, 0x0183L, 0xffL}},
/*1600*/ {{0x4L, 0x64030120L, 0x64010110L, 0x60000108L, 0x6f200108L, 0x0000L, 0x0000L, 0x0000L, 0x0000L}},
/*1800*/ {{0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L}},
/*1a00*/ {{0x1L, 0x62000108L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L}},
/*1f80*/ 0x0005L,
/*2100*/ {0x0L},
/*6000*/ {0x0L},
/*6200*/ {0x0L},
/*6401*/ {0x00},
/*6403*/ {0},
/*6f20*/ {0x0L},

           CO_OD_FIRST_LAST_WORD,
};


/***** Definition for EEPROM variables ********************************************/
struct sCO_OD_EEPROM CO_OD_EEPROM = {
           CO_OD_FIRST_LAST_WORD,


           CO_OD_FIRST_LAST_WORD,
};




/*******************************************************************************
   STRUCTURES FOR RECORD TYPE OBJECTS
*******************************************************************************/


/*0x1018*/ const CO_OD_entryRecord_t OD_record1018[5] = {
           {(void*)&CO_OD_RAM.identity.maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.identity.vendorID, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.identity.productCode, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.identity.revisionNumber, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.identity.serialNumber, 0x86, 0x4 },
};

/*0x1200*/ const CO_OD_entryRecord_t OD_record1200[3] = {
           {(void*)&CO_OD_RAM.SDOServerParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SDOServerParameter[0].COB_IDClientToServer, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.SDOServerParameter[0].COB_IDServerToClient, 0x86, 0x4 },
};

/*0x1400*/ const CO_OD_entryRecord_t OD_record1400[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[0].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[0].transmissionType, 0x0e, 0x1 },
};

/*0x1600*/ const CO_OD_entryRecord_t OD_record1600[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].numberOfMappedObjects, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject1, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject2, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject3, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject4, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject5, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject6, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject7, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject8, 0x8e, 0x4 },
};

/*0x1800*/ const CO_OD_entryRecord_t OD_record1800[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1a00*/ const CO_OD_entryRecord_t OD_record1a00[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].numberOfMappedObjects, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject1, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject2, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject3, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject4, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject5, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject6, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject7, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject8, 0x8e, 0x4 },
};

/*******************************************************************************
   OBJECT DICTIONARY
*******************************************************************************/
const CO_OD_entry_t CO_OD[28] = {

{0x1000, 0x00, 0x86, 4, (void*)&CO_OD_RAM.deviceType},
{0x1001, 0x00, 0x26, 1, (void*)&CO_OD_RAM.errorRegister},
{0x1003, 0x08, 0x8e, 4, (void*)&CO_OD_RAM.preDefinedErrorField[0]},
{0x1005, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.COB_ID_SYNCMessage},
{0x1006, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.communicationCyclePeriod},
{0x1007, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.synchronousWindowLength},
{0x1008, 0x00, 0x06, 13, (void*)&CO_OD_RAM.manufacturerDeviceName},
{0x1009, 0x00, 0x06, 4, (void*)&CO_OD_RAM.manufacturerHardwareVersion},
{0x100a, 0x00, 0x06, 4, (void*)&CO_OD_RAM.manufacturerSoftwareVersion},
{0x1014, 0x00, 0x86, 4, (void*)&CO_OD_RAM.COB_ID_EMCY},
{0x1015, 0x00, 0x8e, 2, (void*)&CO_OD_RAM.inhibitTimeEMCY},
{0x1016, 0x04, 0x8e, 4, (void*)&CO_OD_RAM.consumerHeartbeatTime[0]},
{0x1017, 0x00, 0x8e, 2, (void*)&CO_OD_RAM.producerHeartbeatTime},
{0x1018, 0x04, 0x00, 0, (void*)&OD_record1018},
{0x1019, 0x00, 0x0e, 1, (void*)&CO_OD_RAM.synchronousCounterOverflowValue},
{0x1029, 0x06, 0x0e, 1, (void*)&CO_OD_RAM.errorBehavior[0]},
{0x1200, 0x02, 0x00, 0, (void*)&OD_record1200},
{0x1400, 0x02, 0x00, 0, (void*)&OD_record1400},
{0x1600, 0x08, 0x00, 0, (void*)&OD_record1600},
{0x1800, 0x06, 0x00, 0, (void*)&OD_record1800},
{0x1a00, 0x08, 0x00, 0, (void*)&OD_record1a00},
{0x1f80, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.NMTStartup},
{0x2100, 0x00, 0x26, 10, (void*)&CO_OD_RAM.errorStatusBits},
{0x6000, 0x01, 0x3e, 1, (void*)&CO_OD_RAM.statusRegister[0]},
{0x6200, 0x01, 0x3e, 1, (void*)&CO_OD_RAM.commandRegister[0]},
{0x6401, 0x01, 0xbe, 2, (void*)&CO_OD_RAM.temperatureRegister[0]},
{0x6403, 0x01, 0xbe, 4, (void*)&CO_OD_RAM.angleRegister[0]},
{0x6f20, 0x01, 0x3e, 1, (void*)&CO_OD_RAM.lifeCounterRegister[0]},
};
// clang-format on
