#include <Motor.h>
/*
 * Test sketch to test the motor library created
 */

Motor motor(11);
int testDuty;

void setup() 
{
  Serial.begin(9600);
  testDuty = 0;
}

void loop() 
{
  delay(500);
  updateDutyCycle();
}

/*
 * Alternate the Duty cycle increasing by 25%
 */
void updateDutyCycle()
{
  testDuty += 25;
  testDuty = testDuty % 125;
  motor.setDutyCycle( testDuty );

  Serial.print("Duty Cycle: ");
  Serial.println(testDuty);
}

