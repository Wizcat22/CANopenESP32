// clang-format off
/*******************************************************************************

   File - CO_OD.c/CO_OD.h
   CANopen Object Dictionary.

   This file was automatically generated with libedssharp Object
   Dictionary Editor v0.8-0-gb60f4eb   DON'T EDIT THIS FILE MANUALLY !!!!
*******************************************************************************/


#ifndef CO_OD_H_
#define CO_OD_H_

/*******************************************************************************
   CANopen DATA TYPES
*******************************************************************************/
   typedef bool_t       BOOLEAN;
   typedef uint8_t      UNSIGNED8;
   typedef uint16_t     UNSIGNED16;
   typedef uint32_t     UNSIGNED32;
   typedef uint64_t     UNSIGNED64;
   typedef int8_t       INTEGER8;
   typedef int16_t      INTEGER16;
   typedef int32_t      INTEGER32;
   typedef int64_t      INTEGER64;
   typedef float32_t    REAL32;
   typedef float64_t    REAL64;
   typedef char_t       VISIBLE_STRING;
   typedef oChar_t      OCTET_STRING;

   #ifdef DOMAIN
   #undef DOMAIN
   #endif

   typedef domain_t     DOMAIN;

#ifndef timeOfDay_t
    typedef union {
        unsigned long long ullValue;
        struct {
            unsigned long ms:28;
            unsigned reserved:4;
            unsigned days:16;
            unsigned reserved2:16;
        };
    }timeOfDay_t;
#endif

    typedef timeOfDay_t TIME_OF_DAY;
    typedef timeOfDay_t TIME_DIFFERENCE;


/*******************************************************************************
   FILE INFO:
      FileName:     84300ZC_modified_functional_evtl_ernsthaft_morgen_dochheute_nedochmorgen_ichgebauf.eds
      FileVersion:  1
      CreationTime: 1:07PM
      CreationDate: 02-14-2018
      CreatedBy:    Muellen, Goetting KG
******************************************************************************/


/*******************************************************************************
   DEVICE INFO:
      VendorName:     Goetting KG
      VendorNumber    514
      ProductName:    HG84300ZC
      ProductNumber:  541440
******************************************************************************/


/*******************************************************************************
   FEATURES
*******************************************************************************/
  #define CO_NO_SYNC                     1   //Associated objects: 1005-1007
  #define CO_NO_EMERGENCY                1   //Associated objects: 1014, 1015
  #define CO_NO_TIME                       0   //Associated objects: 1012, 1013
  #define CO_NO_SDO_SERVER               1   //Associated objects: 1200-127F
  #define CO_NO_SDO_CLIENT               0   //Associated objects: 1280-12FF
  #define CO_NO_LSS_SERVER               0   //LSS Slave
  #define CO_NO_LSS_CLIENT               0   //LSS Master
  #define CO_NO_RPDO                     8   //Associated objects: 14xx, 16xx
  #define CO_NO_TPDO                     8   //Associated objects: 18xx, 1Axx
  #define CO_NO_NMT_MASTER               1


/*******************************************************************************
   OBJECT DICTIONARY
*******************************************************************************/
   #define CO_OD_NoOfElements             56


/*******************************************************************************
   TYPE DEFINITIONS FOR RECORDS
*******************************************************************************/
/*1018    */ typedef struct {
               UNSIGNED8      highestSubindex;
               UNSIGNED32     vendorID;
               UNSIGNED32     produktCode;
               UNSIGNED32     revision;
               UNSIGNED32     serialNumber;
               }              OD_identityObject_t;
/*1200    */ typedef struct {
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDClientToServer;
               UNSIGNED32     COB_IDServerToClient;
               }              OD_SDOServerParameter_t;
/*1400    */ typedef struct {
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDUsedByRPDO;
               UNSIGNED8      transmissionType;
               }              OD_RPDOCommunicationParameter_t;
