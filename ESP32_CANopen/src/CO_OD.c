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

/*1000*/ 0x70191L,
/*1001*/ 0x0L,
/*1003*/ {0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1005*/ 0x80000080L,
/*1006*/ 0x0000L,
/*1007*/ 0x0000L,
/*1008*/ {'8', '4', '3', '0'},
/*1009*/ {'B', '2'},
/*100a*/ {'1', '.', '0', '0'},
/*1014*/ 0x0080L,
/*1015*/ 0x64,
/*1016*/ {0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1017*/ 0x00,
/*1018*/ {0x4L, 0x0202L, 0x84300L, 0x0001L, 0x98967fL},
/*1019*/ 0x0L,
/*1029*/ {0x0L, 0x1L, 0x0L, 0x0L, 0x0L, 0x0L},
/*1200*/ {{0x2L, 0x0600L, 0x0580L}},
/*1400*/ {{0x2L, 0x0183L, 0xffL},
/*1401*/ {0x2L, 0x0183L, 0xffL},
/*1402*/ {0x2L, 0x0183L, 0xffL},
/*1403*/ {0x2L, 0x0183L, 0xffL},
/*1404*/ {0x2L, 0x0183L, 0xffL},
/*1405*/ {0x2L, 0x0183L, 0xffL},
/*1406*/ {0x2L, 0x0183L, 0xffL},
/*1407*/ {0x2L, 0x0183L, 0xffL}},
/*1600*/ {{0x4L, 0x64030120L, 0x64010110L, 0x60000108L, 0x6f200108L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1601*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1602*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1603*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1604*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1605*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1606*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1607*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L}},
/*1800*/ {{0x6L, 0x0203L, 0xffL, 0x00, 0x0L, 0x00, 0x0L},
/*1801*/ {0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L},
/*1802*/ {0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L},
/*1803*/ {0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L},
/*1804*/ {0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L},
/*1805*/ {0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L},
/*1806*/ {0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L},
/*1807*/ {0x6L, 0x0203L, 0xffL, 0x64, 0x0L, 0x00, 0x0L}},
/*1a00*/ {{0x1L, 0x62000108L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1a01*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1a02*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1a03*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1a04*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1a05*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1a06*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*1a07*/ {0x0L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L}},
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
           {(void*)&CO_OD_RAM.identityObject.highestSubindex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.identityObject.vendorID, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.identityObject.produktCode, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.identityObject.revision, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.identityObject.serialNumber, 0x86, 0x4 },
};

/*0x1200*/ const CO_OD_entryRecord_t OD_record1200[3] = {
           {(void*)&CO_OD_RAM.SDOServerParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SDOServerParameter[0].COB_IDClientToServer, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.SDOServerParameter[0].COB_IDServerToClient, 0x86, 0x4 },
};

/*0x1400*/ const CO_OD_entryRecord_t OD_record1400[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[0].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[0].transmissionType, 0x06, 0x1 },
};

/*0x1401*/ const CO_OD_entryRecord_t OD_record1401[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[1].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[1].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[1].transmissionType, 0x0e, 0x1 },
};

/*0x1402*/ const CO_OD_entryRecord_t OD_record1402[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[2].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[2].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[2].transmissionType, 0x0e, 0x1 },
};

/*0x1403*/ const CO_OD_entryRecord_t OD_record1403[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[3].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[3].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[3].transmissionType, 0x0e, 0x1 },
};

/*0x1404*/ const CO_OD_entryRecord_t OD_record1404[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[4].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[4].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[4].transmissionType, 0x0e, 0x1 },
};

/*0x1405*/ const CO_OD_entryRecord_t OD_record1405[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[5].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[5].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[5].transmissionType, 0x0e, 0x1 },
};

/*0x1406*/ const CO_OD_entryRecord_t OD_record1406[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[6].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[6].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[6].transmissionType, 0x0e, 0x1 },
};

