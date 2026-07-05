#ifndef REGISTER_H
#define REGISTER_H

/******************************************************************************
 * @file    register.h
 * @brief   Generic Register Access Macros
 *
 * This file provides generic macros for accessing memory-mapped peripheral
 * registers on the RP2040 microcontroller.
 *
 * These macros are hardware-independent and can be reused across all drivers.
 ******************************************************************************/

#include <stdint.h>

/*=============================================================================
 * Generic Register Access
 *===========================================================================*/

/* Read/Write 32-bit Register */
#define REG32(addr) (*(volatile uint32_t *)(addr))

/* Read/Write 16-bit Register */
#define REG16(addr) (*(volatile uint16_t *)(addr))

/* Read/Write 8-bit Register */
#define REG8(addr)  (*(volatile uint8_t *)(addr))

/*=============================================================================
 * Bit Manipulation Macros
 *===========================================================================*/

/* Set a bit */
#define SET_BIT(REG, BIT)        ((REG) |= (1U << (BIT)))

/* Clear a bit */
#define CLEAR_BIT(REG, BIT)      ((REG) &= ~(1U << (BIT)))

/* Toggle a bit */
#define TOGGLE_BIT(REG, BIT)     ((REG) ^= (1U << (BIT)))

/* Read a bit */
#define READ_BIT(REG, BIT)       (((REG) >> (BIT)) & 0x1U)

/* Write a bit */
#define WRITE_BIT(REG, BIT, VAL) \
    ((VAL) ? SET_BIT(REG, BIT) : CLEAR_BIT(REG, BIT))

#endif /* REGISTER_H */