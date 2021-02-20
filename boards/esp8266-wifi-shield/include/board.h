/*
 * Copyright (C) 2021 madokapeng
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_esp8266-wifi-shield
 * @{
 *
 * @file
 * @brief       Board specific definitions for the ESP8266 WiFi Shield Version 1.0 By WangTongze
 *
 * @author      Liang, Peng <plian076@gmail.com>
 */

#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    On-board LED configuration and control definitions
 * @{
 */
#define LED0_PIN    GPIO2    /**< GPIO2 is used as LED Pin */
#define LED0_ACTIVE (0)      /**< LED is low active */

#define LED1_PIN    GPIO12   /**< GPIO12 is used as LED Pin */
#define LED1_ACTIVE (1)      /**< LED is high active */

#define LED2_PIN    GPIO14   /**< GPIO14 is used as LED Pin */
#define LED2_ACTIVE (1)      /**< LED is high active */
/** @} */

#ifdef __cplusplus
} /* end extern "C" */
#endif

/* include common board definitions as last step */
#include "board_common.h"

#endif /* BOARD_H */
/** @} */
