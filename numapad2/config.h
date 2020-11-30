/*
Copyright 2019 yohei <yohewi@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6062
#define DEVICE_VER      0x0001
#define MANUFACTURER    yohewi
#define PRODUCT         NumApad2

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 8

// wiring of each half
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { B4, B5, B6, B2 }
/*#define DIRECT_PINS { { B3, B1 } }*/


/* COL2ROW or ROW2COL */
/*#define DIODE_DIRECTION ROW2COL*/
#define DIODE_DIRECTION COL2ROW


//#define NUMBER_OF_ENCODERS 2
#define ENCODERS_PAD_A { F7, F5 }
#define ENCODERS_PAD_B { F6, F4 }
#define ENCODER_RESOLUTION 3


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define RGB_DI_PIN D3

// keyboard RGB LED support
//#define RGBLIGHT_ANIMATIONS : see ./rules.mk: LED_ANIMATIONS = yes or no
//    see ./rules.mk: LED_BACK_ENABLE or LED_UNDERGLOW_ENABLE set yes
#define RGBLED_NUM 2

#define RGBLIGHT_LIMIT_VAL 200
#define RGBLIGHT_VAL_STEP 17

#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17

#define RGBLIGHT_LAYERS

#if defined(RGBLIGHT_ENABLE)
// USB_MAX_POWER_CONSUMPTION value for stonehenge30 keyboard
//  120  RGBoff, OLEDoff
//  120  OLED
//  330  RGB 6
//  300  RGB 32
//  310  OLED & RGB 32
  #define USB_MAX_POWER_CONSUMPTION 400
#else
  // fix iPhone and iPad power adapter issue
  // iOS device need lessthan 100
  #define USB_MAX_POWER_CONSUMPTION 100
#endif