/*1600    */ typedef struct {
               UNSIGNED8      numberOfMappedObjects;
               UNSIGNED32     mappedObject1;
               UNSIGNED32     mappedObject2;
               UNSIGNED32     mappedObject3;
               UNSIGNED32     mappedObject4;
               UNSIGNED32     mappedObject5;
               UNSIGNED32     mappedObject6;
               UNSIGNED32     mappedObject7;
               UNSIGNED32     mappedObject8;
               }              OD_RPDOMappingParameter_t;
/*1800    */ typedef struct {
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDUsedByTPDO;
               UNSIGNED8      transmissionType;
               UNSIGNED16     inhibitTime;
               UNSIGNED8      compatibilityEntry;
               UNSIGNED16     eventTimer;
               UNSIGNED8      SYNCStartValue;
               }              OD_TPDOCommunicationParameter_t;
/*1a00    */ typedef struct {
               UNSIGNED8      numberOfMappedObjects;
               UNSIGNED32     mappedObject1;
               UNSIGNED32     mappedObject2;
               UNSIGNED32     mappedObject3;
               UNSIGNED32     mappedObject4;
               UNSIGNED32     mappedObject5;
               UNSIGNED32     mappedObject6;
               UNSIGNED32     mappedObject7;
               UNSIGNED32     mappedObject8;
               }              OD_TPDOMappingParameter_t;

/*******************************************************************************
   TYPE DEFINITIONS FOR OBJECT DICTIONARY INDEXES

   some of those are redundant with CO_SDO.h CO_ObjDicId_t <Common CiA301 object 
   dictionary entries>
*******************************************************************************/
/*1000 */
        #define OD_1000_deviceType                                  0x1000

/*1001 */
        #define OD_1001_errorRegister                               0x1001

/*1003 */
        #define OD_1003_preDefinedErrorField                        0x1003

        #define OD_1003_0_preDefinedErrorField_maxSubIndex          0
        #define OD_1003_1_preDefinedErrorField_standardErrorField   1
        #define OD_1003_2_preDefinedErrorField_standardErrorField   2
        #define OD_1003_3_preDefinedErrorField_standardErrorField   3
        #define OD_1003_4_preDefinedErrorField_standardErrorField   4
        #define OD_1003_5_preDefinedErrorField_standardErrorField   5
        #define OD_1003_6_preDefinedErrorField_standardErrorField   6
        #define OD_1003_7_preDefinedErrorField_standardErrorField   7
        #define OD_1003_8_preDefinedErrorField_standardErrorField   8

/*1005 */
        #define OD_1005_COB_ID_SYNCMessage                          0x1005

/*1006 */
        #define OD_1006_communicationCyclePeriod                    0x1006

/*1007 */
        #define OD_1007_synchronousWindowLength                     0x1007

/*1008 */
        #define OD_1008_manufacturerDeviceName                      0x1008

/*1009 */
        #define OD_1009_manufacturerHardwareVersion                 0x1009

/*100a */
        #define OD_100a_manufacturerSoftwareVersion                 0x100a

/*1014 */
        #define OD_1014_COB_ID_EMCY                                 0x1014

/*1015 */
        #define OD_1015_inhibitTimeEMCY                             0x1015

/*1016 */
        #define OD_1016_consumerHeartbeatTime                       0x1016

        #define OD_1016_0_consumerHeartbeatTime_maxSubIndex         0
        #define OD_1016_1_consumerHeartbeatTime_consumerHeartbeatTime 1
        #define OD_1016_2_consumerHeartbeatTime_consumerHeartbeatTime 2
        #define OD_1016_3_consumerHeartbeatTime_consumerHeartbeatTime 3
        #define OD_1016_4_consumerHeartbeatTime_consumerHeartbeatTime 4

/*1017 */
        #define OD_1017_producerHeartbeatTime                       0x1017

