#include "WProgram.h"

// An extremely simple analog input reader class.
// Simply reads the input when called and returns
// the value.
class AnalogInput {
private:
  byte _pin_number;

public:
  AnalogInput(byte pin_number) {
    _pin_number = pin_number;
  }

  unsigned int read() {
    return analogRead(_pin_number);
  }
};




