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
#define SE_AE SE_ADIA
#define SE_OE SE_OSLH
#define MS_ACCEL0 KC_MS_ACCEL0
#define MS_ACCEL1 KC_MS_ACCEL1
#define MS_ACCEL2 KC_MS_ACCEL2
#define MS_ACCELP KC_MS_ACCELP
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RIGHT KC_MS_RIGHT
#define MS_UP KC_MS_UP
#define MSW_DOWN KC_MS_WH_DOWN
#define MSW_LEFT KC_MS_WH_LEFT
#define MSW_RIGHT KC_MS_WH_RIGHT
#define MSW_UP KC_MS_WH_UP

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ALTTAB,
  CONND,
  CONNDBC,
  CONNLC,
  CONNLCBC,
  CYGWIN,
  EXITVNCV,
  LEDBRIGHT,
  LOCKDESK,
  LOCKKBD,
  UNLOCKKBD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    SE_SECT,   KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_F1,                               KC_F2,     KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      SE_PLUS,   //
    KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_F3,                               KC_F4,     KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      SE_AA,     //
    KC_F5,     KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                                      KC_H,      KC_J,      KC_K,      KC_L,      SE_OE,     SE_AE,     //
    SE_LESS,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_F6,                               KC_F7,     KC_N,      KC_M,      KC_COMMA,  KC_DOT,    SE_MINS,   KC_RSHIFT, //
    KC_F9,     KC_F10,    KC_F11,    KC_F12,    MO(1),                                                                           KC_F13,    KC_F14,    KC_F15,    KC_F16,    LOCKDESK,  //
                                                                      KC_F17,    KC_F18,        KC_F19,    KC_F20,                                                                      //
                                                                                 KC_F21,        KC_F22,                                                                                 //
                                                           KC_BSPACE, KC_DELETE, KC_F23,        KC_F24,    KC_ENTER,  KC_SPACE                                                          //
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_ESC,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                             XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   LEDBRIGHT, XXXXXXX,   RESET,     //
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                             XXXXXXX,   XXXXXXX,   XXXXXXX,   MS_UP,     XXXXXXX,   MS_BTN2,   XXXXXXX,   //
    XXXXXXX,   MS_ACCEL2, MS_ACCEL1, MS_ACCEL0, MS_ACCELP, XXXXXXX,                                                   MSW_UP,    MS_LEFT,   MS_DOWN,   MS_RIGHT,  MS_BTN1,   XXXXXXX,   //
    XXXXXXX,   CONNLC,    CONNLCBC,  CONND,     CONNDBC,   CYGWIN,    XXXXXXX,                             XXXXXXX,   MSW_DOWN,  MSW_LEFT,  XXXXXXX,   MSW_RIGHT, MS_BTN3,   XXXXXXX,   //
    KC_LSUPER, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                         LOCKKBD,   UNLOCKKBD, XXXXXXX,   XXXXXXX,   XXXXXXX,   //
                                                                      XXXXXXX,   XXXXXXX,       XXXXXXX,   XXXXXXX,                                                                     //
                                                                                 XXXXXXX,       OSM_LALT,                                                                               //
                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,       OSM_LCTL,  EXITVNCV,  ALTTAB                                                            //
  ),
};

static bool is_layer1_and_altdown = false;
static bool is_locked = false;
static uint8_t led_brightness = 0x10;

void update_led_brightness(void) {
  ergodox_led_all_set(led_brightness-1);
}

void ensure_layer1_alt_up(void) {
  if(is_layer1_and_altdown) {
    SEND_STRING(SS_UP(X_LALT) SS_DELAY(100));
    is_layer1_and_altdown = false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == UNLOCKKBD) {
    is_locked = false;
    ergodox_right_led_1_off();
    return true;
  }
  if(is_locked && keycode != MO(1) && keycode != LOCKKBD && keycode != LOCKDESK) {
    return false;
  }
  if(keycode == LOCKKBD) {
    is_locked = true;
    ergodox_right_led_1_on();
    return false;
  }
  if (record->event.pressed) {
    switch (keycode) {
    case ALTTAB:
      if(!is_layer1_and_altdown) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(100)); // The corresponding key-up event for left alt is in ensure_layer1_alt_up()
        is_layer1_and_altdown = true;
      }
      SEND_STRING(SS_TAP(X_TAB));
      break;
    case CONND:
      ergodox_right_led_2_on();
      ensure_layer1_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case CONNDBC:
      ergodox_right_led_2_on();
      ensure_layer1_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_D) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case CONNLC:
      ergodox_right_led_2_on();
      ensure_layer1_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_L) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case CONNLCBC:
      ergodox_right_led_2_on();
      ensure_layer1_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_N) SS_DELAY(100) SS_TAP(X_L) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case CYGWIN:
      ergodox_right_led_2_on();
      ensure_layer1_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) SS_DELAY(100) SS_TAP(X_C) SS_DELAY(100) SS_TAP(X_Y) SS_DELAY(100) SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_ENTER));
      break;
    case EXITVNCV:
      ergodox_right_led_2_on();
      ensure_layer1_alt_up();
      SEND_STRING(SS_TAP(X_F8) SS_DELAY(100) SS_TAP(X_C));
      break;
    case LEDBRIGHT:
      if(led_brightness) {
        led_brightness <<= 2;
      } else {
        led_brightness = 1;
      }
      update_led_brightness();
      break;
    case LOCKDESK:
      ergodox_right_led_2_on();
      ensure_layer1_alt_up();
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
  if(layer != 1) {
    ensure_layer1_alt_up();
  }
  return state;
};

void keyboard_post_init_user(void) {
  update_led_brightness();
};
