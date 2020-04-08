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

/*1400*/ {{0x2L, 0x019aL, 0xffL}},
/*1600*/ {{0x3L, 0x43000120L, 0x40030108L, 0x40040108L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L}},
/*1800*/ {{0x6L, 0x021aL, 0xffL, 0x00, 0x0L, 0x00, 0x0L}},
/*1a00*/ {{0x3L, 0x43000120L, 0x40030108L, 0x40040108L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L}},

           CO_OD_FIRST_LAST_WORD,
};


/***** Definition for RAM variables ********************************************/
struct sCO_OD_RAM CO_OD_RAM = {
           CO_OD_FIRST_LAST_WORD,

/*1000*/ 0xf0191L,
/*1001*/ 0x0L,
/*1003*/ {0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
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
/*1280*/ {{0x3L, 0x061aL, 0x059aL, 0x1bL}},
/*1f80*/ 0x0005L,
/*200a*/ {0x1L, 0x0000L},
/*2100*/ {0x0L},
/*4000*/ {0x13L, 0x0L, 0x0L, 0x00, 0x0000L, 0x0000L, 0x00},
/*4001*/ {0x21L, 0x00, 0x0000L, 0x0000L},
/*4002*/ {0x4L, 0x0000L, 0x00},
/*4003*/ {0x1L, 0x0L},
/*4004*/ {0x1L, 0x0L},
/*4010*/ {0x35L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L},
/*4014*/ {0x85L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L, 0x0L},
/*4020*/ {0x2L, 0x00, 0x00},
/*4023*/ {0x83L, 0x00, 0x00, 0x0000L, 0x0000L},
/*4024*/ {0x1L, 0x00},
/*402c*/ {0x1L, 0x0000L},
/*402e*/ {0xbL, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*402f*/ {0x5L, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*4031*/ {0x4L, 0x0000L, 0x00, 0x00, 0x00},
/*4032*/ {0x1L, 0x0000L},
/*4050*/ {0x1L, 0x00},
/*4051*/ {0x1L, 0x00},
/*4052*/ {0x1L, 0x00},
/*4055*/ {0x1L, 0x00},
/*4056*/ {0x1L, 0x00},
/*4057*/ {0x1L, 0x00},
/*4060*/ {0x1L, 0x00},
/*4080*/ {0x1L, 0x0L},
/*4090*/ {0x9L, 0x0000L, 0x0000L, 0xd2f0L},
/*4100*/ {0x1L, 0x00},
/*4108*/ {0x1L, 0x00},
/*410a*/ {0x1L, 0x00},
/*4110*/ {0x1L, 0x0000L},
/*4111*/ {0x1L, 0x0000L},
/*4112*/ {0x1L, 0x0000L},
/*4113*/ {0x1L, 0x0000L},
/*4114*/ {0x4L, 0x00, 0x00},
/*4120*/ {0x1L, 0x0L},
/*4128*/ {0x2L, 0x0L, 0x0L},
/*4150*/ {0x1L, 0x0L},
/*4154*/ {0x1L, 0xffL},
/*4200*/ {{0x1L, 0x0000L},
/*4260*/ {0x1L, 0x0000L}},
/*4261*/ {0x1L, 0x0000L},
/*4262*/ {0x2L, 0x0000L, 0x0000L},
/*4263*/ {0x1L, 0x0000L},
/*42a0*/ {0x11L, 0xc8, 0x1L},
/*4300*/ {0x1L, 0x0000L},
/*4302*/ {0x1L, 0x0001L},
/*4303*/ {0x1L, 0x0001L},
/*4304*/ {0x1L, 0x300},
/*4305*/ {0x1L, 0x03e8L},
/*430a*/ {0x1L, 0x0001L},
/*430b*/ {0x1L, 0x0001L},
/*4310*/ {0x8L, 0x64, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff},
/*4311*/ {0x8L, 0x00, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff},
/*4312*/ {0x8L, 0x00, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff},
/*4313*/ {0x8L, 0x2710, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff},
/*4314*/ {0x8L, 0x3e8, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff},
/*4315*/ {0x1L, 0x00},
/*4317*/ {0x1L, 0x00},
/*4318*/ {0x1L, 0x00},
/*4321*/ {0x1L, 0x7fffffffL},
/*4323*/ {0x1L, 0x7fffffffL},
/*4340*/ {0x1L, 0x03e8L},
/*4341*/ {0x1L, 0x03e8L},
/*4342*/ {0x1L, 0x03e8L},
/*4343*/ {0x1L, 0x03e8L},
/*4344*/ {0x1L, 0x03e8L},
/*4345*/ {0x1L, 0x0064L},
/*434c*/ {0x1L, 0x1L},
/*434d*/ {0x1L, 0x0L},
/*4350*/ {0x4L, 0x96a, 0x03e8L},
/*4380*/ {0x1L, 0x0000L},
/*4381*/ {0x1L, 0x0000L},
/*4382*/ {0x1L, 0x0000L},
/*43a0*/ {0x1L, 0x7d0},
/*43c0*/ {0x5L, 0x0L, 0xffffffffL, 0xffffffffL, 0x0a, 0x0L},
/*43d4*/ {0x1L, 0xffff},
/*4500*/ {0x1L, 0x00},
/*4502*/ {0x1L, 0x01},
/*4503*/ {0x1L, 0x01},
/*4504*/ {0x1L, 0x500},
/*4505*/ {0x1L, 0x03e8L},
/*4510*/ {0x1L, 0x64},
/*4511*/ {0x1L, 0x64},
/*4517*/ {0x1L, 0x00},
/*4550*/ {0x1L, 0x96a},
/*45a0*/ {0x1L, 0x18f},
/*45a1*/ {0x1L, 0x3fff},
/*4708*/ {0x1L, 0x0},
/*4720*/ {0x2L, 0x80000000L, 0x7fffffffL},
/*4732*/ {0x2L, 0x03e8L, 0xffffffffL},
/*4733*/ {0x2L, 0x00, 0xffff},
/*4735*/ {0x1L, 0x0L},
/*473a*/ {0x1L, 0xffffffffL},
/*473b*/ {0x2L, 0x00, 0xffff},
/*473c*/ {0x1L, 0x00},
/*474c*/ {0x1L, 0x1L},
/*474d*/ {0x1L, 0x0L},
/*4760*/ {0x1L, 0x0000L},
/*4761*/ {0x1L, 0x0000L},
/*4762*/ {0x1L, 0x0000L},
/*4763*/ {0x1L, 0x0000L},
/*4764*/ {0x1L, 0x0000L},
/*4770*/ {0x1L, 0x0000L},
/*4771*/ {0x1L, 0x0000L},
/*4772*/ {0x1L, 0x0000L},
/*4773*/ {0x1L, 0x0000L},
/*4774*/ {0x1L, 0x0000L},
/*4790*/ {0x1L, 0x0000L},
/*4791*/ {0x1L, 0x0000L},
/*47a4*/ {0x5L, 0x0000L, 0x0064L, 0x0064L, 0x0L},
/*47b0*/ {0x1L, 0x0L},
/*47b1*/ {0x5L, 0x0L, 0x00, 0x0L, 0x0000L, 0x0000L},
/*47b2*/ {0x1L, 0x0},
/*47b3*/ {0x2L, 0x0000L, 0x0000L},
/*47b4*/ {0x3L, 0x0000L, 0x0000L, 0x0000L},
/*47b5*/ {0x2L, 0xea60L, 0x0000L},
/*47b6*/ {0x2L, 0x7fffffffL, 0x00},
/*47b7*/ {0x12L, 0x0L, 0x000aL, 0xffffffffL, 0x1L, 0xffffffffL, 0xffffffffL, 0xffffffffL},
/*47c2*/ {0x7L, 0x0L, 0x07d0L, 0x00},
/*47c5*/ {0x1L, 0x00},
/*47c6*/ {0x1L, 0x0000L},
/*47c7*/ {0x3L, 0x0000L, 0x0000L, 0x0000L},
/*47c8*/ {0x1L, 0x0L},
/*47c9*/ {0x1L, 0x0001L},
/*4830*/ {0x5L, 0x61a8, 0x0L, 0x0},
/*4850*/ {0x3L, 0x0000L, 0x00},
/*48f3*/ {0x3L, 0x0L, 0x01, 0x0000L},
/*4900*/ {0x1L, 0x1L},
/*4901*/ {0x1L, 0xbb8},
/*4902*/ {0x1L, 0x5dc0},
/*4910*/ {0x1L, 0x8L},
/*4911*/ {0x1L, 0x0L},
/*4913*/ {0x1L, 0x1L},
/*4940*/ {0x1L, 0x0L},
/*4944*/ {0x3L, 0x0L, 0x0L, 0x0L},
/*4949*/ {0x4L, 0x0L, 0x0L, 0x0L, 0x01},
/*494a*/ {0x1L, 0x0000L},
/*4962*/ {0x1L, 0x00},
/*4963*/ {0x1L, 0x100},
/*496a*/ {0x1L, 0x0000L},
/*496b*/ {0x1L, 0x0000L},
/*496c*/ {0x1L, 0x00},
/*4970*/ {0x9L, 0x0L, 0x0L, 0x0000L},
/*4971*/ {0x2L, 0x0L, 0x0L},
/*4972*/ {0x1L, 0x0000L},
/*497a*/ {0x3L, 0x0000L, 0x0000L, 0x0000L},
/*497b*/ {0x1L, 0x0000L},
/*497c*/ {0x1L, 0x00},
/*49a0*/ {0x1bL, 0x0L, 0x0000L, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
/*49a2*/ {0x34L, 0x0L, 0x0L, 0x00, 0x00, 0x0000L, 0x0000L, 0x0000L, 0x0000L, 0x0000L},
/*4a02*/ {0x1L, 0x64},
/*4a04*/ {0x2L, 0x0000L, 0x0000L},
/*4b00*/ {0x2L, 0x1L, 0x0L},
/*4b10*/ {0x1L, 0x0L},
/*4b11*/ {0x1L, 0x0},
/*4b12*/ {0x1L, 0xb4L},
/*4b13*/ {0x1L, 0x0},
/*4b14*/ {0x1L, 0xa4L},
/*4b15*/ {0x1L, 0x0},
/*4b16*/ {0x1L, 0xb0L},
/*4b17*/ {0x2L, 0x0001L, 0x0001L},
/*4b18*/ {0x2L, 0x0001L, 0x0001L},
/*4b19*/ {0x2L, 0x0001L, 0x0001L},
/*4b1a*/ {0x2L, 0x0001L, 0x0001L},
/*6007*/ 0x00,
/*603f*/ 0x00,
/*6040*/ 0x00,
/*6041*/ 0x00,
/*6042*/ 0x00,
/*6043*/ 0x00,
/*6044*/ 0x00,
/*6046*/ {0x2L, 0x0000L, 0x7fffL},
/*6048*/ {0x2L, 0x03e8L, 0x01},
/*6049*/ {0x2L, 0x03e8L, 0x01},
/*604a*/ {0x2L, 0x2710L, 0x01},
/*604c*/ {0x2L, 0x0001L, 0x0001L},
/*605a*/ 0x02,
/*6060*/ 0x0,
/*6061*/ 0x0,
/*6062*/ 0x0000L,
/*6063*/ 0x0000L,
/*6064*/ 0x0000L,
/*6065*/ 0x0001L,
/*6066*/ 0x00,
/*6067*/ 0xffffffffL,
/*6068*/ 0x00,
/*606c*/ 0x0000L,
/*606d*/ 0x32,
/*606e*/ 0x00,
/*606f*/ 0x3fff,
/*6070*/ 0x14,
/*6071*/ 0x00,
/*6072*/ 0x00,
/*6075*/ 0x0000L,
/*6077*/ 0x00,
/*6078*/ 0x00,
/*6079*/ 0x0000L,
/*607a*/ 0x0000L,
/*607c*/ 0x0000L,
/*607d*/ {0x2L, 0x80000000L, 0x7fffffffL},
/*607e*/ 0x0L,
/*607f*/ 0xffffffffL,
/*6081*/ 0x0000L,
/*6083*/ 0xea60L,
/*6084*/ 0xea60L,
/*6085*/ 0x927c0L,
/*6086*/ 0x00,
/*6087*/ 0x0000L,
/*6088*/ 0xffff,
/*6089*/ 0x0,
/*608a*/ 0xb4L,
/*608b*/ 0x0,
/*608c*/ 0xa4L,
/*608d*/ 0x0,
/*608e*/ 0xb0L,
/*608f*/ {0x2L, 0x0001L, 0x0001L},
/*6090*/ {0x2L, 0x0001L, 0x0001L},
/*6091*/ {0x2L, 0x0001L, 0x0001L},
/*6092*/ {0x2L, 0x0001L, 0x0001L},
/*6098*/ 0x0,
/*6099*/ {0x2L, 0x0000L, 0x0000L},
/*609a*/ 0xea60L,
/*60c1*/ {0x1L, 0x0000L},
/*60c2*/ {0x2L, 0x2L, 0xfd},
/*60e0*/ 0x2710,
/*60e1*/ 0x2710,
/*60e3*/ {0x1fL, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0},
/*60f4*/ 0x0000L,
/*60fc*/ 0x0000L,
/*60fd*/ 0x0000L,
/*60fe*/ {0x2L, 0x0000L, 0x0000L},
/*60ff*/ 0x0000L,
/*6402*/ 0x8001,
/*6502*/ 0x0000L,
/*67fe*/ {0x3L, 0x0L, 0x1L, 0x1L},

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

/*0x1280*/ const CO_OD_entryRecord_t OD_record1280[4] = {
           {(void*)&CO_OD_RAM.SDOClientParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SDOClientParameter[0].COB_IDClientToServer, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.SDOClientParameter[0].COB_IDServerToClient, 0x8e, 0x4 },
           {(void*)&CO_OD_RAM.SDOClientParameter[0].nodeIDOfTheSDOServer, 0x0e, 0x1 },
};

/*0x1400*/ const CO_OD_entryRecord_t OD_record1400[3] = {
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[0].COB_IDUsedByRPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_ROM.RPDOCommunicationParameter[0].transmissionType, 0x0e, 0x1 },
};

/*0x1600*/ const CO_OD_entryRecord_t OD_record1600[9] = {
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.RPDOMappingParameter[0].mappedObject8, 0x86, 0x4 },
};

/*0x1800*/ const CO_OD_entryRecord_t OD_record1800[7] = {
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].maxSubIndex, 0x06, 0x1 },
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].COB_IDUsedByTPDO, 0x8e, 0x4 },
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].transmissionType, 0x0e, 0x1 },
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].inhibitTime, 0x8e, 0x2 },
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].compatibilityEntry, 0x06, 0x1 },
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].eventTimer, 0x8e, 0x2 },
           {(void*)&CO_OD_ROM.TPDOCommunicationParameter[0].SYNCStartValue, 0x0e, 0x1 },
};

