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
      FileName:     test.eds
      FileVersion:  1
      CreationTime: 12:05PM
      CreationDate: 03-30-2020
      CreatedBy:    Alexander Miller
******************************************************************************/


/*******************************************************************************
   DEVICE INFO:
      VendorName:     IDiAL IMSL - FH Dortmund
      VendorNumber    1
      ProductName:    IMSL-ESP-Node
      ProductNumber:  1
******************************************************************************/


/*******************************************************************************
   FEATURES
*******************************************************************************/
  #define CO_NO_SYNC                     1   //Associated objects: 1005-1007
  #define CO_NO_EMERGENCY                1   //Associated objects: 1014, 1015
  #define CO_NO_TIME                       0   //Associated objects: 1012, 1013
  #define CO_NO_SDO_SERVER               1   //Associated objects: 1200-127F
  #define CO_NO_SDO_CLIENT               1   //Associated objects: 1280-12FF
  #define CO_NO_LSS_SERVER               0   //LSS Slave
  #define CO_NO_LSS_CLIENT               0   //LSS Master
  #define CO_NO_RPDO                     1   //Associated objects: 14xx, 16xx
  #define CO_NO_TPDO                     1   //Associated objects: 18xx, 1Axx
  #define CO_NO_NMT_MASTER               1


/*******************************************************************************
   OBJECT DICTIONARY
*******************************************************************************/
   #define CO_OD_NoOfElements             258


/*******************************************************************************
   TYPE DEFINITIONS FOR RECORDS
*******************************************************************************/
/*1018    */ typedef struct {
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     vendorID;
               UNSIGNED32     productCode;
               UNSIGNED32     revisionNumber;
               UNSIGNED32     serialNumber;
               }              OD_identity_t;
/*1200    */ typedef struct {
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDClientToServer;
               UNSIGNED32     COB_IDServerToClient;
               }              OD_SDOServerParameter_t;
/*1280    */ typedef struct {
               UNSIGNED8      maxSubIndex;
               UNSIGNED32     COB_IDClientToServer;
               UNSIGNED32     COB_IDServerToClient;
               UNSIGNED8      nodeIDOfTheSDOServer;
               }              OD_SDOClientParameter_t;
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
/*200a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     version;
               }              OD_manufacturerSoftwareVersion_t;
/*4000    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      command;
               UNSIGNED8      quickStartDeviceCommand;
               INTEGER16      deviceCommandSetError;
               INTEGER32      quickStartDesiredValue0;
               INTEGER32      quickStartDesiredValue1;
               INTEGER16      quickStartDesiredValue0Int16;
               }              OD_deviceCommand_t;
/*4001    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      error;
               UNSIGNED32     warningRegister;
               UNSIGNED32     warningConfiguration;
               }              OD_manufacturerErrorRegister_t;
/*4002    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     statusRegister;
               UNSIGNED16     statusRegister16Bit;
               }              OD_statusRegister_t;
/*4003    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      deviceMode;
               }              OD_deviceMode_t;
/*4004    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      powerEnable;
               }              OD_powerEnable_t;
/*4010    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      reserved;
               UNSIGNED8      eventOnError_cmd1;
               UNSIGNED8      eventOnError_cmd2;
               UNSIGNED8      eventOnError_cmd3;
               UNSIGNED8      eventOnError_cmd4;
               UNSIGNED8      commandsOnCommunicationErrorsCmd1;
               UNSIGNED8      commandsOnCommunicationErrorsCmd2;
               UNSIGNED8      commandsOnCommunicationErrorsCmd3;
               UNSIGNED8      commandsOnCommunicationErrorsCmd4;
               }              OD_reserved0_t;
/*4014    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      reserved;
               UNSIGNED8      quickStartConfigurationUserCommand1Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand1Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand1Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand1Instruction4;
               UNSIGNED8      quickStartConfigurationUserCommand2Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand2Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand2Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand2Instruction4;
               UNSIGNED8      quickStartConfigurationUserCommand3Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand3Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand3Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand3Instruction4;
               UNSIGNED8      quickStartConfigurationUserCommand4Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand4Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand4Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand4Instruction4;
               UNSIGNED8      quickStartConfigurationUserCommand5Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand5Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand5Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand5Instruction4;
               UNSIGNED8      quickStartConfigurationUserCommand6Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand6Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand6Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand6Instruction4;
               UNSIGNED8      quickStartConfigurationUserCommand7Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand7Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand7Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand7Instruction4;
               UNSIGNED8      quickStartConfigurationUserCommand8Instruction1;
               UNSIGNED8      quickStartConfigurationUserCommand8Instruction2;
               UNSIGNED8      quickStartConfigurationUserCommand8Instruction3;
               UNSIGNED8      quickStartConfigurationUserCommand8Instruction4;
               }              OD_reserved1_t;
/*4020    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     deviceCode;
               UNSIGNED16     deviceSubcode;
               }              OD_deviceCode_t;
/*4023    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     softwareVersion;
               UNSIGNED16     softwareSubversion;
               UNSIGNED32     powerCardSoftwareVersion;
               UNSIGNED32     powerCardBootloaderVersion;
               }              OD_motorSoftwareVersion_t;
/*4024    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     hardwareVersion;
               }              OD_motorHardwareVersion_t;
/*402c    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     freeData;
               }              OD_freeData_t;
/*402e    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     OEMDataCommand;
               UNSIGNED32     OEMDataD0;
               UNSIGNED32     OEMDataD1;
               UNSIGNED32     OEMDataD2;
               UNSIGNED32     OEMDataD3;
               UNSIGNED32     OEMDataD4;
               UNSIGNED32     OEMDataD5;
               UNSIGNED32     OEMDataD6;
               UNSIGNED32     OEMDataD7;
               UNSIGNED32     OEMDataD8;
               UNSIGNED32     OEMDataD9;
               }              OD_OEMDataCommand_t;
/*402f    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     userDataCommand;
               UNSIGNED32     userDataD0;
               UNSIGNED32     userDataD1;
               UNSIGNED32     userDataD2;
               UNSIGNED32     userDataD3;
               }              OD_userDataCommand_t;
/*4031    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     maxPowerVoltage;
               UNSIGNED16     minPowerVoltage;
               UNSIGNED16     maxElectronicVoltage;
               UNSIGNED16     minElectronicVoltage;
               }              OD_maxPowerVoltage_t;
/*4032    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     maxMotorCurrent;
               }              OD_maxMotorCurrent_t;
/*4050    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      inputAssignmentEnable;
               }              OD_inputAssignmentEnable_t;
/*4051    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      inputAssignmentErrorQuitting;
               }              OD_inputAssignmentErrorQuitting_t;
/*4052    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      inputAssignmentStartStop;
               }              OD_inputAssignmentStartStop_t;
/*4055    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      inputAssignmentPositiveLimitSwitch;
               }              OD_inputAssignmentPositiveLimitSwitch_t;
/*4056    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      inputAssignmentNegativeLimitSwitch;
               }              OD_inputAssignmentNegativeLimitSwitch_t;
/*4057    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      inputAssignmentReferenceSwitch;
               }              OD_inputAssignmentReferenceSwitch_t;
/*4060    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      outputAssignmentError;
               }              OD_outputAssignmentError_t;
/*4080    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      continueMode;
               }              OD_continueMode_t;
/*4090    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     minimumUpError;
               UNSIGNED32     ballastOnThreshold;
               UNSIGNED32     voltageControlledDeceleration;
               }              OD_minimumUpError_t;
/*4100    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      analogueInput0;
               }              OD_analogueInput0_t;
/*4108    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      analogueIntputOffset;
               }              OD_analogueIntputOffset_t;
/*410a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      analogueIntputDeadband;
               }              OD_analogueIntputDeadband_t;
/*4110    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     electronicVoltageUe;
               }              OD_electronicVoltageUe_t;
/*4111    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     powerVoltageUp;
               }              OD_powerVoltageUp_t;
/*4112    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      motorVoltageUm;
               }              OD_motorVoltageUm_t;
/*4113    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      motorCurrentIm;
               }              OD_motorCurrentIm_t;
/*4114    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      temperatureOfPowerAmplifier;
               INTEGER16      temperatureOfMotor;
               }              OD_temperatureOfPowerAmplifier_t;
/*4120    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      digitalInputsPort0;
               }              OD_digitalInputsPort0_t;
/*4128    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      digitalInputsHallSensors;
               UNSIGNED8      digitalInputsEncoder;
               }              OD_digitalInputsHallSensors_t;
/*4150    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      digitalOutputsPort0;
               }              OD_digitalOutputsPort0_t;
/*4154    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      enableDigitalOutputs;
               }              OD_enableDigitalOutputs_t;
/*4200    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      currentDesiredValue;
               }              OD_currentDesiredValue_t;
/*4261    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      currentCommandedValue;
               }              OD_currentCommandedValue_t;
/*4262    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      currentActualValue;
               INTEGER32      currentActualFilteredValue;
               }              OD_currentActualValue0_t;
/*4263    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      currentFollowingError;
               }              OD_currentFollowingError_t;
/*42a0    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     currentControllerSampleTime;
               UNSIGNED8      currentActualFilteredValueFilterLevel;
               }              OD_currentControllerSampleTime_t;
/*4300    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityDesiredValue;
               }              OD_velocityDesiredValue_t;
/*4302    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityScaleFactorNumerator;
               }              OD_velocityScaleFactorNumerator_t;
/*4303    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityScaleFactorDenominator;
               }              OD_velocityScaleFactorDenominator_t;
/*4304    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     velocitySource;
               }              OD_velocitySource_t;
/*4305    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityReferenceValue;
               }              OD_velocityReferenceValue_t;
/*430a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityDimensionFactorNumerator;
               }              OD_velocityDimensionFactorNumerator_t;
/*430b    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityDimensionFactorDenominator;
               }              OD_velocityDimensionFactorDenominator_t;
/*4310    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     PID_ControllerGain;
               UNSIGNED16     PID_ControllerGainAtStandstill;
               UNSIGNED16     PID_ControllerGainAtAccelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerGainAtConstantVelocityInPositiveDirection;
               UNSIGNED16     PID_ControllerGainAtDecelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerGainAtAccelerationInNegativeDirection;
               UNSIGNED16     PID_ControllerGainAtConstantVelocityInNegativeDirection;
               UNSIGNED16     PID_ControllerGainAtDecelerationInNegativeDirection;
               }              OD_PID_ControllerGain_t;
/*4311    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     PID_ControllerIntegralFactor;
               UNSIGNED16     PID_ControllerIntegralFactorAtStandstill;
               UNSIGNED16     PID_ControllerIntegralFactorAtAccelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerIntegralFactorAtConstantVelocityInPositiveDirection;
               UNSIGNED16     PID_ControllerIntegralFactorAtDecelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerIntegralFactorAtAccelerationInNegativeDirection;
               UNSIGNED16     PID_ControllerIntegralFactorAtConstantVelocityInNegativeDirection;
               UNSIGNED16     PID_ControllerIntegralFactorAtDecelerationInNegativeDirection;
               }              OD_PID_ControllerIntegralFactor_t;
/*4312    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     PID_ControllerDifferentialFactor;
               UNSIGNED16     PID_ControllerDifferentialFactorAtStandstill;
               UNSIGNED16     PID_ControllerDifferentialFactorAtAccelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerDifferentialFactorAtConstantVelocityInPositiveDirection;
               UNSIGNED16     PID_ControllerDifferentialFactorAtDecelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerDifferentialFactorAtAccelerationInNegativeDirection;
               UNSIGNED16     PID_ControllerDifferentialFactorAtConstantVelocityInNegativeDirection;
               UNSIGNED16     PID_ControllerDifferentialFactorAtDecelerationInNegativeDirection;
               }              OD_PID_ControllerDifferentialFactor_t;
/*4313    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     PID_ControllerIntegralLimit;
               UNSIGNED16     PID_ControllerIntegralLimitAtStandstill;
               UNSIGNED16     PID_ControllerIntegralLimitAtAccelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerIntegralLimitAtConstantVelocityInPositiveDirection;
               UNSIGNED16     PID_ControllerIntegralLimitAtDecelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerIntegralLimitAtAccelerationInNegativeDirection;
               UNSIGNED16     PID_ControllerIntegralLimitAtConstantVelocityInNegativeDirection;
               UNSIGNED16     PID_ControllerIntegralLimitAtDecelerationInNegativeDirection;
               }              OD_PID_ControllerIntegralLimit_t;
/*4314    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     PID_ControllerVelocityFeedForward;
               UNSIGNED16     PID_ControllerVelocityFeedForwardAtStandstill;
               UNSIGNED16     PID_ControllerVelocityFeedForwardAtAccelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerVelocityFeedForwardAtConstantVelocityInPositiveDirection;
               UNSIGNED16     PID_ControllerVelocityFeedForwardAtDecelerationInPositiveDirection;
               UNSIGNED16     PID_ControllerVelocityFeedForwardAtAccelerationInNegativeDirection;
               UNSIGNED16     PID_ControllerVelocityFeedForwardConstantVelocityInNegativeDirection;
               UNSIGNED16     PID_ControllerVelocityFeedForwardAtDecelerationInNegativeDirection;
               }              OD_PID_ControllerVelocityFeedForward_t;
/*4315    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     PID_ControllerVelocityFeedForwardAcceleration;
               }              OD_PID_ControllerVelocityFeedForwardAcceleration_t;
/*4317    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     ixR_Factor;
               }              OD_ixR_Factor_t;
/*4318    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      PID_ControllerDifferentialSampleTime;
               }              OD_PID_ControllerDifferentialSampleTime_t;
/*4321    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityMaxLimitPositiveDirection;
               }              OD_velocityMaxLimitPositiveDirection_t;
/*4323    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityMaxLimitNegativeDirection;
               }              OD_velocityMaxLimitNegativeDirection_t;
/*4340    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityAccelerationDeltav;
               }              OD_velocityAccelerationDeltav_t;
/*4341    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityAccelerationDeltat;
               }              OD_velocityAccelerationDeltat_t;
/*4342    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityDecelerationDeltav;
               }              OD_velocityDecelerationDeltav_t;
/*4343    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityDecelerationDeltat;
               }              OD_velocityDecelerationDeltat_t;
/*4344    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityDecelerationQuickStopDeltav;
               }              OD_velocityDecelerationQuickStopDeltav_t;
/*4345    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityDecelerationQuickStopDeltat;
               }              OD_velocityDecelerationQuickStopDeltat_t;
/*434c    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      velocityRampGeneratorRampType;
               }              OD_velocityRampGeneratorRampType_t;
/*434d    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      velocityRampGeneratorState;
               }              OD_velocityRampGeneratorState_t;
/*4350    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     velocityFeedback;
               INTEGER32      velocityFeedbackReference;
               }              OD_velocityFeedback_t;
/*4380    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityAccelerationInRevMin2;
               }              OD_velocityAccelerationInRevMin2_t;
/*4381    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityDecelerationInRevMin2;
               }              OD_velocityDecelerationInRevMin2_t;
/*4382    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityQuickStopDecelerationInRevMin2;
               }              OD_velocityQuickStopDecelerationInRevMin2_t;
/*43a0    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     velocityPositionControllerSampleTime;
               }              OD_velocityPositionControllerSampleTime_t;
/*43c0    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      blockageGuardingConfigurationFlags;
               INTEGER32      blockageGuardingLowVelocity;
               INTEGER32      blockageGuardingHighVelocity;
               UNSIGNED16     blockageGuardingTime;
               UNSIGNED8      blockageGuardingStatus;
               }              OD_blockageGuardingConfigurationFlags_t;
/*43d4    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      outputRampgenerator;
               }              OD_outputRampgenerator_t;
/*4500    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      SVelDesiredValue;
               }              OD_SVelDesiredValue_t;
/*4502    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      SVelScaleFactorNumerator;
               }              OD_SVelScaleFactorNumerator_t;
/*4503    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER16      SVelScaleFactorDenominator;
               }              OD_SVelScaleFactorDenominator_t;
/*4504    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SVelSourceOfDesiredValue;
               }              OD_SVelSourceOfDesiredValue_t;
/*4505    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      SVelReferenceValue;
               }              OD_SVelReferenceValue_t;
/*4510    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SVelPI_ControllerGain;
               }              OD_SVelPI_ControllerGain_t;
/*4511    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SVelPI_ControllerIntegralFactor;
               }              OD_SVelPI_ControllerIntegralFactor_t;
/*4517    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SVelIxR_Factor;
               }              OD_SVelIxR_Factor_t;
/*4550    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SVelFeedback;
               }              OD_SVelFeedback_t;
/*45a0    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SVelSampleTime;
               }              OD_SVelSampleTime_t;
/*45a1    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SVelVelocityScalingResolution;
               }              OD_SVelVelocityScalingResolution_t;
/*4708    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER8       positionMode;
               }              OD_positionMode_t;
/*4720    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      positionLimitMinimum;
               INTEGER32      positionLimitMaximum;
               }              OD_positionLimitMinimum_t;
/*4732    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     positionFollowingErrorWindow;
               UNSIGNED32     positionFollowingErrorWindowDynamic;
               }              OD_positionFollowingErrorWindow_t;
/*4733    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     positionFollowingErrorTime;
               UNSIGNED16     positionFollowingErrorTimeDynamic;
               }              OD_positionFollowingErrorTime_t;
/*4735    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      deactivatingOfFollowingErrorCorrection;
               }              OD_deactivatingOfFollowingErrorCorrection_t;
/*473a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     positionWindow;
               }              OD_positionWindow0_t;
/*473b    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     positionWindowTime;
               UNSIGNED16     positionWindowTimeout;
               }              OD_positionWindowTime0_t;
/*473c    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     positionReachedConfigurationBits;
               }              OD_positionReachedConfigurationBits_t;
/*474c    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      positionRampGeneratorRampType;
               }              OD_positionRampGeneratorRampType_t;
/*474d    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      positionRampGeneratorState;
               }              OD_positionRampGeneratorState_t;
/*4760    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualTargetPosition;
               }              OD_actualTargetPosition_t;
/*4761    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualCommandPosition;
               }              OD_actualCommandPosition_t;
/*4762    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualPosition;
               }              OD_actualPosition_t;
/*4763    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualPositionFollowingError;
               }              OD_actualPositionFollowingError_t;
/*4764    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualPositionOfIndex;
               }              OD_actualPositionOfIndex_t;
/*4770    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualTargetPositionInIncrements;
               }              OD_actualTargetPositionInIncrements_t;
/*4771    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualCommandPositionInIncrements;
               }              OD_actualCommandPositionInIncrements_t;
/*4772    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualPositionInIncrements;
               }              OD_actualPositionInIncrements_t;
/*4773    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualFollowingErrorInIncrements;
               }              OD_actualFollowingErrorInIncrements_t;
/*4774    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualIndexPositionInIncrements;
               }              OD_actualIndexPositionInIncrements_t;
/*4790    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      absolutePositioning;
               }              OD_absolutePositioning_t;
/*4791    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      relativePositioning;
               }              OD_relativePositioning_t;
/*47a4    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      gearBackLashPath;
               UNSIGNED32     gearBackLashVelocity;
               UNSIGNED32     gearBackLashAccelerationDeceleration;
               UNSIGNED8      gearBackLashDoItInAllDirection;
               }              OD_gearBackLashPath_t;
/*47b0    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      homingCommand;
               }              OD_homingCommand_t;
/*47b1    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      homingStatus;
               INTEGER16      homingError;
               UNSIGNED8      homingState;
               INTEGER32      homingPathOfReferenceSwitchToIndex;
               INTEGER32      homingPathOfReferenceSwitchToIndexInCounts;
               }              OD_homingStatus_t;
/*47b2    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER8       homingMethod;
               }              OD_homingMethod0_t;
/*47b3    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      homingOffset;
               INTEGER32      homingOffsetMoveToZero;
               }              OD_homingOffset_t;
/*47b4    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     homingVelocitySearchingTheSwitch;
               UNSIGNED32     homingVelocitySearchingTheZeroPosition;
               UNSIGNED32     homingVelocityMoveFromOffsetToZeroPosition;
               }              OD_homingVelocitySearchingTheSwitch_t;
/*47b5    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     homingAcceleration;
               UNSIGNED32     homingDeceleration;
               }              OD_homingAcceleration0_t;
/*47b6    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     homingMaxPathForSearchingTheIndex;
               UNSIGNED16     homingIndexOffset;
               }              OD_homingMaxPathForSearchingTheIndex_t;
/*47b7    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      homingOnBlockageConfigurationFlags;
               INTEGER32      homingOnBlockageLowVelocity;
               INTEGER32      homingOnBlockageHighVelocity;
               UNSIGNED8      homingOnBlockageTime;
               INTEGER32      homingOnBlockageFollowingErrorWindow;
               INTEGER32      homingOnBlockageCurrentLimitMaxPositive;
               INTEGER32      homingOnBlockageCurrentLimitMaxNegative;
               }              OD_homingOnBlockageConfigurationFlags_t;
/*47c2    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      interpolationMethod;
               UNSIGNED32     interpolationTime;
               UNSIGNED16     interpolationDelay;
               }              OD_interpolationMethod_t;
/*47c5    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     interpolationBufferConfiguration;
               }              OD_interpolationBufferConfiguration_t;
/*47c6    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     interpolationData;
               }              OD_interpolationData_t;
/*47c7    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     interpolationActualTargetPosition;
               UNSIGNED32     interpolationActualCommandPosition;
               UNSIGNED32     interpolationActualPosition;
               }              OD_interpolationActualTargetPosition_t;
/*47c8    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      moduloMethod;
               }              OD_moduloMethod_t;
/*47c9    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     moduloValue;
               }              OD_moduloValue_t;
/*4830    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     PWM_Frequency;
               UNSIGNED8      PWM_Mode;
               INTEGER8       PWM_ControlValue;
               }              OD_PWM_Frequency_t;
/*4850    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     systemClock;
               UNSIGNED16     systemTimer2ms;
               }              OD_systemClock_t;
/*48f3    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      SSI_InterfaceConfiguration;
               UNSIGNED16     SSI_InterfaceEnocderDivider;
               INTEGER32      SSI_InterfaceCounter;
               }              OD_SSI_InterfaceConfiguration_t;
/*4900    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      motorType;
               }              OD_motorType0_t;
/*4901    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     motorRatedSpeed;
               }              OD_motorRatedSpeed_t;
/*4902    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     motorRatedVoltage;
               }              OD_motorRatedVoltage_t;
/*4910    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      motorNumberOfPoles;
               }              OD_motorNumberOfPoles_t;
/*4911    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      motorPolarity;
               }              OD_motorPolarity_t;
/*4913    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      motorCommutationType;
               }              OD_motorCommutationType_t;
/*4940    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      hallSensorType;
               }              OD_hallSensorType_t;
/*4944    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      reserved;
               UNSIGNED8      hallDiagnosticsWrongPulses;
               UNSIGNED8      hallDiagnosticsWrongOrder;
               }              OD_reserved_t;
/*4949    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      hallPulsesConfigurationFlags;
               UNSIGNED8      hallPulsesBitMaskForOutputA;
               UNSIGNED8      hallPulsesBitMaskForOutputB;
               UNSIGNED16     hallPulsesModuloValue;
               }              OD_hallPulsesConfigurationFlags_t;
/*494a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualHallPosition;
               }              OD_actualHallPosition_t;
/*4962    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     encoderResolutionInCounts;
               }              OD_encoderResolutionInCounts_t;
/*4963    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     encoderResolutionInLines;
               }              OD_encoderResolutionInLines_t;
/*496a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualEncoderPosition;
               }              OD_actualEncoderPosition_t;
/*496b    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      actualEncoderIndexPosition;
               }              OD_actualEncoderIndexPosition_t;
/*496c    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     countsIndexPulses;
               }              OD_countsIndexPulses_t;
/*4970    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      SSI_AbsoluteEncoderEnable;
               UNSIGNED8      SSI_AbsoluteEncoderStatus;
               UNSIGNED32     SSI_AbsoluteEncoderSave;
               }              OD_SSI_AbsoluteEncoderEnable_t;
/*4971    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      SSI_AbsoluteEncoderCode;
               UNSIGNED8      SSI_AbsoluteEncoderTotalResolutionInBits;
               }              OD_SSI_AbsoluteEncoderCode_t;
/*4972    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     SSI_AbsoluteEncoderSingleTurnResolutionInCounts;
               }              OD_SSI_AbsoluteEncoderSingleTurnResolutionInCounts_t;
/*497a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      SSI_AbsoluteEncoderActualPositionExtendedOn32Bits;
               INTEGER32      SSI_AbsoluteEncoderActualPosition;
               INTEGER32      SSI_AbsoluteEncoderActualRawPosition;
               }              OD_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits_t;
/*497b    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      SSI_AbsoluteEncoderActualIndexPosition;
               }              OD_SSI_AbsoluteEncoderActualIndexPosition_t;
/*497c    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     SSI_AbsoluteEncoderCountOfIndexPulses;
               }              OD_SSI_AbsoluteEncoderCountOfIndexPulses_t;
/*49a0    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      brakeManagementConfiguration;
               UNSIGNED32     brakeManagementStatus;
               INTEGER16      brakeManagementBrakeOutput;
               UNSIGNED16     brakeManagementDelay1Activating;
               UNSIGNED16     brakeManagementDelay2Activating;
               UNSIGNED16     brakeManagementDelay1Deactivating;
               UNSIGNED16     brakeManagementDelay2Deactivating;
               UNSIGNED16     brakeManagementActivatingCondition;
               UNSIGNED16     brakeManagementDeactivatingCondition;
               }              OD_brakeManagementConfiguration_t;
/*49a2    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      quasiAbsoluteEncoderConfigurationFlags;
               UNSIGNED8      quasiAbsoluteEncoderStatus;
               INTEGER16      quasiAbsoluteEncoderError;
               UNSIGNED16     quasiAbsoluteEncoderTolerance;
               UNSIGNED32     quasiAbsoluteEncoderCommand;
               INTEGER32      quasiAbsoluteEncoderCorrectedPosition;
               INTEGER32      quasiAbsoluteEncoderSavedPosition;
               INTEGER32      quasiAbsoluteEncoderSavedIndexPosition;
               UNSIGNED32     quasiAbsoluteEncoderSavedCounter;
               }              OD_quasiAbsoluteEncoderConfigurationFlags_t;
/*4a02    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED16     velocityMeasurementGateTime;
               }              OD_velocityMeasurementGateTime_t;
/*4a04    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      velocityMeasurementInCounts;
               INTEGER32      velocityMeasurementInRpm;
               }              OD_velocityMeasurementInCounts_t;
/*4b00    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      factorGroupConfiguration;
               UNSIGNED8      factorGroupPrecision;
               }              OD_factorGroupConfiguration_t;
/*4b10    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      factorGroupPolarity;
               }              OD_factorGroupPolarity_t;
/*4b11    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER8       factorGroupPositionNotationIndex;
               }              OD_factorGroupPositionNotationIndex_t;
/*4b12    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      factorGroupPositionDimensionIndex;
               }              OD_factorGroupPositionDimensionIndex_t;
/*4b13    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER8       factorGroupVelocityNotationIndex;
               }              OD_factorGroupVelocityNotationIndex_t;
/*4b14    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      factorGroupVelocityDimensionIndex;
               }              OD_factorGroupVelocityDimensionIndex_t;
/*4b15    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER8       factorGroupAccelerationNotationIndex;
               }              OD_factorGroupAccelerationNotationIndex_t;
/*4b16    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      factorGroupAccelerationDimensionIndex;
               }              OD_factorGroupAccelerationDimensionIndex_t;
/*4b17    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     factorGroupPositionScaleNumerator;
               UNSIGNED32     factorGroupPositionScaleDenominator;
               }              OD_factorGroupPositionScaleNumerator_t;
/*4b18    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     factorGroupVelocityScaleNumerator;
               UNSIGNED32     factorGroupVelocityScaleDenominator;
               }              OD_factorGroupVelocityScaleNumerator_t;
/*4b19    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     factorGroupGearRatioMotorShaftRevolution;
               UNSIGNED32     factorGroupGearRatioGearShaftRevolution;
               }              OD_factorGroupGearRatioMotorShaftRevolution_t;
/*4b1a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     factorGroupFeedConstantFeed;
               UNSIGNED32     factorGroupFeedConstantDrivingShaftRevolution;
               }              OD_factorGroupFeedConstantFeed_t;
/*6046    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     velocityMinAmountRpm;
               UNSIGNED32     velocityMaxAmountRpm;
               }              OD_vlVelocityMinMaxAmount_t;
/*6048    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     deltaSpeedRpm;
               UNSIGNED16     deltaTimes;
               }              OD_vlVelocityAcceleration_t;
/*6049    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     deltaSpeedRpm;
               UNSIGNED16     deltaTimes;
               }              OD_vlVelocityDeceleration_t;
/*604a    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     deltaSpeedRpm;
               UNSIGNED16     deltaTimes;
               }              OD_vlVelocityQuickStop_t;
/*604c    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      numerator;
               INTEGER32      denominator;
               }              OD_vlDimensionFactor_t;
/*607d    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      minPositionLimit;
               INTEGER32      maxPositionLimit;
               }              OD_softwarePositionLimit_t;
/*608f    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     encoderIncrements;
               UNSIGNED32     motorRevolutions;
               }              OD_positionEncoderResolution_t;
/*6090    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     encoderIncrements;
               UNSIGNED32     motorRevolutions;
               }              OD_velocityEncoderResolution_t;
/*6091    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     motorRevolutions;
               UNSIGNED32     shaftRevolutions;
               }              OD_gearRatio_t;
/*6092    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     feed;
               UNSIGNED32     shaftRevolutions;
               }              OD_feedConstant_t;
/*6099    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     speedDuringSearchForSwitch;
               UNSIGNED32     speedDuringSearchForZero;
               }              OD_homingSpeeds_t;
/*60c1    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               INTEGER32      interpolationData1stSetPoint;
               }              OD_interpolatedDataRecord_t;
/*60c2    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED8      interpolationTimePeriodValue;
               INTEGER8       interpolationTimeIndex;
               }              OD_interpolationTimePeriod_t;
/*60e3    */ typedef struct {
               UNSIGNED8      numberOfErrorClasses;
               INTEGER8       homingOnNegativeLimitSwitchAndIndexPulse;
               INTEGER8       homingOnPositiveLimitSwitchAndIndexPulse;
               INTEGER8       homingOnPositiveHomeSwitchAndIndexPulse;
               INTEGER8       homingOnPositiveHomeSwitchAndIndexPulse2;
               INTEGER8       homingOnNegativeHomeSwitchAndIndexPulse;
               INTEGER8       homingOnNegativeHomeSwitchAndIndexPulse2;
               INTEGER8       homingOnHomeSwitchAndIndexPulse0;
               INTEGER8       homingOnHomeSwitchAndIndexPulse1;
               INTEGER8       homingOnHomeSwitchAndIndexPulse2;
               INTEGER8       homingOnHomeSwitchAndIndexPulse3;
               INTEGER8       homingOnHomeSwitchAndIndexPulse4;
               INTEGER8       homingOnHomeSwitchAndIndexPulse5;
               INTEGER8       homingOnHomeSwitchAndIndexPulse6;
               INTEGER8       homingOnHomeSwitchAndIndexPulse7;
               INTEGER8       homingWithoutIndexPulse00;
               INTEGER8       homingWithoutIndexPulse01;
               INTEGER8       homingWithoutIndexPulse02;
               INTEGER8       homingWithoutIndexPulse03;
               INTEGER8       homingWithoutIndexPulse04;
               INTEGER8       homingWithoutIndexPulse05;
               INTEGER8       homingWithoutIndexPulse06;
               INTEGER8       homingWithoutIndexPulse07;
               INTEGER8       homingWithoutIndexPulse08;
               INTEGER8       homingWithoutIndexPulse09;
               INTEGER8       homingWithoutIndexPulse10;
               INTEGER8       homingWithoutIndexPulse11;
               INTEGER8       homingWithoutIndexPulse12;
               INTEGER8       homingWithoutIndexPulse13;
               INTEGER8       homingOnIndexPulse0;
               INTEGER8       homingOnIndexPulse1;
               INTEGER8       homingOnCurrentPosition;
               }              OD_supportedHomingMethods_t;
