#include "PicoEasyReflash.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);

  //OPTIONAL: Set timings (50ms - reset, 5s - bootloader)
  EasyReflashSetDelays(50, 5000);
}

void loop() {
  //Tick to check for bootsel press and restart if needed.
  TickEasyReflash();

  //code to blink LED asynchronously.
  int leddata = millis() % 1000;
  digitalWrite(LED_BUILTIN, leddata > 500);
  delay(100);
  //Other code...
}