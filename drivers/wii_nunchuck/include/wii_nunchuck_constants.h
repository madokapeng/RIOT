/*
 * Copyright (C) 2021 madokapeng
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_wii_nunchuck
 * @{
 *
 * @file
 * @brief       Internal addresses, registers and constants
 *
 * @author      Peng liang <plian076@gmail.com>
 */

#ifndef WII_NUNCHUCK_CONSTANTS_H
#define WII_NUNCHUCK_CONSTANTS_H


#ifdef __cplusplus
extern "C" {
#endif

/* define here the addresses, register and constants of the driver */

/**
 * @name    WII_NUNCHUCK registers
 * @{
 */
#define WII_NUNCHUCK_REG1_INIT          (0xF0) /**< initialization reg 1 */
#define WII_NUNCHUCK_REG1_CMD           (0x55)
#define WII_NUNCHUCK_REG2_INIT          (0xFB) /**< initialization reg 2 */
#define WII_NUNCHUCK_REG2_CMD           (0x00)
#define WII_NUNCHUCK_REG_DATA           (0x00) /**< data reg */

/**
 * @name    WII_NUNCHUCK data decoding
 * @{
 */
#define DECODE_FACTOR                   (0x17)
#define BIT_0                           (1)
#define BIT_1                           (1 << 1)
#define BIT_6_7                         (3 << 6)
#define BIT_4_5                         (3 << 4)
#define BIT_2_3                         (3 << 2)
#define WII_NUNCHUCK_DECODE(X)          (((X) ^ (DECODE_FACTOR)) + (DECODE_FACTOR))
#define WII_NUNCHUCK_ACCEL_X(X,Y)       ((((uint16_t)(X)) * 4) | (uint16_t)((BIT_2_3 & Y) >> 2))
#define WII_NUNCHUCK_ACCEL_Y(X,Y)       ((((uint16_t)(X)) * 4) | (uint16_t)((BIT_4_5 & Y) >> 4))
#define WII_NUNCHUCK_ACCEL_Z(X,Y)       ((((uint16_t)(X)) * 4) | (uint16_t)((BIT_6_7 & Y) >> 6))
#define WII_NUNCHUCK_BUTTON_C(X)        (((X) & (BIT_1)) >> 1)
#define WII_NUNCHUCK_BUTTON_Z(X)        ((X) & (BIT_0))


#ifdef __cplusplus
}
#endif

#endif /* WII_NUNCHUCK_CONSTANTS_H */
/** @} */
