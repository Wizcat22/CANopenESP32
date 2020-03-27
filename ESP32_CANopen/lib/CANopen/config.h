#ifndef CONFIG_H
#define CONFIG_H

//####  CAN CONFIG  ####

#define CAN_TX_IO GPIO_NUM_5  /** CAN TX pin */
#define CAN_RX_IO GPIO_NUM_15 /** CAN RX pin */
#define CAN_TX_QUEUE_LENGTH 5 /** CAN TX buffer size */
#define CAN_RX_QUEUE_LENGTH 5 /** CAN RX buffer size */

#define CO_CAN_PSEUDO_INTERRUPT_INTERVAL 1000 /** CAN "Interrupt" Interval in μs*/

#define CAN_TICKS_TO_WAIT 10000

//----------------------------------

#endif /* CONFIG_H */