/*60fe    */ typedef struct {
               UNSIGNED8      numberOfEntries;
               UNSIGNED32     outputState;
               UNSIGNED32     enableBitMask;
               }              OD_digitalOutputs_t;
/*67fe    */ typedef struct {
               UNSIGNED8      numberOfErrorClasses;
               UNSIGNED8      communicationError;
               UNSIGNED8      outputError;
               UNSIGNED8      inputError;
               }              OD_errorBehaviourOld_t;

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
        #define OD_1009_hardwareVersion                             0x1009

/*100a */
        #define OD_100a_softwareVersion                             0x100a

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
        #define OD_1018_identity                                    0x1018

        #define OD_1018_0_identity_maxSubIndex                      0
        #define OD_1018_1_identity_vendorID                         1
        #define OD_1018_2_identity_productCode                      2
        #define OD_1018_3_identity_revisionNumber                   3
        #define OD_1018_4_identity_serialNumber                     4

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

/*1280 */
        #define OD_1280_SDOClientParameter                          0x1280

        #define OD_1280_0_SDOClientParameter_maxSubIndex            0
        #define OD_1280_1_SDOClientParameter_COB_IDClientToServer   1
        #define OD_1280_2_SDOClientParameter_COB_IDServerToClient   2
        #define OD_1280_3_SDOClientParameter_nodeIDOfTheSDOServer   3

/*1400 */
        #define OD_1400_RPDOCommunicationParameter                  0x1400

        #define OD_1400_0_RPDOCommunicationParameter_maxSubIndex    0
        #define OD_1400_1_RPDOCommunicationParameter_COB_IDUsedByRPDO 1
        #define OD_1400_2_RPDOCommunicationParameter_transmissionType 2

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

/*1800 */
        #define OD_1800_TPDOCommunicationParameter                  0x1800

        #define OD_1800_0_TPDOCommunicationParameter_maxSubIndex    0
        #define OD_1800_1_TPDOCommunicationParameter_COB_IDUsedByTPDO 1
        #define OD_1800_2_TPDOCommunicationParameter_transmissionType 2
        #define OD_1800_3_TPDOCommunicationParameter_inhibitTime    3
        #define OD_1800_4_TPDOCommunicationParameter_compatibilityEntry 4
        #define OD_1800_5_TPDOCommunicationParameter_eventTimer     5
        #define OD_1800_6_TPDOCommunicationParameter_SYNCStartValue 6

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

/*1f80 */
        #define OD_1f80_NMTStartup                                  0x1f80

/*200a */
        #define OD_200a_manufacturerSoftwareVersion                 0x200a

        #define OD_200a_0_manufacturerSoftwareVersion_maxSubIndex   0
        #define OD_200a_1_manufacturerSoftwareVersion_version       1

/*2100 */
        #define OD_2100_errorStatusBits                             0x2100

/*4000 */
        #define OD_4000_deviceCommand                               0x4000

        #define OD_4000_0_deviceCommand_maxSubIndex                 0
        #define OD_4000_1_deviceCommand_command                     1
        #define OD_4000_2_deviceCommand_quickStartDeviceCommand     2
        #define OD_4000_9_deviceCommand_deviceCommandSetError       9
        #define OD_4000_17_deviceCommand_quickStartDesiredValue0    17
        #define OD_4000_18_deviceCommand_quickStartDesiredValue1    18
        #define OD_4000_19_deviceCommand_quickStartDesiredValue0Int16 19

/*4001 */
        #define OD_4001_manufacturerErrorRegister                   0x4001

        #define OD_4001_0_manufacturerErrorRegister_maxSubIndex     0
        #define OD_4001_1_manufacturerErrorRegister_error           1
        #define OD_4001_17_manufacturerErrorRegister_warningRegister 17
        #define OD_4001_33_manufacturerErrorRegister_warningConfiguration 33

/*4002 */
        #define OD_4002_statusRegister                              0x4002

        #define OD_4002_0_statusRegister_maxSubIndex                0
        #define OD_4002_1_statusRegister_statusRegister             1
        #define OD_4002_4_statusRegister_statusRegister16Bit        4

/*4003 */
        #define OD_4003_deviceMode                                  0x4003

        #define OD_4003_0_deviceMode_maxSubIndex                    0
        #define OD_4003_1_deviceMode_deviceMode                     1

/*4004 */
        #define OD_4004_powerEnable                                 0x4004

        #define OD_4004_0_powerEnable_maxSubIndex                   0
        #define OD_4004_1_powerEnable_powerEnable                   1

/*4010 */
        #define OD_4010_reserved0                                   0x4010

        #define OD_4010_0_reserved0_maxSubIndex                     0
        #define OD_4010_1_reserved0_reserved                        1
        #define OD_4010_18_reserved0_eventOnError_cmd1              18
        #define OD_4010_19_reserved0_eventOnError_cmd2              19
        #define OD_4010_20_reserved0_eventOnError_cmd3              20
        #define OD_4010_21_reserved0_eventOnError_cmd4              21
        #define OD_4010_50_reserved0_commandsOnCommunicationErrorsCmd1 50
        #define OD_4010_51_reserved0_commandsOnCommunicationErrorsCmd2 51
        #define OD_4010_52_reserved0_commandsOnCommunicationErrorsCmd3 52
        #define OD_4010_53_reserved0_commandsOnCommunicationErrorsCmd4 53

/*4014 */
        #define OD_4014_reserved1                                   0x4014

        #define OD_4014_0_reserved1_maxSubIndex                     0
        #define OD_4014_1_reserved1_reserved                        1
        #define OD_4014_18_reserved1_quickStartConfigurationUserCommand1Instruction1 18
        #define OD_4014_19_reserved1_quickStartConfigurationUserCommand1Instruction2 19
        #define OD_4014_20_reserved1_quickStartConfigurationUserCommand1Instruction3 20
        #define OD_4014_21_reserved1_quickStartConfigurationUserCommand1Instruction4 21
        #define OD_4014_34_reserved1_quickStartConfigurationUserCommand2Instruction1 34
        #define OD_4014_35_reserved1_quickStartConfigurationUserCommand2Instruction2 35
        #define OD_4014_36_reserved1_quickStartConfigurationUserCommand2Instruction3 36
        #define OD_4014_37_reserved1_quickStartConfigurationUserCommand2Instruction4 37
        #define OD_4014_50_reserved1_quickStartConfigurationUserCommand3Instruction1 50
        #define OD_4014_51_reserved1_quickStartConfigurationUserCommand3Instruction2 51
        #define OD_4014_52_reserved1_quickStartConfigurationUserCommand3Instruction3 52
        #define OD_4014_53_reserved1_quickStartConfigurationUserCommand3Instruction4 53
        #define OD_4014_66_reserved1_quickStartConfigurationUserCommand4Instruction1 66
        #define OD_4014_67_reserved1_quickStartConfigurationUserCommand4Instruction2 67
        #define OD_4014_68_reserved1_quickStartConfigurationUserCommand4Instruction3 68
        #define OD_4014_69_reserved1_quickStartConfigurationUserCommand4Instruction4 69
        #define OD_4014_82_reserved1_quickStartConfigurationUserCommand5Instruction1 82
        #define OD_4014_83_reserved1_quickStartConfigurationUserCommand5Instruction2 83
        #define OD_4014_84_reserved1_quickStartConfigurationUserCommand5Instruction3 84
        #define OD_4014_85_reserved1_quickStartConfigurationUserCommand5Instruction4 85
        #define OD_4014_98_reserved1_quickStartConfigurationUserCommand6Instruction1 98
        #define OD_4014_99_reserved1_quickStartConfigurationUserCommand6Instruction2 99
        #define OD_4014_100_reserved1_quickStartConfigurationUserCommand6Instruction3 100
        #define OD_4014_101_reserved1_quickStartConfigurationUserCommand6Instruction4 101
        #define OD_4014_114_reserved1_quickStartConfigurationUserCommand7Instruction1 114
        #define OD_4014_115_reserved1_quickStartConfigurationUserCommand7Instruction2 115
        #define OD_4014_116_reserved1_quickStartConfigurationUserCommand7Instruction3 116
        #define OD_4014_117_reserved1_quickStartConfigurationUserCommand7Instruction4 117
        #define OD_4014_130_reserved1_quickStartConfigurationUserCommand8Instruction1 130
        #define OD_4014_131_reserved1_quickStartConfigurationUserCommand8Instruction2 131
        #define OD_4014_132_reserved1_quickStartConfigurationUserCommand8Instruction3 132
        #define OD_4014_133_reserved1_quickStartConfigurationUserCommand8Instruction4 133

