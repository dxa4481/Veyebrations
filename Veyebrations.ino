#include <proximity.h>
#include <Motor.h>

Proximity proximity(3, 4);
Motor motor(5);

void setup() 
{
  Serial.begin(9600);
}
  
void loop() 
{
  double distance = proximity.getProximity();
  
  //610 cm's = max range
  
  int vibAmount = (int)((1 - distance / 305) * 255);
  if(distance > 305){
    vibAmount = 0;
  }

  Serial.print("Vibe: ");
  Serial.println(vibAmount);
  motor.setSpeed(vibAmount);
}
