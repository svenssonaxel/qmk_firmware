#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_swedish.h"
#include "keymap_us_international.h"
#include "mousekey.h"

#define DELAY SS_DELAY(20)

#define SE_LESS SE_LABK
#define SE_AA SE_ARNG
#define SE_OSLH SE_ODIA
#define KC_LSUPER KC_LGUI
#define KC_RSUPER KC_RGUI
#define MOD_LSUPER MOD_LGUI
#define MOD_RSUPER MOD_RGUI
#define X_LSUPER X_LGUI
#define X_RSUPER X_RGUI
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define SE_AE SE_ADIA
#define SE_OE SE_OSLH
#define MS_ACCEL0 KC_MS_ACCEL0
#define MS_ACCEL1 KC_MS_ACCEL1
#define MS_ACCEL2 KC_MS_ACCEL2
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
  SC1,
  SC2,
  SC3,
  SC4,
  SC5,
  EXITVNCV,
  LEDBRIGHT,
  LOCKDESK,
  LOCKKBD,
  MK_CSTM_0,
  MK_CSTM_1,
  MK_CSTM_2,
  MK_CSTM_3,
  UNLOCKKBD,
  DOWN10,
  ENTERUPEND,
  LEFT10,
  RIGHT10,
  SFTEND_BSP,
  SFTHM_BSP,
  SP_LEFT,
  UP10,
};