/*4020 */
        #define OD_4020_deviceCode                                  0x4020

        #define OD_4020_0_deviceCode_maxSubIndex                    0
        #define OD_4020_1_deviceCode_deviceCode                     1
        #define OD_4020_2_deviceCode_deviceSubcode                  2

/*4023 */
        #define OD_4023_motorSoftwareVersion                        0x4023

        #define OD_4023_0_motorSoftwareVersion_maxSubIndex          0
        #define OD_4023_1_motorSoftwareVersion_softwareVersion      1
        #define OD_4023_2_motorSoftwareVersion_softwareSubversion   2
        #define OD_4023_130_motorSoftwareVersion_powerCardSoftwareVersion 130
        #define OD_4023_131_motorSoftwareVersion_powerCardBootloaderVersion 131

/*4024 */
        #define OD_4024_motorHardwareVersion                        0x4024

        #define OD_4024_0_motorHardwareVersion_maxSubIndex          0
        #define OD_4024_1_motorHardwareVersion_hardwareVersion      1

/*402c */
        #define OD_402c_freeData                                    0x402c

        #define OD_402c_0_freeData_maxSubIndex                      0
        #define OD_402c_1_freeData_freeData                         1

/*402e */
        #define OD_402e_OEMDataCommand                              0x402e

        #define OD_402e_0_OEMDataCommand_maxSubIndex                0
        #define OD_402e_1_OEMDataCommand_OEMDataCommand             1
        #define OD_402e_2_OEMDataCommand_OEMDataD0                  2
        #define OD_402e_3_OEMDataCommand_OEMDataD1                  3
        #define OD_402e_4_OEMDataCommand_OEMDataD2                  4
        #define OD_402e_5_OEMDataCommand_OEMDataD3                  5
        #define OD_402e_6_OEMDataCommand_OEMDataD4                  6
        #define OD_402e_7_OEMDataCommand_OEMDataD5                  7
        #define OD_402e_8_OEMDataCommand_OEMDataD6                  8
        #define OD_402e_9_OEMDataCommand_OEMDataD7                  9
        #define OD_402e_10_OEMDataCommand_OEMDataD8                 10
        #define OD_402e_11_OEMDataCommand_OEMDataD9                 11

/*402f */
        #define OD_402f_userDataCommand                             0x402f

        #define OD_402f_0_userDataCommand_maxSubIndex               0
        #define OD_402f_1_userDataCommand_userDataCommand           1
        #define OD_402f_2_userDataCommand_userDataD0                2
        #define OD_402f_3_userDataCommand_userDataD1                3
        #define OD_402f_4_userDataCommand_userDataD2                4
        #define OD_402f_5_userDataCommand_userDataD3                5

/*4031 */
        #define OD_4031_maxPowerVoltage                             0x4031

        #define OD_4031_0_maxPowerVoltage_maxSubIndex               0
        #define OD_4031_1_maxPowerVoltage_maxPowerVoltage           1
        #define OD_4031_2_maxPowerVoltage_minPowerVoltage           2
        #define OD_4031_3_maxPowerVoltage_maxElectronicVoltage      3
        #define OD_4031_4_maxPowerVoltage_minElectronicVoltage      4

/*4032 */
        #define OD_4032_maxMotorCurrent                             0x4032

        #define OD_4032_0_maxMotorCurrent_maxSubIndex               0
        #define OD_4032_1_maxMotorCurrent_maxMotorCurrent           1

/*4050 */
        #define OD_4050_inputAssignmentEnable                       0x4050

        #define OD_4050_0_inputAssignmentEnable_maxSubIndex         0
        #define OD_4050_1_inputAssignmentEnable_inputAssignmentEnable 1

/*4051 */
        #define OD_4051_inputAssignmentErrorQuitting                0x4051

        #define OD_4051_0_inputAssignmentErrorQuitting_maxSubIndex  0
        #define OD_4051_1_inputAssignmentErrorQuitting_inputAssignmentErrorQuitting 1

/*4052 */
        #define OD_4052_inputAssignmentStartStop                    0x4052

        #define OD_4052_0_inputAssignmentStartStop_maxSubIndex      0
        #define OD_4052_1_inputAssignmentStartStop_inputAssignmentStartStop 1

/*4055 */
        #define OD_4055_inputAssignmentPositiveLimitSwitch          0x4055

        #define OD_4055_0_inputAssignmentPositiveLimitSwitch_maxSubIndex 0
        #define OD_4055_1_inputAssignmentPositiveLimitSwitch_inputAssignmentPositiveLimitSwitch 1

/*4056 */
        #define OD_4056_inputAssignmentNegativeLimitSwitch          0x4056

        #define OD_4056_0_inputAssignmentNegativeLimitSwitch_maxSubIndex 0
        #define OD_4056_1_inputAssignmentNegativeLimitSwitch_inputAssignmentNegativeLimitSwitch 1

/*4057 */
        #define OD_4057_inputAssignmentReferenceSwitch              0x4057

        #define OD_4057_0_inputAssignmentReferenceSwitch_maxSubIndex 0
        #define OD_4057_1_inputAssignmentReferenceSwitch_inputAssignmentReferenceSwitch 1

/*4060 */
        #define OD_4060_outputAssignmentError                       0x4060

        #define OD_4060_0_outputAssignmentError_maxSubIndex         0
        #define OD_4060_1_outputAssignmentError_outputAssignmentError 1

/*4080 */
        #define OD_4080_continueMode                                0x4080

        #define OD_4080_0_continueMode_maxSubIndex                  0
        #define OD_4080_1_continueMode_continueMode                 1

/*4090 */
        #define OD_4090_minimumUpError                              0x4090

        #define OD_4090_0_minimumUpError_maxSubIndex                0
        #define OD_4090_1_minimumUpError_minimumUpError             1
        #define OD_4090_8_minimumUpError_ballastOnThreshold         8
        #define OD_4090_9_minimumUpError_voltageControlledDeceleration 9

/*4100 */
        #define OD_4100_analogueInput0                              0x4100

        #define OD_4100_0_analogueInput0_maxSubIndex                0
        #define OD_4100_1_analogueInput0_analogueInput0             1

/*4108 */
        #define OD_4108_analogueIntputOffset                        0x4108

        #define OD_4108_0_analogueIntputOffset_maxSubIndex          0
        #define OD_4108_1_analogueIntputOffset_analogueIntputOffset 1

/*410a */
        #define OD_410a_analogueIntputDeadband                      0x410a

        #define OD_410a_0_analogueIntputDeadband_maxSubIndex        0
        #define OD_410a_1_analogueIntputDeadband_analogueIntputDeadband 1

/*4110 */
        #define OD_4110_electronicVoltageUe                         0x4110

        #define OD_4110_0_electronicVoltageUe_maxSubIndex           0
        #define OD_4110_1_electronicVoltageUe_electronicVoltageUe   1

/*4111 */
        #define OD_4111_powerVoltageUp                              0x4111

        #define OD_4111_0_powerVoltageUp_maxSubIndex                0
        #define OD_4111_1_powerVoltageUp_powerVoltageUp             1

/*4112 */
        #define OD_4112_motorVoltageUm                              0x4112

        #define OD_4112_0_motorVoltageUm_maxSubIndex                0
        #define OD_4112_1_motorVoltageUm_motorVoltageUm             1

/*4113 */
        #define OD_4113_motorCurrentIm                              0x4113

        #define OD_4113_0_motorCurrentIm_maxSubIndex                0
        #define OD_4113_1_motorCurrentIm_motorCurrentIm             1

/*4114 */
        #define OD_4114_temperatureOfPowerAmplifier                 0x4114

        #define OD_4114_0_temperatureOfPowerAmplifier_maxSubIndex   0
        #define OD_4114_1_temperatureOfPowerAmplifier_temperatureOfPowerAmplifier 1
        #define OD_4114_4_temperatureOfPowerAmplifier_temperatureOfMotor 4

/*4120 */
        #define OD_4120_digitalInputsPort0                          0x4120

        #define OD_4120_0_digitalInputsPort0_maxSubIndex            0
        #define OD_4120_1_digitalInputsPort0_digitalInputsPort0     1

/*4128 */
        #define OD_4128_digitalInputsHallSensors                    0x4128

        #define OD_4128_0_digitalInputsHallSensors_maxSubIndex      0
        #define OD_4128_1_digitalInputsHallSensors_digitalInputsHallSensors 1
        #define OD_4128_2_digitalInputsHallSensors_digitalInputsEncoder 2

/*4150 */
        #define OD_4150_digitalOutputsPort0                         0x4150

        #define OD_4150_0_digitalOutputsPort0_maxSubIndex           0
        #define OD_4150_1_digitalOutputsPort0_digitalOutputsPort0   1

/*4154 */
        #define OD_4154_enableDigitalOutputs                        0x4154

        #define OD_4154_0_enableDigitalOutputs_maxSubIndex          0
        #define OD_4154_1_enableDigitalOutputs_enableDigitalOutputs 1

/*4200 */
        #define OD_4200_currentDesiredValue                         0x4200

        #define OD_4200_0_currentDesiredValue_maxSubIndex           0
        #define OD_4200_1_currentDesiredValue_currentDesiredValue   1

/*4260 */
        #define OD_4260_currentDesiredValue                         0x4260

        #define OD_4260_0_currentDesiredValue_maxSubIndex           0
        #define OD_4260_1_currentDesiredValue_currentDesiredValue   1

/*4261 */
        #define OD_4261_currentCommandedValue                       0x4261

        #define OD_4261_0_currentCommandedValue_maxSubIndex         0
        #define OD_4261_1_currentCommandedValue_currentCommandedValue 1

/*4262 */
        #define OD_4262_currentActualValue0                         0x4262

        #define OD_4262_0_currentActualValue0_maxSubIndex           0
        #define OD_4262_1_currentActualValue0_currentActualValue    1
        #define OD_4262_2_currentActualValue0_currentActualFilteredValue 2

/*4263 */
        #define OD_4263_currentFollowingError                       0x4263

        #define OD_4263_0_currentFollowingError_maxSubIndex         0
        #define OD_4263_1_currentFollowingError_currentFollowingError 1

/*42a0 */
        #define OD_42a0_currentControllerSampleTime                 0x42a0

        #define OD_42a0_0_currentControllerSampleTime_maxSubIndex   0
        #define OD_42a0_1_currentControllerSampleTime_currentControllerSampleTime 1
        #define OD_42a0_17_currentControllerSampleTime_currentActualFilteredValueFilterLevel 17

/*4300 */
        #define OD_4300_velocityDesiredValue                        0x4300

        #define OD_4300_0_velocityDesiredValue_maxSubIndex          0
        #define OD_4300_1_velocityDesiredValue_velocityDesiredValue 1

/*4302 */
        #define OD_4302_velocityScaleFactorNumerator                0x4302

        #define OD_4302_0_velocityScaleFactorNumerator_maxSubIndex  0
        #define OD_4302_1_velocityScaleFactorNumerator_velocityScaleFactorNumerator 1

/*4303 */
        #define OD_4303_velocityScaleFactorDenominator              0x4303

        #define OD_4303_0_velocityScaleFactorDenominator_maxSubIndex 0
        #define OD_4303_1_velocityScaleFactorDenominator_velocityScaleFactorDenominator 1

/*4304 */
        #define OD_4304_velocitySource                              0x4304

        #define OD_4304_0_velocitySource_maxSubIndex                0
        #define OD_4304_1_velocitySource_velocitySource             1

/*4305 */
        #define OD_4305_velocityReferenceValue                      0x4305

        #define OD_4305_0_velocityReferenceValue_maxSubIndex        0
        #define OD_4305_1_velocityReferenceValue_velocityReferenceValue 1

/*430a */
        #define OD_430a_velocityDimensionFactorNumerator            0x430a

        #define OD_430a_0_velocityDimensionFactorNumerator_maxSubIndex 0
        #define OD_430a_1_velocityDimensionFactorNumerator_velocityDimensionFactorNumerator 1

/*430b */
        #define OD_430b_velocityDimensionFactorDenominator          0x430b

        #define OD_430b_0_velocityDimensionFactorDenominator_maxSubIndex 0
        #define OD_430b_1_velocityDimensionFactorDenominator_velocityDimensionFactorDenominator 1

/*4310 */
        #define OD_4310_PID_ControllerGain                          0x4310

        #define OD_4310_0_PID_ControllerGain_maxSubIndex            0
        #define OD_4310_1_PID_ControllerGain_PID_ControllerGain     1
        #define OD_4310_2_PID_ControllerGain_PID_ControllerGainAtStandstill 2
        #define OD_4310_3_PID_ControllerGain_PID_ControllerGainAtAccelerationInPositiveDirection 3
        #define OD_4310_4_PID_ControllerGain_PID_ControllerGainAtConstantVelocityInPositiveDirection 4
        #define OD_4310_5_PID_ControllerGain_PID_ControllerGainAtDecelerationInPositiveDirection 5
        #define OD_4310_6_PID_ControllerGain_PID_ControllerGainAtAccelerationInNegativeDirection 6
        #define OD_4310_7_PID_ControllerGain_PID_ControllerGainAtConstantVelocityInNegativeDirection 7
        #define OD_4310_8_PID_ControllerGain_PID_ControllerGainAtDecelerationInNegativeDirection 8

/*4311 */
        #define OD_4311_PID_ControllerIntegralFactor                0x4311

        #define OD_4311_0_PID_ControllerIntegralFactor_maxSubIndex  0
        #define OD_4311_1_PID_ControllerIntegralFactor_PID_ControllerIntegralFactor 1
        #define OD_4311_2_PID_ControllerIntegralFactor_PID_ControllerIntegralFactorAtStandstill 2
        #define OD_4311_3_PID_ControllerIntegralFactor_PID_ControllerIntegralFactorAtAccelerationInPositiveDirection 3
        #define OD_4311_4_PID_ControllerIntegralFactor_PID_ControllerIntegralFactorAtConstantVelocityInPositiveDirection 4
        #define OD_4311_5_PID_ControllerIntegralFactor_PID_ControllerIntegralFactorAtDecelerationInPositiveDirection 5
        #define OD_4311_6_PID_ControllerIntegralFactor_PID_ControllerIntegralFactorAtAccelerationInNegativeDirection 6
        #define OD_4311_7_PID_ControllerIntegralFactor_PID_ControllerIntegralFactorAtConstantVelocityInNegativeDirection 7
        #define OD_4311_8_PID_ControllerIntegralFactor_PID_ControllerIntegralFactorAtDecelerationInNegativeDirection 8

/*4312 */
        #define OD_4312_PID_ControllerDifferentialFactor            0x4312

        #define OD_4312_0_PID_ControllerDifferentialFactor_maxSubIndex 0
        #define OD_4312_1_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactor 1
        #define OD_4312_2_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactorAtStandstill 2
        #define OD_4312_3_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactorAtAccelerationInPositiveDirection 3
        #define OD_4312_4_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactorAtConstantVelocityInPositiveDirection 4
        #define OD_4312_5_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactorAtDecelerationInPositiveDirection 5
        #define OD_4312_6_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactorAtAccelerationInNegativeDirection 6
        #define OD_4312_7_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactorAtConstantVelocityInNegativeDirection 7
        #define OD_4312_8_PID_ControllerDifferentialFactor_PID_ControllerDifferentialFactorAtDecelerationInNegativeDirection 8

/*4313 */
        #define OD_4313_PID_ControllerIntegralLimit                 0x4313

        #define OD_4313_0_PID_ControllerIntegralLimit_maxSubIndex   0
        #define OD_4313_1_PID_ControllerIntegralLimit_PID_ControllerIntegralLimit 1
        #define OD_4313_2_PID_ControllerIntegralLimit_PID_ControllerIntegralLimitAtStandstill 2
        #define OD_4313_3_PID_ControllerIntegralLimit_PID_ControllerIntegralLimitAtAccelerationInPositiveDirection 3
        #define OD_4313_4_PID_ControllerIntegralLimit_PID_ControllerIntegralLimitAtConstantVelocityInPositiveDirection 4
        #define OD_4313_5_PID_ControllerIntegralLimit_PID_ControllerIntegralLimitAtDecelerationInPositiveDirection 5
        #define OD_4313_6_PID_ControllerIntegralLimit_PID_ControllerIntegralLimitAtAccelerationInNegativeDirection 6
        #define OD_4313_7_PID_ControllerIntegralLimit_PID_ControllerIntegralLimitAtConstantVelocityInNegativeDirection 7
        #define OD_4313_8_PID_ControllerIntegralLimit_PID_ControllerIntegralLimitAtDecelerationInNegativeDirection 8

/*4314 */
        #define OD_4314_PID_ControllerVelocityFeedForward           0x4314

        #define OD_4314_0_PID_ControllerVelocityFeedForward_maxSubIndex 0
        #define OD_4314_1_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForward 1
        #define OD_4314_2_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForwardAtStandstill 2
        #define OD_4314_3_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForwardAtAccelerationInPositiveDirection 3
        #define OD_4314_4_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForwardAtConstantVelocityInPositiveDirection 4
        #define OD_4314_5_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForwardAtDecelerationInPositiveDirection 5
        #define OD_4314_6_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForwardAtAccelerationInNegativeDirection 6
        #define OD_4314_7_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForwardConstantVelocityInNegativeDirection 7
        #define OD_4314_8_PID_ControllerVelocityFeedForward_PID_ControllerVelocityFeedForwardAtDecelerationInNegativeDirection 8

/*4315 */
        #define OD_4315_PID_ControllerVelocityFeedForwardAcceleration 0x4315

        #define OD_4315_0_PID_ControllerVelocityFeedForwardAcceleration_maxSubIndex 0
        #define OD_4315_1_PID_ControllerVelocityFeedForwardAcceleration_PID_ControllerVelocityFeedForwardAcceleration 1

/*4317 */
        #define OD_4317_ixR_Factor                                  0x4317

        #define OD_4317_0_ixR_Factor_maxSubIndex                    0
        #define OD_4317_1_ixR_Factor_ixR_Factor                     1

/*4318 */
        #define OD_4318_PID_ControllerDifferentialSampleTime        0x4318

        #define OD_4318_0_PID_ControllerDifferentialSampleTime_maxSubIndex 0
        #define OD_4318_1_PID_ControllerDifferentialSampleTime_PID_ControllerDifferentialSampleTime 1

/*4321 */
        #define OD_4321_velocityMaxLimitPositiveDirection           0x4321

        #define OD_4321_0_velocityMaxLimitPositiveDirection_maxSubIndex 0
        #define OD_4321_1_velocityMaxLimitPositiveDirection_velocityMaxLimitPositiveDirection 1

/*4323 */
        #define OD_4323_velocityMaxLimitNegativeDirection           0x4323

        #define OD_4323_0_velocityMaxLimitNegativeDirection_maxSubIndex 0
        #define OD_4323_1_velocityMaxLimitNegativeDirection_velocityMaxLimitNegativeDirection 1

/*4340 */
        #define OD_4340_velocityAccelerationDeltav                  0x4340

        #define OD_4340_0_velocityAccelerationDeltav_maxSubIndex    0
        #define OD_4340_1_velocityAccelerationDeltav_velocityAccelerationDeltav 1

/*4341 */
        #define OD_4341_velocityAccelerationDeltat                  0x4341

        #define OD_4341_0_velocityAccelerationDeltat_maxSubIndex    0
        #define OD_4341_1_velocityAccelerationDeltat_velocityAccelerationDeltat 1

/*4342 */
        #define OD_4342_velocityDecelerationDeltav                  0x4342

        #define OD_4342_0_velocityDecelerationDeltav_maxSubIndex    0
        #define OD_4342_1_velocityDecelerationDeltav_velocityDecelerationDeltav 1

/*4343 */
        #define OD_4343_velocityDecelerationDeltat                  0x4343

        #define OD_4343_0_velocityDecelerationDeltat_maxSubIndex    0
        #define OD_4343_1_velocityDecelerationDeltat_velocityDecelerationDeltat 1

/*4344 */
        #define OD_4344_velocityDecelerationQuickStopDeltav         0x4344

        #define OD_4344_0_velocityDecelerationQuickStopDeltav_maxSubIndex 0
        #define OD_4344_1_velocityDecelerationQuickStopDeltav_velocityDecelerationQuickStopDeltav 1

