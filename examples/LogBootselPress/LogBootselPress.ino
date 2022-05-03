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

  Serial.begin(115200);

  //Set our function to handle bootsel button press events.
  EasyReflashSetCallback(BootselCallback);
}

void loop() {
  //Tick to check for bootsel press and restart if needed.
  TickEasyReflash();
}

void BootselCallback(int duration, bool holding){
  //Print duration while user is holding the button with holding = true. Then print for how long the user held it.
  Serial.print("Bootsel: ");
  Serial.print(duration);
  Serial.println(holding?" [x]":" [ ]");
}
