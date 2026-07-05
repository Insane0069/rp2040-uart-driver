#ifndef RP2040_H
#define RP2040_H

/******************************************************************************
 * @file    rp2040.h
 * @brief   RP2040 Peripheral Register Definitions
 *
 * This header contains the RP2040 peripheral base addresses, register
 * definitions, register offsets, and hardware constants used by the firmware
 * drivers.
 *
 * This file is shared across all firmware drivers in this project.
 ******************************************************************************/

#include <stdint.h>
#include "register.h"

/*=============================================================================
 * Peripheral Base Addresses
 *===========================================================================*/

#define RESETS_BASE         0x4000C000U

#define IO_BANK0_BASE       0x40014000U

#define PADS_BANK0_BASE     0x4001C000U

#define SIO_BASE            0xD0000000U

#define UART0_BASE          0x40034000U

#define UART1_BASE          0x40038000U

/*=============================================================================
 * GPIO Constants
 *===========================================================================*/

#define GPIO_MAX_PIN        29U

#define GPIO_IS_VALID(pin)  ((pin) <= GPIO_MAX_PIN)

/*=============================================================================
 * GPIO Function Select
 *===========================================================================*/

#define GPIO_FUNC_XIP       0U

#define GPIO_FUNC_SPI       1U

#define GPIO_FUNC_UART      2U

#define GPIO_FUNC_I2C       3U

#define GPIO_FUNC_PWM       4U

#define GPIO_FUNC_SIO       5U

#define GPIO_FUNC_PIO0      6U

#define GPIO_FUNC_PIO1      7U

#define GPIO_FUNC_GPCK      8U

#define GPIO_FUNC_USB       9U

#define GPIO_FUNC_NULL      31U

/*=============================================================================
 * Pad Register Bit Definitions
 *===========================================================================*/

#define PAD_SLEW_BIT        0U

#define PAD_SCHMITT_BIT     1U

#define PAD_PDE_BIT         2U

#define PAD_PUE_BIT         3U

#define PAD_DRIVE0_BIT      4U

#define PAD_DRIVE1_BIT      5U

#define PAD_IE_BIT          6U

#define PAD_OD_BIT          7U

/*=============================================================================
 * Register Stride
 *===========================================================================*/

#define GPIO_CTRL_STRIDE    8U

#define GPIO_PAD_STRIDE     4U

/*=============================================================================
 * SIO Register Offsets
 *===========================================================================*/

/* GPIO Input */

#define GPIO_IN_OFFSET         0x004U

/* GPIO Output */

#define GPIO_OUT_OFFSET        0x010U
#define GPIO_OUT_SET_OFFSET    0x014U
#define GPIO_OUT_CLR_OFFSET    0x018U
#define GPIO_OUT_XOR_OFFSET    0x01CU

/* GPIO Output Enable */

#define GPIO_OE_OFFSET         0x020U
#define GPIO_OE_SET_OFFSET     0x024U
#define GPIO_OE_CLR_OFFSET     0x028U
#define GPIO_OE_XOR_OFFSET     0x02CU

/*=============================================================================
 * SIO Registers
 *===========================================================================*/

/* GPIO Input Register */

#define SIO_GPIO_IN \
    REG32(SIO_BASE + GPIO_IN_OFFSET)

/* GPIO Output Registers */

#define SIO_GPIO_OUT \
    REG32(SIO_BASE + GPIO_OUT_OFFSET)

#define SIO_GPIO_OUT_SET \
    REG32(SIO_BASE + GPIO_OUT_SET_OFFSET)

#define SIO_GPIO_OUT_CLR \
    REG32(SIO_BASE + GPIO_OUT_CLR_OFFSET)

#define SIO_GPIO_OUT_XOR \
    REG32(SIO_BASE + GPIO_OUT_XOR_OFFSET)

/* GPIO Output Enable Registers */

#define SIO_GPIO_OE \
    REG32(SIO_BASE + GPIO_OE_OFFSET)

#define SIO_GPIO_OE_SET \
    REG32(SIO_BASE + GPIO_OE_SET_OFFSET)

#define SIO_GPIO_OE_CLR \
    REG32(SIO_BASE + GPIO_OE_CLR_OFFSET)

#define SIO_GPIO_OE_XOR \
    REG32(SIO_BASE + GPIO_OE_XOR_OFFSET)

/*=============================================================================
 * GPIO Control Register
 *
 * GPIO0_CTRL = IO_BANK0_BASE + 0x04
 * Each GPIO occupies 8 bytes.
 *===========================================================================*/