/*4345 */
        #define OD_4345_velocityDecelerationQuickStopDeltat         0x4345

        #define OD_4345_0_velocityDecelerationQuickStopDeltat_maxSubIndex 0
        #define OD_4345_1_velocityDecelerationQuickStopDeltat_velocityDecelerationQuickStopDeltat 1

/*434c */
        #define OD_434c_velocityRampGeneratorRampType               0x434c

        #define OD_434c_0_velocityRampGeneratorRampType_maxSubIndex 0
        #define OD_434c_1_velocityRampGeneratorRampType_velocityRampGeneratorRampType 1

/*434d */
        #define OD_434d_velocityRampGeneratorState                  0x434d

        #define OD_434d_0_velocityRampGeneratorState_maxSubIndex    0
        #define OD_434d_1_velocityRampGeneratorState_velocityRampGeneratorState 1

/*4350 */
        #define OD_4350_velocityFeedback                            0x4350

        #define OD_4350_0_velocityFeedback_maxSubIndex              0
        #define OD_4350_1_velocityFeedback_velocityFeedback         1
        #define OD_4350_4_velocityFeedback_velocityFeedbackReference 4

/*4380 */
        #define OD_4380_velocityAccelerationInRevMin2               0x4380

        #define OD_4380_0_velocityAccelerationInRevMin2_maxSubIndex 0
        #define OD_4380_1_velocityAccelerationInRevMin2_velocityAccelerationInRevMin2 1

/*4381 */
        #define OD_4381_velocityDecelerationInRevMin2               0x4381

        #define OD_4381_0_velocityDecelerationInRevMin2_maxSubIndex 0
        #define OD_4381_1_velocityDecelerationInRevMin2_velocityDecelerationInRevMin2 1

/*4382 */
        #define OD_4382_velocityQuickStopDecelerationInRevMin2      0x4382

        #define OD_4382_0_velocityQuickStopDecelerationInRevMin2_maxSubIndex 0
        #define OD_4382_1_velocityQuickStopDecelerationInRevMin2_velocityQuickStopDecelerationInRevMin2 1

/*43a0 */
        #define OD_43a0_velocityPositionControllerSampleTime        0x43a0

        #define OD_43a0_0_velocityPositionControllerSampleTime_maxSubIndex 0
        #define OD_43a0_1_velocityPositionControllerSampleTime_velocityPositionControllerSampleTime 1

/*43c0 */
        #define OD_43c0_blockageGuardingConfigurationFlags          0x43c0

        #define OD_43c0_0_blockageGuardingConfigurationFlags_maxSubIndex 0
        #define OD_43c0_1_blockageGuardingConfigurationFlags_blockageGuardingConfigurationFlags 1
        #define OD_43c0_2_blockageGuardingConfigurationFlags_blockageGuardingLowVelocity 2
        #define OD_43c0_3_blockageGuardingConfigurationFlags_blockageGuardingHighVelocity 3
        #define OD_43c0_4_blockageGuardingConfigurationFlags_blockageGuardingTime 4
        #define OD_43c0_5_blockageGuardingConfigurationFlags_blockageGuardingStatus 5

/*43d4 */
        #define OD_43d4_outputRampgenerator                         0x43d4

        #define OD_43d4_0_outputRampgenerator_maxSubIndex           0
        #define OD_43d4_1_outputRampgenerator_outputRampgenerator   1

/*4500 */
        #define OD_4500_SVelDesiredValue                            0x4500

        #define OD_4500_0_SVelDesiredValue_maxSubIndex              0
        #define OD_4500_1_SVelDesiredValue_SVelDesiredValue         1

/*4502 */
        #define OD_4502_SVelScaleFactorNumerator                    0x4502

        #define OD_4502_0_SVelScaleFactorNumerator_maxSubIndex      0
        #define OD_4502_1_SVelScaleFactorNumerator_SVelScaleFactorNumerator 1

/*4503 */
        #define OD_4503_SVelScaleFactorDenominator                  0x4503

        #define OD_4503_0_SVelScaleFactorDenominator_maxSubIndex    0
        #define OD_4503_1_SVelScaleFactorDenominator_SVelScaleFactorDenominator 1

/*4504 */
        #define OD_4504_SVelSourceOfDesiredValue                    0x4504

        #define OD_4504_0_SVelSourceOfDesiredValue_maxSubIndex      0
        #define OD_4504_1_SVelSourceOfDesiredValue_SVelSourceOfDesiredValue 1

/*4505 */
        #define OD_4505_SVelReferenceValue                          0x4505

        #define OD_4505_0_SVelReferenceValue_maxSubIndex            0
        #define OD_4505_1_SVelReferenceValue_SVelReferenceValue     1

/*4510 */
        #define OD_4510_SVelPI_ControllerGain                       0x4510

        #define OD_4510_0_SVelPI_ControllerGain_maxSubIndex         0
        #define OD_4510_1_SVelPI_ControllerGain_SVelPI_ControllerGain 1

/*4511 */
        #define OD_4511_SVelPI_ControllerIntegralFactor             0x4511

        #define OD_4511_0_SVelPI_ControllerIntegralFactor_maxSubIndex 0
        #define OD_4511_1_SVelPI_ControllerIntegralFactor_SVelPI_ControllerIntegralFactor 1

/*4517 */
        #define OD_4517_SVelIxR_Factor                              0x4517

        #define OD_4517_0_SVelIxR_Factor_maxSubIndex                0
        #define OD_4517_1_SVelIxR_Factor_SVelIxR_Factor             1

/*4550 */
        #define OD_4550_SVelFeedback                                0x4550

        #define OD_4550_0_SVelFeedback_maxSubIndex                  0
        #define OD_4550_1_SVelFeedback_SVelFeedback                 1

/*45a0 */
        #define OD_45a0_SVelSampleTime                              0x45a0

        #define OD_45a0_0_SVelSampleTime_maxSubIndex                0
        #define OD_45a0_1_SVelSampleTime_SVelSampleTime             1

/*45a1 */
        #define OD_45a1_SVelVelocityScalingResolution               0x45a1

        #define OD_45a1_0_SVelVelocityScalingResolution_maxSubIndex 0
        #define OD_45a1_1_SVelVelocityScalingResolution_SVelVelocityScalingResolution 1

/*4708 */
        #define OD_4708_positionMode                                0x4708

        #define OD_4708_0_positionMode_maxSubIndex                  0
        #define OD_4708_1_positionMode_positionMode                 1

/*4720 */
        #define OD_4720_positionLimitMinimum                        0x4720

        #define OD_4720_0_positionLimitMinimum_maxSubIndex          0
        #define OD_4720_1_positionLimitMinimum_positionLimitMinimum 1
        #define OD_4720_2_positionLimitMinimum_positionLimitMaximum 2

/*4732 */
        #define OD_4732_positionFollowingErrorWindow                0x4732

        #define OD_4732_0_positionFollowingErrorWindow_maxSubIndex  0
        #define OD_4732_1_positionFollowingErrorWindow_positionFollowingErrorWindow 1
        #define OD_4732_2_positionFollowingErrorWindow_positionFollowingErrorWindowDynamic 2

/*4733 */
        #define OD_4733_positionFollowingErrorTime                  0x4733

        #define OD_4733_0_positionFollowingErrorTime_maxSubIndex    0
        #define OD_4733_1_positionFollowingErrorTime_positionFollowingErrorTime 1
        #define OD_4733_2_positionFollowingErrorTime_positionFollowingErrorTimeDynamic 2

/*4735 */
        #define OD_4735_deactivatingOfFollowingErrorCorrection      0x4735

        #define OD_4735_0_deactivatingOfFollowingErrorCorrection_maxSubIndex 0
        #define OD_4735_1_deactivatingOfFollowingErrorCorrection_deactivatingOfFollowingErrorCorrection 1

/*473a */
        #define OD_473a_positionWindow0                             0x473a

        #define OD_473a_0_positionWindow0_maxSubIndex               0
        #define OD_473a_1_positionWindow0_positionWindow            1

/*473b */
        #define OD_473b_positionWindowTime0                         0x473b

        #define OD_473b_0_positionWindowTime0_maxSubIndex           0
        #define OD_473b_1_positionWindowTime0_positionWindowTime    1
        #define OD_473b_2_positionWindowTime0_positionWindowTimeout 2

/*473c */
        #define OD_473c_positionReachedConfigurationBits            0x473c

        #define OD_473c_0_positionReachedConfigurationBits_maxSubIndex 0
        #define OD_473c_1_positionReachedConfigurationBits_positionReachedConfigurationBits 1

/*474c */
        #define OD_474c_positionRampGeneratorRampType               0x474c

        #define OD_474c_0_positionRampGeneratorRampType_maxSubIndex 0
        #define OD_474c_1_positionRampGeneratorRampType_positionRampGeneratorRampType 1

/*474d */
        #define OD_474d_positionRampGeneratorState                  0x474d

        #define OD_474d_0_positionRampGeneratorState_maxSubIndex    0
        #define OD_474d_1_positionRampGeneratorState_positionRampGeneratorState 1

/*4760 */
        #define OD_4760_actualTargetPosition                        0x4760

        #define OD_4760_0_actualTargetPosition_maxSubIndex          0
        #define OD_4760_1_actualTargetPosition_actualTargetPosition 1

/*4761 */
        #define OD_4761_actualCommandPosition                       0x4761

        #define OD_4761_0_actualCommandPosition_maxSubIndex         0
        #define OD_4761_1_actualCommandPosition_actualCommandPosition 1

/*4762 */
        #define OD_4762_actualPosition                              0x4762

        #define OD_4762_0_actualPosition_maxSubIndex                0
        #define OD_4762_1_actualPosition_actualPosition             1

/*4763 */
        #define OD_4763_actualPositionFollowingError                0x4763

        #define OD_4763_0_actualPositionFollowingError_maxSubIndex  0
        #define OD_4763_1_actualPositionFollowingError_actualPositionFollowingError 1

/*4764 */
        #define OD_4764_actualPositionOfIndex                       0x4764

        #define OD_4764_0_actualPositionOfIndex_maxSubIndex         0
        #define OD_4764_1_actualPositionOfIndex_actualPositionOfIndex 1

/*4770 */
        #define OD_4770_actualTargetPositionInIncrements            0x4770

        #define OD_4770_0_actualTargetPositionInIncrements_maxSubIndex 0
        #define OD_4770_1_actualTargetPositionInIncrements_actualTargetPositionInIncrements 1

/*4771 */
        #define OD_4771_actualCommandPositionInIncrements           0x4771

        #define OD_4771_0_actualCommandPositionInIncrements_maxSubIndex 0
        #define OD_4771_1_actualCommandPositionInIncrements_actualCommandPositionInIncrements 1

/*4772 */
        #define OD_4772_actualPositionInIncrements                  0x4772

        #define OD_4772_0_actualPositionInIncrements_maxSubIndex    0
        #define OD_4772_1_actualPositionInIncrements_actualPositionInIncrements 1

/*4773 */
        #define OD_4773_actualFollowingErrorInIncrements            0x4773

        #define OD_4773_0_actualFollowingErrorInIncrements_maxSubIndex 0
        #define OD_4773_1_actualFollowingErrorInIncrements_actualFollowingErrorInIncrements 1

/*4774 */
        #define OD_4774_actualIndexPositionInIncrements             0x4774

        #define OD_4774_0_actualIndexPositionInIncrements_maxSubIndex 0
        #define OD_4774_1_actualIndexPositionInIncrements_actualIndexPositionInIncrements 1

/*4790 */
        #define OD_4790_absolutePositioning                         0x4790

        #define OD_4790_0_absolutePositioning_maxSubIndex           0
        #define OD_4790_1_absolutePositioning_absolutePositioning   1

/*4791 */
        #define OD_4791_relativePositioning                         0x4791

        #define OD_4791_0_relativePositioning_maxSubIndex           0
        #define OD_4791_1_relativePositioning_relativePositioning   1

/*47a4 */
        #define OD_47a4_gearBackLashPath                            0x47a4

        #define OD_47a4_0_gearBackLashPath_maxSubIndex              0
        #define OD_47a4_2_gearBackLashPath_gearBackLashPath         2
        #define OD_47a4_3_gearBackLashPath_gearBackLashVelocity     3
        #define OD_47a4_4_gearBackLashPath_gearBackLashAccelerationDeceleration 4
        #define OD_47a4_5_gearBackLashPath_gearBackLashDoItInAllDirection 5

/*47b0 */
        #define OD_47b0_homingCommand                               0x47b0

        #define OD_47b0_0_homingCommand_maxSubIndex                 0
        #define OD_47b0_1_homingCommand_homingCommand               1

/*47b1 */
        #define OD_47b1_homingStatus                                0x47b1

        #define OD_47b1_0_homingStatus_maxSubIndex                  0
        #define OD_47b1_1_homingStatus_homingStatus                 1
        #define OD_47b1_2_homingStatus_homingError                  2
        #define OD_47b1_3_homingStatus_homingState                  3
        #define OD_47b1_4_homingStatus_homingPathOfReferenceSwitchToIndex 4
        #define OD_47b1_5_homingStatus_homingPathOfReferenceSwitchToIndexInCounts 5

/*47b2 */
        #define OD_47b2_homingMethod0                               0x47b2

        #define OD_47b2_0_homingMethod0_maxSubIndex                 0
        #define OD_47b2_1_homingMethod0_homingMethod                1

/*47b3 */
        #define OD_47b3_homingOffset                                0x47b3

        #define OD_47b3_0_homingOffset_maxSubIndex                  0
        #define OD_47b3_1_homingOffset_homingOffset                 1
        #define OD_47b3_2_homingOffset_homingOffsetMoveToZero       2

/*47b4 */
        #define OD_47b4_homingVelocitySearchingTheSwitch            0x47b4

        #define OD_47b4_0_homingVelocitySearchingTheSwitch_maxSubIndex 0
        #define OD_47b4_1_homingVelocitySearchingTheSwitch_homingVelocitySearchingTheSwitch 1
        #define OD_47b4_2_homingVelocitySearchingTheSwitch_homingVelocitySearchingTheZeroPosition 2
        #define OD_47b4_3_homingVelocitySearchingTheSwitch_homingVelocityMoveFromOffsetToZeroPosition 3

/*47b5 */
        #define OD_47b5_homingAcceleration0                         0x47b5

        #define OD_47b5_0_homingAcceleration0_maxSubIndex           0
        #define OD_47b5_1_homingAcceleration0_homingAcceleration    1
        #define OD_47b5_2_homingAcceleration0_homingDeceleration    2

/*47b6 */
        #define OD_47b6_homingMaxPathForSearchingTheIndex           0x47b6

        #define OD_47b6_0_homingMaxPathForSearchingTheIndex_maxSubIndex 0
        #define OD_47b6_1_homingMaxPathForSearchingTheIndex_homingMaxPathForSearchingTheIndex 1
        #define OD_47b6_2_homingMaxPathForSearchingTheIndex_homingIndexOffset 2

/*47b7 */
        #define OD_47b7_homingOnBlockageConfigurationFlags          0x47b7

        #define OD_47b7_0_homingOnBlockageConfigurationFlags_maxSubIndex 0
        #define OD_47b7_1_homingOnBlockageConfigurationFlags_homingOnBlockageConfigurationFlags 1
        #define OD_47b7_2_homingOnBlockageConfigurationFlags_homingOnBlockageLowVelocity 2
        #define OD_47b7_3_homingOnBlockageConfigurationFlags_homingOnBlockageHighVelocity 3
        #define OD_47b7_4_homingOnBlockageConfigurationFlags_homingOnBlockageTime 4
        #define OD_47b7_5_homingOnBlockageConfigurationFlags_homingOnBlockageFollowingErrorWindow 5
        #define OD_47b7_17_homingOnBlockageConfigurationFlags_homingOnBlockageCurrentLimitMaxPositive 17
        #define OD_47b7_18_homingOnBlockageConfigurationFlags_homingOnBlockageCurrentLimitMaxNegative 18

/*47c2 */
        #define OD_47c2_interpolationMethod                         0x47c2

        #define OD_47c2_0_interpolationMethod_maxSubIndex           0
        #define OD_47c2_1_interpolationMethod_interpolationMethod   1
        #define OD_47c2_2_interpolationMethod_interpolationTime     2
        #define OD_47c2_7_interpolationMethod_interpolationDelay    7

/*47c5 */
        #define OD_47c5_interpolationBufferConfiguration            0x47c5

        #define OD_47c5_0_interpolationBufferConfiguration_maxSubIndex 0
        #define OD_47c5_1_interpolationBufferConfiguration_interpolationBufferConfiguration 1

/*47c6 */
        #define OD_47c6_interpolationData                           0x47c6

        #define OD_47c6_0_interpolationData_maxSubIndex             0
        #define OD_47c6_1_interpolationData_interpolationData       1

/*47c7 */
        #define OD_47c7_interpolationActualTargetPosition           0x47c7

        #define OD_47c7_0_interpolationActualTargetPosition_maxSubIndex 0
        #define OD_47c7_1_interpolationActualTargetPosition_interpolationActualTargetPosition 1
        #define OD_47c7_2_interpolationActualTargetPosition_interpolationActualCommandPosition 2
        #define OD_47c7_3_interpolationActualTargetPosition_interpolationActualPosition 3

/*47c8 */
        #define OD_47c8_moduloMethod                                0x47c8

        #define OD_47c8_0_moduloMethod_maxSubIndex                  0
        #define OD_47c8_1_moduloMethod_moduloMethod                 1

/*47c9 */
        #define OD_47c9_moduloValue                                 0x47c9

        #define OD_47c9_0_moduloValue_maxSubIndex                   0
        #define OD_47c9_1_moduloValue_moduloValue                   1

/*4830 */
        #define OD_4830_PWM_Frequency                               0x4830

        #define OD_4830_0_PWM_Frequency_maxSubIndex                 0
        #define OD_4830_1_PWM_Frequency_PWM_Frequency               1
        #define OD_4830_2_PWM_Frequency_PWM_Mode                    2
        #define OD_4830_5_PWM_Frequency_PWM_ControlValue            5

/*4850 */
        #define OD_4850_systemClock                                 0x4850

        #define OD_4850_0_systemClock_maxSubIndex                   0
        #define OD_4850_1_systemClock_systemClock                   1
        #define OD_4850_3_systemClock_systemTimer2ms                3

/*48f3 */
        #define OD_48f3_SSI_InterfaceConfiguration                  0x48f3

        #define OD_48f3_0_SSI_InterfaceConfiguration_maxSubIndex    0
        #define OD_48f3_1_SSI_InterfaceConfiguration_SSI_InterfaceConfiguration 1
        #define OD_48f3_2_SSI_InterfaceConfiguration_SSI_InterfaceEnocderDivider 2
        #define OD_48f3_3_SSI_InterfaceConfiguration_SSI_InterfaceCounter 3

/*4900 */
        #define OD_4900_motorType0                                  0x4900

        #define OD_4900_0_motorType0_maxSubIndex                    0
        #define OD_4900_1_motorType0_motorType                      1

/*4901 */
        #define OD_4901_motorRatedSpeed                             0x4901

        #define OD_4901_0_motorRatedSpeed_maxSubIndex               0
        #define OD_4901_1_motorRatedSpeed_motorRatedSpeed           1

/*4902 */
        #define OD_4902_motorRatedVoltage                           0x4902

        #define OD_4902_0_motorRatedVoltage_maxSubIndex             0
        #define OD_4902_1_motorRatedVoltage_motorRatedVoltage       1

/*4910 */
        #define OD_4910_motorNumberOfPoles                          0x4910

        #define OD_4910_0_motorNumberOfPoles_maxSubIndex            0
        #define OD_4910_1_motorNumberOfPoles_motorNumberOfPoles     1

/*4911 */
        #define OD_4911_motorPolarity                               0x4911

        #define OD_4911_0_motorPolarity_maxSubIndex                 0
        #define OD_4911_1_motorPolarity_motorPolarity               1

/*4913 */
        #define OD_4913_motorCommutationType                        0x4913

        #define OD_4913_0_motorCommutationType_maxSubIndex          0
        #define OD_4913_1_motorCommutationType_motorCommutationType 1

/*4940 */
        #define OD_4940_hallSensorType                              0x4940

        #define OD_4940_0_hallSensorType_maxSubIndex                0
        #define OD_4940_1_hallSensorType_hallSensorType             1