/*1018 */
        #define OD_1018_identityObject                              0x1018

        #define OD_1018_0_identityObject_maxSubIndex                0
        #define OD_1018_1_identityObject_vendorID                   1
        #define OD_1018_2_identityObject_produktCode                2
        #define OD_1018_3_identityObject_revision                   3
        #define OD_1018_4_identityObject_serialNumber               4

/*1019 */
        #define OD_1019_synchronousCounterOverflowValue             0x1019

/*1029 */
        #define OD_1029_errorBehavior                               0x1029

        #define OD_1029_0_errorBehavior_maxSubIndex                 0
        #define OD_1029_1_errorBehavior_communication               1
        #define OD_1029_2_errorBehavior_communicationOther          2
        #define OD_1029_3_errorBehavior_communicationPassive        3
        #define OD_1029_4_errorBehavior_generic                     4
        #define OD_1029_5_errorBehavior_deviceProfile               5
        #define OD_1029_6_errorBehavior_manufacturerSpecific        6

/*1200 */
        #define OD_1200_SDOServerParameter                          0x1200

        #define OD_1200_0_SDOServerParameter_maxSubIndex            0
        #define OD_1200_1_SDOServerParameter_COB_IDClientToServer   1
        #define OD_1200_2_SDOServerParameter_COB_IDServerToClient   2

/*1400 */
        #define OD_1400_RPDOCommunicationParameter                  0x1400

        #define OD_1400_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1400_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1400_2_RPDOCommunicationParameter_transmissionType 2

/*1401 */
        #define OD_1401_RPDOCommunicationParameter                  0x1401

        #define OD_1401_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1401_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1401_2_RPDOCommunicationParameter_transmissionType 2

/*1402 */
        #define OD_1402_RPDOCommunicationParameter                  0x1402

        #define OD_1402_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1402_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1402_2_RPDOCommunicationParameter_transmissionType 2

/*1403 */
        #define OD_1403_RPDOCommunicationParameter                  0x1403

        #define OD_1403_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1403_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1403_2_RPDOCommunicationParameter_transmissionType 2

/*1404 */
        #define OD_1404_RPDOCommunicationParameter                  0x1404

        #define OD_1404_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1404_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1404_2_RPDOCommunicationParameter_transmissionType 2

/*1405 */
        #define OD_1405_RPDOCommunicationParameter                  0x1405

        #define OD_1405_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1405_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1405_2_RPDOCommunicationParameter_transmissionType 2

/*1406 */
        #define OD_1406_RPDOCommunicationParameter                  0x1406

        #define OD_1406_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1406_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1406_2_RPDOCommunicationParameter_transmissionType 2

/*1407 */
        #define OD_1407_RPDOCommunicationParameter                  0x1407

        #define OD_1407_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1407_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1407_2_RPDOCommunicationParameter_transmissionType 2

/*1600 */
        #define OD_1600_RPDOMappingParameter                        0x1600

        #define OD_1600_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1600_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1600_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1600_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1600_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1600_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1600_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1600_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1600_8_RPDOMappingParameter_mappedObject8        8

/*1601 */
        #define OD_1601_RPDOMappingParameter                        0x1601

        #define OD_1601_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1601_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1601_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1601_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1601_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1601_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1601_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1601_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1601_8_RPDOMappingParameter_mappedObject8        8

/*1602 */
        #define OD_1602_RPDOMappingParameter                        0x1602

        #define OD_1602_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1602_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1602_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1602_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1602_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1602_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1602_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1602_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1602_8_RPDOMappingParameter_mappedObject8        8

/*1603 */
        #define OD_1603_RPDOMappingParameter                        0x1603

        #define OD_1603_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1603_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1603_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1603_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1603_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1603_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1603_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1603_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1603_8_RPDOMappingParameter_mappedObject8        8

/*1604 */
        #define OD_1604_RPDOMappingParameter                        0x1604

        #define OD_1604_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1604_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1604_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1604_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1604_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1604_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1604_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1604_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1604_8_RPDOMappingParameter_mappedObject8        8

