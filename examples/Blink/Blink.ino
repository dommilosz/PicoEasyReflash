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
}

void loop() {
  PerformRestart();

  //code to blink LED asynchronously.
  int leddata = millis() % 1000;
  digitalWrite(LED_BUILTIN, leddata > 500);
  delay(100);
  //Other code...
}