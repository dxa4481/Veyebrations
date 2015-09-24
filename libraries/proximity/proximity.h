#ifndef PROXIMITY_H
#define PROXIMITY_H

#include "Arduino.h"
#include <temperature.h>

class Proximity 
{
 public:
 
  /// @param echoPin the digital pin connected to the proximity sensor's echo pin
  /// @param trigPin the digital pin connected to the proximity sensor's trigger pin
  /// @param tempPin the analog pin connected to the thermistor
  Proximity(int32_t echoPin, int32_t trigPin, int8_t tempPin);
  
  /// @return distance measured in centimeters
  double getProximity();
  
 private:
 
  int32_t echoPin;
  int32_t trigPin;
  Temperature temp;
};

#endif