#include "WProgram.h"

class ArduinoInstrument {
private:
  byte enabled_digital[14];
  byte enabled_analog[6];
  unsigned long last_sample;


public: 
  void tick() {
    last_sample = millis();
  }
};


