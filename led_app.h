/***********************************************************************************************//**
 * \file   led_app.h
 * \brief  Functions and data related to LED application
 ***************************************************************************************************
 * This file is for demonstration purposes only, not meant for production or
 * commercial use.  Use this code at your own risk.
 **************************************************************************************************/
#include <stdint.h>

void initLEDs(void);

void LED_control(uint8_t ledRegister);

uint8_t LED_status(void);
