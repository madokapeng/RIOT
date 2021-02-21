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
 * @brief       Device driver implementation for the Wii Nunchuck Controller
 *
 * @author      Peng liang <plian076@gmail.com>
 *
 * @}
 */

#include <string.h>
#include "periph/i2c.h"
#include "wii_nunchuck.h"
#include "wii_nunchuck_constants.h"
#include "wii_nunchuck_params.h"

#define ENABLE_DEBUG 1
#include "debug.h"

#define DEV         (dev->params.i2c)
#define ADDR        (dev->params.addr)

static int _read_raw(wii_nunchuck_t *dev)
{
    int res = WII_NUNCHUCK_OK;

    assert(dev);
    
    i2c_acquire(DEV);

    /* Read data reg */
    if (i2c_read_regs(DEV, ADDR, WII_NUNCHUCK_REG_DATA, dev->raw_data, WII_NUNCHUCK_BUF_SIZE, 0)) {
            DEBUG("[wii-nunchuck] Cannot read data from I2C.\n");
            res = WII_NUNCHUCK_I2CERR;
            goto release;
        }

release:
    i2c_release(DEV);
    return res;
}

static void _decode_raw(wii_nunchuck_t *dev)
{
    assert(dev);

    dev->joystick_x = dev->raw_data[0];
    dev->joystick_y = dev->raw_data[1];
    dev->accel_x = WII_NUNCHUCK_ACCEL_X(dev->raw_data[2], dev->raw_data[5]);
    dev->accel_y = WII_NUNCHUCK_ACCEL_Y(dev->raw_data[3], dev->raw_data[5]);
    dev->accel_z = WII_NUNCHUCK_ACCEL_Z(dev->raw_data[4], dev->raw_data[5]);
    dev->c_btn = WII_NUNCHUCK_BUTTON_C(dev->raw_data[5]);
    dev->z_btn = WII_NUNCHUCK_BUTTON_Z(dev->raw_data[5]);
}

int wii_nunchuck_init(wii_nunchuck_t *dev, const wii_nunchuck_params_t *params)
{
    int res = WII_NUNCHUCK_OK;

    assert(dev && params);
    dev->params = *params;

    i2c_acquire(DEV);

    /* write initialization command for reg 1 */
    if (i2c_write_reg(DEV, ADDR, WII_NUNCHUCK_REG1_INIT, WII_NUNCHUCK_REG1_CMD, 0)) {
        DEBUG("[wii-nunchuck] init - error: unable to init nunchuck\n");
        res = WII_NUNCHUCK_NODEV;
        goto release;
    }

    /* write initialization command for reg 2 */
    if (i2c_write_reg(DEV, ADDR, WII_NUNCHUCK_REG2_CMD, WII_NUNCHUCK_REG2_CMD, 0)) {
        DEBUG("[wii-nunchuck] init - error: unable to init nunchuck\n");
        res = WII_NUNCHUCK_I2CERR;
        goto release;
    }

release:
    i2c_release(DEV);
    return res;
}

int wii_nunchuck_collect_data(wii_nunchuck_t *dev)
{
    int res = WII_NUNCHUCK_OK;
    assert(dev);

    /* get raw data */
    if((res = _read_raw(dev))) {
        DEBUG("[wii-nunchuck] failed to collect data, error %d\n", res);
    }

    /* decode data */
    _decode_raw(dev);

    return res;
}
