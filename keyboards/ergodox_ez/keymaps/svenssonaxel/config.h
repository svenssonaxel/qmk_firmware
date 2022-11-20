/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define EECONFIG_LOCKED (bool *) EECONFIG_SIZE
#define EECONFIG_BRIGHTNESS (uint8_t *) (EECONFIG_SIZE + 1)
