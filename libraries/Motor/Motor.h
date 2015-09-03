#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
/* 
This library defines the different types of functionality that a motor can have.

This is where a function would be created to alter the vibrations of a motor
*/

class Motor
{
public:
	// initialize a motor
	Motor( byte pin );

	/* 
	Set the Speed of the motor
	
	Duty cycles are as follows:
	
	0   -> 0% Duty Cycle
	64  -> 25% Duty Cycle
	127 -> 50% Duty Cycle
	191 -> 75% Duty Cycle
	255 -> 100% Duty Cycle
	*/
	void setSpeed( byte speed );
	
	// Set the duty cycle to the percentage[0, 100]
	void setDutyCycle( byte percentage );
	
private:
	// The analog pin that the physical motor is attached to
	byte pin;
	
	// The current pwm rate(0-255) of the motor
	byte speed;
};

#endif