#define FN_LAYER 5
#define MO_FN MO(FN_LAYER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty( // Remote mode: Base
    LOCKDESK,  LOCKKBD,   KC_2,      KC_3,      KC_4,      KC_5,      KC_F1,                               KC_F2,     KC_6,      KC_7,      KC_8,      KC_9,      LOCKKBD,   LOCKDESK,  //
    SE_SECT,   KC_1,      KC_W,      KC_E,      KC_R,      KC_T,      KC_F3,                               KC_F4,     KC_Y,      KC_U,      KC_I,      KC_O,      KC_0,      SE_PLUS,   //
    KC_TAB,    KC_Q,      KC_S,      KC_D,      KC_F,      KC_G,                                                      KC_H,      KC_J,      KC_K,      KC_L,      KC_P,      SE_AA,     //
    KC_F5,     KC_A,      KC_X,      KC_C,      KC_V,      KC_B,      KC_F6,                               TO(1),     KC_N,      KC_M,      KC_COMMA,  KC_DOT,    SE_OE,     SE_AE,     //
    SE_LESS,   KC_Z,      KC_F11,    KC_F12,    MO_FN,                                                                           KC_F13,    KC_F14,    KC_F15,    SE_MINS,   KC_RSFT,   //
                                                                      KC_F17,    KC_F18,        KC_F19,    KC_F20,                                                                      //
                                                                                 KC_F21,        KC_F22,                                                                                 //
                                                           KC_BSPC,   KC_DELETE, KC_F23,        KC_F24,    KC_ENTER,  KC_SPACE                                                          //
  ),
  [1] = LAYOUT_ergodox_pretty( // Local mode: Base
#define LM_F     LT(3, KC_F)
#define LM_J     LT(3, KC_J)
#define LM_D     LT(2, KC_D)
#define LM_K     LT(2, KC_K)
#define LM_C     LT(4, KC_C)
#define LM_COMMA LT(4, KC_COMMA)
#define LM_S     MT(MOD_LALT, KC_S)
#define LM_L     MT(MOD_RALT, KC_L)
#define LM_A     MT(MOD_LCTL, KC_A)
#define LM_OE    MT(MOD_RCTL, SE_OE)
#define LM_Z     MT(MOD_LSFT, KC_Z)
#define LM_MINS  MT(MOD_RSFT, SE_MINS)
#define LM_TAB   MT(MOD_LSUPER, KC_TAB)
#define LM_AA    MT(MOD_RSUPER, SE_AA)
    LOCKDESK,  LOCKKBD,   KC_2,      KC_3,      KC_4,      KC_5,      XXXXXXX,                             XXXXXXX,   KC_6,      KC_7,      KC_8,      KC_9,      LOCKKBD,   LOCKDESK,  //
    SE_SECT,   KC_1,      KC_W,      KC_E,      KC_R,      KC_T,      XXXXXXX,                             XXXXXXX,   KC_Y,      KC_U,      KC_I,      KC_O,      KC_0,      SE_PLUS,   //
    LM_TAB,    KC_Q,      LM_S,      LM_D,      LM_F,      KC_G,                                                      KC_H,      LM_J,      LM_K,      LM_L,      KC_P,      LM_AA,     //
    XXXXXXX,   LM_A,      KC_X,      LM_C,      KC_V,      KC_B,      XXXXXXX,                             TO(0),     KC_N,      KC_M,      LM_COMMA,  KC_DOT,    LM_OE,     SE_AE,     //
    SE_LESS,   LM_Z,      XXXXXXX,   XXXXXXX,   MO_FN,                                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,   LM_MINS,   KC_RSFT,   //
                                                                      XXXXXXX,   XXXXXXX,       XXXXXXX,   XXXXXXX,                                                                     //
                                                                                 XXXXXXX,       OSM_LALT,                                                                               //
                                                           KC_BSPC,   KC_DELETE, XXXXXXX,       OSM_LCTL,  KC_ENTER,  KC_SPACE                                                          //
  ),
  [2] = LAYOUT_ergodox_pretty( // Local mode: Navigation
#define ____ KC_TRANSPARENT
#define CTLSFT_TAB LCTL(S(KC_TAB))
#define CTL_TAB    LCTL(KC_TAB)
#define ALT_F4     LALT(KC_F4)
#define CTL_PGUP   LCTL(KC_PGUP)
#define CTL_PGDN   LCTL(KC_PGDN)
#define ALT_HOME   LALT(KC_HOME)
#define ALT_LEFT   LALT(KC_LEFT)
#define ALT_RIGHT  LALT(KC_RIGHT)
#define SFT_TAB    S(KC_TAB)
#define CTL_ENTER  LCTL(KC_ENTER)
    ____,      ____,      ____,      CTLSFT_TAB,CTL_TAB,   ____,      ____,                                ____,      ____,      ____,      UP10,      ____,      ____,      ____,      //
    ____,      ____,      ALT_F4,    CTL_PGUP,  CTL_PGDN,  ALT_HOME,  ____,                                ____,      ____,      KC_HOME,   KC_UP,     KC_END,    ____,      ____,      //
    ____,      KC_ESC,    ALT_RIGHT, SFT_TAB,   KC_TAB,    CTL_ENTER,                                                 ____,      KC_LEFT,   KC_DOWN,   KC_RIGHT,  KC_BSPC,   KC_DEL,    //
    KC_CAPS,   ALT_LEFT,  ____,      ____,      ____,      ____,      ____,                                ____,      KC_INS,    LEFT10,    DOWN10,    RIGHT10,   KC_ENTER,  ENTERUPEND,//
    ____,      ____,      ____,      ____,      ____,                                                                            SP_LEFT,   ____,      ____,      SFTHM_BSP, SFTEND_BSP,//
                                                                      ____,      ____,          ____,      ____,                                                                        //
                                                                                 ____,          ____,                                                                                   //
                                                           ____,      ____,      ____,          ____,      ____,      ____                                                              //
  ),
  [3] = LAYOUT_ergodox_pretty( // Local mode: Symbols
    ____,      ____,      ____,      ____,      SE_CURR,   ____,      ____,                                ____,      ____,      ____,      ____,      ____,      ____,      ____,      //
    ____,      ____,      SE_UNDS,   SE_LBRC,   SE_RBRC,   SE_CIRC,   ____,                                ____,      SE_EXLM,   SE_LABK,   SE_RABK,   SE_EQL,    ____,      ____,      //
    ____,      ____,      SE_SLSH,   SE_LCBR,   SE_RCBR,   SE_ASTR,                                                   SE_QUES,   SE_LPRN,   SE_RPRN,   SE_MINS,   SE_AMPR,   ____,      //
    ____,      SE_BSLS,   SE_DLR,    SE_PIPE,   SE_TILD,   SE_GRV,    ____,                                ____,      SE_PLUS,   SE_PERC,   SE_DQUO,   SE_QUOT,   SE_COLN,   SE_AT,     //
    ____,      SE_HASH,   ____,      ____,      ____,                                                                            ____,      ____,      ____,      SE_SCLN,   ____,      //
                                                                      ____,      ____,          ____,      ____,                                                                        //
                                                                                 ____,          ____,                                                                                   //
                                                           ____,      ____,      ____,          ____,      ____,      ____                                                              //
  ),
  [4] = LAYOUT_ergodox_pretty( // Local mode: Numpad
    ____,      ____,      KC_F12,    KC_F11,    KC_F10,    ____,      ____,                                ____,      KC_E,      KC_A,      KC_B,      KC_C,      ____,      ____,      //
    ____,      KC_F12,    KC_F9,     KC_F8,     KC_F7,     ____,      ____,                                ____,      SE_SLSH,   KC_7,      KC_8,      KC_9,      KC_D,      KC_F,      //
    ____,      KC_F11,    KC_F6,     KC_F5,     KC_F4,     ____,                                                      SE_ASTR,   KC_4,      KC_5,      KC_6,      KC_BSPC,   KC_COMMA,  //
    ____,      KC_F10,    KC_F3,     KC_F2,     KC_F1,     ____,      ____,                                ____,      SE_PLUS,   KC_1,      KC_2,      KC_3,      KC_ENTER,  KC_DOT,    //
    ____,      ____,      SE_LPRN,   SE_RPRN,   ____,                                                                            KC_0,      SE_LBRC,   SE_RBRC,   KC_MINS,   SE_COLN,   //
                                                                      ____,      ____,          ____,      ____,                                                                        //
                                                                                 ____,          ____,                                                                                   //
                                                           ____,      ____,      ____,          ____,      ____,      ____                                                              //
  ),
  [FN_LAYER] = LAYOUT_ergodox_pretty( // Fn Layer
    LOCKDESK,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                             XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   LEDBRIGHT, QK_BOOT,   LOCKDESK,  //
    KC_ESC,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                             XXXXXXX,   XXXXXXX,   XXXXXXX,   MS_UP,     XXXXXXX,   XXXXXXX,   XXXXXXX,   //
    XXXXXXX,   XXXXXXX,   MK_CSTM_2, MK_CSTM_1, MK_CSTM_0, XXXXXXX,                                                   MSW_UP,    MS_LEFT,   MS_DOWN,   MS_RIGHT,  MS_BTN2,   XXXXXXX,   //
    XXXXXXX,   MK_CSTM_3, SC2,       SC3,       SC4,       SC5,       XXXXXXX,                             XXXXXXX,   MSW_DOWN,  MSW_LEFT,  XXXXXXX,   MSW_RIGHT, MS_BTN1,   XXXXXXX,   //
    KC_LSUPER, SC1,       XXXXXXX,   XXXXXXX,   XXXXXXX,                                                                         LOCKKBD,   UNLOCKKBD, XXXXXXX,   MS_BTN3,   XXXXXXX,   //
                                                                      XXXXXXX,   XXXXXXX,       XXXXXXX,   XXXXXXX,                                                                     //
                                                                                 XXXXXXX,       OSM_LALT,                                                                               //
                                                           XXXXXXX,   XXXXXXX,   XXXXXXX,       OSM_LCTL,  EXITVNCV,  ALTTAB                                                            //
  ),
};

