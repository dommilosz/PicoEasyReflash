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

Blink exaple in the exaples directory.
