#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"
#include "keymap_us_international.h"

#define SE_LESS SE_LABK
#define SE_AA SE_ARNG
#define SE_OSLH SE_ODIA
#define KC_LSUPER KC_LGUI
#define KC_RSUPER KC_RGUI
#define X_LSUPER X_LGUI
#define X_RSUPER X_RGUI
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ALTTAB_HOLD,
  KC_NOTHING,
  MACRO_CONND,
  MACRO_CONNDBC,
  MACRO_CONNLC,
  MACRO_CONNLCBC,
  MACRO_CYGWIN,
  MACRO_EXITVNCV,
  MACRO_LOCK,
  LOCKKBD,
  UNLOCKKBD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    SE_SECT,        KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_F1,                                          KC_F2,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           SE_PLUS,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_F3,                                          KC_F4,          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           SE_AA,
    KC_F5,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           SE_OSLH,        SE_ADIA,
    SE_LESS,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_F6,                                          KC_F7,          KC_N,           KC_M,           KC_COMMA,       KC_DOT,         SE_MINS,        KC_RSHIFT,
    KC_F9,          KC_F10,         KC_F11,         KC_F12,         MO(1),                                                                                                          KC_F13,         KC_F14,         KC_F15,         KC_F16,         MACRO_LOCK,
                                                                                                    KC_F17,         KC_F18,         KC_F19,         KC_F20,
                                                                                                                    KC_F21,         KC_F22,
                                                                                    KC_BSPACE,      KC_DELETE,      KC_F23,         KC_F24,         KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_ESC,         KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,                                     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     RESET,
    KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,                                     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_MS_UP,       KC_NOTHING,     KC_MS_BTN2,     KC_NOTHING,
    KC_NOTHING,     KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_MS_ACCELP,   KC_NOTHING,                                                                     KC_MS_WH_UP,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_BTN1,     KC_NOTHING,
    KC_NOTHING,     MACRO_CONNLC,   MACRO_CONNLCBC, MACRO_CONND,    MACRO_CONNDBC,  MACRO_CYGWIN,   KC_NOTHING,                                     KC_NOTHING,     KC_MS_WH_DOWN,  KC_MS_WH_LEFT,  KC_NOTHING,     KC_MS_WH_RIGHT, KC_MS_BTN3,     KC_NOTHING,
    KC_LSUPER,      KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,                                                                                                     LOCKKBD,        UNLOCKKBD,      KC_NOTHING,     KC_NOTHING,     KC_NOTHING,
                                                                                                    KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     KC_NOTHING,
                                                                                                                    KC_NOTHING,     OSM_LALT,
                                                                                    KC_NOTHING,     KC_NOTHING,     KC_NOTHING,     OSM_LCTL,       MACRO_EXITVNCV, ALTTAB_HOLD
  ),
};

static bool is_layer1_and_altdown = false;
static bool is_locked = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == UNLOCKKBD) {
    is_locked = false;
    ergodox_right_led_1_off();
    return true;
  }
  if(is_locked && keycode != MO(1) && keycode != LOCKKBD && keycode != MACRO_LOCK) {
    return false;
  }
  if(keycode == LOCKKBD) {
    is_locked = true;
    ergodox_right_led_1_on();
    return false;
  }
  if (keycode == KC_NOTHING) {
    return true;
  }
  if (record->event.pressed) {
    switch (keycode) {
    case ALTTAB_HOLD:
      if(!is_layer1_and_altdown) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(100)); // The corresponding key-up event for left alt is in layer_state_set_user()
        is_layer1_and_altdown = true;
      }
      SEND_STRING(SS_TAP(X_TAB));
      break;
    case MACRO_CONND:
      ergodox_right_led_2_on();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case MACRO_CONNDBC:
      ergodox_right_led_2_on();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case MACRO_CONNLC:
      ergodox_right_led_2_on();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_L) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case MACRO_CONNLCBC:
      ergodox_right_led_2_on();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_L) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case MACRO_CYGWIN:
      ergodox_right_led_2_on();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case MACRO_EXITVNCV:
      ergodox_right_led_2_on();
      SEND_STRING(SS_TAP(X_F8) SS_DELAY(100) SS_TAP(X_C));
      break;
    case MACRO_LOCK:
      ergodox_right_led_2_on();
      SEND_STRING(SS_DOWN(X_LSUPER) SS_DELAY(100) SS_TAP(X_L) SS_DELAY(100) SS_UP(X_LSUPER));
      break;
    }
    ergodox_right_led_2_off();
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (layer) {
    ergodox_right_led_3_on();
  }
  else {
    ergodox_right_led_3_off();
  }
  if(is_layer1_and_altdown && layer == 0) {
    SEND_STRING(SS_UP(X_LALT));
    is_layer1_and_altdown = false;
  }
  return state;
};