/*0x1a00*/ const CO_OD_entryRecord_t OD_record1a00[9] = {
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].numberOfMappedObjects, 0x06, 0x1 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject1, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject2, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject3, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject4, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject5, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject6, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject7, 0x86, 0x4 },
           {(void*)&CO_OD_ROM.TPDOMappingParameter[0].mappedObject8, 0x86, 0x4 },
};

/*0x200a*/ const CO_OD_entryRecord_t OD_record200a[2] = {
           {(void*)&CO_OD_RAM.manufacturerSoftwareVersion.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.manufacturerSoftwareVersion.version, 0x86, 0x4 },
};

/*0x4000*/ const CO_OD_entryRecord_t OD_record4000[7] = {
           {(void*)&CO_OD_RAM.deviceCommand.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.deviceCommand.command, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.deviceCommand.quickStartDeviceCommand, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.deviceCommand.deviceCommandSetError, 0x9a, 0x2 },
           {(void*)&CO_OD_RAM.deviceCommand.quickStartDesiredValue0, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.deviceCommand.quickStartDesiredValue1, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.deviceCommand.quickStartDesiredValue0Int16, 0xbe, 0x2 },
};

/*0x4001*/ const CO_OD_entryRecord_t OD_record4001[4] = {
           {(void*)&CO_OD_RAM.manufacturerErrorRegister.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.manufacturerErrorRegister.error, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.manufacturerErrorRegister.warningRegister, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.manufacturerErrorRegister.warningConfiguration, 0xbe, 0x4 },
};

/*0x4002*/ const CO_OD_entryRecord_t OD_record4002[3] = {
           {(void*)&CO_OD_RAM.statusRegister.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.statusRegister.statusRegister, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.statusRegister.statusRegister16Bit, 0xa6, 0x2 },
};

/*0x4003*/ const CO_OD_entryRecord_t OD_record4003[2] = {
           {(void*)&CO_OD_RAM.deviceMode.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.deviceMode.deviceMode, 0x3e, 0x1 },
};

/*0x4004*/ const CO_OD_entryRecord_t OD_record4004[2] = {
           {(void*)&CO_OD_RAM.powerEnable.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.powerEnable.powerEnable, 0x3e, 0x1 },
};

/*0x4010*/ const CO_OD_entryRecord_t OD_record4010[10] = {
           {(void*)&CO_OD_RAM.reserved0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.reserved, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.eventOnError_cmd1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.eventOnError_cmd2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.eventOnError_cmd3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.eventOnError_cmd4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.commandsOnCommunicationErrorsCmd1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.commandsOnCommunicationErrorsCmd2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.commandsOnCommunicationErrorsCmd3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved0.commandsOnCommunicationErrorsCmd4, 0x3e, 0x1 },
};

/*0x4014*/ const CO_OD_entryRecord_t OD_record4014[34] = {
           {(void*)&CO_OD_RAM.reserved1.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.reserved, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand1Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand1Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand1Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand1Instruction4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand2Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand2Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand2Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand2Instruction4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand3Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand3Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand3Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand3Instruction4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand4Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand4Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand4Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand4Instruction4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand5Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand5Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand5Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand5Instruction4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand6Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand6Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand6Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand6Instruction4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand7Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand7Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand7Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand7Instruction4, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand8Instruction1, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand8Instruction2, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand8Instruction3, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved1.quickStartConfigurationUserCommand8Instruction4, 0x3e, 0x1 },
};

/*0x4020*/ const CO_OD_entryRecord_t OD_record4020[3] = {
           {(void*)&CO_OD_RAM.deviceCode.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.deviceCode.deviceCode, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.deviceCode.deviceSubcode, 0xa6, 0x2 },
};

/*0x4023*/ const CO_OD_entryRecord_t OD_record4023[5] = {
           {(void*)&CO_OD_RAM.motorSoftwareVersion.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorSoftwareVersion.softwareVersion, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.motorSoftwareVersion.softwareSubversion, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.motorSoftwareVersion.powerCardSoftwareVersion, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.motorSoftwareVersion.powerCardBootloaderVersion, 0xa6, 0x4 },
};

/*0x4024*/ const CO_OD_entryRecord_t OD_record4024[2] = {
           {(void*)&CO_OD_RAM.motorHardwareVersion.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorHardwareVersion.hardwareVersion, 0xa6, 0x2 },
};

/*0x402c*/ const CO_OD_entryRecord_t OD_record402c[2] = {
           {(void*)&CO_OD_RAM.freeData.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.freeData.freeData, 0xbe, 0x4 },
};

/*0x402e*/ const CO_OD_entryRecord_t OD_record402e[12] = {
           {(void*)&CO_OD_RAM.OEMDataCommand.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataCommand, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD0, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD1, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD2, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD3, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD4, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD5, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD6, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD7, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD8, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.OEMDataCommand.OEMDataD9, 0xbe, 0x4 },
};

/*0x402f*/ const CO_OD_entryRecord_t OD_record402f[6] = {
           {(void*)&CO_OD_RAM.userDataCommand.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.userDataCommand.userDataCommand, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.userDataCommand.userDataD0, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.userDataCommand.userDataD1, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.userDataCommand.userDataD2, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.userDataCommand.userDataD3, 0xbe, 0x4 },
};

/*0x4031*/ const CO_OD_entryRecord_t OD_record4031[5] = {
           {(void*)&CO_OD_RAM.maxPowerVoltage.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.maxPowerVoltage.maxPowerVoltage, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.maxPowerVoltage.minPowerVoltage, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.maxPowerVoltage.maxElectronicVoltage, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.maxPowerVoltage.minElectronicVoltage, 0xa6, 0x2 },
};

/*0x4032*/ const CO_OD_entryRecord_t OD_record4032[2] = {
           {(void*)&CO_OD_RAM.maxMotorCurrent.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.maxMotorCurrent.maxMotorCurrent, 0xa6, 0x4 },
};

/*0x4050*/ const CO_OD_entryRecord_t OD_record4050[2] = {
           {(void*)&CO_OD_RAM.inputAssignmentEnable.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.inputAssignmentEnable.inputAssignmentEnable, 0xbe, 0x2 },
};

/*0x4051*/ const CO_OD_entryRecord_t OD_record4051[2] = {
           {(void*)&CO_OD_RAM.inputAssignmentErrorQuitting.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.inputAssignmentErrorQuitting.inputAssignmentErrorQuitting, 0xbe, 0x2 },
};

/*0x4052*/ const CO_OD_entryRecord_t OD_record4052[2] = {
           {(void*)&CO_OD_RAM.inputAssignmentStartStop.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.inputAssignmentStartStop.inputAssignmentStartStop, 0xbe, 0x2 },
};

/*0x4055*/ const CO_OD_entryRecord_t OD_record4055[2] = {
           {(void*)&CO_OD_RAM.inputAssignmentPositiveLimitSwitch.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.inputAssignmentPositiveLimitSwitch.inputAssignmentPositiveLimitSwitch, 0xbe, 0x2 },
};

/*0x4056*/ const CO_OD_entryRecord_t OD_record4056[2] = {
           {(void*)&CO_OD_RAM.inputAssignmentNegativeLimitSwitch.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.inputAssignmentNegativeLimitSwitch.inputAssignmentNegativeLimitSwitch, 0xbe, 0x2 },
};

