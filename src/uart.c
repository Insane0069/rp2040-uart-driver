/******************************************************************************
 * @file    uart.c
 * @brief   RP2040 UART Driver Implementation
 ******************************************************************************/

#include "include/uart.h"

/*=============================================================================
 * UART Initialization
 *===========================================================================*/

void UART_Init(UART_Instance_t uart, uint32_t baudrate)
{
    (void)uart;

    /*---------------------------------------------------------
     * Configure GPIO0 as UART TX
     *--------------------------------------------------------*/
    GPIO_CTRL(0) = GPIO_FUNC_UART;

    /*---------------------------------------------------------
     * Configure GPIO1 as UART RX
     *--------------------------------------------------------*/
    GPIO_CTRL(1) = GPIO_FUNC_UART;

    /*---------------------------------------------------------
     * Disable UART before configuration
     *--------------------------------------------------------*/
    UART0_CR = 0;

    /*---------------------------------------------------------
     * Baud Rate Configuration
     *
     * UARTCLK = 125 MHz
     *
     * Baud Divisor = UARTCLK / (16 × Baud)
     *
     * Example for 115200 baud:
     *
     * Integer = 67
     * Fraction = 52
     *
     * (Simple implementation)
     *--------------------------------------------------------*/

    (void)baudrate;

    UART0_IBRD = 67;
    UART0_FBRD = 52;

    /*---------------------------------------------------------
     * Configure Line Control
     *
     * 8 Data Bits
     * No Parity
     * One Stop Bit
     * FIFO Enabled
     *--------------------------------------------------------*/

    UART0_LCR_H =
            UART_LCR_H_WLEN_8 |
            UART_LCR_H_FEN;

    /*---------------------------------------------------------
     * Enable UART
     *--------------------------------------------------------*/

    UART0_CR =
            UART_CR_UARTEN |
            UART_CR_TXE |
            UART_CR_RXE;
}

/*=============================================================================
 * Send One Character
 *===========================================================================*/

void UART_SendChar(char c)
{
    /* Wait until TX FIFO has space */

    while (UART0_FR & UART_FR_TXFF);

    UART0_DR = (uint32_t)c;
}

/*=============================================================================
 * Send String
 *===========================================================================*/

void UART_SendString(const char *str)
{
    while (*str != '\0')
    {
        UART_SendChar(*str);
        str++;
    }
}

/*=============================================================================
 * Read One Character
 *===========================================================================*/

char UART_ReadChar(void)
{
    /* Wait until RX FIFO contains data */

    while (UART0_FR & UART_FR_RXFE);

    return (char)(UART0_DR & 0xFF);
}