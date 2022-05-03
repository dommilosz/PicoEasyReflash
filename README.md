# PicoEasyReflash
Library to easily reflash/restart rpi pico using only bootsel button

# Restart types

* Short press (<1000ms) = Watchdog restart.
* Long press (>1000ms)  = Restart to bootloader. Appears as USB drive to flash new firmware.

# Usage
In your loop() place `TickEasyReflash();`. It will automatically check for button press and restart if needed.

```cpp
#include "PicoEasyReflash.h"

void loop(){
  ...
  TickEasyReflash();
}
```

Click [here](https://github.com/dommilosz/PicoEasyReflash/tree/master/examples) for examples.
If you just want to reset without reading BOOTSEL status you can omit TickEasyReflash 

# Other Functions

Function                                                                             |   Description                   |    Notes  
-------------------------------------------------------------------------------------|---------------------------------|------------
bool GetBOOTSEL()                                                                    | Reads the BOOTSEL Button        | This function takes about 100 μS. Can be switched to builtin non pausing version to free memory (EASY_REFLASH_NO_PAUSE)
void EasyReflashReset()                                                              | Reset the PICO                  | -
void EasyReflashResetBootloader()                                                    | Reset the PICO to BOOTLOADER    | Can be disabled to free memory (EASY_REFLASH_DISABLE_BOOTLOADER_RESET)
int TickBootselRead(bool *holding = 0)                                               | Tick the BOOTSEL reader         | -
void TickEasyReflash()                                                               | Tick the Easy Reflash           | Used to tick all reader and calls callbacks if needed.
void EasyReflashSetDelays(int reset = 50, int bootloader = 1000)                     | Set delays for default callback | Use without parameters for default values.
void EasyReflashSetCallback(bootsel_read_callback_t cb = DefaultEasyReflashCallback) | Override the default callback   | Use without parameters for default callback