/*4944 */
        #define OD_4944_reserved                                    0x4944

        #define OD_4944_0_reserved_maxSubIndex                      0
        #define OD_4944_1_reserved_reserved                         1
        #define OD_4944_2_reserved_hallDiagnosticsWrongPulses       2
        #define OD_4944_3_reserved_hallDiagnosticsWrongOrder        3

/*4949 */
        #define OD_4949_hallPulsesConfigurationFlags                0x4949

        #define OD_4949_0_hallPulsesConfigurationFlags_maxSubIndex  0
        #define OD_4949_1_hallPulsesConfigurationFlags_hallPulsesConfigurationFlags 1
        #define OD_4949_2_hallPulsesConfigurationFlags_hallPulsesBitMaskForOutputA 2
        #define OD_4949_3_hallPulsesConfigurationFlags_hallPulsesBitMaskForOutputB 3
        #define OD_4949_4_hallPulsesConfigurationFlags_hallPulsesModuloValue 4

/*494a */
        #define OD_494a_actualHallPosition                          0x494a

        #define OD_494a_0_actualHallPosition_maxSubIndex            0
        #define OD_494a_1_actualHallPosition_actualHallPosition     1

/*4962 */
        #define OD_4962_encoderResolutionInCounts                   0x4962

        #define OD_4962_0_encoderResolutionInCounts_maxSubIndex     0
        #define OD_4962_1_encoderResolutionInCounts_encoderResolutionInCounts 1

/*4963 */
        #define OD_4963_encoderResolutionInLines                    0x4963

        #define OD_4963_0_encoderResolutionInLines_maxSubIndex      0
        #define OD_4963_1_encoderResolutionInLines_encoderResolutionInLines 1

/*496a */
        #define OD_496a_actualEncoderPosition                       0x496a

        #define OD_496a_0_actualEncoderPosition_maxSubIndex         0
        #define OD_496a_1_actualEncoderPosition_actualEncoderPosition 1

/*496b */
        #define OD_496b_actualEncoderIndexPosition                  0x496b

        #define OD_496b_0_actualEncoderIndexPosition_maxSubIndex    0
        #define OD_496b_1_actualEncoderIndexPosition_actualEncoderIndexPosition 1

/*496c */
        #define OD_496c_countsIndexPulses                           0x496c

        #define OD_496c_0_countsIndexPulses_maxSubIndex             0
        #define OD_496c_1_countsIndexPulses_countsIndexPulses       1

/*4970 */
        #define OD_4970_SSI_AbsoluteEncoderEnable                   0x4970

        #define OD_4970_0_SSI_AbsoluteEncoderEnable_maxSubIndex     0
        #define OD_4970_1_SSI_AbsoluteEncoderEnable_SSI_AbsoluteEncoderEnable 1
        #define OD_4970_2_SSI_AbsoluteEncoderEnable_SSI_AbsoluteEncoderStatus 2
        #define OD_4970_9_SSI_AbsoluteEncoderEnable_SSI_AbsoluteEncoderSave 9

/*4971 */
        #define OD_4971_SSI_AbsoluteEncoderCode                     0x4971

        #define OD_4971_0_SSI_AbsoluteEncoderCode_maxSubIndex       0
        #define OD_4971_1_SSI_AbsoluteEncoderCode_SSI_AbsoluteEncoderCode 1
        #define OD_4971_2_SSI_AbsoluteEncoderCode_SSI_AbsoluteEncoderTotalResolutionInBits 2

/*4972 */
        #define OD_4972_SSI_AbsoluteEncoderSingleTurnResolutionInCounts 0x4972

        #define OD_4972_0_SSI_AbsoluteEncoderSingleTurnResolutionInCounts_maxSubIndex 0
        #define OD_4972_1_SSI_AbsoluteEncoderSingleTurnResolutionInCounts_SSI_AbsoluteEncoderSingleTurnResolutionInCounts 1

/*497a */
        #define OD_497a_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits 0x497a

        #define OD_497a_0_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits_maxSubIndex 0
        #define OD_497a_1_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits 1
        #define OD_497a_2_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits_SSI_AbsoluteEncoderActualPosition 2
        #define OD_497a_3_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits_SSI_AbsoluteEncoderActualRawPosition 3

/*497b */
        #define OD_497b_SSI_AbsoluteEncoderActualIndexPosition      0x497b

        #define OD_497b_0_SSI_AbsoluteEncoderActualIndexPosition_maxSubIndex 0
        #define OD_497b_1_SSI_AbsoluteEncoderActualIndexPosition_SSI_AbsoluteEncoderActualIndexPosition 1

/*497c */
        #define OD_497c_SSI_AbsoluteEncoderCountOfIndexPulses       0x497c

        #define OD_497c_0_SSI_AbsoluteEncoderCountOfIndexPulses_maxSubIndex 0
        #define OD_497c_1_SSI_AbsoluteEncoderCountOfIndexPulses_SSI_AbsoluteEncoderCountOfIndexPulses 1

/*49a0 */
        #define OD_49a0_brakeManagementConfiguration                0x49a0

        #define OD_49a0_0_brakeManagementConfiguration_maxSubIndex  0
        #define OD_49a0_1_brakeManagementConfiguration_brakeManagementConfiguration 1
        #define OD_49a0_2_brakeManagementConfiguration_brakeManagementStatus 2
        #define OD_49a0_9_brakeManagementConfiguration_brakeManagementBrakeOutput 9
        #define OD_49a0_17_brakeManagementConfiguration_brakeManagementDelay1Activating 17
        #define OD_49a0_18_brakeManagementConfiguration_brakeManagementDelay2Activating 18
        #define OD_49a0_19_brakeManagementConfiguration_brakeManagementDelay1Deactivating 19
        #define OD_49a0_20_brakeManagementConfiguration_brakeManagementDelay2Deactivating 20
        #define OD_49a0_25_brakeManagementConfiguration_brakeManagementActivatingCondition 25
        #define OD_49a0_27_brakeManagementConfiguration_brakeManagementDeactivatingCondition 27

/*49a2 */
        #define OD_49a2_quasiAbsoluteEncoderConfigurationFlags      0x49a2

        #define OD_49a2_0_quasiAbsoluteEncoderConfigurationFlags_maxSubIndex 0
        #define OD_49a2_1_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderConfigurationFlags 1
        #define OD_49a2_2_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderStatus 2
        #define OD_49a2_3_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderError 3
        #define OD_49a2_8_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderTolerance 8
        #define OD_49a2_9_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderCommand 9
        #define OD_49a2_17_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderCorrectedPosition 17
        #define OD_49a2_50_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderSavedPosition 50
        #define OD_49a2_51_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderSavedIndexPosition 51
        #define OD_49a2_52_quasiAbsoluteEncoderConfigurationFlags_quasiAbsoluteEncoderSavedCounter 52

/*4a02 */
        #define OD_4a02_velocityMeasurementGateTime                 0x4a02

        #define OD_4a02_0_velocityMeasurementGateTime_maxSubIndex   0
        #define OD_4a02_1_velocityMeasurementGateTime_velocityMeasurementGateTime 1

/*4a04 */
        #define OD_4a04_velocityMeasurementInCounts                 0x4a04

        #define OD_4a04_0_velocityMeasurementInCounts_maxSubIndex   0
        #define OD_4a04_1_velocityMeasurementInCounts_velocityMeasurementInCounts 1
        #define OD_4a04_2_velocityMeasurementInCounts_velocityMeasurementInRpm 2

/*4b00 */
        #define OD_4b00_factorGroupConfiguration                    0x4b00

        #define OD_4b00_0_factorGroupConfiguration_maxSubIndex      0
        #define OD_4b00_1_factorGroupConfiguration_factorGroupConfiguration 1
        #define OD_4b00_2_factorGroupConfiguration_factorGroupPrecision 2

/*4b10 */
        #define OD_4b10_factorGroupPolarity                         0x4b10

        #define OD_4b10_0_factorGroupPolarity_maxSubIndex           0
        #define OD_4b10_1_factorGroupPolarity_factorGroupPolarity   1

/*4b11 */
        #define OD_4b11_factorGroupPositionNotationIndex            0x4b11

        #define OD_4b11_0_factorGroupPositionNotationIndex_maxSubIndex 0
        #define OD_4b11_1_factorGroupPositionNotationIndex_factorGroupPositionNotationIndex 1

/*4b12 */
        #define OD_4b12_factorGroupPositionDimensionIndex           0x4b12

        #define OD_4b12_0_factorGroupPositionDimensionIndex_maxSubIndex 0
        #define OD_4b12_1_factorGroupPositionDimensionIndex_factorGroupPositionDimensionIndex 1

/*4b13 */
        #define OD_4b13_factorGroupVelocityNotationIndex            0x4b13

        #define OD_4b13_0_factorGroupVelocityNotationIndex_maxSubIndex 0
        #define OD_4b13_1_factorGroupVelocityNotationIndex_factorGroupVelocityNotationIndex 1

/*4b14 */
        #define OD_4b14_factorGroupVelocityDimensionIndex           0x4b14

        #define OD_4b14_0_factorGroupVelocityDimensionIndex_maxSubIndex 0
        #define OD_4b14_1_factorGroupVelocityDimensionIndex_factorGroupVelocityDimensionIndex 1

/*4b15 */
        #define OD_4b15_factorGroupAccelerationNotationIndex        0x4b15

        #define OD_4b15_0_factorGroupAccelerationNotationIndex_maxSubIndex 0
        #define OD_4b15_1_factorGroupAccelerationNotationIndex_factorGroupAccelerationNotationIndex 1

/*4b16 */
        #define OD_4b16_factorGroupAccelerationDimensionIndex       0x4b16

        #define OD_4b16_0_factorGroupAccelerationDimensionIndex_maxSubIndex 0
        #define OD_4b16_1_factorGroupAccelerationDimensionIndex_factorGroupAccelerationDimensionIndex 1

/*4b17 */
        #define OD_4b17_factorGroupPositionScaleNumerator           0x4b17

        #define OD_4b17_0_factorGroupPositionScaleNumerator_maxSubIndex 0
        #define OD_4b17_1_factorGroupPositionScaleNumerator_factorGroupPositionScaleNumerator 1
        #define OD_4b17_2_factorGroupPositionScaleNumerator_factorGroupPositionScaleDenominator 2

/*4b18 */
        #define OD_4b18_factorGroupVelocityScaleNumerator           0x4b18

        #define OD_4b18_0_factorGroupVelocityScaleNumerator_maxSubIndex 0
        #define OD_4b18_1_factorGroupVelocityScaleNumerator_factorGroupVelocityScaleNumerator 1
        #define OD_4b18_2_factorGroupVelocityScaleNumerator_factorGroupVelocityScaleDenominator 2

/*4b19 */
        #define OD_4b19_factorGroupGearRatioMotorShaftRevolution    0x4b19

        #define OD_4b19_0_factorGroupGearRatioMotorShaftRevolution_maxSubIndex 0
        #define OD_4b19_1_factorGroupGearRatioMotorShaftRevolution_factorGroupGearRatioMotorShaftRevolution 1
        #define OD_4b19_2_factorGroupGearRatioMotorShaftRevolution_factorGroupGearRatioGearShaftRevolution 2

/*4b1a */
        #define OD_4b1a_factorGroupFeedConstantFeed                 0x4b1a

        #define OD_4b1a_0_factorGroupFeedConstantFeed_maxSubIndex   0
        #define OD_4b1a_1_factorGroupFeedConstantFeed_factorGroupFeedConstantFeed 1
        #define OD_4b1a_2_factorGroupFeedConstantFeed_factorGroupFeedConstantDrivingShaftRevolution 2

/*6007 */
        #define OD_6007_abortConnectionOptionCode                   0x6007

/*603f */
        #define OD_603f_errorCode                                   0x603f

/*6040 */
        #define OD_6040_controlword                                 0x6040

/*6041 */
        #define OD_6041_statusword                                  0x6041

/*6042 */
        #define OD_6042_vlTargetVelocity                            0x6042

/*6043 */
        #define OD_6043_vlVelocityDemand                            0x6043

/*6044 */
        #define OD_6044_vlVelocityActualValue                       0x6044

/*6046 */
        #define OD_6046_vlVelocityMinMaxAmount                      0x6046

        #define OD_6046_0_vlVelocityMinMaxAmount_maxSubIndex        0
        #define OD_6046_1_vlVelocityMinMaxAmount_velocityMinAmountRpm 1
        #define OD_6046_2_vlVelocityMinMaxAmount_velocityMaxAmountRpm 2

/*6048 */
        #define OD_6048_vlVelocityAcceleration                      0x6048

        #define OD_6048_0_vlVelocityAcceleration_maxSubIndex        0
        #define OD_6048_1_vlVelocityAcceleration_deltaSpeedRpm      1
        #define OD_6048_2_vlVelocityAcceleration_deltaTimes         2

/*6049 */
        #define OD_6049_vlVelocityDeceleration                      0x6049

        #define OD_6049_0_vlVelocityDeceleration_maxSubIndex        0
        #define OD_6049_1_vlVelocityDeceleration_deltaSpeedRpm      1
        #define OD_6049_2_vlVelocityDeceleration_deltaTimes         2

/*604a */
        #define OD_604a_vlVelocityQuickStop                         0x604a

        #define OD_604a_0_vlVelocityQuickStop_maxSubIndex           0
        #define OD_604a_1_vlVelocityQuickStop_deltaSpeedRpm         1
        #define OD_604a_2_vlVelocityQuickStop_deltaTimes            2

/*604c */
        #define OD_604c_vlDimensionFactor                           0x604c

        #define OD_604c_0_vlDimensionFactor_maxSubIndex             0
        #define OD_604c_1_vlDimensionFactor_numerator               1
        #define OD_604c_2_vlDimensionFactor_denominator             2

/*605a */
        #define OD_605a_quickStopOptionCode                         0x605a

/*6060 */
        #define OD_6060_modesOfOperation                            0x6060

/*6061 */
        #define OD_6061_modesOfOperationDisplay                     0x6061

/*6062 */
        #define OD_6062_positionDemandValue                         0x6062

/*6063 */
        #define OD_6063_positionActualValueCount                    0x6063

/*6064 */
        #define OD_6064_positionActualValue                         0x6064

/*6065 */
        #define OD_6065_followingErrorWindow                        0x6065

/*6066 */
        #define OD_6066_followingErrorTimeOut                       0x6066

/*6067 */
        #define OD_6067_positionWindow                              0x6067

/*6068 */
        #define OD_6068_positionWindowTime                          0x6068

/*606c */
        #define OD_606c_velocityActualValue                         0x606c

/*606d */
        #define OD_606d_velocityWindow                              0x606d

/*606e */
        #define OD_606e_velocityWindowTime                          0x606e

/*606f */
        #define OD_606f_velocityThreshold                           0x606f

/*6070 */
        #define OD_6070_velocityThresholdTime                       0x6070

/*6071 */
        #define OD_6071_targetTorque                                0x6071

/*6072 */
        #define OD_6072_maxTorque                                   0x6072

/*6075 */
        #define OD_6075_motorRatedCurrent                           0x6075

/*6077 */
        #define OD_6077_torqueActualValue                           0x6077

/*6078 */
        #define OD_6078_currentActualValue                          0x6078

/*6079 */
        #define OD_6079_DCLinkCircuitVoltage                        0x6079

/*607a */
        #define OD_607a_targetPosition                              0x607a

/*607c */
        #define OD_607c_homeOffset                                  0x607c

/*607d */
        #define OD_607d_softwarePositionLimit                       0x607d

        #define OD_607d_0_softwarePositionLimit_maxSubIndex         0
        #define OD_607d_1_softwarePositionLimit_minPositionLimit    1
        #define OD_607d_2_softwarePositionLimit_maxPositionLimit    2

/*607e */
        #define OD_607e_polarity                                    0x607e

/*607f */
        #define OD_607f_maxProfileVelocity                          0x607f

/*6081 */
        #define OD_6081_profileVelocity                             0x6081

/*6083 */
        #define OD_6083_profileAcceleration                         0x6083

/*6084 */
        #define OD_6084_profileDeceleration                         0x6084

/*6085 */
        #define OD_6085_quickStopDeceleration                       0x6085

/*6086 */
        #define OD_6086_motionProfileType                           0x6086

/*6087 */
        #define OD_6087_torqueSlope                                 0x6087

/*6088 */
        #define OD_6088_torqueProfileType                           0x6088

/*6089 */
        #define OD_6089_positionNotationIndex                       0x6089

/*608a */
        #define OD_608a_positionDimensionIndex                      0x608a

/*608b */
        #define OD_608b_velocityNotationIndex                       0x608b

/*608c */
        #define OD_608c_velocityDimensionIndex                      0x608c

/*608d */
        #define OD_608d_accelerationNotationIndex                   0x608d

/*608e */
        #define OD_608e_accelerationDimensionIndex                  0x608e

/*608f */
        #define OD_608f_positionEncoderResolution                   0x608f

        #define OD_608f_0_positionEncoderResolution_maxSubIndex     0
        #define OD_608f_1_positionEncoderResolution_encoderIncrements 1
        #define OD_608f_2_positionEncoderResolution_motorRevolutions 2

/*6090 */
        #define OD_6090_velocityEncoderResolution                   0x6090

        #define OD_6090_0_velocityEncoderResolution_maxSubIndex     0
        #define OD_6090_1_velocityEncoderResolution_encoderIncrements 1
        #define OD_6090_2_velocityEncoderResolution_motorRevolutions 2

/*6091 */
        #define OD_6091_gearRatio                                   0x6091

        #define OD_6091_0_gearRatio_maxSubIndex                     0
        #define OD_6091_1_gearRatio_motorRevolutions                1
        #define OD_6091_2_gearRatio_shaftRevolutions                2

/*6092 */
        #define OD_6092_feedConstant                                0x6092

        #define OD_6092_0_feedConstant_maxSubIndex                  0
        #define OD_6092_1_feedConstant_feed                         1
        #define OD_6092_2_feedConstant_shaftRevolutions             2

/*6098 */
        #define OD_6098_homingMethod                                0x6098

/*6099 */
        #define OD_6099_homingSpeeds                                0x6099

        #define OD_6099_0_homingSpeeds_maxSubIndex                  0
        #define OD_6099_1_homingSpeeds_speedDuringSearchForSwitch   1
        #define OD_6099_2_homingSpeeds_speedDuringSearchForZero     2

/*609a */
        #define OD_609a_homingAcceleration                          0x609a

/*60c1 */
        #define OD_60c1_interpolatedDataRecord                      0x60c1

        #define OD_60c1_0_interpolatedDataRecord_maxSubIndex        0
        #define OD_60c1_1_interpolatedDataRecord_interpolationData1stSetPoint 1

/*60c2 */
        #define OD_60c2_interpolationTimePeriod                     0x60c2

        #define OD_60c2_0_interpolationTimePeriod_maxSubIndex       0
        #define OD_60c2_1_interpolationTimePeriod_interpolationTimePeriodValue 1
        #define OD_60c2_2_interpolationTimePeriod_interpolationTimeIndex 2

/*60e0 */
        #define OD_60e0_positiveTorqueLimitValue                    0x60e0

/*60e1 */
        #define OD_60e1_negativeTorqueLimitValue                    0x60e1

