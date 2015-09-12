#ifndef PROXIMITY_H
#define PROXIMITY_H

#include "Arduino.h"
#include <temperature.h>

class Proximity 
{
 public:
 
  Proximity(int32_t echoPin, int32_t trigPin);
  
  double getProximity();
  
 private:
 
  int32_t echoPin;
  int32_t trigPin;
  Temperature temp;
};

#endif