/*1605 */
        #define OD_1605_RPDOMappingParameter                        0x1605

        #define OD_1605_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1605_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1605_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1605_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1605_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1605_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1605_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1605_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1605_8_RPDOMappingParameter_mappedObject8        8

/*1606 */
        #define OD_1606_RPDOMappingParameter                        0x1606

        #define OD_1606_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1606_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1606_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1606_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1606_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1606_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1606_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1606_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1606_8_RPDOMappingParameter_mappedObject8        8

/*1607 */
        #define OD_1607_RPDOMappingParameter                        0x1607

        #define OD_1607_0_RPDOMappingParameter_maxSubIndex          0
        #define OD_1607_1_RPDOMappingParameter_mappedObject1        1
        #define OD_1607_2_RPDOMappingParameter_mappedObject2        2
        #define OD_1607_3_RPDOMappingParameter_mappedObject3        3
        #define OD_1607_4_RPDOMappingParameter_mappedObject4        4
        #define OD_1607_5_RPDOMappingParameter_mappedObject5        5
        #define OD_1607_6_RPDOMappingParameter_mappedObject6        6
        #define OD_1607_7_RPDOMappingParameter_mappedObject7        7
        #define OD_1607_8_RPDOMappingParameter_mappedObject8        8

/*1800 */
        #define OD_1800_TPDOCommunicationParameter                  0x1800

        #define OD_1800_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1800_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1800_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1800_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1800_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1800_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1800_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1801 */
        #define OD_1801_TPDOCommunicationParameter                  0x1801

        #define OD_1801_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1801_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1801_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1801_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1801_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1801_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1801_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1802 */
        #define OD_1802_TPDOCommunicationParameter                  0x1802

        #define OD_1802_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1802_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1802_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1802_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1802_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1802_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1802_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1803 */
        #define OD_1803_TPDOCommunicationParameter                  0x1803

        #define OD_1803_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1803_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1803_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1803_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1803_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1803_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1803_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1804 */
        #define OD_1804_TPDOCommunicationParameter                  0x1804

        #define OD_1804_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1804_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1804_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1804_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1804_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1804_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1804_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1805 */
        #define OD_1805_TPDOCommunicationParameter                  0x1805

        #define OD_1805_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1805_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1805_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1805_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1805_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1805_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1805_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1806 */
        #define OD_1806_TPDOCommunicationParameter                  0x1806

        #define OD_1806_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1806_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1806_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1806_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1806_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1806_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1806_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1807 */
        #define OD_1807_TPDOCommunicationParameter                  0x1807

        #define OD_1807_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1807_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1807_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1807_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1807_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1807_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1807_6_TPDOCommunicationParameter_SYNCStartValue 6

/*1a00 */
        #define OD_1a00_TPDOMappingParameter                        0x1a00

        #define OD_1a00_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a00_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a00_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a00_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a00_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a00_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a00_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a00_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a00_8_TPDOMappingParameter_mappedObject8        8

/*1a01 */
        #define OD_1a01_TPDOMappingParameter                        0x1a01

        #define OD_1a01_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a01_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a01_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a01_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a01_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a01_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a01_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a01_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a01_8_TPDOMappingParameter_mappedObject8        8

/*1a02 */
        #define OD_1a02_TPDOMappingParameter                        0x1a02

        #define OD_1a02_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a02_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a02_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a02_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a02_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a02_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a02_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a02_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a02_8_TPDOMappingParameter_mappedObject8        8

/*1a03 */
        #define OD_1a03_TPDOMappingParameter                        0x1a03

        #define OD_1a03_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a03_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a03_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a03_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a03_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a03_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a03_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a03_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a03_8_TPDOMappingParameter_mappedObject8        8

/*1a04 */
        #define OD_1a04_TPDOMappingParameter                        0x1a04

        #define OD_1a04_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a04_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a04_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a04_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a04_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a04_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a04_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a04_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a04_8_TPDOMappingParameter_mappedObject8        8

