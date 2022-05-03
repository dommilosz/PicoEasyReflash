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
}

void loop() {
  if(Serial.available()){
    char read = Serial.read();

    //Reset to bootloader after b char received.
    if(read == 'b'){
      EasyReflashResetBootloader();
    }
    //Normal restart
    if(read == 'r'){
      EasyReflashReset();
    }
  }
}