/*
 * CAN module object for generic microcontroller.
 *
 * This file is a template for other microcontrollers.
 *
 * @file        CO_driver.c
 * @ingroup     CO_driver
 * @author      Janez Paternoster
 * @author      Alexander Miller
 * @author      Mathias Parys
 * @copyright   2004 - 2020 Janez Paternoster
 *
 * This file is part of CANopenNode, an opensource CANopen Stack.
 * Project home page is <https://github.com/CANopenNode/CANopenNode>.
 * For more information on CANopen see <http://www.can-cia.org/>.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "CO_driver.h"
#include "CO_Emergency.h"
#include "config.h"
#include "stdio.h"
#include <stdlib.h>
#include <stdint.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/can.h"
#include "soc/soc.h"
#include "esp_intr_alloc.h"

CO_CANmodule_t* CANmodulePointer = NULL;

//CAN Timing configuration
  static can_timing_config_t timingConfig = CAN_TIMING_CONFIG_1MBITS(); //Set Baudrate to 1Mbit
//CAN Filter configuration
  static can_filter_config_t filterConfig = CAN_FILTER_CONFIG_ACCEPT_ALL(); //Don't filter messages
//CAN General configuration
  static can_general_config_t generalConfig = {.mode = CAN_MODE_NORMAL, .tx_io = CAN_TX_IO, .rx_io = CAN_RX_IO, .clkout_io = CAN_IO_UNUSED, .bus_off_io = CAN_IO_UNUSED, .tx_queue_len = CAN_TX_QUEUE_LENGTH, .rx_queue_len = CAN_RX_QUEUE_LENGTH, .alerts_enabled = CAN_ALERT_NONE, .clkout_divider = 0 };

//#########-TimerConfiguration-############

const esp_timer_create_args_t CO_CANinterruptArgs = {
    .callback = &CO_CANinterrupt,
    /* name is optional, but may help identify the timer when debugging */
    .name = "CO_CANinterrupt"};

esp_timer_handle_t CO_CANinterruptPeriodicTimer;

/******************************************************************************/
void CO_CANsetConfigurationMode(void *CANdriverState){
    /* Put CAN module in configuration mode */
    (void) CANdriverState;
}


/******************************************************************************/
void CO_CANsetNormalMode(CO_CANmodule_t *CANmodule){
    generalConfig.mode = CAN_MODE_NORMAL;
    generalConfig.tx_io = CAN_TX_IO;
    generalConfig.rx_io = CAN_RX_IO;
    generalConfig.clkout_io = CAN_IO_UNUSED;
    generalConfig.bus_off_io = CAN_IO_UNUSED;
    generalConfig.tx_queue_len = CAN_TX_QUEUE_LENGTH;
    generalConfig.rx_queue_len = CAN_RX_QUEUE_LENGTH;
    generalConfig.alerts_enabled = CAN_ALERT_NONE;
    generalConfig.clkout_divider = 0;
    CANmodule->CANnormal = true;
}