/*0x4057*/ const CO_OD_entryRecord_t OD_record4057[2] = {
           {(void*)&CO_OD_RAM.inputAssignmentReferenceSwitch.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.inputAssignmentReferenceSwitch.inputAssignmentReferenceSwitch, 0xbe, 0x2 },
};

/*0x4060*/ const CO_OD_entryRecord_t OD_record4060[2] = {
           {(void*)&CO_OD_RAM.outputAssignmentError.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.outputAssignmentError.outputAssignmentError, 0xbe, 0x2 },
};

/*0x4080*/ const CO_OD_entryRecord_t OD_record4080[2] = {
           {(void*)&CO_OD_RAM.continueMode.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.continueMode.continueMode, 0x3e, 0x1 },
};

/*0x4090*/ const CO_OD_entryRecord_t OD_record4090[4] = {
           {(void*)&CO_OD_RAM.minimumUpError.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.minimumUpError.minimumUpError, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.minimumUpError.ballastOnThreshold, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.minimumUpError.voltageControlledDeceleration, 0xbe, 0x4 },
};

/*0x4100*/ const CO_OD_entryRecord_t OD_record4100[2] = {
           {(void*)&CO_OD_RAM.analogueInput0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.analogueInput0.analogueInput0, 0xa6, 0x2 },
};

/*0x4108*/ const CO_OD_entryRecord_t OD_record4108[2] = {
           {(void*)&CO_OD_RAM.analogueIntputOffset.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.analogueIntputOffset.analogueIntputOffset, 0xbe, 0x2 },
};

/*0x410a*/ const CO_OD_entryRecord_t OD_record410a[2] = {
           {(void*)&CO_OD_RAM.analogueIntputDeadband.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.analogueIntputDeadband.analogueIntputDeadband, 0xbe, 0x2 },
};

/*0x4110*/ const CO_OD_entryRecord_t OD_record4110[2] = {
           {(void*)&CO_OD_RAM.electronicVoltageUe.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.electronicVoltageUe.electronicVoltageUe, 0xa6, 0x4 },
};

/*0x4111*/ const CO_OD_entryRecord_t OD_record4111[2] = {
           {(void*)&CO_OD_RAM.powerVoltageUp.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.powerVoltageUp.powerVoltageUp, 0xa6, 0x4 },
};

/*0x4112*/ const CO_OD_entryRecord_t OD_record4112[2] = {
           {(void*)&CO_OD_RAM.motorVoltageUm.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorVoltageUm.motorVoltageUm, 0xa6, 0x4 },
};

/*0x4113*/ const CO_OD_entryRecord_t OD_record4113[2] = {
           {(void*)&CO_OD_RAM.motorCurrentIm.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorCurrentIm.motorCurrentIm, 0xa6, 0x4 },
};

/*0x4114*/ const CO_OD_entryRecord_t OD_record4114[3] = {
           {(void*)&CO_OD_RAM.temperatureOfPowerAmplifier.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.temperatureOfPowerAmplifier.temperatureOfPowerAmplifier, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.temperatureOfPowerAmplifier.temperatureOfMotor, 0xa6, 0x2 },
};

/*0x4120*/ const CO_OD_entryRecord_t OD_record4120[2] = {
           {(void*)&CO_OD_RAM.digitalInputsPort0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.digitalInputsPort0.digitalInputsPort0, 0x26, 0x1 },
};

/*0x4128*/ const CO_OD_entryRecord_t OD_record4128[3] = {
           {(void*)&CO_OD_RAM.digitalInputsHallSensors.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.digitalInputsHallSensors.digitalInputsHallSensors, 0x26, 0x1 },
           {(void*)&CO_OD_RAM.digitalInputsHallSensors.digitalInputsEncoder, 0x26, 0x1 },
};

/*0x4150*/ const CO_OD_entryRecord_t OD_record4150[2] = {
           {(void*)&CO_OD_RAM.digitalOutputsPort0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.digitalOutputsPort0.digitalOutputsPort0, 0x3e, 0x1 },
};

/*0x4154*/ const CO_OD_entryRecord_t OD_record4154[2] = {
           {(void*)&CO_OD_RAM.enableDigitalOutputs.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.enableDigitalOutputs.enableDigitalOutputs, 0x3e, 0x1 },
};

/*0x4200*/ const CO_OD_entryRecord_t OD_record4200[2] = {
           {(void*)&CO_OD_RAM.currentDesiredValue[0].numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.currentDesiredValue[0].currentDesiredValue, 0xbe, 0x4 },
};

/*0x4260*/ const CO_OD_entryRecord_t OD_record4260[2] = {
           {(void*)&CO_OD_RAM.currentDesiredValue[1].numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.currentDesiredValue[1].currentDesiredValue, 0xa6, 0x4 },
};

/*0x4261*/ const CO_OD_entryRecord_t OD_record4261[2] = {
           {(void*)&CO_OD_RAM.currentCommandedValue.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.currentCommandedValue.currentCommandedValue, 0xa6, 0x4 },
};

/*0x4262*/ const CO_OD_entryRecord_t OD_record4262[3] = {
           {(void*)&CO_OD_RAM.currentActualValue0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.currentActualValue0.currentActualValue, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.currentActualValue0.currentActualFilteredValue, 0xa6, 0x4 },
};

/*0x4263*/ const CO_OD_entryRecord_t OD_record4263[2] = {
           {(void*)&CO_OD_RAM.currentFollowingError.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.currentFollowingError.currentFollowingError, 0xa6, 0x4 },
};

/*0x42a0*/ const CO_OD_entryRecord_t OD_record42a0[3] = {
           {(void*)&CO_OD_RAM.currentControllerSampleTime.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.currentControllerSampleTime.currentControllerSampleTime, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.currentControllerSampleTime.currentActualFilteredValueFilterLevel, 0x3e, 0x1 },
};

/*0x4300*/ const CO_OD_entryRecord_t OD_record4300[2] = {
           {(void*)&CO_OD_RAM.velocityDesiredValue.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDesiredValue.velocityDesiredValue, 0xbe, 0x4 },
};

/*0x4302*/ const CO_OD_entryRecord_t OD_record4302[2] = {
           {(void*)&CO_OD_RAM.velocityScaleFactorNumerator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityScaleFactorNumerator.velocityScaleFactorNumerator, 0xbe, 0x4 },
};

/*0x4303*/ const CO_OD_entryRecord_t OD_record4303[2] = {
           {(void*)&CO_OD_RAM.velocityScaleFactorDenominator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityScaleFactorDenominator.velocityScaleFactorDenominator, 0xbe, 0x4 },
};

/*0x4304*/ const CO_OD_entryRecord_t OD_record4304[2] = {
           {(void*)&CO_OD_RAM.velocitySource.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocitySource.velocitySource, 0xbe, 0x2 },
};

/*0x4305*/ const CO_OD_entryRecord_t OD_record4305[2] = {
           {(void*)&CO_OD_RAM.velocityReferenceValue.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityReferenceValue.velocityReferenceValue, 0xbe, 0x4 },
};

/*0x430a*/ const CO_OD_entryRecord_t OD_record430a[2] = {
           {(void*)&CO_OD_RAM.velocityDimensionFactorNumerator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDimensionFactorNumerator.velocityDimensionFactorNumerator, 0xbe, 0x4 },
};

/*0x430b*/ const CO_OD_entryRecord_t OD_record430b[2] = {
           {(void*)&CO_OD_RAM.velocityDimensionFactorDenominator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDimensionFactorDenominator.velocityDimensionFactorDenominator, 0xbe, 0x4 },
};

/*0x4310*/ const CO_OD_entryRecord_t OD_record4310[9] = {
           {(void*)&CO_OD_RAM.PID_ControllerGain.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGain, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGainAtStandstill, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGainAtAccelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGainAtConstantVelocityInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGainAtDecelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGainAtAccelerationInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGainAtConstantVelocityInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerGain.PID_ControllerGainAtDecelerationInNegativeDirection, 0xbe, 0x2 },
};

/*0x4311*/ const CO_OD_entryRecord_t OD_record4311[9] = {
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactor, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactorAtStandstill, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactorAtAccelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactorAtConstantVelocityInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactorAtDecelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactorAtAccelerationInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactorAtConstantVelocityInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralFactor.PID_ControllerIntegralFactorAtDecelerationInNegativeDirection, 0xbe, 0x2 },
};

/*0x4312*/ const CO_OD_entryRecord_t OD_record4312[9] = {
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactor, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactorAtStandstill, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactorAtAccelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactorAtConstantVelocityInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactorAtDecelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactorAtAccelerationInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactorAtConstantVelocityInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialFactor.PID_ControllerDifferentialFactorAtDecelerationInNegativeDirection, 0xbe, 0x2 },
};

/*0x4313*/ const CO_OD_entryRecord_t OD_record4313[9] = {
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimit, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimitAtStandstill, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimitAtAccelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimitAtConstantVelocityInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimitAtDecelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimitAtAccelerationInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimitAtConstantVelocityInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerIntegralLimit.PID_ControllerIntegralLimitAtDecelerationInNegativeDirection, 0xbe, 0x2 },
};

/*0x4314*/ const CO_OD_entryRecord_t OD_record4314[9] = {
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForward, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForwardAtStandstill, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForwardAtAccelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForwardAtConstantVelocityInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForwardAtDecelerationInPositiveDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForwardAtAccelerationInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForwardConstantVelocityInNegativeDirection, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForward.PID_ControllerVelocityFeedForwardAtDecelerationInNegativeDirection, 0xbe, 0x2 },
};

/*0x4315*/ const CO_OD_entryRecord_t OD_record4315[2] = {
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForwardAcceleration.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PID_ControllerVelocityFeedForwardAcceleration.PID_ControllerVelocityFeedForwardAcceleration, 0xbe, 0x2 },
};

/*0x4317*/ const CO_OD_entryRecord_t OD_record4317[2] = {
           {(void*)&CO_OD_RAM.ixR_Factor.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.ixR_Factor.ixR_Factor, 0xbe, 0x2 },
};

/*0x4318*/ const CO_OD_entryRecord_t OD_record4318[2] = {
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialSampleTime.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PID_ControllerDifferentialSampleTime.PID_ControllerDifferentialSampleTime, 0xbe, 0x2 },
};

/*0x4321*/ const CO_OD_entryRecord_t OD_record4321[2] = {
           {(void*)&CO_OD_RAM.velocityMaxLimitPositiveDirection.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityMaxLimitPositiveDirection.velocityMaxLimitPositiveDirection, 0xbe, 0x4 },
};

/*0x4323*/ const CO_OD_entryRecord_t OD_record4323[2] = {
           {(void*)&CO_OD_RAM.velocityMaxLimitNegativeDirection.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityMaxLimitNegativeDirection.velocityMaxLimitNegativeDirection, 0xbe, 0x4 },
};

/*0x4340*/ const CO_OD_entryRecord_t OD_record4340[2] = {
           {(void*)&CO_OD_RAM.velocityAccelerationDeltav.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityAccelerationDeltav.velocityAccelerationDeltav, 0xbe, 0x4 },
};

