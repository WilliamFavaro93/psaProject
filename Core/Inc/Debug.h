/*
 * Debug.h
 *
 *  Created on: May 18, 2022
 *      Author: William.Favaro
 */

#ifndef DEBUG_H_
#define DEBUG_H_

/* "Debug.h" contains the debugging settings */

/* DEBUG */
#ifdef DEBUG


/* DEBUG_UART */

//#define DEBUG_UART

#ifdef DEBUG_UART
#define DEBUG_UART_TX_STATE
#define DEBUG_UART_TX_MODE
#define DEBUG_UART_RX_COMMAND
#endif /* DEBUG_UART */

#endif /* DEBUG */

#endif /* DEBUG_H_ */
