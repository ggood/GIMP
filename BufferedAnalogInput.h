#include "WProgram.h"

// An analog input reader class that buffers
// read values such that it will only sample
// at a maximum given rate.

class BufferedAnalogInput : 
public AnalogInput {
private:
  unsigned int _interval;
  unsigned int _last_value;
  unsigned long _last_sample_time;

public:
  BufferedAnalogInput(byte pin_number, unsigned int interval) {
    : AnalogInput(pin_number);
    _interval = interval;
    _last_value = analogRead(_pin_number);
    _last_sample_time = millis();
  }

  unsigned int read() {
    if (millis() - _last_sample > _interval) {
      // resample
      _last_value = analogRead(_pin_number);
      _last_sample_time = millis;
    }
    return _last_value;
  }
};