/*0x4341*/ const CO_OD_entryRecord_t OD_record4341[2] = {
           {(void*)&CO_OD_RAM.velocityAccelerationDeltat.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityAccelerationDeltat.velocityAccelerationDeltat, 0xbe, 0x4 },
};

/*0x4342*/ const CO_OD_entryRecord_t OD_record4342[2] = {
           {(void*)&CO_OD_RAM.velocityDecelerationDeltav.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDecelerationDeltav.velocityDecelerationDeltav, 0xbe, 0x4 },
};

/*0x4343*/ const CO_OD_entryRecord_t OD_record4343[2] = {
           {(void*)&CO_OD_RAM.velocityDecelerationDeltat.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDecelerationDeltat.velocityDecelerationDeltat, 0xbe, 0x4 },
};

/*0x4344*/ const CO_OD_entryRecord_t OD_record4344[2] = {
           {(void*)&CO_OD_RAM.velocityDecelerationQuickStopDeltav.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDecelerationQuickStopDeltav.velocityDecelerationQuickStopDeltav, 0xbe, 0x4 },
};

/*0x4345*/ const CO_OD_entryRecord_t OD_record4345[2] = {
           {(void*)&CO_OD_RAM.velocityDecelerationQuickStopDeltat.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDecelerationQuickStopDeltat.velocityDecelerationQuickStopDeltat, 0xbe, 0x4 },
};

/*0x434c*/ const CO_OD_entryRecord_t OD_record434c[2] = {
           {(void*)&CO_OD_RAM.velocityRampGeneratorRampType.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityRampGeneratorRampType.velocityRampGeneratorRampType, 0x3e, 0x1 },
};

/*0x434d*/ const CO_OD_entryRecord_t OD_record434d[2] = {
           {(void*)&CO_OD_RAM.velocityRampGeneratorState.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityRampGeneratorState.velocityRampGeneratorState, 0x26, 0x1 },
};

/*0x4350*/ const CO_OD_entryRecord_t OD_record4350[3] = {
           {(void*)&CO_OD_RAM.velocityFeedback.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityFeedback.velocityFeedback, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.velocityFeedback.velocityFeedbackReference, 0xbe, 0x4 },
};

/*0x4380*/ const CO_OD_entryRecord_t OD_record4380[2] = {
           {(void*)&CO_OD_RAM.velocityAccelerationInRevMin2.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityAccelerationInRevMin2.velocityAccelerationInRevMin2, 0xbe, 0x4 },
};

/*0x4381*/ const CO_OD_entryRecord_t OD_record4381[2] = {
           {(void*)&CO_OD_RAM.velocityDecelerationInRevMin2.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityDecelerationInRevMin2.velocityDecelerationInRevMin2, 0xbe, 0x4 },
};

/*0x4382*/ const CO_OD_entryRecord_t OD_record4382[2] = {
           {(void*)&CO_OD_RAM.velocityQuickStopDecelerationInRevMin2.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityQuickStopDecelerationInRevMin2.velocityQuickStopDecelerationInRevMin2, 0xbe, 0x4 },
};

/*0x43a0*/ const CO_OD_entryRecord_t OD_record43a0[2] = {
           {(void*)&CO_OD_RAM.velocityPositionControllerSampleTime.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityPositionControllerSampleTime.velocityPositionControllerSampleTime, 0xbe, 0x2 },
};

/*0x43c0*/ const CO_OD_entryRecord_t OD_record43c0[6] = {
           {(void*)&CO_OD_RAM.blockageGuardingConfigurationFlags.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.blockageGuardingConfigurationFlags.blockageGuardingConfigurationFlags, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.blockageGuardingConfigurationFlags.blockageGuardingLowVelocity, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.blockageGuardingConfigurationFlags.blockageGuardingHighVelocity, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.blockageGuardingConfigurationFlags.blockageGuardingTime, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.blockageGuardingConfigurationFlags.blockageGuardingStatus, 0x3e, 0x1 },
};

/*0x43d4*/ const CO_OD_entryRecord_t OD_record43d4[2] = {
           {(void*)&CO_OD_RAM.outputRampgenerator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.outputRampgenerator.outputRampgenerator, 0xa6, 0x2 },
};

/*0x4500*/ const CO_OD_entryRecord_t OD_record4500[2] = {
           {(void*)&CO_OD_RAM.SVelDesiredValue.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelDesiredValue.SVelDesiredValue, 0xbe, 0x2 },
};

/*0x4502*/ const CO_OD_entryRecord_t OD_record4502[2] = {
           {(void*)&CO_OD_RAM.SVelScaleFactorNumerator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelScaleFactorNumerator.SVelScaleFactorNumerator, 0xbe, 0x2 },
};

/*0x4503*/ const CO_OD_entryRecord_t OD_record4503[2] = {
           {(void*)&CO_OD_RAM.SVelScaleFactorDenominator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelScaleFactorDenominator.SVelScaleFactorDenominator, 0xbe, 0x2 },
};

/*0x4504*/ const CO_OD_entryRecord_t OD_record4504[2] = {
           {(void*)&CO_OD_RAM.SVelSourceOfDesiredValue.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelSourceOfDesiredValue.SVelSourceOfDesiredValue, 0xbe, 0x2 },
};

/*0x4505*/ const CO_OD_entryRecord_t OD_record4505[2] = {
           {(void*)&CO_OD_RAM.SVelReferenceValue.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelReferenceValue.SVelReferenceValue, 0xbe, 0x4 },
};

/*0x4510*/ const CO_OD_entryRecord_t OD_record4510[2] = {
           {(void*)&CO_OD_RAM.SVelPI_ControllerGain.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelPI_ControllerGain.SVelPI_ControllerGain, 0xbe, 0x2 },
};

/*0x4511*/ const CO_OD_entryRecord_t OD_record4511[2] = {
           {(void*)&CO_OD_RAM.SVelPI_ControllerIntegralFactor.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelPI_ControllerIntegralFactor.SVelPI_ControllerIntegralFactor, 0xbe, 0x2 },
};

/*0x4517*/ const CO_OD_entryRecord_t OD_record4517[2] = {
           {(void*)&CO_OD_RAM.SVelIxR_Factor.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelIxR_Factor.SVelIxR_Factor, 0xbe, 0x2 },
};

/*0x4550*/ const CO_OD_entryRecord_t OD_record4550[2] = {
           {(void*)&CO_OD_RAM.SVelFeedback.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelFeedback.SVelFeedback, 0xbe, 0x2 },
};

/*0x45a0*/ const CO_OD_entryRecord_t OD_record45a0[2] = {
           {(void*)&CO_OD_RAM.SVelSampleTime.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelSampleTime.SVelSampleTime, 0xa6, 0x2 },
};

/*0x45a1*/ const CO_OD_entryRecord_t OD_record45a1[2] = {
           {(void*)&CO_OD_RAM.SVelVelocityScalingResolution.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SVelVelocityScalingResolution.SVelVelocityScalingResolution, 0xbe, 0x2 },
};

/*0x4708*/ const CO_OD_entryRecord_t OD_record4708[2] = {
           {(void*)&CO_OD_RAM.positionMode.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionMode.positionMode, 0x3e, 0x1 },
};

/*0x4720*/ const CO_OD_entryRecord_t OD_record4720[3] = {
           {(void*)&CO_OD_RAM.positionLimitMinimum.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionLimitMinimum.positionLimitMinimum, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.positionLimitMinimum.positionLimitMaximum, 0xbe, 0x4 },
};

/*0x4732*/ const CO_OD_entryRecord_t OD_record4732[3] = {
           {(void*)&CO_OD_RAM.positionFollowingErrorWindow.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionFollowingErrorWindow.positionFollowingErrorWindow, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.positionFollowingErrorWindow.positionFollowingErrorWindowDynamic, 0xbe, 0x4 },
};

/*0x4733*/ const CO_OD_entryRecord_t OD_record4733[3] = {
           {(void*)&CO_OD_RAM.positionFollowingErrorTime.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionFollowingErrorTime.positionFollowingErrorTime, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.positionFollowingErrorTime.positionFollowingErrorTimeDynamic, 0xbe, 0x2 },
};

/*0x4735*/ const CO_OD_entryRecord_t OD_record4735[2] = {
           {(void*)&CO_OD_RAM.deactivatingOfFollowingErrorCorrection.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.deactivatingOfFollowingErrorCorrection.deactivatingOfFollowingErrorCorrection, 0x3e, 0x1 },
};

/*0x473a*/ const CO_OD_entryRecord_t OD_record473a[2] = {
           {(void*)&CO_OD_RAM.positionWindow0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionWindow0.positionWindow, 0xbe, 0x4 },
};

/*0x473b*/ const CO_OD_entryRecord_t OD_record473b[3] = {
           {(void*)&CO_OD_RAM.positionWindowTime0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionWindowTime0.positionWindowTime, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.positionWindowTime0.positionWindowTimeout, 0xbe, 0x2 },
};

/*0x473c*/ const CO_OD_entryRecord_t OD_record473c[2] = {
           {(void*)&CO_OD_RAM.positionReachedConfigurationBits.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionReachedConfigurationBits.positionReachedConfigurationBits, 0xbe, 0x2 },
};

/*0x474c*/ const CO_OD_entryRecord_t OD_record474c[2] = {
           {(void*)&CO_OD_RAM.positionRampGeneratorRampType.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionRampGeneratorRampType.positionRampGeneratorRampType, 0x3e, 0x1 },
};

/*0x474d*/ const CO_OD_entryRecord_t OD_record474d[2] = {
           {(void*)&CO_OD_RAM.positionRampGeneratorState.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionRampGeneratorState.positionRampGeneratorState, 0x3e, 0x1 },
};

/*0x4760*/ const CO_OD_entryRecord_t OD_record4760[2] = {
           {(void*)&CO_OD_RAM.actualTargetPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualTargetPosition.actualTargetPosition, 0xa6, 0x4 },
};

/*0x4761*/ const CO_OD_entryRecord_t OD_record4761[2] = {
           {(void*)&CO_OD_RAM.actualCommandPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualCommandPosition.actualCommandPosition, 0xa6, 0x4 },
};

/*0x4762*/ const CO_OD_entryRecord_t OD_record4762[2] = {
           {(void*)&CO_OD_RAM.actualPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualPosition.actualPosition, 0xbe, 0x4 },
};

/*0x4763*/ const CO_OD_entryRecord_t OD_record4763[2] = {
           {(void*)&CO_OD_RAM.actualPositionFollowingError.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualPositionFollowingError.actualPositionFollowingError, 0xa6, 0x4 },
};

/*0x4764*/ const CO_OD_entryRecord_t OD_record4764[2] = {
           {(void*)&CO_OD_RAM.actualPositionOfIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualPositionOfIndex.actualPositionOfIndex, 0xa6, 0x4 },
};

/*0x4770*/ const CO_OD_entryRecord_t OD_record4770[2] = {
           {(void*)&CO_OD_RAM.actualTargetPositionInIncrements.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualTargetPositionInIncrements.actualTargetPositionInIncrements, 0xa6, 0x4 },
};