/*1a05 */
        #define OD_1a05_TPDOMappingParameter                        0x1a05

        #define OD_1a05_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a05_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a05_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a05_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a05_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a05_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a05_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a05_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a05_8_TPDOMappingParameter_mappedObject8        8

/*1a06 */
        #define OD_1a06_TPDOMappingParameter                        0x1a06

        #define OD_1a06_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a06_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a06_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a06_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a06_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a06_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a06_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a06_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a06_8_TPDOMappingParameter_mappedObject8        8

/*1a07 */
        #define OD_1a07_TPDOMappingParameter                        0x1a07

        #define OD_1a07_0_TPDOMappingParameter_maxSubIndex          0
        #define OD_1a07_1_TPDOMappingParameter_mappedObject1        1
        #define OD_1a07_2_TPDOMappingParameter_mappedObject2        2
        #define OD_1a07_3_TPDOMappingParameter_mappedObject3        3
        #define OD_1a07_4_TPDOMappingParameter_mappedObject4        4
        #define OD_1a07_5_TPDOMappingParameter_mappedObject5        5
        #define OD_1a07_6_TPDOMappingParameter_mappedObject6        6
        #define OD_1a07_7_TPDOMappingParameter_mappedObject7        7
        #define OD_1a07_8_TPDOMappingParameter_mappedObject8        8

/*1f80 */
        #define OD_1f80_NMTStartup                                  0x1f80

/*2100 */
        #define OD_2100_errorStatusBits                             0x2100

/*6000 */
        #define OD_6000_readInput8Bit                               0x6000

        #define OD_6000_0_readInput8Bit_maxSubIndex                 0
        #define OD_6000_1_readInput8Bit_statusbits07                1

/*6200 */
        #define OD_6200_writeOutput8Bit                             0x6200

        #define OD_6200_0_writeOutput8Bit_maxSubIndex               0
        #define OD_6200_1_writeOutput8Bit_commandbits07             1

/*6401 */
        #define OD_6401_readAnalogueInput16Bit                      0x6401

        #define OD_6401_0_readAnalogueInput16Bit_maxSubIndex        0
        #define OD_6401_1_readAnalogueInput16Bit_temperature        1

/*6403 */
        #define OD_6403_readAngle                                   0x6403

        #define OD_6403_0_readAngle_maxSubIndex                     0
        #define OD_6403_1_readAngle_angle                           1

/*6f20 */
        #define OD_6f20_lifeCounter                                 0x6f20

        #define OD_6f20_0_lifeCounter_maxSubIndex                   0
        #define OD_6f20_1_lifeCounter_lifeCounter                   1

/*******************************************************************************
   STRUCTURES FOR VARIABLES IN DIFFERENT MEMORY LOCATIONS
*******************************************************************************/
#define  CO_OD_FIRST_LAST_WORD     0x55 //Any value from 0x01 to 0xFE. If changed, EEPROM will be reinitialized.

/***** Structure for ROM variables ********************************************/
struct sCO_OD_ROM{
               UNSIGNED32     FirstWord;


               UNSIGNED32     LastWord;
};

