#include <proximity.h>
#include <temperature.h>

Proximity proximity(3, 4);
Temperature temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double distance = proximity.getProximity();
  double temp = temperature.getTemp();
  
  Serial.print("Distance: ");
  Serial.println(distance);

  Serial.print("Temperature: ");
  Serial.println(temp);
  
  delay(500);
}