/*0x4771*/ const CO_OD_entryRecord_t OD_record4771[2] = {
           {(void*)&CO_OD_RAM.actualCommandPositionInIncrements.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualCommandPositionInIncrements.actualCommandPositionInIncrements, 0xa6, 0x4 },
};

/*0x4772*/ const CO_OD_entryRecord_t OD_record4772[2] = {
           {(void*)&CO_OD_RAM.actualPositionInIncrements.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualPositionInIncrements.actualPositionInIncrements, 0xbe, 0x4 },
};

/*0x4773*/ const CO_OD_entryRecord_t OD_record4773[2] = {
           {(void*)&CO_OD_RAM.actualFollowingErrorInIncrements.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualFollowingErrorInIncrements.actualFollowingErrorInIncrements, 0xa6, 0x4 },
};

/*0x4774*/ const CO_OD_entryRecord_t OD_record4774[2] = {
           {(void*)&CO_OD_RAM.actualIndexPositionInIncrements.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualIndexPositionInIncrements.actualIndexPositionInIncrements, 0xa6, 0x4 },
};

/*0x4790*/ const CO_OD_entryRecord_t OD_record4790[2] = {
           {(void*)&CO_OD_RAM.absolutePositioning.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.absolutePositioning.absolutePositioning, 0x9a, 0x4 },
};

/*0x4791*/ const CO_OD_entryRecord_t OD_record4791[2] = {
           {(void*)&CO_OD_RAM.relativePositioning.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.relativePositioning.relativePositioning, 0x9a, 0x4 },
};

/*0x47a4*/ const CO_OD_entryRecord_t OD_record47a4[5] = {
           {(void*)&CO_OD_RAM.gearBackLashPath.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.gearBackLashPath.gearBackLashPath, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.gearBackLashPath.gearBackLashVelocity, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.gearBackLashPath.gearBackLashAccelerationDeceleration, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.gearBackLashPath.gearBackLashDoItInAllDirection, 0x3e, 0x1 },
};

/*0x47b0*/ const CO_OD_entryRecord_t OD_record47b0[2] = {
           {(void*)&CO_OD_RAM.homingCommand.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingCommand.homingCommand, 0x1a, 0x1 },
};

/*0x47b1*/ const CO_OD_entryRecord_t OD_record47b1[6] = {
           {(void*)&CO_OD_RAM.homingStatus.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingStatus.homingStatus, 0x26, 0x1 },
           {(void*)&CO_OD_RAM.homingStatus.homingError, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.homingStatus.homingState, 0x26, 0x1 },
           {(void*)&CO_OD_RAM.homingStatus.homingPathOfReferenceSwitchToIndex, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.homingStatus.homingPathOfReferenceSwitchToIndexInCounts, 0xa6, 0x4 },
};

/*0x47b2*/ const CO_OD_entryRecord_t OD_record47b2[2] = {
           {(void*)&CO_OD_RAM.homingMethod0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingMethod0.homingMethod, 0x3e, 0x1 },
};

/*0x47b3*/ const CO_OD_entryRecord_t OD_record47b3[3] = {
           {(void*)&CO_OD_RAM.homingOffset.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingOffset.homingOffset, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingOffset.homingOffsetMoveToZero, 0xbe, 0x4 },
};

/*0x47b4*/ const CO_OD_entryRecord_t OD_record47b4[4] = {
           {(void*)&CO_OD_RAM.homingVelocitySearchingTheSwitch.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingVelocitySearchingTheSwitch.homingVelocitySearchingTheSwitch, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingVelocitySearchingTheSwitch.homingVelocitySearchingTheZeroPosition, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingVelocitySearchingTheSwitch.homingVelocityMoveFromOffsetToZeroPosition, 0xbe, 0x4 },
};

/*0x47b5*/ const CO_OD_entryRecord_t OD_record47b5[3] = {
           {(void*)&CO_OD_RAM.homingAcceleration0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingAcceleration0.homingAcceleration, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingAcceleration0.homingDeceleration, 0xbe, 0x4 },
};

/*0x47b6*/ const CO_OD_entryRecord_t OD_record47b6[3] = {
           {(void*)&CO_OD_RAM.homingMaxPathForSearchingTheIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingMaxPathForSearchingTheIndex.homingMaxPathForSearchingTheIndex, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingMaxPathForSearchingTheIndex.homingIndexOffset, 0xbe, 0x2 },
};

/*0x47b7*/ const CO_OD_entryRecord_t OD_record47b7[8] = {
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.homingOnBlockageConfigurationFlags, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.homingOnBlockageLowVelocity, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.homingOnBlockageHighVelocity, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.homingOnBlockageTime, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.homingOnBlockageFollowingErrorWindow, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.homingOnBlockageCurrentLimitMaxPositive, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingOnBlockageConfigurationFlags.homingOnBlockageCurrentLimitMaxNegative, 0xbe, 0x4 },
};

/*0x47c2*/ const CO_OD_entryRecord_t OD_record47c2[4] = {
           {(void*)&CO_OD_RAM.interpolationMethod.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.interpolationMethod.interpolationMethod, 0x26, 0x1 },
           {(void*)&CO_OD_RAM.interpolationMethod.interpolationTime, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.interpolationMethod.interpolationDelay, 0xbe, 0x2 },
};

/*0x47c5*/ const CO_OD_entryRecord_t OD_record47c5[2] = {
           {(void*)&CO_OD_RAM.interpolationBufferConfiguration.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.interpolationBufferConfiguration.interpolationBufferConfiguration, 0xbe, 0x2 },
};

/*0x47c6*/ const CO_OD_entryRecord_t OD_record47c6[2] = {
           {(void*)&CO_OD_RAM.interpolationData.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.interpolationData.interpolationData, 0xbe, 0x4 },
};

/*0x47c7*/ const CO_OD_entryRecord_t OD_record47c7[4] = {
           {(void*)&CO_OD_RAM.interpolationActualTargetPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.interpolationActualTargetPosition.interpolationActualTargetPosition, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.interpolationActualTargetPosition.interpolationActualCommandPosition, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.interpolationActualTargetPosition.interpolationActualPosition, 0xa6, 0x4 },
};

/*0x47c8*/ const CO_OD_entryRecord_t OD_record47c8[2] = {
           {(void*)&CO_OD_RAM.moduloMethod.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.moduloMethod.moduloMethod, 0x3e, 0x1 },
};

/*0x47c9*/ const CO_OD_entryRecord_t OD_record47c9[2] = {
           {(void*)&CO_OD_RAM.moduloValue.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.moduloValue.moduloValue, 0xbe, 0x4 },
};

/*0x4830*/ const CO_OD_entryRecord_t OD_record4830[4] = {
           {(void*)&CO_OD_RAM.PWM_Frequency.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.PWM_Frequency.PWM_Frequency, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.PWM_Frequency.PWM_Mode, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.PWM_Frequency.PWM_ControlValue, 0x26, 0x1 },
};

/*0x4850*/ const CO_OD_entryRecord_t OD_record4850[3] = {
           {(void*)&CO_OD_RAM.systemClock.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.systemClock.systemClock, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.systemClock.systemTimer2ms, 0xbe, 0x2 },
};

/*0x48f3*/ const CO_OD_entryRecord_t OD_record48f3[4] = {
           {(void*)&CO_OD_RAM.SSI_InterfaceConfiguration.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SSI_InterfaceConfiguration.SSI_InterfaceConfiguration, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.SSI_InterfaceConfiguration.SSI_InterfaceEnocderDivider, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.SSI_InterfaceConfiguration.SSI_InterfaceCounter, 0xbe, 0x4 },
};

/*0x4900*/ const CO_OD_entryRecord_t OD_record4900[2] = {
           {(void*)&CO_OD_RAM.motorType0.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorType0.motorType, 0x3e, 0x1 },
};

/*0x4901*/ const CO_OD_entryRecord_t OD_record4901[2] = {
           {(void*)&CO_OD_RAM.motorRatedSpeed.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorRatedSpeed.motorRatedSpeed, 0xbe, 0x2 },
};

/*0x4902*/ const CO_OD_entryRecord_t OD_record4902[2] = {
           {(void*)&CO_OD_RAM.motorRatedVoltage.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorRatedVoltage.motorRatedVoltage, 0xbe, 0x2 },
};

/*0x4910*/ const CO_OD_entryRecord_t OD_record4910[2] = {
           {(void*)&CO_OD_RAM.motorNumberOfPoles.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorNumberOfPoles.motorNumberOfPoles, 0x3e, 0x1 },
};

/*0x4911*/ const CO_OD_entryRecord_t OD_record4911[2] = {
           {(void*)&CO_OD_RAM.motorPolarity.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorPolarity.motorPolarity, 0x3e, 0x1 },
};

/*0x4913*/ const CO_OD_entryRecord_t OD_record4913[2] = {
           {(void*)&CO_OD_RAM.motorCommutationType.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.motorCommutationType.motorCommutationType, 0x26, 0x1 },
};

/*0x4940*/ const CO_OD_entryRecord_t OD_record4940[2] = {
           {(void*)&CO_OD_RAM.hallSensorType.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.hallSensorType.hallSensorType, 0x3e, 0x1 },
};

/*0x4944*/ const CO_OD_entryRecord_t OD_record4944[4] = {
           {(void*)&CO_OD_RAM.reserved.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.reserved.reserved, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved.hallDiagnosticsWrongPulses, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.reserved.hallDiagnosticsWrongOrder, 0x3e, 0x1 },
};

/*0x4949*/ const CO_OD_entryRecord_t OD_record4949[5] = {
           {(void*)&CO_OD_RAM.hallPulsesConfigurationFlags.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.hallPulsesConfigurationFlags.hallPulsesConfigurationFlags, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.hallPulsesConfigurationFlags.hallPulsesBitMaskForOutputA, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.hallPulsesConfigurationFlags.hallPulsesBitMaskForOutputB, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.hallPulsesConfigurationFlags.hallPulsesModuloValue, 0xbe, 0x2 },
};

/*0x494a*/ const CO_OD_entryRecord_t OD_record494a[2] = {
           {(void*)&CO_OD_RAM.actualHallPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualHallPosition.actualHallPosition, 0xbe, 0x4 },
};

/*0x4962*/ const CO_OD_entryRecord_t OD_record4962[2] = {
           {(void*)&CO_OD_RAM.encoderResolutionInCounts.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.encoderResolutionInCounts.encoderResolutionInCounts, 0xbe, 0x2 },
};

/*0x4963*/ const CO_OD_entryRecord_t OD_record4963[2] = {
           {(void*)&CO_OD_RAM.encoderResolutionInLines.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.encoderResolutionInLines.encoderResolutionInLines, 0xbe, 0x2 },
};

/*0x496a*/ const CO_OD_entryRecord_t OD_record496a[2] = {
           {(void*)&CO_OD_RAM.actualEncoderPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualEncoderPosition.actualEncoderPosition, 0xbe, 0x4 },
};