/***** Structure for RAM variables ********************************************/
struct sCO_OD_RAM{
               UNSIGNED32     FirstWord;

/*1000      */ UNSIGNED32      deviceType;
/*1001      */ UNSIGNED8       errorRegister;
/*1003      */ UNSIGNED32      preDefinedErrorField[8];
/*1005      */ UNSIGNED32      COB_ID_SYNCMessage;
/*1006      */ UNSIGNED32      communicationCyclePeriod;
/*1007      */ UNSIGNED32      synchronousWindowLength;
/*1008      */ VISIBLE_STRING  manufacturerDeviceName[4];
/*1009      */ VISIBLE_STRING  manufacturerHardwareVersion[2];
/*100a      */ VISIBLE_STRING  manufacturerSoftwareVersion[4];
/*1014      */ UNSIGNED32      COB_ID_EMCY;
/*1015      */ UNSIGNED16      inhibitTimeEMCY;
/*1016      */ UNSIGNED32      consumerHeartbeatTime[4];
/*1017      */ UNSIGNED16      producerHeartbeatTime;
/*1018      */ OD_identityObject_t identityObject;
/*1019      */ UNSIGNED8       synchronousCounterOverflowValue;
/*1029      */ UNSIGNED8       errorBehavior[6];
/*1200      */ OD_SDOServerParameter_t SDOServerParameter[1];
/*1400      */ OD_RPDOCommunicationParameter_t RPDOCommunicationParameter[8];
/*1600      */ OD_RPDOMappingParameter_t RPDOMappingParameter[8];
/*1800      */ OD_TPDOCommunicationParameter_t TPDOCommunicationParameter[8];
/*1a00      */ OD_TPDOMappingParameter_t TPDOMappingParameter[8];
/*1f80      */ UNSIGNED32      NMTStartup;
/*2100      */ OCTET_STRING    errorStatusBits[10];
/*6000      */ UNSIGNED8       readInput8Bit[1];
/*6200      */ UNSIGNED8       writeOutput8Bit[1];
/*6401      */ INTEGER16       readAnalogueInput16Bit[1];
/*6403      */ REAL32          readAngle[1];
/*6f20      */ UNSIGNED8       lifeCounter[1];

               UNSIGNED32     LastWord;
};

/***** Structure for EEPROM variables ********************************************/
struct sCO_OD_EEPROM{
               UNSIGNED32     FirstWord;


               UNSIGNED32     LastWord;
};

/***** Declaration of Object Dictionary variables *****************************/
extern struct sCO_OD_ROM CO_OD_ROM;

extern struct sCO_OD_RAM CO_OD_RAM;

extern struct sCO_OD_EEPROM CO_OD_EEPROM;

/*******************************************************************************
   ALIASES FOR OBJECT DICTIONARY VARIABLES
*******************************************************************************/
/*1000, Data Type: UNSIGNED32 */
        #define OD_deviceType                                       CO_OD_RAM.deviceType

/*1001, Data Type: UNSIGNED8 */
        #define OD_errorRegister                                    CO_OD_RAM.errorRegister

/*1003, Data Type: UNSIGNED32, Array[8] */
        #define OD_preDefinedErrorField                             CO_OD_RAM.preDefinedErrorField
        #define ODL_preDefinedErrorField_arrayLength                8
        #define ODA_preDefinedErrorField_standardErrorField         0

/*1005, Data Type: UNSIGNED32 */
        #define OD_COB_ID_SYNCMessage                               CO_OD_RAM.COB_ID_SYNCMessage

/*1006, Data Type: UNSIGNED32 */
        #define OD_communicationCyclePeriod                         CO_OD_RAM.communicationCyclePeriod

/*1007, Data Type: UNSIGNED32 */
        #define OD_synchronousWindowLength                          CO_OD_RAM.synchronousWindowLength

/*1008, Data Type: VISIBLE_STRING */
        #define OD_manufacturerDeviceName                           CO_OD_RAM.manufacturerDeviceName
        #define ODL_manufacturerDeviceName_stringLength             4

/*1009, Data Type: VISIBLE_STRING */
        #define OD_manufacturerHardwareVersion                      CO_OD_RAM.manufacturerHardwareVersion
        #define ODL_manufacturerHardwareVersion_stringLength        2

/*100a, Data Type: VISIBLE_STRING */
        #define OD_manufacturerSoftwareVersion                      CO_OD_RAM.manufacturerSoftwareVersion
        #define ODL_manufacturerSoftwareVersion_stringLength        4

/*1014, Data Type: UNSIGNED32 */
        #define OD_COB_ID_EMCY                                      CO_OD_RAM.COB_ID_EMCY

