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

Blink example in the examples directory.

You can also manually reset the pico: `EasyReflashReset()`

By defining `EASY_REFLASH_NO_PAUSE` you can use simpler version without many dependencies. Also it doesn't pause the other core while reading bootsel.

To customize durations use `void EasyReflashSetDelays(int reset=50, int bootloader=1000)`