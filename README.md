# PicoEasyReflash
Library to easily reflash/restart rpi pico using only bootsel button

# Restart types

* Short press (<2000ms) = Watchdog restart.
* Long press (>2000ms)  = Restart to bootloader. Appears as USB drive to flash new firmware.

# Usage
In your loop() place `PerformRestart();`. It will automatically check for button press and restart if needed.

```cpp
#include "PicoEasyReflash.h"

void loop(){
  ...
  PerformRestart();
}
```

Blink exaple in the exaples directory.
