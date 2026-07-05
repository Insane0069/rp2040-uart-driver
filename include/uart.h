#ifndef UART_H
#define UART_H

/******************************************************************************
 * @file    uart.h
 * @brief   RP2040 UART Driver Interface
 *
 * This file provides the public interface for the RP2040 UART driver.
 ******************************************************************************/

#include <stdint.h>
#include "rp2040.h"

/*=============================================================================
 * UART Configuration
 *===========================================================================*/

/* UART Instance */

typedef enum
{
    UART0_INSTANCE = 0,
    UART1_INSTANCE = 1

} UART_Instance_t;

/* Word Length */

typedef enum
{
    UART_WORD_LENGTH_5 = 5,
    UART_WORD_LENGTH_6 = 6,
    UART_WORD_LENGTH_7 = 7,
    UART_WORD_LENGTH_8 = 8

} UART_WordLength_t;

/* Stop Bits */

typedef enum
{
    UART_STOP_BITS_1 = 1,
    UART_STOP_BITS_2 = 2

} UART_StopBits_t;

/* Parity */

typedef enum
{
    UART_PARITY_NONE,
    UART_PARITY_EVEN,
    UART_PARITY_ODD

} UART_Parity_t;

/*=============================================================================
 * UART Driver API
 *===========================================================================*/

/**
 * @brief Initialize UART.
 *
 * @param uart UART0_INSTANCE or UART1_INSTANCE
 * @param baudrate Desired baud rate
 */
void UART_Init(UART_Instance_t uart, uint32_t baudrate);

/**
 * @brief Send one character.
 *
 * @param c Character to transmit
 */
void UART_SendChar(char c);

/**
 * @brief Send a string.
 *
 * @param str Null-terminated string
 */
void UART_SendString(const char *str);

/**
 * @brief Receive one character.
 *
 * @return Received character
 */
char UART_ReadChar(void);

#endif /* UART_H */