/*0x496b*/ const CO_OD_entryRecord_t OD_record496b[2] = {
           {(void*)&CO_OD_RAM.actualEncoderIndexPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.actualEncoderIndexPosition.actualEncoderIndexPosition, 0xa6, 0x4 },
};

/*0x496c*/ const CO_OD_entryRecord_t OD_record496c[2] = {
           {(void*)&CO_OD_RAM.countsIndexPulses.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.countsIndexPulses.countsIndexPulses, 0xbe, 0x2 },
};

/*0x4970*/ const CO_OD_entryRecord_t OD_record4970[4] = {
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderEnable.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderEnable.SSI_AbsoluteEncoderEnable, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderEnable.SSI_AbsoluteEncoderStatus, 0x26, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderEnable.SSI_AbsoluteEncoderSave, 0x9a, 0x4 },
};

/*0x4971*/ const CO_OD_entryRecord_t OD_record4971[3] = {
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderCode.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderCode.SSI_AbsoluteEncoderCode, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderCode.SSI_AbsoluteEncoderTotalResolutionInBits, 0x3e, 0x1 },
};

/*0x4972*/ const CO_OD_entryRecord_t OD_record4972[2] = {
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderSingleTurnResolutionInCounts.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderSingleTurnResolutionInCounts.SSI_AbsoluteEncoderSingleTurnResolutionInCounts, 0xbe, 0x4 },
};

/*0x497a*/ const CO_OD_entryRecord_t OD_record497a[4] = {
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderActualPositionExtendedOn32Bits.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderActualPositionExtendedOn32Bits.SSI_AbsoluteEncoderActualPositionExtendedOn32Bits, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderActualPositionExtendedOn32Bits.SSI_AbsoluteEncoderActualPosition, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderActualPositionExtendedOn32Bits.SSI_AbsoluteEncoderActualRawPosition, 0xa6, 0x4 },
};

/*0x497b*/ const CO_OD_entryRecord_t OD_record497b[2] = {
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderActualIndexPosition.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderActualIndexPosition.SSI_AbsoluteEncoderActualIndexPosition, 0xa6, 0x4 },
};

/*0x497c*/ const CO_OD_entryRecord_t OD_record497c[2] = {
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderCountOfIndexPulses.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.SSI_AbsoluteEncoderCountOfIndexPulses.SSI_AbsoluteEncoderCountOfIndexPulses, 0xbe, 0x2 },
};

/*0x49a0*/ const CO_OD_entryRecord_t OD_record49a0[10] = {
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementConfiguration, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementStatus, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementBrakeOutput, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementDelay1Activating, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementDelay2Activating, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementDelay1Deactivating, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementDelay2Deactivating, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementActivatingCondition, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.brakeManagementConfiguration.brakeManagementDeactivatingCondition, 0xbe, 0x2 },
};

/*0x49a2*/ const CO_OD_entryRecord_t OD_record49a2[10] = {
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderConfigurationFlags, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderStatus, 0x26, 0x1 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderError, 0xa6, 0x2 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderTolerance, 0xbe, 0x2 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderCommand, 0x9a, 0x4 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderCorrectedPosition, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderSavedPosition, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderSavedIndexPosition, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags.quasiAbsoluteEncoderSavedCounter, 0xa6, 0x4 },
};

/*0x4a02*/ const CO_OD_entryRecord_t OD_record4a02[2] = {
           {(void*)&CO_OD_RAM.velocityMeasurementGateTime.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityMeasurementGateTime.velocityMeasurementGateTime, 0xbe, 0x2 },
};

/*0x4a04*/ const CO_OD_entryRecord_t OD_record4a04[3] = {
           {(void*)&CO_OD_RAM.velocityMeasurementInCounts.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityMeasurementInCounts.velocityMeasurementInCounts, 0xa6, 0x4 },
           {(void*)&CO_OD_RAM.velocityMeasurementInCounts.velocityMeasurementInRpm, 0xa6, 0x4 },
};

/*0x4b00*/ const CO_OD_entryRecord_t OD_record4b00[3] = {
           {(void*)&CO_OD_RAM.factorGroupConfiguration.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupConfiguration.factorGroupConfiguration, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupConfiguration.factorGroupPrecision, 0x3e, 0x1 },
};

/*0x4b10*/ const CO_OD_entryRecord_t OD_record4b10[2] = {
           {(void*)&CO_OD_RAM.factorGroupPolarity.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupPolarity.factorGroupPolarity, 0x3e, 0x1 },
};

/*0x4b11*/ const CO_OD_entryRecord_t OD_record4b11[2] = {
           {(void*)&CO_OD_RAM.factorGroupPositionNotationIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupPositionNotationIndex.factorGroupPositionNotationIndex, 0x3e, 0x1 },
};

/*0x4b12*/ const CO_OD_entryRecord_t OD_record4b12[2] = {
           {(void*)&CO_OD_RAM.factorGroupPositionDimensionIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupPositionDimensionIndex.factorGroupPositionDimensionIndex, 0x3e, 0x1 },
};

/*0x4b13*/ const CO_OD_entryRecord_t OD_record4b13[2] = {
           {(void*)&CO_OD_RAM.factorGroupVelocityNotationIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupVelocityNotationIndex.factorGroupVelocityNotationIndex, 0x3e, 0x1 },
};

/*0x4b14*/ const CO_OD_entryRecord_t OD_record4b14[2] = {
           {(void*)&CO_OD_RAM.factorGroupVelocityDimensionIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupVelocityDimensionIndex.factorGroupVelocityDimensionIndex, 0x3e, 0x1 },
};

/*0x4b15*/ const CO_OD_entryRecord_t OD_record4b15[2] = {
           {(void*)&CO_OD_RAM.factorGroupAccelerationNotationIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupAccelerationNotationIndex.factorGroupAccelerationNotationIndex, 0x3e, 0x1 },
};

/*0x4b16*/ const CO_OD_entryRecord_t OD_record4b16[2] = {
           {(void*)&CO_OD_RAM.factorGroupAccelerationDimensionIndex.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupAccelerationDimensionIndex.factorGroupAccelerationDimensionIndex, 0x3e, 0x1 },
};

/*0x4b17*/ const CO_OD_entryRecord_t OD_record4b17[3] = {
           {(void*)&CO_OD_RAM.factorGroupPositionScaleNumerator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupPositionScaleNumerator.factorGroupPositionScaleNumerator, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.factorGroupPositionScaleNumerator.factorGroupPositionScaleDenominator, 0xbe, 0x4 },
};

/*0x4b18*/ const CO_OD_entryRecord_t OD_record4b18[3] = {
           {(void*)&CO_OD_RAM.factorGroupVelocityScaleNumerator.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupVelocityScaleNumerator.factorGroupVelocityScaleNumerator, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.factorGroupVelocityScaleNumerator.factorGroupVelocityScaleDenominator, 0xbe, 0x4 },
};

/*0x4b19*/ const CO_OD_entryRecord_t OD_record4b19[3] = {
           {(void*)&CO_OD_RAM.factorGroupGearRatioMotorShaftRevolution.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupGearRatioMotorShaftRevolution.factorGroupGearRatioMotorShaftRevolution, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.factorGroupGearRatioMotorShaftRevolution.factorGroupGearRatioGearShaftRevolution, 0xbe, 0x4 },
};

/*0x4b1a*/ const CO_OD_entryRecord_t OD_record4b1a[3] = {
           {(void*)&CO_OD_RAM.factorGroupFeedConstantFeed.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.factorGroupFeedConstantFeed.factorGroupFeedConstantFeed, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.factorGroupFeedConstantFeed.factorGroupFeedConstantDrivingShaftRevolution, 0xbe, 0x4 },
};

/*0x6046*/ const CO_OD_entryRecord_t OD_record6046[3] = {
           {(void*)&CO_OD_RAM.vlVelocityMinMaxAmount.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.vlVelocityMinMaxAmount.velocityMinAmountRpm, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.vlVelocityMinMaxAmount.velocityMaxAmountRpm, 0xbe, 0x4 },
};

/*0x6048*/ const CO_OD_entryRecord_t OD_record6048[3] = {
           {(void*)&CO_OD_RAM.vlVelocityAcceleration.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.vlVelocityAcceleration.deltaSpeedRpm, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.vlVelocityAcceleration.deltaTimes, 0xbe, 0x2 },
};

/*0x6049*/ const CO_OD_entryRecord_t OD_record6049[3] = {
           {(void*)&CO_OD_RAM.vlVelocityDeceleration.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.vlVelocityDeceleration.deltaSpeedRpm, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.vlVelocityDeceleration.deltaTimes, 0xbe, 0x2 },
};

/*0x604a*/ const CO_OD_entryRecord_t OD_record604a[3] = {
           {(void*)&CO_OD_RAM.vlVelocityQuickStop.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.vlVelocityQuickStop.deltaSpeedRpm, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.vlVelocityQuickStop.deltaTimes, 0xbe, 0x2 },
};

/*0x604c*/ const CO_OD_entryRecord_t OD_record604c[3] = {
           {(void*)&CO_OD_RAM.vlDimensionFactor.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.vlDimensionFactor.numerator, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.vlDimensionFactor.denominator, 0xbe, 0x4 },
};

/*0x607d*/ const CO_OD_entryRecord_t OD_record607d[3] = {
           {(void*)&CO_OD_RAM.softwarePositionLimit.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.softwarePositionLimit.minPositionLimit, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.softwarePositionLimit.maxPositionLimit, 0xbe, 0x4 },
};

/*0x608f*/ const CO_OD_entryRecord_t OD_record608f[3] = {
           {(void*)&CO_OD_RAM.positionEncoderResolution.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.positionEncoderResolution.encoderIncrements, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.positionEncoderResolution.motorRevolutions, 0xbe, 0x4 },
};

/*0x6090*/ const CO_OD_entryRecord_t OD_record6090[3] = {
           {(void*)&CO_OD_RAM.velocityEncoderResolution.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.velocityEncoderResolution.encoderIncrements, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.velocityEncoderResolution.motorRevolutions, 0xbe, 0x4 },
};

/*0x6091*/ const CO_OD_entryRecord_t OD_record6091[3] = {
           {(void*)&CO_OD_RAM.gearRatio.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.gearRatio.motorRevolutions, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.gearRatio.shaftRevolutions, 0xbe, 0x4 },
};

/*0x6092*/ const CO_OD_entryRecord_t OD_record6092[3] = {
           {(void*)&CO_OD_RAM.feedConstant.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.feedConstant.feed, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.feedConstant.shaftRevolutions, 0xbe, 0x4 },
};

/*0x6099*/ const CO_OD_entryRecord_t OD_record6099[3] = {
           {(void*)&CO_OD_RAM.homingSpeeds.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.homingSpeeds.speedDuringSearchForSwitch, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.homingSpeeds.speedDuringSearchForZero, 0xbe, 0x4 },
};

/*0x60c1*/ const CO_OD_entryRecord_t OD_record60c1[2] = {
           {(void*)&CO_OD_RAM.interpolatedDataRecord.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.interpolatedDataRecord.interpolationData1stSetPoint, 0xbe, 0x4 },
};