#define GPIO_CTRL(pin) \
    REG32(IO_BANK0_BASE + 0x04U + ((pin) * GPIO_CTRL_STRIDE))

/*=============================================================================
 * GPIO Pad Register
 *
 * GPIO0 = PADS_BANK0_BASE + 0x04
 * Each GPIO occupies 4 bytes.
 *===========================================================================*/

#define GPIO_PAD(pin) \
    REG32(PADS_BANK0_BASE + 0x04U + ((pin) * GPIO_PAD_STRIDE))


/*=============================================================================
 * UART Register Offsets
 *===========================================================================*/

/* Data Register */
#define UART_DR_OFFSET         0x000U

/* Receive Status/Error Clear Register */
#define UART_RSR_OFFSET        0x004U

/* Flag Register */
#define UART_FR_OFFSET         0x018U

/* Integer Baud Rate Divisor */
#define UART_IBRD_OFFSET       0x024U

/* Fractional Baud Rate Divisor */
#define UART_FBRD_OFFSET       0x028U

/* Line Control Register */
#define UART_LCR_H_OFFSET      0x02CU

/* Control Register */
#define UART_CR_OFFSET         0x030U

/* Interrupt FIFO Level Select */
#define UART_IFLS_OFFSET       0x034U

/* Interrupt Mask Set/Clear */
#define UART_IMSC_OFFSET       0x038U

/* Raw Interrupt Status */
#define UART_RIS_OFFSET        0x03CU

/* Masked Interrupt Status */
#define UART_MIS_OFFSET        0x040U

/* Interrupt Clear Register */
#define UART_ICR_OFFSET        0x044U

/* DMA Control Register */
#define UART_DMACR_OFFSET      0x048U

/*=============================================================================
 * UART0 Registers
 *===========================================================================*/

#define UART0_DR          REG32(UART0_BASE + UART_DR_OFFSET)

#define UART0_RSR         REG32(UART0_BASE + UART_RSR_OFFSET)

#define UART0_FR          REG32(UART0_BASE + UART_FR_OFFSET)

#define UART0_IBRD        REG32(UART0_BASE + UART_IBRD_OFFSET)

#define UART0_FBRD        REG32(UART0_BASE + UART_FBRD_OFFSET)

#define UART0_LCR_H       REG32(UART0_BASE + UART_LCR_H_OFFSET)

#define UART0_CR          REG32(UART0_BASE + UART_CR_OFFSET)

#define UART0_IFLS        REG32(UART0_BASE + UART_IFLS_OFFSET)

#define UART0_IMSC        REG32(UART0_BASE + UART_IMSC_OFFSET)

#define UART0_RIS         REG32(UART0_BASE + UART_RIS_OFFSET)

#define UART0_MIS         REG32(UART0_BASE + UART_MIS_OFFSET)

#define UART0_ICR         REG32(UART0_BASE + UART_ICR_OFFSET)

#define UART0_DMACR       REG32(UART0_BASE + UART_DMACR_OFFSET)

/*=============================================================================
 * UART Control Register Bits (UARTCR)
 *===========================================================================*/

#define UART_CR_UARTEN    (1U << 0)

#define UART_CR_TXE       (1U << 8)

#define UART_CR_RXE       (1U << 9)

/*=============================================================================
 * UART Flag Register Bits (UARTFR)
 *===========================================================================*/

#define UART_FR_CTS       (1U << 0)

#define UART_FR_BUSY      (1U << 3)

#define UART_FR_RXFE      (1U << 4)

#define UART_FR_TXFF      (1U << 5)

#define UART_FR_RXFF      (1U << 6)

#define UART_FR_TXFE      (1U << 7)

/*=============================================================================
 * UART Line Control Register Bits (UARTLCR_H)
 *===========================================================================*/

#define UART_LCR_H_BRK        (1U << 0)

#define UART_LCR_H_PEN        (1U << 1)

#define UART_LCR_H_EPS        (1U << 2)

#define UART_LCR_H_STP2       (1U << 3)

#define UART_LCR_H_FEN        (1U << 4)

#define UART_LCR_H_WLEN_5     (0U << 5)

#define UART_LCR_H_WLEN_6     (1U << 5)

#define UART_LCR_H_WLEN_7     (2U << 5)

#define UART_LCR_H_WLEN_8     (3U << 5)

#define UART_LCR_H_SPS        (1U << 7)

#endif /* RP2040_H */