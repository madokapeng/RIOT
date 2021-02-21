/*
 * Copyright (C) 2021 madokapeng
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     tests
 * @{
 *
 * @file
 * @brief       test wii nunchuck device driver
 *
 * @author      Peng Liang <plian076@gmail.com>
 *
 * @}
 */

#include <stdio.h>
#include <string.h>

#include "wii_nunchuck.h"
#include "wii_nunchuck_params.h"
#include "xtimer.h"
#include "timex.h"
#include "periph/i2c.h"

#define SLEEP_USEC  (1000 * US_PER_MS)

static wii_nunchuck_t dev;

int main(void)
{
    int ret = 0;
    puts("Generated RIOT application: 'wii_nunchuck_test'");
    printf("Initializing wii nunchuck at I2C_DEV(%i)... ", wii_nunchuck_params->i2c);

    if (wii_nunchuck_init(&dev, wii_nunchuck_params)) {
        puts("[Init failed]");
        return -1;
    }

    while (1) {
        ret = wii_nunchuck_collect_data(&dev);
        if (ret) {
            printf("No data available yet. error(%d)\n", ret);
        }

        printf("joystick_x: 0x%x\n", dev.joystick_x);
        printf("joystick_y: 0x%x\n", dev.joystick_y);
        printf("acceleometer_x: 0x%x\n", dev.accel_x);
        printf("acceleometer_y: 0x%x\n", dev.accel_y);
        printf("acceleometer_z: 0x%x\n", dev.accel_z);
        printf("button C status: %s\n", dev.c_btn ? "released" : "pressed");
        printf("button Z status: %s\n", dev.z_btn ? "released" : "pressed");

        puts("");
        xtimer_usleep(SLEEP_USEC);
    }


    return 0;
}
