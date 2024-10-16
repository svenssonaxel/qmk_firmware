/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define MK_CUSTOM_SPEED
#define MK_DEFAULT_MOVE_SPEED 3162
#define MK_DEFAULT_WHEEL_SPEED 3162
#define EECONFIG_LOCKED (bool *) EECONFIG_SIZE
#define EECONFIG_BRIGHTNESS (uint8_t *) (EECONFIG_SIZE + 1)
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#undef LAYER_STATE_32BIT
#define LAYER_STATE_8BIT