_Static_assert((KC_F | KC_J | KC_D | KC_K | KC_C | KC_COMMA | KC_S | KC_L | KC_A | SE_OE | KC_Z | SE_MINS | KC_TAB | SE_AA) < 0x100, "LT and MT can only take 8-bit key codes.");

static bool is_fnlayer_and_altdown = false;
static bool is_locked = false;
static uint8_t led_brightness = 0x10;
static uint8_t mk_cstm_down = 0;

void update_led_brightness(void) {
  ergodox_led_all_set(led_brightness-1);
}

void update_mousekey_speeds(void) {
  if(is_locked) {
    return;
  }
  static const uint8_t idx_lookup[16] = {
      [0x5] =  1, // -S-F
      [0xd] =  2, // AS-F
      [0x9] =  3, // A--F
      [0x1] =  4, // ---F
      [0x3] =  5, // --DF
      [0x2] =  6, // --D-
      [0x7] =  6, // -SDF
      [0x0] =  6, // ----
      [0x6] =  7, // -SD-
      [0xf] =  7, // ASDF
      [0x4] =  8, // -S--
      [0xe] =  8, // ASD-
      [0xc] =  9, // AS--
      [0x8] = 10, // A---
      // Unused
      [0xa] =  0, // A-D-
      [0xb] =  0, // A-DF
      };
  uint8_t idx = idx_lookup[mk_cstm_down];
  // Factor 10^(1/4) except for move_speeds with idx < 4.
  // idx value:                              0    1    2    3     4     5     6     7      8      9     10
  static const uint16_t move_speeds[11] =  { 0,   1,  10, 100, 1000, 1778, 3162, 5623, 10000, 17783, 31623};
  static const uint16_t wheel_speeds[11] = { 0, 178, 316, 562, 1000, 1778, 3162, 5623, 10000, 17783, 31623};
  mousekey_set_speeds(move_speeds[idx], wheel_speeds[idx]);
}

