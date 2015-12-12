#include <proximity.h>

Proximity proximity(3, 4, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double distance = proximity.getProximity();
  
  Serial.print("Distance: ");
  Serial.println(distance);

  delay(500);
}