/*0x60c2*/ const CO_OD_entryRecord_t OD_record60c2[3] = {
           {(void*)&CO_OD_RAM.interpolationTimePeriod.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.interpolationTimePeriod.interpolationTimePeriodValue, 0x3e, 0x1 },
           {(void*)&CO_OD_RAM.interpolationTimePeriod.interpolationTimeIndex, 0x3e, 0x1 },
};

/*0x60e3*/ const CO_OD_entryRecord_t OD_record60e3[32] = {
           {(void*)&CO_OD_RAM.supportedHomingMethods.numberOfErrorClasses, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnNegativeLimitSwitchAndIndexPulse, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnPositiveLimitSwitchAndIndexPulse, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnPositiveHomeSwitchAndIndexPulse, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnPositiveHomeSwitchAndIndexPulse2, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnNegativeHomeSwitchAndIndexPulse, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnNegativeHomeSwitchAndIndexPulse2, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse0, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse1, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse2, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse3, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse4, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse5, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse6, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnHomeSwitchAndIndexPulse7, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse00, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse01, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse02, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse03, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse04, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse05, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse06, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse07, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse08, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse09, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse10, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse11, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse12, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingWithoutIndexPulse13, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnIndexPulse0, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnIndexPulse1, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.supportedHomingMethods.homingOnCurrentPosition, 0x06, 0x1 },
};

/*0x60fe*/ const CO_OD_entryRecord_t OD_record60fe[3] = {
           {(void*)&CO_OD_RAM.digitalOutputs.numberOfEntries, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.digitalOutputs.outputState, 0xbe, 0x4 },
           {(void*)&CO_OD_RAM.digitalOutputs.enableBitMask, 0xbe, 0x4 },
};

/*0x67fe*/ const CO_OD_entryRecord_t OD_record67fe[4] = {
           {(void*)&CO_OD_RAM.errorBehaviourOld.numberOfErrorClasses, 0x06, 0x1 },
           {(void*)&CO_OD_RAM.errorBehaviourOld.communicationError, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.errorBehaviourOld.outputError, 0x0e, 0x1 },
           {(void*)&CO_OD_RAM.errorBehaviourOld.inputError, 0x0e, 0x1 },
};

