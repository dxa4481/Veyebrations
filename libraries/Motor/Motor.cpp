#include "Motor.h"

Motor::Motor( byte pin )
{
	this->pin = pin;
	pinMode(pin, OUTPUT);
	speed = 0;
}

void Motor::setSpeed( byte speed )
{
	this->speed = speed;
	
	//write the pwm wave
	analogWrite( pin, speed );
}

void Motor::setDutyCycle( uint16_t percentage )
{
	byte val = (byte)((percentage * 255)/100);
	setSpeed( val );
}