void ensure_fnlayer_alt_up(void) {
  if(is_fnlayer_and_altdown) {
    SEND_STRING(SS_UP(X_LALT) DELAY);
    is_fnlayer_and_altdown = false;
  }
}

_Static_assert(sizeof(bool) == 1, "");
bool eeprom_read_bool(const bool *addr) {
    bool ret = 0;
    eeprom_read_block(&ret, addr, 1);
    return ret;
}
void eeprom_write_bool(bool *addr, bool value) { eeprom_write_block(&value, addr, 1); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == UNLOCKKBD) {
    is_locked = false;
    eeprom_write_bool(EECONFIG_LOCKED, is_locked);
    ergodox_right_led_1_off();
    return true;
  }
  if(is_locked && keycode != MO_FN && keycode != LOCKKBD && keycode != LOCKDESK) {
    return false;
  }
  if(keycode == LOCKKBD) {
    is_locked = true;
    mousekey_clear();
    eeprom_write_bool(EECONFIG_LOCKED, is_locked);
    ergodox_right_led_1_on();
    return false;
  }
  if (record->event.pressed) {
    switch (keycode) {
    case DOWN10:
      SEND_STRING(SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN) DELAY SS_TAP(X_DOWN));
      break;
    case ENTERUPEND:
      SEND_STRING(SS_TAP(X_ENTER) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_END));
      break;
    case LEFT10:
      SEND_STRING(SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT) DELAY SS_TAP(X_LEFT));
      break;
    case RIGHT10:
      SEND_STRING(SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT) DELAY SS_TAP(X_RIGHT));
      break;
    case SFTEND_BSP:
      SEND_STRING(SS_DOWN(X_LSFT) DELAY SS_TAP(X_END) DELAY SS_UP(X_LSFT) DELAY SS_TAP(X_BSPC));
      break;
    case SFTHM_BSP:
      SEND_STRING(SS_DOWN(X_LSFT) DELAY SS_TAP(X_HOME) DELAY SS_UP(X_LSFT) DELAY SS_TAP(X_BSPC));
      break;
    case SP_LEFT:
      SEND_STRING(SS_TAP(X_SPACE) DELAY SS_TAP(X_LEFT));
      break;
    case UP10:
      SEND_STRING(SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP) DELAY SS_TAP(X_UP));
      break;
    case ALTTAB:
      if(!is_fnlayer_and_altdown) {
        SEND_STRING(SS_DOWN(X_LALT) DELAY); // The corresponding key-up event for left alt is in ensure_fnlayer_alt_up()
        is_fnlayer_and_altdown = true;
      }
      SEND_STRING(SS_TAP(X_TAB));
      break;
    case SC1:
      ensure_fnlayer_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) DELAY SS_TAP(X_S) DELAY SS_TAP(X_C) DELAY SS_TAP(X_1) DELAY SS_TAP(X_ENTER));
      break;
    case SC2:
      ensure_fnlayer_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) DELAY SS_TAP(X_S) DELAY SS_TAP(X_C) DELAY SS_TAP(X_2) DELAY SS_TAP(X_ENTER));
      break;
    case SC3:
      ensure_fnlayer_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) DELAY SS_TAP(X_S) DELAY SS_TAP(X_C) DELAY SS_TAP(X_3) DELAY SS_TAP(X_ENTER));
      break;
    case SC4:
      ensure_fnlayer_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) DELAY SS_TAP(X_S) DELAY SS_TAP(X_C) DELAY SS_TAP(X_4) DELAY SS_TAP(X_ENTER));
      break;
    case SC5:
      ensure_fnlayer_alt_up();
      SEND_STRING(SS_TAP(X_LSUPER) DELAY SS_TAP(X_S) DELAY SS_TAP(X_C) DELAY SS_TAP(X_5) DELAY SS_TAP(X_ENTER));
      break;
    case EXITVNCV:
      ensure_fnlayer_alt_up();
      SEND_STRING(SS_TAP(X_F8) DELAY SS_TAP(X_C));
      break;
    case LEDBRIGHT:
      if(led_brightness) {
        led_brightness <<= 2;
      } else {
        led_brightness = 1;
      }
      eeprom_write_byte(EECONFIG_BRIGHTNESS, led_brightness);
      update_led_brightness();
      break;
    case LOCKDESK:
      ensure_fnlayer_alt_up();
      SEND_STRING(SS_DOWN(X_LSUPER) DELAY SS_TAP(X_L) DELAY SS_UP(X_LSUPER));
      break;
    case MK_CSTM_0:
      mk_cstm_down |= (1 << 0);
      update_mousekey_speeds();
      break;
    case MK_CSTM_1:
      mk_cstm_down |= (1 << 1);
      update_mousekey_speeds();
      break;
    case MK_CSTM_2:
      mk_cstm_down |= (1 << 2);
      update_mousekey_speeds();
      break;
    case MK_CSTM_3:
      mk_cstm_down |= (1 << 3);
      update_mousekey_speeds();
      break;
    }
  }
  else {
    switch (keycode) {
    case MK_CSTM_0:
      mk_cstm_down &= ~(1 << 0);
      update_mousekey_speeds();
      break;
    case MK_CSTM_1:
      mk_cstm_down &= ~(1 << 1);
      update_mousekey_speeds();
      break;
    case MK_CSTM_2:
      mk_cstm_down &= ~(1 << 2);
      update_mousekey_speeds();
      break;
    case MK_CSTM_3:
      mk_cstm_down &= ~(1 << 3);
      update_mousekey_speeds();
      break;
    }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  if (state & (1 << 1)) {
    ergodox_right_led_2_on();
  }
  else {
    ergodox_right_led_2_off();
  }
  if (state & (1 << FN_LAYER)) {
    ergodox_right_led_3_on();
  }
  else {
    ergodox_right_led_3_off();
    ensure_fnlayer_alt_up();
  }
  return state;
};

void keyboard_post_init_user(void) {
  led_brightness = eeprom_read_byte(EECONFIG_BRIGHTNESS);
  update_led_brightness();
  is_locked = eeprom_read_bool(EECONFIG_LOCKED);
  if(is_locked) {
    ergodox_right_led_1_on();
  } else {
    ergodox_right_led_1_off();
  }
};
