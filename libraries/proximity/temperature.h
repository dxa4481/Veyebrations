#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Arduino.h"

class Temperature {
 public:
  /// @param readPin the analog pin connected to the thermistor
  Temperature(int8_t readPin);
  /// @return current temperature in Celcius
  double getTemp();
 private:
  int8_t readPin;
};

#endif