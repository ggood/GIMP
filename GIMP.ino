/**
 * Main sketch file for the Generic Instrumental Music Platform
 */

#include "ArduinoInstrument.h"
#include "AnalogInput.h"

ArduinoInstrument inst = ArduinoInstrument();
AnalogInput i0 = AnalogInput(0);

void setup() {
  // Perform any one-time instrument initialization here.
}

void loop() {
  inst.tick();
  // Perform any instrument-specific logic here
  Serial.print(i0.read(), HEX);
  // Delay, if needed
  delay(10);
}



