/*
 * Copyright (C) 2021 madokapeng
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_wii_nunchuck
 *
 * @{
 * @file
 * @brief       Default configuration
 *
 * @author      Peng liang <plian076@gmail.com>
 */

#ifndef WII_NUNCHUCK_PARAMS_H
#define WII_NUNCHUCK_PARAMS_H

#include "board.h"
#include "wii_nunchuck.h"
#include "wii_nunchuck_constants.h"
#include "saul_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Set default configuration parameters
 * @{
 */
#ifndef WII_NUNCHUCK_PARAM_I2C
#define WII_NUNCHUCK_PARAM_I2C      (I2C_DEV(0))
#endif

#ifndef WII_NUNCHUCK_PARAM_ADDR
#define WII_NUNCHUCK_PARAM_ADDR     (0x52)
#endif

#ifndef WII_NUNCHUCK_PARAMS
#define WII_NUNCHUCK_PARAMS         { .i2c    = WII_NUNCHUCK_PARAM_I2C, \
                                      .addr   = WII_NUNCHUCK_PARAM_ADDR }
#endif

#ifndef WII_NUNCHUCK_SAUL_INFO
#define WII_NUNCHUCK_SAUL_INFO      { .name = "nunchuck" }
#endif
/**@}*/

/**
 * @brief   Configuration struct
 */
static const wii_nunchuck_params_t wii_nunchuck_params[] =
{
    WII_NUNCHUCK_PARAMS
};

/**
 * @brief   Additional meta information to keep in the SAUL registry
 */
static const saul_reg_info_t wii_nunchuck_saul_info[] =
{
    WII_NUNCHUCK_SAUL_INFO
};

#ifdef __cplusplus
}
#endif

#endif /* WII_NUNCHUCK_PARAMS_H */
/** @} */