/*1015, Data Type: UNSIGNED16 */
        #define OD_inhibitTimeEMCY                                  CO_OD_RAM.inhibitTimeEMCY

/*1016, Data Type: UNSIGNED32, Array[4] */
        #define OD_consumerHeartbeatTime                            CO_OD_RAM.consumerHeartbeatTime
        #define ODL_consumerHeartbeatTime_arrayLength               4
        #define ODA_consumerHeartbeatTime_consumerHeartbeatTime     0

/*1017, Data Type: UNSIGNED16 */
        #define OD_producerHeartbeatTime                            CO_OD_RAM.producerHeartbeatTime

/*1018, Data Type: identityObject_t */
        #define OD_identityObject                                   CO_OD_RAM.identityObject

/*1019, Data Type: UNSIGNED8 */
        #define OD_synchronousCounterOverflowValue                  CO_OD_RAM.synchronousCounterOverflowValue

/*1029, Data Type: UNSIGNED8, Array[6] */
        #define OD_errorBehavior                                    CO_OD_RAM.errorBehavior
        #define ODL_errorBehavior_arrayLength                       6
        #define ODA_errorBehavior_communication                     0
        #define ODA_errorBehavior_communicationOther                1
        #define ODA_errorBehavior_communicationPassive              2
        #define ODA_errorBehavior_generic                           3
        #define ODA_errorBehavior_deviceProfile                     4
        #define ODA_errorBehavior_manufacturerSpecific              5

/*1200, Data Type: SDOServerParameter_t */
        #define OD_SDOServerParameter                               CO_OD_RAM.SDOServerParameter

/*1400, Data Type: RPDOCommunicationParameter_t */
        #define OD_RPDOCommunicationParameter                       CO_OD_RAM.RPDOCommunicationParameter

/*1600, Data Type: RPDOMappingParameter_t */
        #define OD_RPDOMappingParameter                             CO_OD_RAM.RPDOMappingParameter

/*1800, Data Type: TPDOCommunicationParameter_t */
        #define OD_TPDOCommunicationParameter                       CO_OD_RAM.TPDOCommunicationParameter

/*1a00, Data Type: TPDOMappingParameter_t */
        #define OD_TPDOMappingParameter                             CO_OD_RAM.TPDOMappingParameter

/*1f80, Data Type: UNSIGNED32 */
        #define OD_NMTStartup                                       CO_OD_RAM.NMTStartup

/*2100, Data Type: OCTET_STRING */
        #define OD_errorStatusBits                                  CO_OD_RAM.errorStatusBits
        #define ODL_errorStatusBits_stringLength                    10

/*6000, Data Type: UNSIGNED8, Array[1] */
        #define OD_readInput8Bit                                    CO_OD_RAM.readInput8Bit
        #define ODL_readInput8Bit_arrayLength                       1
        #define ODA_readInput8Bit_statusbits07                      0

/*6200, Data Type: UNSIGNED8, Array[1] */
        #define OD_writeOutput8Bit                                  CO_OD_RAM.writeOutput8Bit
        #define ODL_writeOutput8Bit_arrayLength                     1
        #define ODA_writeOutput8Bit_commandbits07                   0

/*6401, Data Type: INTEGER16, Array[1] */
        #define OD_readAnalogueInput16Bit                           CO_OD_RAM.readAnalogueInput16Bit
        #define ODL_readAnalogueInput16Bit_arrayLength              1
        #define ODA_readAnalogueInput16Bit_temperature              0

/*6403, Data Type: REAL32, Array[1] */
        #define OD_readAngle                                        CO_OD_RAM.readAngle
        #define ODL_readAngle_arrayLength                           1
        #define ODA_readAngle_angle                                 0

/*6f20, Data Type: UNSIGNED8, Array[1] */
        #define OD_lifeCounter                                      CO_OD_RAM.lifeCounter
        #define ODL_lifeCounter_arrayLength                         1
        #define ODA_lifeCounter_lifeCounter                         0

#endif
// clang-format on