/*0x1407*/ const CO_OD_entryRecord_t OD_record1407[3] = {
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[7].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[7].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOCommunicationParameter[7].transmissionType, 0x0e, 0x1 },
};

/*0x1600*/ const CO_OD_entryRecord_t OD_record1600[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject1, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject2, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject3, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject4, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[0].mappedObject8, 0x86, 0x4 },
};

/*0x1601*/ const CO_OD_entryRecord_t OD_record1601[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[1].mappedObject8, 0x86, 0x4 },
};

/*0x1602*/ const CO_OD_entryRecord_t OD_record1602[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[2].mappedObject8, 0x86, 0x4 },
};

/*0x1603*/ const CO_OD_entryRecord_t OD_record1603[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[3].mappedObject8, 0x86, 0x4 },
};

/*0x1604*/ const CO_OD_entryRecord_t OD_record1604[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[4].mappedObject8, 0x86, 0x4 },
};

/*0x1605*/ const CO_OD_entryRecord_t OD_record1605[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[5].mappedObject8, 0x86, 0x4 },
};

/*0x1606*/ const CO_OD_entryRecord_t OD_record1606[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[6].mappedObject8, 0x86, 0x4 },
};

/*0x1607*/ const CO_OD_entryRecord_t OD_record1607[9] = {
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.RPDOMappingParameter[7].mappedObject8, 0x86, 0x4 },
};

/*0x1800*/ const CO_OD_entryRecord_t OD_record1800[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].compatibilityEntry, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[0].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1801*/ const CO_OD_entryRecord_t OD_record1801[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[1].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[1].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[1].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[1].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[1].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[1].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[1].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1802*/ const CO_OD_entryRecord_t OD_record1802[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[2].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[2].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[2].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[2].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[2].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[2].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[2].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1803*/ const CO_OD_entryRecord_t OD_record1803[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[3].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[3].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[3].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[3].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[3].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[3].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[3].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1804*/ const CO_OD_entryRecord_t OD_record1804[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[4].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[4].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[4].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[4].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[4].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[4].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[4].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1805*/ const CO_OD_entryRecord_t OD_record1805[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[5].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[5].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[5].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[5].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[5].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[5].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[5].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1806*/ const CO_OD_entryRecord_t OD_record1806[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[6].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[6].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[6].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[6].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[6].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[6].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[6].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1807*/ const CO_OD_entryRecord_t OD_record1807[7] = {
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[7].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[7].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[7].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[7].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[7].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[7].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_RAM.TPDOCommunicationParameter[7].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1a00*/ const CO_OD_entryRecord_t OD_record1a00[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject1, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[0].mappedObject8, 0x86, 0x4 },
};

/*0x1a01*/ const CO_OD_entryRecord_t OD_record1a01[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[1].mappedObject8, 0x86, 0x4 },
};

/*0x1a02*/ const CO_OD_entryRecord_t OD_record1a02[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[2].mappedObject8, 0x86, 0x4 },
};

/*0x1a03*/ const CO_OD_entryRecord_t OD_record1a03[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[3].mappedObject8, 0x86, 0x4 },
};

/*0x1a04*/ const CO_OD_entryRecord_t OD_record1a04[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[4].mappedObject8, 0x86, 0x4 },
};

/*0x1a05*/ const CO_OD_entryRecord_t OD_record1a05[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[5].mappedObject8, 0x86, 0x4 },
};

/*0x1a06*/ const CO_OD_entryRecord_t OD_record1a06[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[6].mappedObject8, 0x86, 0x4 },
};

/*0x1a07*/ const CO_OD_entryRecord_t OD_record1a07[9] = {
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_RAM.TPDOMappingParameter[7].mappedObject8, 0x86, 0x4 },
};

