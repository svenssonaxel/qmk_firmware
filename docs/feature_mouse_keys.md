# Mouse keys

Mouse keys is a feature that allows you to emulate a mouse using your keyboard. You can move the pointer at different speeds, press 5 buttons and scroll in 8 directions.

## Adding mouse keys to your keyboard

To use mouse keys, you must at least enable mouse keys support and map mouse actions to keys on your keyboard.

### Enabling mouse keys

To enable mouse keys, add the following line to your keymap’s `rules.mk`:

```c
MOUSEKEY_ENABLE = yes
```

### Mapping mouse actions

In your keymap you can use the following keycodes to map key presses to mouse actions:

|Key             |Aliases  |Description      |
|----------------|---------|-----------------|
|`KC_MS_UP`      |`KC_MS_U`|Move cursor up   |
|`KC_MS_DOWN`    |`KC_MS_D`|Move cursor down |
|`KC_MS_LEFT`    |`KC_MS_L`|Move cursor left |
|`KC_MS_RIGHT`   |`KC_MS_R`|Move cursor right|
|`KC_MS_BTN1`    |`KC_BTN1`|Press button 1   |
|`KC_MS_BTN2`    |`KC_BTN2`|Press button 2   |
|`KC_MS_BTN3`    |`KC_BTN3`|Press button 3   |
|`KC_MS_BTN4`    |`KC_BTN4`|Press button 4   |
|`KC_MS_BTN5`    |`KC_BTN5`|Press button 5   |
|`KC_MS_BTN6`    |`KC_BTN6`|Press button 6   |
|`KC_MS_BTN7`    |`KC_BTN7`|Press button 7   |
|`KC_MS_BTN8`    |`KC_BTN8`|Press button 8   |
|`KC_MS_WH_UP`   |`KC_WH_U`|Move wheel up    |
|`KC_MS_WH_DOWN` |`KC_WH_D`|Move wheel down  |
|`KC_MS_WH_LEFT` |`KC_WH_L`|Move wheel left  |
|`KC_MS_WH_RIGHT`|`KC_WH_R`|Move wheel right |
|`KC_MS_ACCEL0`  |`KC_ACL0`|Set speed to 0   |
|`KC_MS_ACCEL1`  |`KC_ACL1`|Set speed to 1   |
|`KC_MS_ACCEL2`  |`KC_ACL2`|Set speed to 2   |

## Configuring mouse keys

Mouse keys supports three different modes to move the cursor:

* **Accelerated (default):** Holding movement keys accelerates the cursor until it reaches its maximum speed.
* **Kinetic:** Holding movement keys accelerates the cursor with its speed following a quadratic curve until it reaches its maximum speed.
* **Constant:** Holding movement keys moves the cursor at constant speeds.
* **Combined:** Holding movement keys accelerates the cursor until it reaches its maximum speed, but holding acceleration and movement keys simultaneously moves the cursor at constant speeds.
* **Inertia:** Cursor accelerates when key held, and decelerates after key release.  Tracks X and Y velocity separately for more nuanced movements.  Applies to cursor only, not scrolling.

The same principle applies to scrolling, in most modes.

Configuration options that are times, intervals or delays are given in milliseconds. Scroll speed is given as multiples of the default scroll step. For example, a scroll speed of 8 means that each scroll action covers 8 times the length of the default scroll step as defined by your operating system or application.

### Accelerated mode

This is the default mode. You can adjust the cursor and scrolling acceleration using the following settings in your keymap’s `config.h` file:

