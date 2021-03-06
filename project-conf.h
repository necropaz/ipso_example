/*
 * Copyright (c) 2015, Yanzi Networks AB.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *    3. Neither the name of the copyright holder nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

#define LWM2M_SERVER_ADDRESS "coap://[2001:0db8:0001:ffff::0527:53CE]"

//#define TSCH_CONF_JOIN_HOPPING_SEQUENCE         (uint8_t[]){ 20 }

//#define LOG_CONF_LEVEL_RPL                       LOG_LEVEL_DBG
#define LOG_CONF_LEVEL_MAC                       LOG_LEVEL_DBG
#define LOG_CONF_LEVEL_COAP                       LOG_LEVEL_NONE
#define LOG_CONF_LEVEL_LWM2M                       LOG_LEVEL_DBG

/* No sleep on CC2538 to enable full 32 KiB RAM */
#define LPM_CONF_ENABLE 0

#ifdef BOARD_STRING
#define LWM2M_DEVICE_MODEL_NUMBER BOARD_STRING
#elif defined(CONTIKI_TARGET_WISMOTE)
#include "dev/watchdog.h"
#define LWM2M_DEVICE_MODEL_NUMBER "LWM2M_DEVICE_MODEL_NUMBER"
#define LWM2M_DEVICE_MANUFACTURER "LWM2M_DEVICE_MANUFACTURER"
#define LWM2M_DEVICE_SERIAL_NO    "LWM2M_DEVICE_SERIAL_NO"
#define PLATFORM_REBOOT watchdog_reboot
#endif

#if BOARD_SENSORTAG
/* Real sensor is present... */
#else
#define IPSO_TEMPERATURE example_ipso_temperature
#endif /* BOARD_SENSORTAG */

/* Increase rpl-border-router IP-buffer when using more than 64. */
#define COAP_MAX_CHUNK_SIZE            64

/* Multiplies with chunk size, be aware of memory constraints. */
#define COAP_MAX_OPEN_TRANSACTIONS     4

/* Filtering .well-known/core per query can be disabled to save space. */
#define COAP_LINK_FORMAT_FILTERING     0
#define COAP_PROXY_OPTION_PROCESSING   0

/* Enable client-side support for COAP observe */
#define COAP_OBSERVE_CLIENT 1

#endif /* PROJECT_CONF_H_ */
