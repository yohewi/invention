#include QMK_KEYBOARD_H


#define LGUI(kc) (QK_LGUI | (kc))
/*#define LCTL(kc) (QK_LCTL | (kc))*/
/*#define LGUI_P LGUI(KC_PPLS) */
/*#define KC_C_UND KC_LGUI(KC_MINS)          */

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  NUM = SAFE_RANGE,
  NUMOFF,
};
/*
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM NUMOFF[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM NUM[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, HSV_PURPLE}
);
// etc..
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
*/

enum layer_number {
    _NUM = 0,
    _NUMOFF,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_NUM] = LAYOUT(
	KC_B, KC_RBRC, RSFT(KC_O), KC_D,
	LGUI(KC_Z), KC_G, LGUI(RSFT(KC_Z)), KC_H,
	KC_E, KC_LBRC, KC_DOWN, LGUI(KC_S),
	LGUI(KC_D), KC_N, KC_I, KC_P),
[_NUMOFF] = LAYOUT(
    KC_HOME, KC_UP, KC_PGUP, _______,
    KC_LEFT, XXXXXXX, KC_RGHT, _______,
    KC_END, KC_DOWN, KC_PGDN, _______,
    KC_INS, KC_DEL, _______, _______),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code16(KC_PLUS);
        } else {
            tap_code16(LGUI(KC_MINS));
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_RGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
}