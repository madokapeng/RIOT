/*
 * Copyright (C) 2021 madokapeng
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    drivers_wii_nunchuck Wii Nunchuck Controller
 * @ingroup     drivers_sensors
 * @brief       A Wii game controller has a 3-axis accelerometer, a X-Y joystick, and two buttons. All features are available through I2C interface
 *
 * @{
 *
 * @file
 *
 * @author      Peng liang <plian076@gmail.com>
 */

#ifndef WII_NUNCHUCK_H
#define WII_NUNCHUCK_H

/* Add header includes here */

#ifdef __cplusplus
extern "C" {
#endif

#include "periph/i2c.h"

/**
 * @brief Nunchuck read buffer size
 */
#define WII_NUNCHUCK_BUF_SIZE  (6)

/**
 * @brief   Named return values
 */
enum {
    WII_NUNCHUCK_OK          =  0,       /**< everything was fine */
    WII_NUNCHUCK_I2CERR      = -1,       /**< I2C communication failed */
    WII_NUNCHUCK_NODEV       = -2        /**< no device found on the bus */
};

/* Declare the API of the driver */

/**
 * @brief   Device initialization parameters
 */
typedef struct {
    i2c_t i2c;                                /**< i2c device */
    uint8_t addr;                             /**< i2c address */
} wii_nunchuck_params_t;

/**
 * @brief   Device descriptor for the driver
 */
typedef struct {
    wii_nunchuck_params_t params;
    uint8_t raw_data[WII_NUNCHUCK_BUF_SIZE];
    uint8_t joystick_x;
    uint8_t joystick_y;
    uint16_t accel_x;
    uint16_t accel_y;
    uint16_t accel_z;
    uint8_t c_btn: 1;
    uint8_t z_btn: 1;
} wii_nunchuck_t;

/**
 * @brief   Initialize the given device
 *
 * @param[inout] dev        Device descriptor of the driver
 * @param[in]    params     Initialization parameters
 *
 * @return                  0 on success
 */
int wii_nunchuck_init(wii_nunchuck_t *dev, const wii_nunchuck_params_t *params);

/**
 * @brief   collect data from device
 *
 * @param[inout] dev        Device descriptor of the driver
 *
 * @return                  0 on success
 */
int wii_nunchuck_collect_data(wii_nunchuck_t *dev);



#ifdef __cplusplus
}
#endif

#endif /* WII_NUNCHUCK_H */
/** @} */