/*60e3 */
        #define OD_60e3_supportedHomingMethods                      0x60e3

        #define OD_60e3_0_supportedHomingMethods_maxSubIndex        0
        #define OD_60e3_1_supportedHomingMethods_homingOnNegativeLimitSwitchAndIndexPulse 1
        #define OD_60e3_2_supportedHomingMethods_homingOnPositiveLimitSwitchAndIndexPulse 2
        #define OD_60e3_3_supportedHomingMethods_homingOnPositiveHomeSwitchAndIndexPulse 3
        #define OD_60e3_4_supportedHomingMethods_homingOnPositiveHomeSwitchAndIndexPulse2 4
        #define OD_60e3_5_supportedHomingMethods_homingOnNegativeHomeSwitchAndIndexPulse 5
        #define OD_60e3_6_supportedHomingMethods_homingOnNegativeHomeSwitchAndIndexPulse2 6
        #define OD_60e3_7_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse0 7
        #define OD_60e3_8_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse1 8
        #define OD_60e3_9_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse2 9
        #define OD_60e3_10_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse3 10
        #define OD_60e3_11_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse4 11
        #define OD_60e3_12_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse5 12
        #define OD_60e3_13_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse6 13
        #define OD_60e3_14_supportedHomingMethods_homingOnHomeSwitchAndIndexPulse7 14
        #define OD_60e3_15_supportedHomingMethods_homingWithoutIndexPulse00 15
        #define OD_60e3_16_supportedHomingMethods_homingWithoutIndexPulse01 16
        #define OD_60e3_17_supportedHomingMethods_homingWithoutIndexPulse02 17
        #define OD_60e3_18_supportedHomingMethods_homingWithoutIndexPulse03 18
        #define OD_60e3_19_supportedHomingMethods_homingWithoutIndexPulse04 19
        #define OD_60e3_20_supportedHomingMethods_homingWithoutIndexPulse05 20
        #define OD_60e3_21_supportedHomingMethods_homingWithoutIndexPulse06 21
        #define OD_60e3_22_supportedHomingMethods_homingWithoutIndexPulse07 22
        #define OD_60e3_23_supportedHomingMethods_homingWithoutIndexPulse08 23
        #define OD_60e3_24_supportedHomingMethods_homingWithoutIndexPulse09 24
        #define OD_60e3_25_supportedHomingMethods_homingWithoutIndexPulse10 25
        #define OD_60e3_26_supportedHomingMethods_homingWithoutIndexPulse11 26
        #define OD_60e3_27_supportedHomingMethods_homingWithoutIndexPulse12 27
        #define OD_60e3_28_supportedHomingMethods_homingWithoutIndexPulse13 28
        #define OD_60e3_29_supportedHomingMethods_homingOnIndexPulse0 29
        #define OD_60e3_30_supportedHomingMethods_homingOnIndexPulse1 30
        #define OD_60e3_31_supportedHomingMethods_homingOnCurrentPosition 31

/*60f4 */
        #define OD_60f4_followingErrorActualValue                   0x60f4

/*60fc */
        #define OD_60fc_positionDemandValueCount                    0x60fc

/*60fd */
        #define OD_60fd_digitalInputs                               0x60fd

/*60fe */
        #define OD_60fe_digitalOutputs                              0x60fe

        #define OD_60fe_0_digitalOutputs_maxSubIndex                0
        #define OD_60fe_1_digitalOutputs_outputState                1
        #define OD_60fe_2_digitalOutputs_enableBitMask              2

/*60ff */
        #define OD_60ff_targetVelocity                              0x60ff

/*6402 */
        #define OD_6402_motorType                                   0x6402

/*6502 */
        #define OD_6502_supportedDriveModes                         0x6502

/*67fe */
        #define OD_67fe_errorBehaviourOld                           0x67fe

        #define OD_67fe_0_errorBehaviourOld_maxSubIndex             0
        #define OD_67fe_1_errorBehaviourOld_communicationError      1
        #define OD_67fe_2_errorBehaviourOld_outputError             2
        #define OD_67fe_3_errorBehaviourOld_inputError              3

/*******************************************************************************
   STRUCTURES FOR VARIABLES IN DIFFERENT MEMORY LOCATIONS
*******************************************************************************/
#define  CO_OD_FIRST_LAST_WORD     0x55 //Any value from 0x01 to 0xFE. If changed, EEPROM will be reinitialized.

