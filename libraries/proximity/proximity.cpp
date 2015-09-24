#include <temperature.h>
#include <proximity.h>

Proximity::Proximity(int32_t echoPin, int32_t trigPin, int8_t tempPin) :
  temp(tempPin)
{
  this->echoPin = echoPin;
  this->trigPin = trigPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

double Proximity::getProximity(){
  // put your main code here, to run repeatedly:
 double speed, duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in m) based on the speed of sound.
 speed = 331 + 0.6 * temp.getTemp();
 distance = duration/10000 * speed / 2;

 return distance; 
}