/*******************************************************************************
   OBJECT DICTIONARY
*******************************************************************************/
const CO_OD_entry_t CO_OD[258] = {

{0x1000, 0x00, 0x86, 4, (void*)&CO_OD_RAM.deviceType},
{0x1001, 0x00, 0x26, 1, (void*)&CO_OD_RAM.errorRegister},
{0x1003, 0x08, 0x8e, 4, (void*)&CO_OD_RAM.preDefinedErrorField[0]},
{0x1005, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.COB_ID_SYNCMessage},
{0x1006, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.communicationCyclePeriod},
{0x1007, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.synchronousWindowLength},
{0x1008, 0x00, 0x06, 13, (void*)&CO_OD_RAM.manufacturerDeviceName},
{0x1009, 0x00, 0x06, 4, (void*)&CO_OD_RAM.hardwareVersion},
{0x100a, 0x00, 0x06, 4, (void*)&CO_OD_RAM.softwareVersion},
{0x1014, 0x00, 0x86, 4, (void*)&CO_OD_RAM.COB_ID_EMCY},
{0x1015, 0x00, 0x8e, 2, (void*)&CO_OD_RAM.inhibitTimeEMCY},
{0x1016, 0x04, 0x8e, 4, (void*)&CO_OD_RAM.consumerHeartbeatTime[0]},
{0x1017, 0x00, 0x8e, 2, (void*)&CO_OD_RAM.producerHeartbeatTime},
{0x1018, 0x04, 0x00, 0, (void*)&OD_record1018},
{0x1019, 0x00, 0x0e, 1, (void*)&CO_OD_RAM.synchronousCounterOverflowValue},
{0x1029, 0x06, 0x0e, 1, (void*)&CO_OD_RAM.errorBehavior[0]},
{0x1200, 0x02, 0x00, 0, (void*)&OD_record1200},
{0x1280, 0x03, 0x00, 0, (void*)&OD_record1280},
{0x1400, 0x02, 0x00, 0, (void*)&OD_record1400},
{0x1600, 0x08, 0x00, 0, (void*)&OD_record1600},
{0x1800, 0x06, 0x00, 0, (void*)&OD_record1800},
{0x1a00, 0x08, 0x00, 0, (void*)&OD_record1a00},
{0x1f80, 0x00, 0x8e, 4, (void*)&CO_OD_RAM.NMTStartup},
{0x200a, 0x01, 0x00, 0, (void*)&OD_record200a},
{0x2100, 0x00, 0x26, 10, (void*)&CO_OD_RAM.errorStatusBits},
{0x4000, 0x06, 0x00, 0, (void*)&OD_record4000},
{0x4001, 0x03, 0x00, 0, (void*)&OD_record4001},
{0x4002, 0x02, 0x00, 0, (void*)&OD_record4002},
{0x4003, 0x01, 0x00, 0, (void*)&OD_record4003},
{0x4004, 0x01, 0x00, 0, (void*)&OD_record4004},
{0x4010, 0x09, 0x00, 0, (void*)&OD_record4010},
{0x4014, 0x21, 0x00, 0, (void*)&OD_record4014},
{0x4020, 0x02, 0x00, 0, (void*)&OD_record4020},
{0x4023, 0x04, 0x00, 0, (void*)&OD_record4023},
{0x4024, 0x01, 0x00, 0, (void*)&OD_record4024},
{0x402c, 0x01, 0x00, 0, (void*)&OD_record402c},
{0x402e, 0x0b, 0x00, 0, (void*)&OD_record402e},
{0x402f, 0x05, 0x00, 0, (void*)&OD_record402f},
{0x4031, 0x04, 0x00, 0, (void*)&OD_record4031},
{0x4032, 0x01, 0x00, 0, (void*)&OD_record4032},
{0x4050, 0x01, 0x00, 0, (void*)&OD_record4050},
{0x4051, 0x01, 0x00, 0, (void*)&OD_record4051},
{0x4052, 0x01, 0x00, 0, (void*)&OD_record4052},
{0x4055, 0x01, 0x00, 0, (void*)&OD_record4055},
{0x4056, 0x01, 0x00, 0, (void*)&OD_record4056},
{0x4057, 0x01, 0x00, 0, (void*)&OD_record4057},
{0x4060, 0x01, 0x00, 0, (void*)&OD_record4060},
{0x4080, 0x01, 0x00, 0, (void*)&OD_record4080},
{0x4090, 0x03, 0x00, 0, (void*)&OD_record4090},
{0x4100, 0x01, 0x00, 0, (void*)&OD_record4100},
{0x4108, 0x01, 0x00, 0, (void*)&OD_record4108},
{0x410a, 0x01, 0x00, 0, (void*)&OD_record410a},
{0x4110, 0x01, 0x00, 0, (void*)&OD_record4110},
{0x4111, 0x01, 0x00, 0, (void*)&OD_record4111},
{0x4112, 0x01, 0x00, 0, (void*)&OD_record4112},
{0x4113, 0x01, 0x00, 0, (void*)&OD_record4113},
{0x4114, 0x02, 0x00, 0, (void*)&OD_record4114},
{0x4120, 0x01, 0x00, 0, (void*)&OD_record4120},
{0x4128, 0x02, 0x00, 0, (void*)&OD_record4128},
{0x4150, 0x01, 0x00, 0, (void*)&OD_record4150},
{0x4154, 0x01, 0x00, 0, (void*)&OD_record4154},
{0x4200, 0x01, 0x00, 0, (void*)&OD_record4200},
{0x4260, 0x01, 0x00, 0, (void*)&OD_record4260},
{0x4261, 0x01, 0x00, 0, (void*)&OD_record4261},
{0x4262, 0x02, 0x00, 4, (void*)&OD_record4262},
{0x4263, 0x01, 0x00, 0, (void*)&OD_record4263},
{0x42a0, 0x02, 0x00, 0, (void*)&OD_record42a0},
{0x4300, 0x01, 0x00, 0, (void*)&OD_record4300},
{0x4302, 0x01, 0x00, 0, (void*)&OD_record4302},
{0x4303, 0x01, 0x00, 0, (void*)&OD_record4303},
{0x4304, 0x01, 0x00, 0, (void*)&OD_record4304},
{0x4305, 0x01, 0x00, 0, (void*)&OD_record4305},
{0x430a, 0x01, 0x00, 0, (void*)&OD_record430a},
{0x430b, 0x01, 0x00, 0, (void*)&OD_record430b},
{0x4310, 0x08, 0x00, 0, (void*)&OD_record4310},
{0x4311, 0x08, 0x00, 0, (void*)&OD_record4311},
{0x4312, 0x08, 0x00, 0, (void*)&OD_record4312},
{0x4313, 0x08, 0x00, 0, (void*)&OD_record4313},
{0x4314, 0x08, 0x00, 0, (void*)&OD_record4314},
{0x4315, 0x01, 0x00, 0, (void*)&OD_record4315},
{0x4317, 0x01, 0x00, 0, (void*)&OD_record4317},
{0x4318, 0x01, 0x00, 0, (void*)&OD_record4318},
{0x4321, 0x01, 0x00, 0, (void*)&OD_record4321},
{0x4323, 0x01, 0x00, 0, (void*)&OD_record4323},
{0x4340, 0x01, 0x00, 0, (void*)&OD_record4340},
{0x4341, 0x01, 0x00, 0, (void*)&OD_record4341},
{0x4342, 0x01, 0x00, 0, (void*)&OD_record4342},
{0x4343, 0x01, 0x00, 0, (void*)&OD_record4343},
{0x4344, 0x01, 0x00, 0, (void*)&OD_record4344},
{0x4345, 0x01, 0x00, 0, (void*)&OD_record4345},
{0x434c, 0x01, 0x00, 0, (void*)&OD_record434c},
{0x434d, 0x01, 0x00, 0, (void*)&OD_record434d},
{0x4350, 0x02, 0x00, 0, (void*)&OD_record4350},
{0x4380, 0x01, 0x00, 0, (void*)&OD_record4380},
{0x4381, 0x01, 0x00, 0, (void*)&OD_record4381},
{0x4382, 0x01, 0x00, 0, (void*)&OD_record4382},
{0x43a0, 0x01, 0x00, 0, (void*)&OD_record43a0},
{0x43c0, 0x05, 0x00, 0, (void*)&OD_record43c0},
{0x43d4, 0x01, 0x00, 0, (void*)&OD_record43d4},
{0x4500, 0x01, 0x00, 0, (void*)&OD_record4500},
{0x4502, 0x01, 0x00, 0, (void*)&OD_record4502},
{0x4503, 0x01, 0x00, 0, (void*)&OD_record4503},
{0x4504, 0x01, 0x00, 0, (void*)&OD_record4504},
{0x4505, 0x01, 0x00, 0, (void*)&OD_record4505},
{0x4510, 0x01, 0x00, 0, (void*)&OD_record4510},
{0x4511, 0x01, 0x00, 0, (void*)&OD_record4511},
{0x4517, 0x01, 0x00, 0, (void*)&OD_record4517},
{0x4550, 0x01, 0x00, 0, (void*)&OD_record4550},
{0x45a0, 0x01, 0x00, 0, (void*)&OD_record45a0},
{0x45a1, 0x01, 0x00, 0, (void*)&OD_record45a1},
{0x4708, 0x01, 0x00, 0, (void*)&OD_record4708},
{0x4720, 0x02, 0x00, 0, (void*)&OD_record4720},
{0x4732, 0x02, 0x00, 0, (void*)&OD_record4732},
{0x4733, 0x02, 0x00, 0, (void*)&OD_record4733},
{0x4735, 0x01, 0x00, 0, (void*)&OD_record4735},
{0x473a, 0x01, 0x00, 4, (void*)&OD_record473a},
{0x473b, 0x02, 0x00, 2, (void*)&OD_record473b},
{0x473c, 0x01, 0x00, 0, (void*)&OD_record473c},
{0x474c, 0x01, 0x00, 0, (void*)&OD_record474c},
{0x474d, 0x01, 0x00, 0, (void*)&OD_record474d},
{0x4760, 0x01, 0x00, 0, (void*)&OD_record4760},
{0x4761, 0x01, 0x00, 0, (void*)&OD_record4761},
{0x4762, 0x01, 0x00, 0, (void*)&OD_record4762},
{0x4763, 0x01, 0x00, 0, (void*)&OD_record4763},
{0x4764, 0x01, 0x00, 0, (void*)&OD_record4764},
{0x4770, 0x01, 0x00, 0, (void*)&OD_record4770},
{0x4771, 0x01, 0x00, 0, (void*)&OD_record4771},
{0x4772, 0x01, 0x00, 0, (void*)&OD_record4772},
{0x4773, 0x01, 0x00, 0, (void*)&OD_record4773},
{0x4774, 0x01, 0x00, 0, (void*)&OD_record4774},
{0x4790, 0x01, 0x00, 0, (void*)&OD_record4790},
{0x4791, 0x01, 0x00, 0, (void*)&OD_record4791},
{0x47a4, 0x04, 0x00, 0, (void*)&OD_record47a4},
{0x47b0, 0x01, 0x00, 0, (void*)&OD_record47b0},
{0x47b1, 0x05, 0x00, 0, (void*)&OD_record47b1},
{0x47b2, 0x01, 0x00, 1, (void*)&OD_record47b2},
{0x47b3, 0x02, 0x00, 0, (void*)&OD_record47b3},
{0x47b4, 0x03, 0x00, 0, (void*)&OD_record47b4},
{0x47b5, 0x02, 0x00, 4, (void*)&OD_record47b5},
{0x47b6, 0x02, 0x00, 0, (void*)&OD_record47b6},
{0x47b7, 0x07, 0x00, 0, (void*)&OD_record47b7},
{0x47c2, 0x03, 0x00, 0, (void*)&OD_record47c2},
{0x47c5, 0x01, 0x00, 0, (void*)&OD_record47c5},
{0x47c6, 0x01, 0x00, 0, (void*)&OD_record47c6},
{0x47c7, 0x03, 0x00, 0, (void*)&OD_record47c7},
{0x47c8, 0x01, 0x00, 0, (void*)&OD_record47c8},
{0x47c9, 0x01, 0x00, 0, (void*)&OD_record47c9},
{0x4830, 0x03, 0x00, 0, (void*)&OD_record4830},
{0x4850, 0x02, 0x00, 0, (void*)&OD_record4850},
{0x48f3, 0x03, 0x00, 0, (void*)&OD_record48f3},
{0x4900, 0x01, 0x00, 1, (void*)&OD_record4900},
{0x4901, 0x01, 0x00, 0, (void*)&OD_record4901},
{0x4902, 0x01, 0x00, 0, (void*)&OD_record4902},
{0x4910, 0x01, 0x00, 0, (void*)&OD_record4910},
{0x4911, 0x01, 0x00, 0, (void*)&OD_record4911},
{0x4913, 0x01, 0x00, 0, (void*)&OD_record4913},
{0x4940, 0x01, 0x00, 0, (void*)&OD_record4940},
{0x4944, 0x03, 0x00, 0, (void*)&OD_record4944},
{0x4949, 0x04, 0x00, 0, (void*)&OD_record4949},
{0x494a, 0x01, 0x00, 0, (void*)&OD_record494a},
{0x4962, 0x01, 0x00, 0, (void*)&OD_record4962},
{0x4963, 0x01, 0x00, 0, (void*)&OD_record4963},
{0x496a, 0x01, 0x00, 0, (void*)&OD_record496a},
{0x496b, 0x01, 0x00, 0, (void*)&OD_record496b},
{0x496c, 0x01, 0x00, 0, (void*)&OD_record496c},
{0x4970, 0x03, 0x00, 0, (void*)&OD_record4970},
{0x4971, 0x02, 0x00, 0, (void*)&OD_record4971},
{0x4972, 0x01, 0x00, 0, (void*)&OD_record4972},
{0x497a, 0x03, 0x00, 0, (void*)&OD_record497a},
{0x497b, 0x01, 0x00, 0, (void*)&OD_record497b},
{0x497c, 0x01, 0x00, 0, (void*)&OD_record497c},
{0x49a0, 0x09, 0x00, 0, (void*)&OD_record49a0},
{0x49a2, 0x09, 0x00, 0, (void*)&OD_record49a2},
{0x4a02, 0x01, 0x00, 0, (void*)&OD_record4a02},
{0x4a04, 0x02, 0x00, 0, (void*)&OD_record4a04},
{0x4b00, 0x02, 0x00, 0, (void*)&OD_record4b00},
{0x4b10, 0x01, 0x00, 0, (void*)&OD_record4b10},
{0x4b11, 0x01, 0x00, 0, (void*)&OD_record4b11},
{0x4b12, 0x01, 0x00, 0, (void*)&OD_record4b12},
{0x4b13, 0x01, 0x00, 0, (void*)&OD_record4b13},
{0x4b14, 0x01, 0x00, 0, (void*)&OD_record4b14},
{0x4b15, 0x01, 0x00, 0, (void*)&OD_record4b15},
{0x4b16, 0x01, 0x00, 0, (void*)&OD_record4b16},
{0x4b17, 0x02, 0x00, 0, (void*)&OD_record4b17},
{0x4b18, 0x02, 0x00, 0, (void*)&OD_record4b18},
{0x4b19, 0x02, 0x00, 0, (void*)&OD_record4b19},
{0x4b1a, 0x02, 0x00, 0, (void*)&OD_record4b1a},
{0x6007, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.abortConnectionOptionCode},
{0x603f, 0x00, 0xa6, 2, (void*)&CO_OD_RAM.errorCode},
{0x6040, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.controlword},
{0x6041, 0x00, 0xa6, 2, (void*)&CO_OD_RAM.statusword},
{0x6042, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.vlTargetVelocity},
{0x6043, 0x00, 0xa6, 2, (void*)&CO_OD_RAM.vlVelocityDemand},
{0x6044, 0x00, 0xa6, 2, (void*)&CO_OD_RAM.vlVelocityActualValue},
{0x6046, 0x02, 0x00, 0, (void*)&OD_record6046},
{0x6048, 0x02, 0x00, 0, (void*)&OD_record6048},
{0x6049, 0x02, 0x00, 0, (void*)&OD_record6049},
{0x604a, 0x02, 0x00, 0, (void*)&OD_record604a},
{0x604c, 0x02, 0x00, 0, (void*)&OD_record604c},
{0x605a, 0x00, 0x8e, 2, (void*)&CO_OD_RAM.quickStopOptionCode},
{0x6060, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.modesOfOperation},
{0x6061, 0x00, 0x26, 1, (void*)&CO_OD_RAM.modesOfOperationDisplay},
{0x6062, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.positionDemandValue},
{0x6063, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.positionActualValueCount},
{0x6064, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.positionActualValue},
{0x6065, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.followingErrorWindow},
{0x6066, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.followingErrorTimeOut},
{0x6067, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.positionWindow},
{0x6068, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.positionWindowTime},
{0x606c, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.velocityActualValue},
{0x606d, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.velocityWindow},
{0x606e, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.velocityWindowTime},
{0x606f, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.velocityThreshold},
{0x6070, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.velocityThresholdTime},
{0x6071, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.targetTorque},
{0x6072, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.maxTorque},
{0x6075, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.motorRatedCurrent},
{0x6077, 0x00, 0xa6, 2, (void*)&CO_OD_RAM.torqueActualValue},
{0x6078, 0x00, 0xa6, 2, (void*)&CO_OD_RAM.currentActualValue},
{0x6079, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.DCLinkCircuitVoltage},
{0x607a, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.targetPosition},
{0x607c, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.homeOffset},
{0x607d, 0x02, 0x00, 0, (void*)&OD_record607d},
{0x607e, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.polarity},
{0x607f, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.maxProfileVelocity},
{0x6081, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.profileVelocity},
{0x6083, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.profileAcceleration},
{0x6084, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.profileDeceleration},
{0x6085, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.quickStopDeceleration},
{0x6086, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.motionProfileType},
{0x6087, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.torqueSlope},
{0x6088, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.torqueProfileType},
{0x6089, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.positionNotationIndex},
{0x608a, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.positionDimensionIndex},
{0x608b, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.velocityNotationIndex},
{0x608c, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.velocityDimensionIndex},
{0x608d, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.accelerationNotationIndex},
{0x608e, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.accelerationDimensionIndex},
{0x608f, 0x02, 0x00, 0, (void*)&OD_record608f},
{0x6090, 0x02, 0x00, 0, (void*)&OD_record6090},
{0x6091, 0x02, 0x00, 0, (void*)&OD_record6091},
{0x6092, 0x02, 0x00, 0, (void*)&OD_record6092},
{0x6098, 0x00, 0x3e, 1, (void*)&CO_OD_RAM.homingMethod},
{0x6099, 0x02, 0x00, 0, (void*)&OD_record6099},
{0x609a, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.homingAcceleration},
{0x60c1, 0x01, 0x00, 0, (void*)&OD_record60c1},
{0x60c2, 0x02, 0x00, 0, (void*)&OD_record60c2},
{0x60e0, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.positiveTorqueLimitValue},
{0x60e1, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.negativeTorqueLimitValue},
{0x60e3, 0x1f, 0x00, 0, (void*)&OD_record60e3},
{0x60f4, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.followingErrorActualValue},
{0x60fc, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.positionDemandValueCount},
{0x60fd, 0x00, 0xa6, 4, (void*)&CO_OD_RAM.digitalInputs},
{0x60fe, 0x02, 0x00, 0, (void*)&OD_record60fe},
{0x60ff, 0x00, 0xbe, 4, (void*)&CO_OD_RAM.targetVelocity},
{0x6402, 0x00, 0xbe, 2, (void*)&CO_OD_RAM.motorType},
{0x6502, 0x00, 0x86, 4, (void*)&CO_OD_RAM.supportedDriveModes},
{0x67fe, 0x03, 0x00, 0, (void*)&OD_record67fe},
};
// clang-format on
