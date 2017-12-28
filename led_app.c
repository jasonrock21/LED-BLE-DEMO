/***********************************************************************************************//**
 * \file   led_app.c
 * \brief  Led Example application
 *
 * This example demonstrates the bare minimum needed to initialize and control
 * the LEDs on a BRD4153 radio board mounted on a WSTK
 ***************************************************************************************************
 * This file is for demonstration purposes only, not meant for production or
 * commercial use.  Use this code at your own risk.
 **************************************************************************************************/

/* Board headers */
#include "init_mcu.h"
#include "init_board.h"
#include "init_app.h"
#include "ble-configuration.h"
#include "board_features.h"

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
#include "gatt_db.h"

/* Libraries containing default Gecko configuration values */
#include "em_emu.h"
#include "em_cmu.h"

/* Device initialization header */
#include "hal-config.h"

#if defined(HAL_CONFIG)
#include "bsphalconfig.h"
#else
#include "bspconfig.h"
#endif


void initLEDs(void) {
  // configure as output, initial state low
  GPIO_PinModeSet(gpioPortF, 4, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortF, 5, gpioModePushPull, 0);
}

/* LED control function
    bit 0 = LED0 -- PF4
    bit 1 = LED1 -- PF5  */
void LED_control(uint8_t ledRegister) {

  /* LED 0 control */
  if ((ledRegister & 0x01) == 1)
    GPIO_PinOutSet(gpioPortF, 4);
  else
    GPIO_PinOutClear(gpioPortF, 4);

  /* LED 1 control */
  if (((ledRegister >> 1) & 0x01) == 1)
    GPIO_PinOutSet(gpioPortF, 5);
  else
    GPIO_PinOutClear(gpioPortF, 5);

}

/* Return status of the LED pins */
uint8_t LED_status(void) {

  return ((GPIO_PinOutGet(gpioPortF, 5) << 1) | GPIO_PinOutGet(gpioPortF, 4));

}