/*******************************************************************************
   OBJECT DICTIONARY
*******************************************************************************/
const CO_OD_entry_t CO_OD[56] = {

{0x1000, 0x00, 0x86, 4, (void*)&CO_OD_RAM.deviceType},
{0x1001, 0x00, 0x06, 1, (void*)&CO_OD_RAM.errorRegister},
{0x1003, 0x08, 0x8e, 4, (void*)&CO_OD_RAM.preDefinedErrorField[0]},
{0x1005, 0x00, 0x86, 4, (void*)&CO_OD_RAM.COB_ID_SYNCMessage},
{0x1006, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.communicationCyclePeriod},
{0x1007, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.synchronousWindowLength},
{0x1008, 0x00, 0x06, 4, (void*)&CO_OD_RAM.manufacturerDeviceName},
{0x1009, 0x00, 0x06, 2, (void*)&CO_OD_RAM.manufacturerHardwareVersion},
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
{0x1401, 0x02, 0x00, 0, (void*)&OD_record1401},
{0x1402, 0x02, 0x00, 0, (void*)&OD_record1402},
{0x1403, 0x02, 0x00, 0, (void*)&OD_record1403},
{0x1404, 0x02, 0x00, 0, (void*)&OD_record1404},
{0x1405, 0x02, 0x00, 0, (void*)&OD_record1405},
{0x1406, 0x02, 0x00, 0, (void*)&OD_record1406},
{0x1407, 0x02, 0x00, 0, (void*)&OD_record1407},
{0x1600, 0x08, 0x00, 0, (void*)&OD_record1600},
{0x1601, 0x08, 0x00, 0, (void*)&OD_record1601},
{0x1602, 0x08, 0x00, 0, (void*)&OD_record1602},
{0x1603, 0x08, 0x00, 0, (void*)&OD_record1603},
{0x1604, 0x08, 0x00, 0, (void*)&OD_record1604},
{0x1605, 0x08, 0x00, 0, (void*)&OD_record1605},
{0x1606, 0x08, 0x00, 0, (void*)&OD_record1606},
{0x1607, 0x08, 0x00, 0, (void*)&OD_record1607},
{0x1800, 0x06, 0x00, 0, (void*)&OD_record1800},
{0x1801, 0x06, 0x00, 0, (void*)&OD_record1801},
{0x1802, 0x06, 0x00, 0, (void*)&OD_record1802},
{0x1803, 0x06, 0x00, 0, (void*)&OD_record1803},
{0x1804, 0x06, 0x00, 0, (void*)&OD_record1804},
{0x1805, 0x06, 0x00, 0, (void*)&OD_record1805},
{0x1806, 0x06, 0x00, 0, (void*)&OD_record1806},
{0x1807, 0x06, 0x00, 0, (void*)&OD_record1807},
{0x1a00, 0x08, 0x00, 0, (void*)&OD_record1a00},
{0x1a01, 0x08, 0x00, 0, (void*)&OD_record1a01},
{0x1a02, 0x08, 0x00, 0, (void*)&OD_record1a02},
{0x1a03, 0x08, 0x00, 0, (void*)&OD_record1a03},
{0x1a04, 0x08, 0x00, 0, (void*)&OD_record1a04},
{0x1a05, 0x08, 0x00, 0, (void*)&OD_record1a05},
{0x1a06, 0x08, 0x00, 0, (void*)&OD_record1a06},
{0x1a07, 0x08, 0x00, 0, (void*)&OD_record1a07},
{0x1f80, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.NMTStartup},
{0x2100, 0x00, 0x26, 10, (void*)&CO_OD_RAM.errorStatusBits},
{0x6000, 0x01, 0x3e, 1, (void*)&CO_OD_RAM.readInput8Bit[0]},
{0x6200, 0x01, 0x3e, 1, (void*)&CO_OD_RAM.writeOutput8Bit[0]},
{0x6401, 0x01, 0xbe, 2, (void*)&CO_OD_RAM.readAnalogueInput16Bit[0]},
{0x6403, 0x01, 0xbe, 4, (void*)&CO_OD_RAM.readAngle[0]},
{0x6f20, 0x01, 0x3e, 1, (void*)&CO_OD_RAM.lifeCounter[0]},
};
// clang-format on