|Define                      |Default|Description                                              |
|----------------------------|-------|---------------------------------------------------------|
|`MOUSEKEY_DELAY`            |10     |Delay between pressing a movement key and cursor movement|
|`MOUSEKEY_INTERVAL`         |20     |Time between cursor movements in milliseconds            |
|`MOUSEKEY_MOVE_DELTA`       |8      |Step size                                                |
|`MOUSEKEY_MAX_SPEED`        |10     |Maximum cursor speed at which acceleration stops         |
|`MOUSEKEY_TIME_TO_MAX`      |30     |Time until maximum cursor speed is reached               |
|`MOUSEKEY_WHEEL_DELAY`      |10     |Delay between pressing a wheel key and wheel movement    |
|`MOUSEKEY_WHEEL_INTERVAL`   |80     |Time between wheel movements                             |
|`MOUSEKEY_WHEEL_MAX_SPEED`  |8      |Maximum number of scroll steps per scroll action         |
|`MOUSEKEY_WHEEL_TIME_TO_MAX`|40     |Time until maximum scroll speed is reached               |

Tips:

* Setting `MOUSEKEY_DELAY` too low makes the cursor unresponsive. Setting it too high makes small movements difficult.
* For smoother cursor movements, lower the value of `MOUSEKEY_INTERVAL`. If the refresh rate of your display is 60Hz, you could set it to `16` (1/60). As this raises the cursor speed significantly, you may want to lower `MOUSEKEY_MAX_SPEED`.
* Setting `MOUSEKEY_TIME_TO_MAX` or `MOUSEKEY_WHEEL_TIME_TO_MAX` to `0` will disable acceleration for the cursor or scrolling respectively. This way you can make one of them constant while keeping the other accelerated, which is not possible in constant speed mode.
* Setting `MOUSEKEY_WHEEL_INTERVAL` too low will make scrolling too fast. Setting it too high will make scrolling too slow when the wheel key is held down.

