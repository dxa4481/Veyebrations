#include <temperature.h>


Proximity::Proximity(int32_t echoPin, int32_t trigPin){
  this->echoPin = echoPin;
  this->trigPin = trigPin;
  this->temp = Temperature();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

double Proximity::getProximity(){
  // put your main code here, to run repeatedly:
 double speed;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in m) based on the speed of sound.
 speed = 331 + 0.6 * temp.getTemp();
 distance = duration * speed / 2;

 return distance; 
}