/***** Structure for ROM variables ********************************************/
struct sCO_OD_ROM{
               UNSIGNED32     FirstWord;

/*1400      */ OD_RPDOCommunicationParameter_t RPDOCommunicationParameter[1];
/*1600      */ OD_RPDOMappingParameter_t RPDOMappingParameter[1];
/*1800      */ OD_TPDOCommunicationParameter_t TPDOCommunicationParameter[1];
/*1a00      */ OD_TPDOMappingParameter_t TPDOMappingParameter[1];

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
/*1008      */ VISIBLE_STRING  manufacturerDeviceName[13];
/*1009      */ VISIBLE_STRING  hardwareVersion[4];
/*100a      */ VISIBLE_STRING  softwareVersion[4];
/*1014      */ UNSIGNED32      COB_ID_EMCY;
/*1015      */ UNSIGNED16      inhibitTimeEMCY;
/*1016      */ UNSIGNED32      consumerHeartbeatTime[4];
/*1017      */ UNSIGNED16      producerHeartbeatTime;
/*1018      */ OD_identity_t   identity;
/*1019      */ UNSIGNED8       synchronousCounterOverflowValue;
/*1029      */ UNSIGNED8       errorBehavior[6];
/*1200      */ OD_SDOServerParameter_t SDOServerParameter[1];
/*1280      */ OD_SDOClientParameter_t SDOClientParameter[1];
/*1f80      */ UNSIGNED32      NMTStartup;
/*200a      */ OD_manufacturerSoftwareVersion_t manufacturerSoftwareVersion;
/*2100      */ OCTET_STRING    errorStatusBits[10];
/*4000      */ OD_deviceCommand_t deviceCommand;
/*4001      */ OD_manufacturerErrorRegister_t manufacturerErrorRegister;
/*4002      */ OD_statusRegister_t statusRegister;
/*4003      */ OD_deviceMode_t deviceMode;
/*4004      */ OD_powerEnable_t powerEnable;
/*4010      */ OD_reserved0_t  reserved0;
/*4014      */ OD_reserved1_t  reserved1;
/*4020      */ OD_deviceCode_t deviceCode;
/*4023      */ OD_motorSoftwareVersion_t motorSoftwareVersion;
/*4024      */ OD_motorHardwareVersion_t motorHardwareVersion;
/*402c      */ OD_freeData_t   freeData;
/*402e      */ OD_OEMDataCommand_t OEMDataCommand;
/*402f      */ OD_userDataCommand_t userDataCommand;
/*4031      */ OD_maxPowerVoltage_t maxPowerVoltage;
/*4032      */ OD_maxMotorCurrent_t maxMotorCurrent;
/*4050      */ OD_inputAssignmentEnable_t inputAssignmentEnable;
/*4051      */ OD_inputAssignmentErrorQuitting_t inputAssignmentErrorQuitting;
/*4052      */ OD_inputAssignmentStartStop_t inputAssignmentStartStop;
/*4055      */ OD_inputAssignmentPositiveLimitSwitch_t inputAssignmentPositiveLimitSwitch;
/*4056      */ OD_inputAssignmentNegativeLimitSwitch_t inputAssignmentNegativeLimitSwitch;
/*4057      */ OD_inputAssignmentReferenceSwitch_t inputAssignmentReferenceSwitch;
/*4060      */ OD_outputAssignmentError_t outputAssignmentError;
/*4080      */ OD_continueMode_t continueMode;
/*4090      */ OD_minimumUpError_t minimumUpError;
/*4100      */ OD_analogueInput0_t analogueInput0;
/*4108      */ OD_analogueIntputOffset_t analogueIntputOffset;
/*410a      */ OD_analogueIntputDeadband_t analogueIntputDeadband;
/*4110      */ OD_electronicVoltageUe_t electronicVoltageUe;
/*4111      */ OD_powerVoltageUp_t powerVoltageUp;
/*4112      */ OD_motorVoltageUm_t motorVoltageUm;
/*4113      */ OD_motorCurrentIm_t motorCurrentIm;
/*4114      */ OD_temperatureOfPowerAmplifier_t temperatureOfPowerAmplifier;
/*4120      */ OD_digitalInputsPort0_t digitalInputsPort0;
/*4128      */ OD_digitalInputsHallSensors_t digitalInputsHallSensors;
/*4150      */ OD_digitalOutputsPort0_t digitalOutputsPort0;
/*4154      */ OD_enableDigitalOutputs_t enableDigitalOutputs;
/*4200      */ OD_currentDesiredValue_t currentDesiredValue[2];
/*4261      */ OD_currentCommandedValue_t currentCommandedValue;
/*4262      */ OD_currentActualValue0_t currentActualValue0;
/*4263      */ OD_currentFollowingError_t currentFollowingError;
/*42a0      */ OD_currentControllerSampleTime_t currentControllerSampleTime;
/*4300      */ OD_velocityDesiredValue_t velocityDesiredValue;
/*4302      */ OD_velocityScaleFactorNumerator_t velocityScaleFactorNumerator;
/*4303      */ OD_velocityScaleFactorDenominator_t velocityScaleFactorDenominator;
/*4304      */ OD_velocitySource_t velocitySource;
/*4305      */ OD_velocityReferenceValue_t velocityReferenceValue;
/*430a      */ OD_velocityDimensionFactorNumerator_t velocityDimensionFactorNumerator;
/*430b      */ OD_velocityDimensionFactorDenominator_t velocityDimensionFactorDenominator;
/*4310      */ OD_PID_ControllerGain_t PID_ControllerGain;
/*4311      */ OD_PID_ControllerIntegralFactor_t PID_ControllerIntegralFactor;
/*4312      */ OD_PID_ControllerDifferentialFactor_t PID_ControllerDifferentialFactor;
/*4313      */ OD_PID_ControllerIntegralLimit_t PID_ControllerIntegralLimit;
/*4314      */ OD_PID_ControllerVelocityFeedForward_t PID_ControllerVelocityFeedForward;
/*4315      */ OD_PID_ControllerVelocityFeedForwardAcceleration_t PID_ControllerVelocityFeedForwardAcceleration;
/*4317      */ OD_ixR_Factor_t ixR_Factor;
/*4318      */ OD_PID_ControllerDifferentialSampleTime_t PID_ControllerDifferentialSampleTime;
/*4321      */ OD_velocityMaxLimitPositiveDirection_t velocityMaxLimitPositiveDirection;
/*4323      */ OD_velocityMaxLimitNegativeDirection_t velocityMaxLimitNegativeDirection;
/*4340      */ OD_velocityAccelerationDeltav_t velocityAccelerationDeltav;
/*4341      */ OD_velocityAccelerationDeltat_t velocityAccelerationDeltat;
/*4342      */ OD_velocityDecelerationDeltav_t velocityDecelerationDeltav;
/*4343      */ OD_velocityDecelerationDeltat_t velocityDecelerationDeltat;
/*4344      */ OD_velocityDecelerationQuickStopDeltav_t velocityDecelerationQuickStopDeltav;
/*4345      */ OD_velocityDecelerationQuickStopDeltat_t velocityDecelerationQuickStopDeltat;
/*434c      */ OD_velocityRampGeneratorRampType_t velocityRampGeneratorRampType;
/*434d      */ OD_velocityRampGeneratorState_t velocityRampGeneratorState;
/*4350      */ OD_velocityFeedback_t velocityFeedback;
/*4380      */ OD_velocityAccelerationInRevMin2_t velocityAccelerationInRevMin2;
/*4381      */ OD_velocityDecelerationInRevMin2_t velocityDecelerationInRevMin2;
/*4382      */ OD_velocityQuickStopDecelerationInRevMin2_t velocityQuickStopDecelerationInRevMin2;
/*43a0      */ OD_velocityPositionControllerSampleTime_t velocityPositionControllerSampleTime;
/*43c0      */ OD_blockageGuardingConfigurationFlags_t blockageGuardingConfigurationFlags;
/*43d4      */ OD_outputRampgenerator_t outputRampgenerator;
/*4500      */ OD_SVelDesiredValue_t SVelDesiredValue;
/*4502      */ OD_SVelScaleFactorNumerator_t SVelScaleFactorNumerator;
/*4503      */ OD_SVelScaleFactorDenominator_t SVelScaleFactorDenominator;
/*4504      */ OD_SVelSourceOfDesiredValue_t SVelSourceOfDesiredValue;
/*4505      */ OD_SVelReferenceValue_t SVelReferenceValue;
/*4510      */ OD_SVelPI_ControllerGain_t SVelPI_ControllerGain;
/*4511      */ OD_SVelPI_ControllerIntegralFactor_t SVelPI_ControllerIntegralFactor;
/*4517      */ OD_SVelIxR_Factor_t SVelIxR_Factor;
/*4550      */ OD_SVelFeedback_t SVelFeedback;
/*45a0      */ OD_SVelSampleTime_t SVelSampleTime;
/*45a1      */ OD_SVelVelocityScalingResolution_t SVelVelocityScalingResolution;
/*4708      */ OD_positionMode_t positionMode;
/*4720      */ OD_positionLimitMinimum_t positionLimitMinimum;
/*4732      */ OD_positionFollowingErrorWindow_t positionFollowingErrorWindow;
/*4733      */ OD_positionFollowingErrorTime_t positionFollowingErrorTime;
/*4735      */ OD_deactivatingOfFollowingErrorCorrection_t deactivatingOfFollowingErrorCorrection;
/*473a      */ OD_positionWindow0_t positionWindow0;
/*473b      */ OD_positionWindowTime0_t positionWindowTime0;
/*473c      */ OD_positionReachedConfigurationBits_t positionReachedConfigurationBits;
/*474c      */ OD_positionRampGeneratorRampType_t positionRampGeneratorRampType;
/*474d      */ OD_positionRampGeneratorState_t positionRampGeneratorState;
/*4760      */ OD_actualTargetPosition_t actualTargetPosition;
/*4761      */ OD_actualCommandPosition_t actualCommandPosition;
/*4762      */ OD_actualPosition_t actualPosition;
/*4763      */ OD_actualPositionFollowingError_t actualPositionFollowingError;
/*4764      */ OD_actualPositionOfIndex_t actualPositionOfIndex;
/*4770      */ OD_actualTargetPositionInIncrements_t actualTargetPositionInIncrements;
/*4771      */ OD_actualCommandPositionInIncrements_t actualCommandPositionInIncrements;
/*4772      */ OD_actualPositionInIncrements_t actualPositionInIncrements;
/*4773      */ OD_actualFollowingErrorInIncrements_t actualFollowingErrorInIncrements;
/*4774      */ OD_actualIndexPositionInIncrements_t actualIndexPositionInIncrements;
/*4790      */ OD_absolutePositioning_t absolutePositioning;
/*4791      */ OD_relativePositioning_t relativePositioning;
/*47a4      */ OD_gearBackLashPath_t gearBackLashPath;
/*47b0      */ OD_homingCommand_t homingCommand;
/*47b1      */ OD_homingStatus_t homingStatus;
/*47b2      */ OD_homingMethod0_t homingMethod0;
/*47b3      */ OD_homingOffset_t homingOffset;
/*47b4      */ OD_homingVelocitySearchingTheSwitch_t homingVelocitySearchingTheSwitch;
/*47b5      */ OD_homingAcceleration0_t homingAcceleration0;
/*47b6      */ OD_homingMaxPathForSearchingTheIndex_t homingMaxPathForSearchingTheIndex;
/*47b7      */ OD_homingOnBlockageConfigurationFlags_t homingOnBlockageConfigurationFlags;
/*47c2      */ OD_interpolationMethod_t interpolationMethod;
/*47c5      */ OD_interpolationBufferConfiguration_t interpolationBufferConfiguration;
/*47c6      */ OD_interpolationData_t interpolationData;
/*47c7      */ OD_interpolationActualTargetPosition_t interpolationActualTargetPosition;
/*47c8      */ OD_moduloMethod_t moduloMethod;
/*47c9      */ OD_moduloValue_t moduloValue;
/*4830      */ OD_PWM_Frequency_t PWM_Frequency;
/*4850      */ OD_systemClock_t systemClock;
/*48f3      */ OD_SSI_InterfaceConfiguration_t SSI_InterfaceConfiguration;
/*4900      */ OD_motorType0_t motorType0;
/*4901      */ OD_motorRatedSpeed_t motorRatedSpeed;
/*4902      */ OD_motorRatedVoltage_t motorRatedVoltage;
/*4910      */ OD_motorNumberOfPoles_t motorNumberOfPoles;
/*4911      */ OD_motorPolarity_t motorPolarity;
/*4913      */ OD_motorCommutationType_t motorCommutationType;
/*4940      */ OD_hallSensorType_t hallSensorType;
/*4944      */ OD_reserved_t   reserved;
/*4949      */ OD_hallPulsesConfigurationFlags_t hallPulsesConfigurationFlags;
/*494a      */ OD_actualHallPosition_t actualHallPosition;
/*4962      */ OD_encoderResolutionInCounts_t encoderResolutionInCounts;
/*4963      */ OD_encoderResolutionInLines_t encoderResolutionInLines;
/*496a      */ OD_actualEncoderPosition_t actualEncoderPosition;
/*496b      */ OD_actualEncoderIndexPosition_t actualEncoderIndexPosition;
/*496c      */ OD_countsIndexPulses_t countsIndexPulses;
/*4970      */ OD_SSI_AbsoluteEncoderEnable_t SSI_AbsoluteEncoderEnable;
/*4971      */ OD_SSI_AbsoluteEncoderCode_t SSI_AbsoluteEncoderCode;
/*4972      */ OD_SSI_AbsoluteEncoderSingleTurnResolutionInCounts_t SSI_AbsoluteEncoderSingleTurnResolutionInCounts;
/*497a      */ OD_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits_t SSI_AbsoluteEncoderActualPositionExtendedOn32Bits;
/*497b      */ OD_SSI_AbsoluteEncoderActualIndexPosition_t SSI_AbsoluteEncoderActualIndexPosition;
/*497c      */ OD_SSI_AbsoluteEncoderCountOfIndexPulses_t SSI_AbsoluteEncoderCountOfIndexPulses;
/*49a0      */ OD_brakeManagementConfiguration_t brakeManagementConfiguration;
/*49a2      */ OD_quasiAbsoluteEncoderConfigurationFlags_t quasiAbsoluteEncoderConfigurationFlags;
/*4a02      */ OD_velocityMeasurementGateTime_t velocityMeasurementGateTime;
/*4a04      */ OD_velocityMeasurementInCounts_t velocityMeasurementInCounts;
/*4b00      */ OD_factorGroupConfiguration_t factorGroupConfiguration;
/*4b10      */ OD_factorGroupPolarity_t factorGroupPolarity;
/*4b11      */ OD_factorGroupPositionNotationIndex_t factorGroupPositionNotationIndex;
/*4b12      */ OD_factorGroupPositionDimensionIndex_t factorGroupPositionDimensionIndex;
/*4b13      */ OD_factorGroupVelocityNotationIndex_t factorGroupVelocityNotationIndex;
/*4b14      */ OD_factorGroupVelocityDimensionIndex_t factorGroupVelocityDimensionIndex;
/*4b15      */ OD_factorGroupAccelerationNotationIndex_t factorGroupAccelerationNotationIndex;
/*4b16      */ OD_factorGroupAccelerationDimensionIndex_t factorGroupAccelerationDimensionIndex;
/*4b17      */ OD_factorGroupPositionScaleNumerator_t factorGroupPositionScaleNumerator;
/*4b18      */ OD_factorGroupVelocityScaleNumerator_t factorGroupVelocityScaleNumerator;
/*4b19      */ OD_factorGroupGearRatioMotorShaftRevolution_t factorGroupGearRatioMotorShaftRevolution;
/*4b1a      */ OD_factorGroupFeedConstantFeed_t factorGroupFeedConstantFeed;
/*6007      */ INTEGER16       abortConnectionOptionCode;
/*603f      */ UNSIGNED16      errorCode;
/*6040      */ UNSIGNED16      controlword;
/*6041      */ UNSIGNED16      statusword;
/*6042      */ INTEGER16       vlTargetVelocity;
/*6043      */ INTEGER16       vlVelocityDemand;
/*6044      */ INTEGER16       vlVelocityActualValue;
/*6046      */ OD_vlVelocityMinMaxAmount_t vlVelocityMinMaxAmount;
/*6048      */ OD_vlVelocityAcceleration_t vlVelocityAcceleration;
/*6049      */ OD_vlVelocityDeceleration_t vlVelocityDeceleration;
/*604a      */ OD_vlVelocityQuickStop_t vlVelocityQuickStop;
/*604c      */ OD_vlDimensionFactor_t vlDimensionFactor;
/*605a      */ INTEGER16       quickStopOptionCode;
/*6060      */ INTEGER8        modesOfOperation;
/*6061      */ INTEGER8        modesOfOperationDisplay;
/*6062      */ INTEGER32       positionDemandValue;
/*6063      */ INTEGER32       positionActualValueCount;
/*6064      */ INTEGER32       positionActualValue;
/*6065      */ UNSIGNED32      followingErrorWindow;
/*6066      */ UNSIGNED16      followingErrorTimeOut;
/*6067      */ UNSIGNED32      positionWindow;
/*6068      */ UNSIGNED16      positionWindowTime;
/*606c      */ INTEGER32       velocityActualValue;
/*606d      */ UNSIGNED16      velocityWindow;
/*606e      */ UNSIGNED16      velocityWindowTime;
/*606f      */ UNSIGNED16      velocityThreshold;
/*6070      */ UNSIGNED16      velocityThresholdTime;
/*6071      */ INTEGER16       targetTorque;
/*6072      */ UNSIGNED16      maxTorque;
/*6075      */ UNSIGNED32      motorRatedCurrent;
/*6077      */ INTEGER16       torqueActualValue;
/*6078      */ INTEGER16       currentActualValue;
/*6079      */ UNSIGNED32      DCLinkCircuitVoltage;
/*607a      */ INTEGER32       targetPosition;
/*607c      */ INTEGER32       homeOffset;
/*607d      */ OD_softwarePositionLimit_t softwarePositionLimit;
/*607e      */ UNSIGNED8       polarity;
/*607f      */ UNSIGNED32      maxProfileVelocity;
/*6081      */ UNSIGNED32      profileVelocity;
/*6083      */ UNSIGNED32      profileAcceleration;
/*6084      */ UNSIGNED32      profileDeceleration;
/*6085      */ UNSIGNED32      quickStopDeceleration;
/*6086      */ INTEGER16       motionProfileType;
/*6087      */ UNSIGNED32      torqueSlope;
/*6088      */ INTEGER16       torqueProfileType;
/*6089      */ INTEGER8        positionNotationIndex;
/*608a      */ UNSIGNED8       positionDimensionIndex;
/*608b      */ INTEGER8        velocityNotationIndex;
/*608c      */ UNSIGNED8       velocityDimensionIndex;
/*608d      */ INTEGER8        accelerationNotationIndex;
/*608e      */ UNSIGNED8       accelerationDimensionIndex;
/*608f      */ OD_positionEncoderResolution_t positionEncoderResolution;
/*6090      */ OD_velocityEncoderResolution_t velocityEncoderResolution;
/*6091      */ OD_gearRatio_t  gearRatio;
/*6092      */ OD_feedConstant_t feedConstant;
/*6098      */ INTEGER8        homingMethod;
/*6099      */ OD_homingSpeeds_t homingSpeeds;
/*609a      */ UNSIGNED32      homingAcceleration;
/*60c1      */ OD_interpolatedDataRecord_t interpolatedDataRecord;
/*60c2      */ OD_interpolationTimePeriod_t interpolationTimePeriod;
/*60e0      */ UNSIGNED16      positiveTorqueLimitValue;
/*60e1      */ UNSIGNED16      negativeTorqueLimitValue;
/*60e3      */ OD_supportedHomingMethods_t supportedHomingMethods;
/*60f4      */ INTEGER32       followingErrorActualValue;
/*60fc      */ INTEGER32       positionDemandValueCount;
/*60fd      */ UNSIGNED32      digitalInputs;
/*60fe      */ OD_digitalOutputs_t digitalOutputs;
/*60ff      */ INTEGER32       targetVelocity;
/*6402      */ UNSIGNED16      motorType;
/*6502      */ UNSIGNED32      supportedDriveModes;
/*67fe      */ OD_errorBehaviourOld_t errorBehaviourOld;

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
        #define ODL_manufacturerDeviceName_stringLength             13

/*1009, Data Type: VISIBLE_STRING */
        #define OD_hardwareVersion                                  CO_OD_RAM.hardwareVersion
        #define ODL_hardwareVersion_stringLength                    4

/*100a, Data Type: VISIBLE_STRING */
        #define OD_softwareVersion                                  CO_OD_RAM.softwareVersion
        #define ODL_softwareVersion_stringLength                    4

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

/*1018, Data Type: identity_t */
        #define OD_identity                                         CO_OD_RAM.identity

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

/*1280, Data Type: SDOClientParameter_t */
        #define OD_SDOClientParameter                               CO_OD_RAM.SDOClientParameter

/*1400, Data Type: RPDOCommunicationParameter_t */
        #define OD_RPDOCommunicationParameter                       CO_OD_ROM.RPDOCommunicationParameter

/*1600, Data Type: RPDOMappingParameter_t */
        #define OD_RPDOMappingParameter                             CO_OD_ROM.RPDOMappingParameter

/*1800, Data Type: TPDOCommunicationParameter_t */
        #define OD_TPDOCommunicationParameter                       CO_OD_ROM.TPDOCommunicationParameter

/*1a00, Data Type: TPDOMappingParameter_t */
        #define OD_TPDOMappingParameter                             CO_OD_ROM.TPDOMappingParameter

/*1f80, Data Type: UNSIGNED32 */
        #define OD_NMTStartup                                       CO_OD_RAM.NMTStartup

/*200a, Data Type: manufacturerSoftwareVersion_t */
        #define OD_manufacturerSoftwareVersion                      CO_OD_RAM.manufacturerSoftwareVersion

/*2100, Data Type: OCTET_STRING */
        #define OD_errorStatusBits                                  CO_OD_RAM.errorStatusBits
        #define ODL_errorStatusBits_stringLength                    10

/*4000, Data Type: deviceCommand_t */
        #define OD_deviceCommand                                    CO_OD_RAM.deviceCommand

/*4001, Data Type: manufacturerErrorRegister_t */
        #define OD_manufacturerErrorRegister                        CO_OD_RAM.manufacturerErrorRegister

/*4002, Data Type: statusRegister_t */
        #define OD_statusRegister                                   CO_OD_RAM.statusRegister

/*4003, Data Type: deviceMode_t */
        #define OD_deviceMode                                       CO_OD_RAM.deviceMode

/*4004, Data Type: powerEnable_t */
        #define OD_powerEnable                                      CO_OD_RAM.powerEnable

/*4010, Data Type: reserved0_t */
        #define OD_reserved0                                        CO_OD_RAM.reserved0

/*4014, Data Type: reserved1_t */
        #define OD_reserved1                                        CO_OD_RAM.reserved1

/*4020, Data Type: deviceCode_t */
        #define OD_deviceCode                                       CO_OD_RAM.deviceCode

/*4023, Data Type: motorSoftwareVersion_t */
        #define OD_motorSoftwareVersion                             CO_OD_RAM.motorSoftwareVersion

/*4024, Data Type: motorHardwareVersion_t */
        #define OD_motorHardwareVersion                             CO_OD_RAM.motorHardwareVersion

/*402c, Data Type: freeData_t */
        #define OD_freeData                                         CO_OD_RAM.freeData

/*402e, Data Type: OEMDataCommand_t */
        #define OD_OEMDataCommand                                   CO_OD_RAM.OEMDataCommand

/*402f, Data Type: userDataCommand_t */
        #define OD_userDataCommand                                  CO_OD_RAM.userDataCommand

/*4031, Data Type: maxPowerVoltage_t */
        #define OD_maxPowerVoltage                                  CO_OD_RAM.maxPowerVoltage

/*4032, Data Type: maxMotorCurrent_t */
        #define OD_maxMotorCurrent                                  CO_OD_RAM.maxMotorCurrent

/*4050, Data Type: inputAssignmentEnable_t */
        #define OD_inputAssignmentEnable                            CO_OD_RAM.inputAssignmentEnable

/*4051, Data Type: inputAssignmentErrorQuitting_t */
        #define OD_inputAssignmentErrorQuitting                     CO_OD_RAM.inputAssignmentErrorQuitting

/*4052, Data Type: inputAssignmentStartStop_t */
        #define OD_inputAssignmentStartStop                         CO_OD_RAM.inputAssignmentStartStop

/*4055, Data Type: inputAssignmentPositiveLimitSwitch_t */
        #define OD_inputAssignmentPositiveLimitSwitch               CO_OD_RAM.inputAssignmentPositiveLimitSwitch

/*4056, Data Type: inputAssignmentNegativeLimitSwitch_t */
        #define OD_inputAssignmentNegativeLimitSwitch               CO_OD_RAM.inputAssignmentNegativeLimitSwitch

/*4057, Data Type: inputAssignmentReferenceSwitch_t */
        #define OD_inputAssignmentReferenceSwitch                   CO_OD_RAM.inputAssignmentReferenceSwitch

/*4060, Data Type: outputAssignmentError_t */
        #define OD_outputAssignmentError                            CO_OD_RAM.outputAssignmentError

/*4080, Data Type: continueMode_t */
        #define OD_continueMode                                     CO_OD_RAM.continueMode

/*4090, Data Type: minimumUpError_t */
        #define OD_minimumUpError                                   CO_OD_RAM.minimumUpError

/*4100, Data Type: analogueInput0_t */
        #define OD_analogueInput0                                   CO_OD_RAM.analogueInput0

/*4108, Data Type: analogueIntputOffset_t */
        #define OD_analogueIntputOffset                             CO_OD_RAM.analogueIntputOffset

/*410a, Data Type: analogueIntputDeadband_t */
        #define OD_analogueIntputDeadband                           CO_OD_RAM.analogueIntputDeadband

/*4110, Data Type: electronicVoltageUe_t */
        #define OD_electronicVoltageUe                              CO_OD_RAM.electronicVoltageUe

/*4111, Data Type: powerVoltageUp_t */
        #define OD_powerVoltageUp                                   CO_OD_RAM.powerVoltageUp

/*4112, Data Type: motorVoltageUm_t */
        #define OD_motorVoltageUm                                   CO_OD_RAM.motorVoltageUm

/*4113, Data Type: motorCurrentIm_t */
        #define OD_motorCurrentIm                                   CO_OD_RAM.motorCurrentIm

/*4114, Data Type: temperatureOfPowerAmplifier_t */
        #define OD_temperatureOfPowerAmplifier                      CO_OD_RAM.temperatureOfPowerAmplifier

/*4120, Data Type: digitalInputsPort0_t */
        #define OD_digitalInputsPort0                               CO_OD_RAM.digitalInputsPort0

/*4128, Data Type: digitalInputsHallSensors_t */
        #define OD_digitalInputsHallSensors                         CO_OD_RAM.digitalInputsHallSensors

/*4150, Data Type: digitalOutputsPort0_t */
        #define OD_digitalOutputsPort0                              CO_OD_RAM.digitalOutputsPort0

/*4154, Data Type: enableDigitalOutputs_t */
        #define OD_enableDigitalOutputs                             CO_OD_RAM.enableDigitalOutputs

/*4200, Data Type: currentDesiredValue_t */
        #define OD_currentDesiredValue                              CO_OD_RAM.currentDesiredValue

/*4261, Data Type: currentCommandedValue_t */
        #define OD_currentCommandedValue                            CO_OD_RAM.currentCommandedValue

/*4262, Data Type: currentActualValue0_t */
        #define OD_currentActualValue0                              CO_OD_RAM.currentActualValue0

/*4263, Data Type: currentFollowingError_t */
        #define OD_currentFollowingError                            CO_OD_RAM.currentFollowingError

/*42a0, Data Type: currentControllerSampleTime_t */
        #define OD_currentControllerSampleTime                      CO_OD_RAM.currentControllerSampleTime

/*4300, Data Type: velocityDesiredValue_t */
        #define OD_velocityDesiredValue                             CO_OD_RAM.velocityDesiredValue

/*4302, Data Type: velocityScaleFactorNumerator_t */
        #define OD_velocityScaleFactorNumerator                     CO_OD_RAM.velocityScaleFactorNumerator

/*4303, Data Type: velocityScaleFactorDenominator_t */
        #define OD_velocityScaleFactorDenominator                   CO_OD_RAM.velocityScaleFactorDenominator

/*4304, Data Type: velocitySource_t */
        #define OD_velocitySource                                   CO_OD_RAM.velocitySource

/*4305, Data Type: velocityReferenceValue_t */
        #define OD_velocityReferenceValue                           CO_OD_RAM.velocityReferenceValue

/*430a, Data Type: velocityDimensionFactorNumerator_t */
        #define OD_velocityDimensionFactorNumerator                 CO_OD_RAM.velocityDimensionFactorNumerator

/*430b, Data Type: velocityDimensionFactorDenominator_t */
        #define OD_velocityDimensionFactorDenominator               CO_OD_RAM.velocityDimensionFactorDenominator

/*4310, Data Type: PID_ControllerGain_t */
        #define OD_PID_ControllerGain                               CO_OD_RAM.PID_ControllerGain

/*4311, Data Type: PID_ControllerIntegralFactor_t */
        #define OD_PID_ControllerIntegralFactor                     CO_OD_RAM.PID_ControllerIntegralFactor

/*4312, Data Type: PID_ControllerDifferentialFactor_t */
        #define OD_PID_ControllerDifferentialFactor                 CO_OD_RAM.PID_ControllerDifferentialFactor

/*4313, Data Type: PID_ControllerIntegralLimit_t */
        #define OD_PID_ControllerIntegralLimit                      CO_OD_RAM.PID_ControllerIntegralLimit

/*4314, Data Type: PID_ControllerVelocityFeedForward_t */
        #define OD_PID_ControllerVelocityFeedForward                CO_OD_RAM.PID_ControllerVelocityFeedForward

/*4315, Data Type: PID_ControllerVelocityFeedForwardAcceleration_t */
        #define OD_PID_ControllerVelocityFeedForwardAcceleration    CO_OD_RAM.PID_ControllerVelocityFeedForwardAcceleration

/*4317, Data Type: ixR_Factor_t */
        #define OD_ixR_Factor                                       CO_OD_RAM.ixR_Factor

/*4318, Data Type: PID_ControllerDifferentialSampleTime_t */
        #define OD_PID_ControllerDifferentialSampleTime             CO_OD_RAM.PID_ControllerDifferentialSampleTime

/*4321, Data Type: velocityMaxLimitPositiveDirection_t */
        #define OD_velocityMaxLimitPositiveDirection                CO_OD_RAM.velocityMaxLimitPositiveDirection

/*4323, Data Type: velocityMaxLimitNegativeDirection_t */
        #define OD_velocityMaxLimitNegativeDirection                CO_OD_RAM.velocityMaxLimitNegativeDirection

/*4340, Data Type: velocityAccelerationDeltav_t */
        #define OD_velocityAccelerationDeltav                       CO_OD_RAM.velocityAccelerationDeltav

/*4341, Data Type: velocityAccelerationDeltat_t */
        #define OD_velocityAccelerationDeltat                       CO_OD_RAM.velocityAccelerationDeltat

/*4342, Data Type: velocityDecelerationDeltav_t */
        #define OD_velocityDecelerationDeltav                       CO_OD_RAM.velocityDecelerationDeltav

/*4343, Data Type: velocityDecelerationDeltat_t */
        #define OD_velocityDecelerationDeltat                       CO_OD_RAM.velocityDecelerationDeltat

/*4344, Data Type: velocityDecelerationQuickStopDeltav_t */
        #define OD_velocityDecelerationQuickStopDeltav              CO_OD_RAM.velocityDecelerationQuickStopDeltav

/*4345, Data Type: velocityDecelerationQuickStopDeltat_t */
        #define OD_velocityDecelerationQuickStopDeltat              CO_OD_RAM.velocityDecelerationQuickStopDeltat

/*434c, Data Type: velocityRampGeneratorRampType_t */
        #define OD_velocityRampGeneratorRampType                    CO_OD_RAM.velocityRampGeneratorRampType

/*434d, Data Type: velocityRampGeneratorState_t */
        #define OD_velocityRampGeneratorState                       CO_OD_RAM.velocityRampGeneratorState

/*4350, Data Type: velocityFeedback_t */
        #define OD_velocityFeedback                                 CO_OD_RAM.velocityFeedback

/*4380, Data Type: velocityAccelerationInRevMin2_t */
        #define OD_velocityAccelerationInRevMin2                    CO_OD_RAM.velocityAccelerationInRevMin2

/*4381, Data Type: velocityDecelerationInRevMin2_t */
        #define OD_velocityDecelerationInRevMin2                    CO_OD_RAM.velocityDecelerationInRevMin2

/*4382, Data Type: velocityQuickStopDecelerationInRevMin2_t */
        #define OD_velocityQuickStopDecelerationInRevMin2           CO_OD_RAM.velocityQuickStopDecelerationInRevMin2

/*43a0, Data Type: velocityPositionControllerSampleTime_t */
        #define OD_velocityPositionControllerSampleTime             CO_OD_RAM.velocityPositionControllerSampleTime

/*43c0, Data Type: blockageGuardingConfigurationFlags_t */
        #define OD_blockageGuardingConfigurationFlags               CO_OD_RAM.blockageGuardingConfigurationFlags

/*43d4, Data Type: outputRampgenerator_t */
        #define OD_outputRampgenerator                              CO_OD_RAM.outputRampgenerator

/*4500, Data Type: SVelDesiredValue_t */
        #define OD_SVelDesiredValue                                 CO_OD_RAM.SVelDesiredValue

/*4502, Data Type: SVelScaleFactorNumerator_t */
        #define OD_SVelScaleFactorNumerator                         CO_OD_RAM.SVelScaleFactorNumerator

/*4503, Data Type: SVelScaleFactorDenominator_t */
        #define OD_SVelScaleFactorDenominator                       CO_OD_RAM.SVelScaleFactorDenominator

/*4504, Data Type: SVelSourceOfDesiredValue_t */
        #define OD_SVelSourceOfDesiredValue                         CO_OD_RAM.SVelSourceOfDesiredValue

/*4505, Data Type: SVelReferenceValue_t */
        #define OD_SVelReferenceValue                               CO_OD_RAM.SVelReferenceValue

/*4510, Data Type: SVelPI_ControllerGain_t */
        #define OD_SVelPI_ControllerGain                            CO_OD_RAM.SVelPI_ControllerGain

/*4511, Data Type: SVelPI_ControllerIntegralFactor_t */
        #define OD_SVelPI_ControllerIntegralFactor                  CO_OD_RAM.SVelPI_ControllerIntegralFactor

/*4517, Data Type: SVelIxR_Factor_t */
        #define OD_SVelIxR_Factor                                   CO_OD_RAM.SVelIxR_Factor

/*4550, Data Type: SVelFeedback_t */
        #define OD_SVelFeedback                                     CO_OD_RAM.SVelFeedback

/*45a0, Data Type: SVelSampleTime_t */
        #define OD_SVelSampleTime                                   CO_OD_RAM.SVelSampleTime

/*45a1, Data Type: SVelVelocityScalingResolution_t */
        #define OD_SVelVelocityScalingResolution                    CO_OD_RAM.SVelVelocityScalingResolution

/*4708, Data Type: positionMode_t */
        #define OD_positionMode                                     CO_OD_RAM.positionMode

/*4720, Data Type: positionLimitMinimum_t */
        #define OD_positionLimitMinimum                             CO_OD_RAM.positionLimitMinimum

/*4732, Data Type: positionFollowingErrorWindow_t */
        #define OD_positionFollowingErrorWindow                     CO_OD_RAM.positionFollowingErrorWindow

/*4733, Data Type: positionFollowingErrorTime_t */
        #define OD_positionFollowingErrorTime                       CO_OD_RAM.positionFollowingErrorTime

/*4735, Data Type: deactivatingOfFollowingErrorCorrection_t */
        #define OD_deactivatingOfFollowingErrorCorrection           CO_OD_RAM.deactivatingOfFollowingErrorCorrection

/*473a, Data Type: positionWindow0_t */
        #define OD_positionWindow0                                  CO_OD_RAM.positionWindow0

/*473b, Data Type: positionWindowTime0_t */
        #define OD_positionWindowTime0                              CO_OD_RAM.positionWindowTime0

/*473c, Data Type: positionReachedConfigurationBits_t */
        #define OD_positionReachedConfigurationBits                 CO_OD_RAM.positionReachedConfigurationBits

/*474c, Data Type: positionRampGeneratorRampType_t */
        #define OD_positionRampGeneratorRampType                    CO_OD_RAM.positionRampGeneratorRampType

/*474d, Data Type: positionRampGeneratorState_t */
        #define OD_positionRampGeneratorState                       CO_OD_RAM.positionRampGeneratorState

/*4760, Data Type: actualTargetPosition_t */
        #define OD_actualTargetPosition                             CO_OD_RAM.actualTargetPosition

/*4761, Data Type: actualCommandPosition_t */
        #define OD_actualCommandPosition                            CO_OD_RAM.actualCommandPosition

/*4762, Data Type: actualPosition_t */
        #define OD_actualPosition                                   CO_OD_RAM.actualPosition

/*4763, Data Type: actualPositionFollowingError_t */
        #define OD_actualPositionFollowingError                     CO_OD_RAM.actualPositionFollowingError

/*4764, Data Type: actualPositionOfIndex_t */
        #define OD_actualPositionOfIndex                            CO_OD_RAM.actualPositionOfIndex

/*4770, Data Type: actualTargetPositionInIncrements_t */
        #define OD_actualTargetPositionInIncrements                 CO_OD_RAM.actualTargetPositionInIncrements

/*4771, Data Type: actualCommandPositionInIncrements_t */
        #define OD_actualCommandPositionInIncrements                CO_OD_RAM.actualCommandPositionInIncrements

/*4772, Data Type: actualPositionInIncrements_t */
        #define OD_actualPositionInIncrements                       CO_OD_RAM.actualPositionInIncrements

/*4773, Data Type: actualFollowingErrorInIncrements_t */
        #define OD_actualFollowingErrorInIncrements                 CO_OD_RAM.actualFollowingErrorInIncrements

/*4774, Data Type: actualIndexPositionInIncrements_t */
        #define OD_actualIndexPositionInIncrements                  CO_OD_RAM.actualIndexPositionInIncrements

/*4790, Data Type: absolutePositioning_t */
        #define OD_absolutePositioning                              CO_OD_RAM.absolutePositioning

/*4791, Data Type: relativePositioning_t */
        #define OD_relativePositioning                              CO_OD_RAM.relativePositioning

/*47a4, Data Type: gearBackLashPath_t */
        #define OD_gearBackLashPath                                 CO_OD_RAM.gearBackLashPath

/*47b0, Data Type: homingCommand_t */
        #define OD_homingCommand                                    CO_OD_RAM.homingCommand

/*47b1, Data Type: homingStatus_t */
        #define OD_homingStatus                                     CO_OD_RAM.homingStatus

/*47b2, Data Type: homingMethod0_t */
        #define OD_homingMethod0                                    CO_OD_RAM.homingMethod0

/*47b3, Data Type: homingOffset_t */
        #define OD_homingOffset                                     CO_OD_RAM.homingOffset

/*47b4, Data Type: homingVelocitySearchingTheSwitch_t */
        #define OD_homingVelocitySearchingTheSwitch                 CO_OD_RAM.homingVelocitySearchingTheSwitch

/*47b5, Data Type: homingAcceleration0_t */
        #define OD_homingAcceleration0                              CO_OD_RAM.homingAcceleration0

/*47b6, Data Type: homingMaxPathForSearchingTheIndex_t */
        #define OD_homingMaxPathForSearchingTheIndex                CO_OD_RAM.homingMaxPathForSearchingTheIndex

/*47b7, Data Type: homingOnBlockageConfigurationFlags_t */
        #define OD_homingOnBlockageConfigurationFlags               CO_OD_RAM.homingOnBlockageConfigurationFlags

/*47c2, Data Type: interpolationMethod_t */
        #define OD_interpolationMethod                              CO_OD_RAM.interpolationMethod

/*47c5, Data Type: interpolationBufferConfiguration_t */
        #define OD_interpolationBufferConfiguration                 CO_OD_RAM.interpolationBufferConfiguration

/*47c6, Data Type: interpolationData_t */
        #define OD_interpolationData                                CO_OD_RAM.interpolationData

/*47c7, Data Type: interpolationActualTargetPosition_t */
        #define OD_interpolationActualTargetPosition                CO_OD_RAM.interpolationActualTargetPosition

/*47c8, Data Type: moduloMethod_t */
        #define OD_moduloMethod                                     CO_OD_RAM.moduloMethod

/*47c9, Data Type: moduloValue_t */
        #define OD_moduloValue                                      CO_OD_RAM.moduloValue

/*4830, Data Type: PWM_Frequency_t */
        #define OD_PWM_Frequency                                    CO_OD_RAM.PWM_Frequency

/*4850, Data Type: systemClock_t */
        #define OD_systemClock                                      CO_OD_RAM.systemClock

/*48f3, Data Type: SSI_InterfaceConfiguration_t */
        #define OD_SSI_InterfaceConfiguration                       CO_OD_RAM.SSI_InterfaceConfiguration

/*4900, Data Type: motorType0_t */
        #define OD_motorType0                                       CO_OD_RAM.motorType0

/*4901, Data Type: motorRatedSpeed_t */
        #define OD_motorRatedSpeed                                  CO_OD_RAM.motorRatedSpeed

/*4902, Data Type: motorRatedVoltage_t */
        #define OD_motorRatedVoltage                                CO_OD_RAM.motorRatedVoltage

/*4910, Data Type: motorNumberOfPoles_t */
        #define OD_motorNumberOfPoles                               CO_OD_RAM.motorNumberOfPoles

/*4911, Data Type: motorPolarity_t */
        #define OD_motorPolarity                                    CO_OD_RAM.motorPolarity

/*4913, Data Type: motorCommutationType_t */
        #define OD_motorCommutationType                             CO_OD_RAM.motorCommutationType

/*4940, Data Type: hallSensorType_t */
        #define OD_hallSensorType                                   CO_OD_RAM.hallSensorType

/*4944, Data Type: reserved_t */
        #define OD_reserved                                         CO_OD_RAM.reserved

/*4949, Data Type: hallPulsesConfigurationFlags_t */
        #define OD_hallPulsesConfigurationFlags                     CO_OD_RAM.hallPulsesConfigurationFlags

/*494a, Data Type: actualHallPosition_t */
        #define OD_actualHallPosition                               CO_OD_RAM.actualHallPosition

/*4962, Data Type: encoderResolutionInCounts_t */
        #define OD_encoderResolutionInCounts                        CO_OD_RAM.encoderResolutionInCounts

/*4963, Data Type: encoderResolutionInLines_t */
        #define OD_encoderResolutionInLines                         CO_OD_RAM.encoderResolutionInLines

/*496a, Data Type: actualEncoderPosition_t */
        #define OD_actualEncoderPosition                            CO_OD_RAM.actualEncoderPosition

/*496b, Data Type: actualEncoderIndexPosition_t */
        #define OD_actualEncoderIndexPosition                       CO_OD_RAM.actualEncoderIndexPosition

/*496c, Data Type: countsIndexPulses_t */
        #define OD_countsIndexPulses                                CO_OD_RAM.countsIndexPulses

/*4970, Data Type: SSI_AbsoluteEncoderEnable_t */
        #define OD_SSI_AbsoluteEncoderEnable                        CO_OD_RAM.SSI_AbsoluteEncoderEnable

/*4971, Data Type: SSI_AbsoluteEncoderCode_t */
        #define OD_SSI_AbsoluteEncoderCode                          CO_OD_RAM.SSI_AbsoluteEncoderCode

/*4972, Data Type: SSI_AbsoluteEncoderSingleTurnResolutionInCounts_t */
        #define OD_SSI_AbsoluteEncoderSingleTurnResolutionInCounts  CO_OD_RAM.SSI_AbsoluteEncoderSingleTurnResolutionInCounts

/*497a, Data Type: SSI_AbsoluteEncoderActualPositionExtendedOn32Bits_t */
        #define OD_SSI_AbsoluteEncoderActualPositionExtendedOn32Bits CO_OD_RAM.SSI_AbsoluteEncoderActualPositionExtendedOn32Bits

/*497b, Data Type: SSI_AbsoluteEncoderActualIndexPosition_t */
        #define OD_SSI_AbsoluteEncoderActualIndexPosition           CO_OD_RAM.SSI_AbsoluteEncoderActualIndexPosition

/*497c, Data Type: SSI_AbsoluteEncoderCountOfIndexPulses_t */
        #define OD_SSI_AbsoluteEncoderCountOfIndexPulses            CO_OD_RAM.SSI_AbsoluteEncoderCountOfIndexPulses

/*49a0, Data Type: brakeManagementConfiguration_t */
        #define OD_brakeManagementConfiguration                     CO_OD_RAM.brakeManagementConfiguration

/*49a2, Data Type: quasiAbsoluteEncoderConfigurationFlags_t */
        #define OD_quasiAbsoluteEncoderConfigurationFlags           CO_OD_RAM.quasiAbsoluteEncoderConfigurationFlags

/*4a02, Data Type: velocityMeasurementGateTime_t */
        #define OD_velocityMeasurementGateTime                      CO_OD_RAM.velocityMeasurementGateTime

/*4a04, Data Type: velocityMeasurementInCounts_t */
        #define OD_velocityMeasurementInCounts                      CO_OD_RAM.velocityMeasurementInCounts

/*4b00, Data Type: factorGroupConfiguration_t */
        #define OD_factorGroupConfiguration                         CO_OD_RAM.factorGroupConfiguration

/*4b10, Data Type: factorGroupPolarity_t */
        #define OD_factorGroupPolarity                              CO_OD_RAM.factorGroupPolarity

/*4b11, Data Type: factorGroupPositionNotationIndex_t */
        #define OD_factorGroupPositionNotationIndex                 CO_OD_RAM.factorGroupPositionNotationIndex

/*4b12, Data Type: factorGroupPositionDimensionIndex_t */
        #define OD_factorGroupPositionDimensionIndex                CO_OD_RAM.factorGroupPositionDimensionIndex

/*4b13, Data Type: factorGroupVelocityNotationIndex_t */
        #define OD_factorGroupVelocityNotationIndex                 CO_OD_RAM.factorGroupVelocityNotationIndex

/*4b14, Data Type: factorGroupVelocityDimensionIndex_t */
        #define OD_factorGroupVelocityDimensionIndex                CO_OD_RAM.factorGroupVelocityDimensionIndex

/*4b15, Data Type: factorGroupAccelerationNotationIndex_t */
        #define OD_factorGroupAccelerationNotationIndex             CO_OD_RAM.factorGroupAccelerationNotationIndex

/*4b16, Data Type: factorGroupAccelerationDimensionIndex_t */
        #define OD_factorGroupAccelerationDimensionIndex            CO_OD_RAM.factorGroupAccelerationDimensionIndex

/*4b17, Data Type: factorGroupPositionScaleNumerator_t */
        #define OD_factorGroupPositionScaleNumerator                CO_OD_RAM.factorGroupPositionScaleNumerator

/*4b18, Data Type: factorGroupVelocityScaleNumerator_t */
        #define OD_factorGroupVelocityScaleNumerator                CO_OD_RAM.factorGroupVelocityScaleNumerator

/*4b19, Data Type: factorGroupGearRatioMotorShaftRevolution_t */
        #define OD_factorGroupGearRatioMotorShaftRevolution         CO_OD_RAM.factorGroupGearRatioMotorShaftRevolution

/*4b1a, Data Type: factorGroupFeedConstantFeed_t */
        #define OD_factorGroupFeedConstantFeed                      CO_OD_RAM.factorGroupFeedConstantFeed

/*6007, Data Type: INTEGER16 */
        #define OD_abortConnectionOptionCode                        CO_OD_RAM.abortConnectionOptionCode

/*603f, Data Type: UNSIGNED16 */
        #define OD_errorCode                                        CO_OD_RAM.errorCode

/*6040, Data Type: UNSIGNED16 */
        #define OD_controlword                                      CO_OD_RAM.controlword

/*6041, Data Type: UNSIGNED16 */
        #define OD_statusword                                       CO_OD_RAM.statusword

/*6042, Data Type: INTEGER16 */
        #define OD_vlTargetVelocity                                 CO_OD_RAM.vlTargetVelocity

/*6043, Data Type: INTEGER16 */
        #define OD_vlVelocityDemand                                 CO_OD_RAM.vlVelocityDemand

/*6044, Data Type: INTEGER16 */
        #define OD_vlVelocityActualValue                            CO_OD_RAM.vlVelocityActualValue

/*6046, Data Type: vlVelocityMinMaxAmount_t */
        #define OD_vlVelocityMinMaxAmount                           CO_OD_RAM.vlVelocityMinMaxAmount

/*6048, Data Type: vlVelocityAcceleration_t */
        #define OD_vlVelocityAcceleration                           CO_OD_RAM.vlVelocityAcceleration

/*6049, Data Type: vlVelocityDeceleration_t */
        #define OD_vlVelocityDeceleration                           CO_OD_RAM.vlVelocityDeceleration

/*604a, Data Type: vlVelocityQuickStop_t */
        #define OD_vlVelocityQuickStop                              CO_OD_RAM.vlVelocityQuickStop

/*604c, Data Type: vlDimensionFactor_t */
        #define OD_vlDimensionFactor                                CO_OD_RAM.vlDimensionFactor

/*605a, Data Type: INTEGER16 */
        #define OD_quickStopOptionCode                              CO_OD_RAM.quickStopOptionCode

/*6060, Data Type: INTEGER8 */
        #define OD_modesOfOperation                                 CO_OD_RAM.modesOfOperation

/*6061, Data Type: INTEGER8 */
        #define OD_modesOfOperationDisplay                          CO_OD_RAM.modesOfOperationDisplay

/*6062, Data Type: INTEGER32 */
        #define OD_positionDemandValue                              CO_OD_RAM.positionDemandValue

/*6063, Data Type: INTEGER32 */
        #define OD_positionActualValueCount                         CO_OD_RAM.positionActualValueCount

/*6064, Data Type: INTEGER32 */
        #define OD_positionActualValue                              CO_OD_RAM.positionActualValue

/*6065, Data Type: UNSIGNED32 */
        #define OD_followingErrorWindow                             CO_OD_RAM.followingErrorWindow

/*6066, Data Type: UNSIGNED16 */
        #define OD_followingErrorTimeOut                            CO_OD_RAM.followingErrorTimeOut

/*6067, Data Type: UNSIGNED32 */
        #define OD_positionWindow                                   CO_OD_RAM.positionWindow

/*6068, Data Type: UNSIGNED16 */
        #define OD_positionWindowTime                               CO_OD_RAM.positionWindowTime

/*606c, Data Type: INTEGER32 */
        #define OD_velocityActualValue                              CO_OD_RAM.velocityActualValue

/*606d, Data Type: UNSIGNED16 */
        #define OD_velocityWindow                                   CO_OD_RAM.velocityWindow

/*606e, Data Type: UNSIGNED16 */
        #define OD_velocityWindowTime                               CO_OD_RAM.velocityWindowTime

/*606f, Data Type: UNSIGNED16 */
        #define OD_velocityThreshold                                CO_OD_RAM.velocityThreshold

/*6070, Data Type: UNSIGNED16 */
        #define OD_velocityThresholdTime                            CO_OD_RAM.velocityThresholdTime

/*6071, Data Type: INTEGER16 */
        #define OD_targetTorque                                     CO_OD_RAM.targetTorque

/*6072, Data Type: UNSIGNED16 */
        #define OD_maxTorque                                        CO_OD_RAM.maxTorque

/*6075, Data Type: UNSIGNED32 */
        #define OD_motorRatedCurrent                                CO_OD_RAM.motorRatedCurrent

/*6077, Data Type: INTEGER16 */
        #define OD_torqueActualValue                                CO_OD_RAM.torqueActualValue

/*6078, Data Type: INTEGER16 */
        #define OD_currentActualValue                               CO_OD_RAM.currentActualValue

/*6079, Data Type: UNSIGNED32 */
        #define OD_DCLinkCircuitVoltage                             CO_OD_RAM.DCLinkCircuitVoltage

/*607a, Data Type: INTEGER32 */
        #define OD_targetPosition                                   CO_OD_RAM.targetPosition

/*607c, Data Type: INTEGER32 */
        #define OD_homeOffset                                       CO_OD_RAM.homeOffset

/*607d, Data Type: softwarePositionLimit_t */
        #define OD_softwarePositionLimit                            CO_OD_RAM.softwarePositionLimit

/*607e, Data Type: UNSIGNED8 */
        #define OD_polarity                                         CO_OD_RAM.polarity

/*607f, Data Type: UNSIGNED32 */
        #define OD_maxProfileVelocity                               CO_OD_RAM.maxProfileVelocity

/*6081, Data Type: UNSIGNED32 */
        #define OD_profileVelocity                                  CO_OD_RAM.profileVelocity

/*6083, Data Type: UNSIGNED32 */
        #define OD_profileAcceleration                              CO_OD_RAM.profileAcceleration

/*6084, Data Type: UNSIGNED32 */
        #define OD_profileDeceleration                              CO_OD_RAM.profileDeceleration

/*6085, Data Type: UNSIGNED32 */
        #define OD_quickStopDeceleration                            CO_OD_RAM.quickStopDeceleration

/*6086, Data Type: INTEGER16 */
        #define OD_motionProfileType                                CO_OD_RAM.motionProfileType

/*6087, Data Type: UNSIGNED32 */
        #define OD_torqueSlope                                      CO_OD_RAM.torqueSlope

/*6088, Data Type: INTEGER16 */
        #define OD_torqueProfileType                                CO_OD_RAM.torqueProfileType

/*6089, Data Type: INTEGER8 */
        #define OD_positionNotationIndex                            CO_OD_RAM.positionNotationIndex

/*608a, Data Type: UNSIGNED8 */
        #define OD_positionDimensionIndex                           CO_OD_RAM.positionDimensionIndex

/*608b, Data Type: INTEGER8 */
        #define OD_velocityNotationIndex                            CO_OD_RAM.velocityNotationIndex

/*608c, Data Type: UNSIGNED8 */
        #define OD_velocityDimensionIndex                           CO_OD_RAM.velocityDimensionIndex

/*608d, Data Type: INTEGER8 */
        #define OD_accelerationNotationIndex                        CO_OD_RAM.accelerationNotationIndex

/*608e, Data Type: UNSIGNED8 */
        #define OD_accelerationDimensionIndex                       CO_OD_RAM.accelerationDimensionIndex

/*608f, Data Type: positionEncoderResolution_t */
        #define OD_positionEncoderResolution                        CO_OD_RAM.positionEncoderResolution

/*6090, Data Type: velocityEncoderResolution_t */
        #define OD_velocityEncoderResolution                        CO_OD_RAM.velocityEncoderResolution

/*6091, Data Type: gearRatio_t */
        #define OD_gearRatio                                        CO_OD_RAM.gearRatio

/*6092, Data Type: feedConstant_t */
        #define OD_feedConstant                                     CO_OD_RAM.feedConstant

/*6098, Data Type: INTEGER8 */
        #define OD_homingMethod                                     CO_OD_RAM.homingMethod

/*6099, Data Type: homingSpeeds_t */
        #define OD_homingSpeeds                                     CO_OD_RAM.homingSpeeds

/*609a, Data Type: UNSIGNED32 */
        #define OD_homingAcceleration                               CO_OD_RAM.homingAcceleration

/*60c1, Data Type: interpolatedDataRecord_t */
        #define OD_interpolatedDataRecord                           CO_OD_RAM.interpolatedDataRecord

/*60c2, Data Type: interpolationTimePeriod_t */
        #define OD_interpolationTimePeriod                          CO_OD_RAM.interpolationTimePeriod

/*60e0, Data Type: UNSIGNED16 */
        #define OD_positiveTorqueLimitValue                         CO_OD_RAM.positiveTorqueLimitValue

/*60e1, Data Type: UNSIGNED16 */
        #define OD_negativeTorqueLimitValue                         CO_OD_RAM.negativeTorqueLimitValue

/*60e3, Data Type: supportedHomingMethods_t */
        #define OD_supportedHomingMethods                           CO_OD_RAM.supportedHomingMethods

/*60f4, Data Type: INTEGER32 */
        #define OD_followingErrorActualValue                        CO_OD_RAM.followingErrorActualValue

/*60fc, Data Type: INTEGER32 */
        #define OD_positionDemandValueCount                         CO_OD_RAM.positionDemandValueCount

/*60fd, Data Type: UNSIGNED32 */
        #define OD_digitalInputs                                    CO_OD_RAM.digitalInputs

/*60fe, Data Type: digitalOutputs_t */
        #define OD_digitalOutputs                                   CO_OD_RAM.digitalOutputs

/*60ff, Data Type: INTEGER32 */
        #define OD_targetVelocity                                   CO_OD_RAM.targetVelocity

/*6402, Data Type: UNSIGNED16 */
        #define OD_motorType                                        CO_OD_RAM.motorType

/*6502, Data Type: UNSIGNED32 */
        #define OD_supportedDriveModes                              CO_OD_RAM.supportedDriveModes

/*67fe, Data Type: errorBehaviourOld_t */
        #define OD_errorBehaviourOld                                CO_OD_RAM.errorBehaviourOld

#endif
// clang-format on