Cursor acceleration uses the same algorithm as the X Window System MouseKeysAccel feature. You can read more about it [on Wikipedia](https://en.wikipedia.org/wiki/Mouse_keys).

### Kinetic Mode

This is an extension of the accelerated mode. The kinetic mode uses a quadratic curve on the cursor speed which allows precise movements at the beginning and allows to cover large distances by increasing cursor speed quickly thereafter.  You can adjust the cursor and scrolling acceleration using the following settings in your keymap’s `config.h` file:

|Define                                |Default  |Description                                                    |
|--------------------------------------|---------|---------------------------------------------------------------|
|`MK_KINETIC_SPEED`                    |undefined|Enable kinetic mode                                            |
|`MOUSEKEY_DELAY`                      |5        |Delay between pressing a movement key and cursor movement      |
|`MOUSEKEY_INTERVAL`                   |10       |Time between cursor movements in milliseconds                  |
|`MOUSEKEY_MOVE_DELTA`                 |16       |Step size for accelerating from initial to base speed          |
|`MOUSEKEY_INITIAL_SPEED`              |100      |Initial speed of the cursor in pixel per second                |
|`MOUSEKEY_BASE_SPEED`                 |5000     |Maximum cursor speed at which acceleration stops               |
|`MOUSEKEY_DECELERATED_SPEED`          |400      |Decelerated cursor speed                                       |
|`MOUSEKEY_ACCELERATED_SPEED`          |3000     |Accelerated cursor speed                                       |
|`MOUSEKEY_WHEEL_INITIAL_MOVEMENTS`    |16       |Initial number of movements of the mouse wheel                 |
|`MOUSEKEY_WHEEL_BASE_MOVEMENTS`       |32       |Maximum number of movements at which acceleration stops        |
|`MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS`|48       |Accelerated wheel movements                                    |
|`MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS`|8        |Decelerated wheel movements                                    |

Tips:

* The smoothness of the cursor movement depends on the `MOUSEKEY_INTERVAL` setting. The shorter the interval is set the smoother the movement will be.  Setting the value too low makes the cursor unresponsive.  Lower settings are possible if the micro processor is fast enough. For example: At an interval of `8` milliseconds, `125` movements per second will be initiated.  With a base speed of `1000` each movement will move the cursor by `8` pixels.
* Mouse wheel movements are implemented differently from cursor movements. While it's okay for the cursor to move multiple pixels at once for the mouse wheel this would lead to jerky movements. Instead, the mouse wheel operates at step size `2`. Setting mouse wheel speed is done by adjusting the number of wheel movements per second.

### Constant mode

In this mode you can define multiple different speeds for both the cursor and the mouse wheel. There is no acceleration. `KC_ACL0`, `KC_ACL1` and `KC_ACL2` change the cursor and scroll speed to their respective setting.

You can choose whether speed selection is momentary or tap-to-select:

* **Momentary:** The chosen speed is only active while you hold the respective key. When the key is raised, mouse keys returns to the unmodified speed.
* **Tap-to-select:** The chosen speed is activated when you press the respective key and remains active even after the key has been raised. The default speed is that of `KC_ACL1`. There is no unmodified speed.

The default speeds from slowest to fastest are as follows:

* **Momentary:** `KC_ACL0` < `KC_ACL1` < *unmodified* < `KC_ACL2`
* **Tap-to-select:** `KC_ACL0` < `KC_ACL1` < `KC_ACL2`

To use constant speed mode, you must at least define `MK_3_SPEED` in your keymap’s `config.h` file:

```c
#define MK_3_SPEED
```

To enable momentary mode, also define `MK_MOMENTARY_ACCEL`:

```c
#define MK_MOMENTARY_ACCEL
```

Use the following settings if you want to adjust cursor movement or scrolling:

|Define               |Default      |Description                                |
|---------------------|-------------|-------------------------------------------|
|`MK_3_SPEED`         |*Not defined*|Enable constant cursor speeds              |
|`MK_MOMENTARY_ACCEL` |*Not defined*|Enable momentary speed selection           |
|`MK_C_OFFSET_UNMOD`  |16           |Cursor offset per movement (unmodified)    |
|`MK_C_INTERVAL_UNMOD`|16           |Time between cursor movements (unmodified) |
|`MK_C_OFFSET_0`      |1            |Cursor offset per movement (`KC_ACL0`)     |
|`MK_C_INTERVAL_0`    |32           |Time between cursor movements (`KC_ACL0`)  |
|`MK_C_OFFSET_1`      |4            |Cursor offset per movement (`KC_ACL1`)     |
|`MK_C_INTERVAL_1`    |16           |Time between cursor movements (`KC_ACL1`)  |
|`MK_C_OFFSET_2`      |32           |Cursor offset per movement (`KC_ACL2`)     |
|`MK_C_INTERVAL_2`    |16           |Time between cursor movements (`KC_ACL2`)  |
|`MK_W_OFFSET_UNMOD`  |1            |Scroll steps per scroll action (unmodified)|
|`MK_W_INTERVAL_UNMOD`|40           |Time between scroll steps (unmodified)     |
|`MK_W_OFFSET_0`      |1            |Scroll steps per scroll action (`KC_ACL0`) |
|`MK_W_INTERVAL_0`    |360          |Time between scroll steps (`KC_ACL0`)      |
|`MK_W_OFFSET_1`      |1            |Scroll steps per scroll action (`KC_ACL1`) |
|`MK_W_INTERVAL_1`    |120          |Time between scroll steps (`KC_ACL1`)      |
|`MK_W_OFFSET_2`      |1            |Scroll steps per scroll action (`KC_ACL2`) |
|`MK_W_INTERVAL_2`    |20           |Time between scroll steps (`KC_ACL2`)      |

### Combined mode

This mode functions like **Accelerated** mode, however, you can hold `KC_ACL0`, `KC_ACL1` and `KC_ACL2`
to momentarily (while held) set the cursor and scroll speeds to constant speeds. When no acceleration
keys are held, this mode is identical to **Accelerated** mode, and can be modified using all of the
relevant settings.

* **KC_ACL0:** This acceleration sets your cursor to the slowest possible speed. This is useful for very
small and detailed movements of the cursor.
* **KC_ACL1:** This acceleration sets your cursor to half the maximum (user defined) speed.
* **KC_ACL2:** This acceleration sets your cursor to the maximum (computer defined) speed. This is
useful for moving the cursor large distances without much accuracy.

To use combined speed mode, you must at least define `MK_COMBINED` in your keymap’s `config.h` file:

```c
#define MK_COMBINED
```

### Inertia mode

This mode provides smooth motion, like sliding on ice.  The cursor accelerates
along a quadratic curve while a key is held, then glides to a stop after the
key is released.  Vertical and horizontal movements are tracked independently,
so the cursor can move in many directions and make curves.

Cannot be used at the same time as Kinetic mode, Constant mode, or Combined mode.

Recommended settings in your keymap’s `config.h` file:

|Define                      |Default  |Description                                                |
|----------------------------|---------|-----------------------------------------------------------|
|`MOUSEKEY_INERTIA`          |undefined|Enable Inertia mode                                        |
|`MOUSEKEY_DELAY`            |150      |Delay between pressing a movement key and cursor movement  |
|`MOUSEKEY_INTERVAL`         |16       |Time between cursor movements in milliseconds (16 = 60fps) |
|`MOUSEKEY_MAX_SPEED`        |32       |Maximum cursor speed at which acceleration stops           |
|`MOUSEKEY_TIME_TO_MAX`      |32       |Number of frames until maximum cursor speed is reached     |
|`MOUSEKEY_FRICTION`         |24       |How quickly the cursor stops after releasing a key         |
|`MOUSEKEY_MOVE_DELTA`       |1        |How much to move on first frame (1 strongly recommended)   |

Tips:

* Set `MOUSEKEY_DELAY` to roughly the same value as your host computer's key repeat delay, in ms.  Recommended values are 100 to 300.
* Set `MOUSEKEY_INTERVAL` to a value of 1000 / your monitor's FPS.  For 60 FPS, 1000/60 = 16.
* Set `MOUSEKEY_MAX_SPEED` based on your screen resolution and refresh rate, like Width / FPS.  For example, 1920 pixels / 60 FPS = 32 pixels per frame.
* Set `MOUSEKEY_TIME_TO_MAX` to a value of approximately FPS / 2, to make it reach full speed in half a second (or so).
* Set `MOUSEKEY_FRICTION` to something between 1 and 255.  Lower makes the cursor glide longer. Values from 8 to 40 are the most effective.
* Keep `MOUSEKEY_MOVE_DELTA` at 1.  This allows precise movements before the gliding effect starts.
* Mouse wheel options are the same as the default accelerated mode, and do not use inertia.

### Custom speed mode

In this mode
* `KC_ACL0`, `KC_ACL1` and `KC_ACL2` are ignored.
* Offset, acceleration and interval configuration is ignored.
* The curosr and wheel directions depend only on what keys are down, never in what order they were pressed.
* You may set the cursor and wheel speeds using a function call:

  ```c
  void mousekey_set_speeds(uint16_t move_speed, uint16_t wheel_speed);
  ```

  For `move_speed` and `wheel_speed`, the whole `0-65535` range is valid.
  There is no need to set offset and interval separately.
  Instead, the offset is calculated dynamically to make the movement smooth and precise.

|Define                   |Default      |Description             |
|---------------------    |-------------|------------------------|
|`MK_CUSTOM_SPEED`        |*Not defined*|Enable custom speed mode|
|`MK_DEFAULT_MOVE_SPEED`  | 0           |Default speed for moving|
|`MK_DEFAULT_WHEEL_SPEED` | 0           |Default speed for wheel |

## Use with PS/2 Mouse and Pointing Device

Mouse keys button state is shared with [PS/2 mouse](feature_ps2_mouse.md) and [pointing device](feature_pointing_device.md) so mouse keys button presses can be used for clicks and drags.