/******************************************************************************/
CO_ReturnError_t CO_CANmodule_init(
        CO_CANmodule_t         *CANmodule,
        void                   *CANdriverState,
        CO_CANrx_t              rxArray[],
        uint16_t                rxSize,
        CO_CANtx_t              txArray[],
        uint16_t                txSize,
        uint16_t                CANbitRate)
{
    CANmodulePointer = CANmodule;
    

    /* verify arguments */
    if(CANmodule==NULL || rxArray==NULL || txArray==NULL){
        return CO_ERROR_ILLEGAL_ARGUMENT;
    }

    /* Configure object variables */
    CANmodule->CANdriverState = CANdriverState;
    CANmodule->baudrate = CANbitRate;
    CANmodule->rxSize = rxSize;
    CANmodule->rxPin = CAN_RX_IO;
    CANmodule->txSize = txSize;
    CANmodule->txPin = CAN_TX_IO;
    CANmodule->CANnormal = false;
    CANmodule->useCANrxFilters = false;/* microcontroller dependent */
    CANmodule->bufferInhibitFlag = false;
    CANmodule->firstCANtxMessage = true;
    CANmodule->CANtxCount = 0U;
    CANmodule->errOld = 0U;
    CANmodule->em = NULL;
    CANmodule->rxArray = rxArray;
    CANmodule->txArray = txArray;

    for(uint16_t i=0U; i<rxSize; i++){
        rxArray[i].ident = 0U;
        rxArray[i].mask = (uint16_t)0xFFFFFFFFU;
        rxArray[i].object = NULL;
        rxArray[i].pFunct = NULL;
    }
    for(uint16_t i=0U; i<txSize; i++){
        txArray[i].bufferFull = false;
    }

    /* Configure CAN module registers */



    /* Configure CAN timing */
    switch(CANmodule->baudrate){
        case 25: 
        //Set Baudrate to 25kbit;
        timingConfig.brp = 128;
        timingConfig.tseg_1 = 16;
        timingConfig.tseg_2 = 8;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        case 50:
        //Set Baudrate to 50kbit;
        timingConfig.brp = 80;
        timingConfig.tseg_1 = 15;
        timingConfig.tseg_2 = 4;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        case 100:
        //Set Baudrate to 100kbit;
        timingConfig.brp = 40;
        timingConfig.tseg_1 = 15;
        timingConfig.tseg_2 = 4;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        case 125:
        //Set Baudrate to 125kbit;
        timingConfig.brp = 32;
        timingConfig.tseg_1 = 15;
        timingConfig.tseg_2 = 4;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        case 250:
        //Set Baudrate to 250kbit;
        timingConfig.brp = 16;
        timingConfig.tseg_1 = 15;
        timingConfig.tseg_2 = 4;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        case 500:
        //Set Baudrate to 500kbit;
        timingConfig.brp = 8;
        timingConfig.tseg_1 = 15;
        timingConfig.tseg_2 = 4;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        case 800:
        //Set Baudrate to 800kbit;
        timingConfig.brp = 4;
        timingConfig.tseg_1 = 16;
        timingConfig.tseg_2 = 8;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        case 1000:
        //Set Baudrate to 1Mbit;
        timingConfig.brp = 4;
        timingConfig.tseg_1 = 15;
        timingConfig.tseg_2 = 4;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
        break;
        default:
        ESP_LOGE("CO_driver","%d => Invalid Baudrate! Using 1Mbit as default!",CANmodule->baudrate);
        //Set Baudrate to 1Mbit;
        timingConfig.brp = 4;
        timingConfig.tseg_1 = 15;
        timingConfig.tseg_2 = 4;
        timingConfig.sjw = 3;
        timingConfig.triple_sampling = false;
    }
    ESP_LOGE("CAN Baudrate","CAN Baudrade: %d",CANmodule->baudrate);

    

    /* Configure CAN module hardware filters */
    if(CANmodule->useCANrxFilters){
        /* CAN module filters are used, they will be configured with */
        /* CO_CANrxBufferInit() functions, called by separate CANopen */
        /* init functions. */
        /* Configure all masks so, that received message must match filter */
        
        //Don't filter messages
        ESP_LOGI("CO_driver","RxFilters are active, but no filter configured.");
        filterConfig.acceptance_code = 0;
        filterConfig.acceptance_mask = 0xFFFFFFFF;
        filterConfig.single_filter = true;
    }
    else{
        /* CAN module filters are not used, all messages with standard 11-bit */
        /* identifier will be received */
        /* Configure mask 0 so, that all messages with standard identifier are accepted */
        //Don't filter messages
        filterConfig.acceptance_code = 0;
        filterConfig.acceptance_mask = 0xFFFFFFFF;
        filterConfig.single_filter = true;
    }

    //Install CAN driver
    ESP_ERROR_CHECK(can_driver_install(&generalConfig, &timingConfig, &filterConfig));

    /* configure CAN interrupt registers */
    /*WORKAROUND: KEINE INTERRUPTS MÖGLICH DA BEREITS IM TREIBER VERWENDET*/
    /* Configure Timer interrupt function for execution every CO_CAN_PSEUDO_INTERRUPT_INTERVAL */
    ESP_ERROR_CHECK(esp_timer_create(&CO_CANinterruptArgs, &CO_CANinterruptPeriodicTimer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(CO_CANinterruptPeriodicTimer, CO_CAN_PSEUDO_INTERRUPT_INTERVAL));

    return CO_ERROR_NO;
}


/******************************************************************************/
void CO_CANmodule_disable(CO_CANmodule_t *CANmodule){
    /* turn off the module */
    can_stop();
}


/******************************************************************************/
uint16_t CO_CANrxMsg_readIdent(const CO_CANrxMsg_t *rxMsg){
    return (uint16_t) rxMsg->ident;
}

//TODO:

/******************************************************************************/
CO_ReturnError_t CO_CANrxBufferInit(
    CO_CANmodule_t *CANmodule,
    uint16_t index,
    uint16_t ident,
    uint16_t mask,
    bool_t rtr,
    void *object,
    void (*pFunct)(void *object, const CO_CANrxMsg_t *message))
{
    CO_ReturnError_t ret = 0;
    if ((CANmodule != NULL) && (object != NULL) && (pFunct != NULL) && (index < CANmodule->rxSize))
    {
        /* buffer, which will be configured */
        CO_CANrx_t *buffer = &CANmodule->rxArray[index];

        /* Configure object variables */
        buffer->object = object;
        buffer->pFunct = pFunct;

        buffer->ident = ident;
        if (rtr == true)
        {
            buffer->mask = CAN_MSG_FLAG_RTR;
        }
        else
        {
            buffer->mask = 0;
        }
        /* CAN identifier and CAN mask, bit aligned with CAN module. Different on different microcontrollers. */
        //buffer->ident = ident & 0x07FFU;
        //if(rtr){
        //    buffer->ident |= 0x0800U;
        //}
        //buffer->mask = (mask & 0x07FFU) | 0x0800U;

        /* Set CAN hardware module filter and mask. */
        if (CANmodule->useCANrxFilters)
        {
        }
    }
    else
    {
        ret = CO_ERROR_ILLEGAL_ARGUMENT;
    }

    return ret;
}

/******************************************************************************/
CO_CANtx_t *CO_CANtxBufferInit(
    CO_CANmodule_t *CANmodule,
    uint16_t index,
    uint16_t ident,
    bool_t rtr,
    uint8_t noOfBytes,
    bool_t syncFlag)
{
    CO_CANtx_t *buffer = NULL;
    if ((CANmodule != NULL) && (index < CANmodule->txSize))
    {
        /* get specific buffer */
        buffer = &CANmodule->txArray[index];
        /* CAN identifier, DLC and rtr, bit aligned with CAN module transmit buffer.
          * Microcontroller specific. */
        buffer->ident = ident;
        if (rtr == true){
            buffer->mask = CAN_MSG_FLAG_RTR;
        }
        buffer->DLC = noOfBytes;
        buffer->bufferFull = false;
        buffer->syncFlag = syncFlag;
    }
    else
    {
        ESP_LOGE("CO_TX_BUFFER", "Buffer FULL or CANModule == NULL!; Return NULL");
    }

    return buffer;
}

/******************************************************************************/
CO_ReturnError_t CO_CANsend(CO_CANmodule_t *CANmodule, CO_CANtx_t *buffer)
{
    can_status_info_t canDriverStatus;
    can_get_status_info(&canDriverStatus);
    CO_ReturnError_t err = CO_ERROR_NO;

    /* Verify overflow */
    if (buffer->bufferFull)
    {
        if (!CANmodule->firstCANtxMessage)
        {
            /* don't set error, if bootup message is still on buffers */
            CO_errorReport((CO_EM_t *)CANmodule->em, CO_EM_CAN_TX_OVERFLOW, CO_EMC_CAN_OVERRUN, buffer->ident);
        }
        err = CO_ERROR_TX_OVERFLOW; //STM is das im IF darüber?
    }
    CO_LOCK_CAN_SEND();
    /* if CAN TX buffer is free, copy message to it */
    //ToDo:
    //check if buffer is full
    if ((canDriverStatus.msgs_to_tx < CAN_TX_QUEUE_LENGTH) && (CANmodule->CANtxCount != 0))
    {
        CANmodule->bufferInhibitFlag = buffer->syncFlag;
        /* copy message and txRequest */
        can_message_t transmit_message;
        transmit_message.identifier = buffer->ident;
        transmit_message.flags = buffer->mask;
        transmit_message.data_length_code = buffer->DLC;
        for (uint8_t i = 0; i < CAN_MAX_DATA_LEN; i++)
        {
            transmit_message.data[i] = buffer->data[i];
        }
        if (can_transmit(&transmit_message, pdMS_TO_TICKS(1000)) == ESP_OK)
        {
            CANmodule->CANtxCount--;
            buffer->bufferFull = false;

            ESP_LOGE("CO_CAN_SEND", "Message queued for transmission");
        }
        else
        {
            ESP_LOGE("CO_CAN_SEND", "Failed to queue message for transmission");
        }
    }

    /* if no buffer is free, throw error message */
    else if ((CANmodule->CANtxCount == 0))
    {
        ESP_LOGE("CO_CAN_SEND", "TX QUEUE is empty. Continue...");
        err = CO_ERROR_NO;
    }
    else
    {
        buffer->bufferFull = true;
        ESP_LOGE("CO_CAN_SEND", "ERROR! TX QUEUE FULL. Message DROPPED!");
        err = CO_ERROR_TX_OVERFLOW;
    }
    CO_UNLOCK_CAN_SEND();

    return err;
}

CO_ReturnError_t CO_CANreceive(CO_CANmodule_t *CANmodule)
{
    CO_ReturnError_t err = CO_ERROR_NO;
    can_status_info_t canDriverStatus;
    can_get_status_info(&canDriverStatus);
    
    CO_CANrx_t CO_receivedMessage;
    uint8_t index = 0;
    can_message_t receivedMesage;

//ToDo: COCANrx_handle
//ToDo: For (Every Package in Queue)
    
    if (canDriverStatus.msgs_to_rx > 0)
    {
        if (can_receive(&receivedMesage, pdMS_TO_TICKS(1)) == ESP_OK)
        {
            ESP_LOGE("CO_CANreceive", "Message received");
        }
        else
        {
            ESP_LOGE("CO_CANreceive", "Failed to receive message\n");
            err = CO_ERROR_TIMEOUT;
        }
    }

    return err;
}

//WTF IS THIS?
/******************************************************************************/
void CO_CANclearPendingSyncPDOs(CO_CANmodule_t *CANmodule){
    uint32_t tpdoDeleted = 0U;

    CO_LOCK_CAN_SEND();
    /* Abort message from CAN module, if there is synchronous TPDO.
     * Take special care with this functionality. */
    if(/*messageIsOnCanBuffer && */CANmodule->bufferInhibitFlag){
        /* clear TXREQ */
        CANmodule->bufferInhibitFlag = false;
        tpdoDeleted = 1U;
    }
    /* delete also pending synchronous TPDOs in TX buffers */
    if(CANmodule->CANtxCount != 0U){
        uint16_t i;
        CO_CANtx_t *buffer = &CANmodule->txArray[0];
        for(i = CANmodule->txSize; i > 0U; i--){
            if(buffer->bufferFull){
                if(buffer->syncFlag){
                    buffer->bufferFull = false;
                    CANmodule->CANtxCount--;
                    tpdoDeleted = 2U;
                }
            }
            buffer++;
        }
    }
    CO_UNLOCK_CAN_SEND();


    if(tpdoDeleted != 0U){
        CO_errorReport((CO_EM_t*)CANmodule->em, CO_EM_TPDO_OUTSIDE_WINDOW, CO_EMC_COMMUNICATION, tpdoDeleted);
    }
}

//GGF durch ESP_LOG bzw ESP_ERROR ersetzen!
/******************************************************************************/
void CO_CANverifyErrors(CO_CANmodule_t *CANmodule){
    uint16_t rxErrors, txErrors, overflow;
    CO_EM_t* em = (CO_EM_t*)CANmodule->em;
    uint32_t err;

    /* get error counters from module. Id possible, function may use different way to
     * determine errors. */
    rxErrors = CANmodule->txSize;
    txErrors = CANmodule->txSize;
    overflow = CANmodule->txSize;

    err = ((uint32_t)txErrors << 16) | ((uint32_t)rxErrors << 8) | overflow;

    if(CANmodule->errOld != err){
        CANmodule->errOld = err;

        if(txErrors >= 256U){                               /* bus off */
            CO_errorReport(em, CO_EM_CAN_TX_BUS_OFF, CO_EMC_BUS_OFF_RECOVERED, err);
        }
        else{                                               /* not bus off */
            CO_errorReset(em, CO_EM_CAN_TX_BUS_OFF, err);

            if((rxErrors >= 96U) || (txErrors >= 96U)){     /* bus warning */
                CO_errorReport(em, CO_EM_CAN_BUS_WARNING, CO_EMC_NO_ERROR, err);
            }

            if(rxErrors >= 128U){                           /* RX bus passive */
                CO_errorReport(em, CO_EM_CAN_RX_BUS_PASSIVE, CO_EMC_CAN_PASSIVE, err);
            }
            else{
                CO_errorReset(em, CO_EM_CAN_RX_BUS_PASSIVE, err);
            }

            if(txErrors >= 128U){                           /* TX bus passive */
                if(!CANmodule->firstCANtxMessage){
                    CO_errorReport(em, CO_EM_CAN_TX_BUS_PASSIVE, CO_EMC_CAN_PASSIVE, err);
                }
            }
            else{
                bool_t isError = CO_isError(em, CO_EM_CAN_TX_BUS_PASSIVE);
                if(isError){
                    CO_errorReset(em, CO_EM_CAN_TX_BUS_PASSIVE, err);
                    CO_errorReset(em, CO_EM_CAN_TX_OVERFLOW, err);
                }
            }

            if((rxErrors < 96U) && (txErrors < 96U)){       /* no error */
                CO_errorReset(em, CO_EM_CAN_BUS_WARNING, err);
            }
        }

        if(overflow != 0U){                                 /* CAN RX bus overflow */
            CO_errorReport(em, CO_EM_CAN_RXB_OVERFLOW, CO_EMC_CAN_OVERRUN, err);
        }
    }
}


/******************************************************************************/
void CO_CANinterrupt(void *args){
    CO_CANmodule_t *CANmodule = CANmodulePointer;
    can_status_info_t canDriverStatus;
    can_get_status_info(&canDriverStatus);
    if (CANmodule == NULL)
    {
       ESP_LOGE("CO_CANinterrupt","No CANmodule Object!");
    }
    
    /* receive interrupt */
    if(0){
        CO_CANrxMsg_t *rcvMsg;      /* pointer to received message in CAN module */
        uint16_t index;             /* index of received message */
        uint32_t rcvMsgIdent;       /* identifier of the received message */
        CO_CANrx_t *buffer = NULL;  /* receive message buffer from CO_CANmodule_t object. */
        bool_t msgMatched = false;

        rcvMsg = 0; /* get message from module here */
        rcvMsgIdent = rcvMsg->ident;
        if(CANmodule->useCANrxFilters){
            /* CAN module filters are used. Message with known 11-bit identifier has */
            /* been received */
            index = 0;  /* get index of the received message here. Or something similar */
            if(index < CANmodule->rxSize){
                buffer = &CANmodule->rxArray[index];
                /* verify also RTR */
                if(((rcvMsgIdent ^ buffer->ident) & buffer->mask) == 0U){
                    msgMatched = true;
                }
            }
        }
        else{
            /* CAN module filters are not used, message with any standard 11-bit identifier */
            /* has been received. Search rxArray form CANmodule for the same CAN-ID. */
            buffer = &CANmodule->rxArray[0];
            for(index = CANmodule->rxSize; index > 0U; index--){
                if(((rcvMsgIdent ^ buffer->ident) & buffer->mask) == 0U){
                    msgMatched = true;
                    break;
                }
                buffer++;
            }
        }

        /* Call specific function, which will process the message */
        if(msgMatched && (buffer != NULL) && (buffer->pFunct != NULL)){
            buffer->pFunct(buffer->object, rcvMsg);
        }

        /* Clear interrupt flag */
    }


    /* transmit interrupt */
    else if(0){
        /* Clear interrupt flag */

        /* First CAN message (bootup) was sent successfully */
        CANmodule->firstCANtxMessage = false;
        /* clear flag from previous message */
        CANmodule->bufferInhibitFlag = false;
        /* Are there any new messages waiting to be send */
        if(CANmodule->CANtxCount > 0U){
            uint16_t i;             /* index of transmitting message */

            /* first buffer */
            CO_CANtx_t *buffer = &CANmodule->txArray[0];
            /* search through whole array of pointers to transmit message buffers. */
            for(i = CANmodule->txSize; i > 0U; i--){
                /* if message buffer is full, send it. */
                if(buffer->bufferFull){
                    buffer->bufferFull = false;
                    CANmodule->CANtxCount--;

                    /* Copy message to CAN buffer */
                    CANmodule->bufferInhibitFlag = buffer->syncFlag;
                    /* canSend... */
                    break;                      /* exit for loop */
                }
                buffer++;
            }/* end of for loop */

            /* Clear counter if no more messages */
            if(i == 0U){
                CANmodule->CANtxCount = 0U;
            }
        }
    }
    else{
        /* some other interrupt reason */
    }
}
