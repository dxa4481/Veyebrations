#include <proximity.h>
#include <Motor.h>

Proximity proximity(3, 4);
Motor motor(5);
int prevVibAmount;


namespace
{
//x_constants for the func, x1 and x2 are values for the func, x1_p and x2_p represent values for the distance from the sensor.  These values are then mapped.
double X1 = .05;
double X2 = 10;
double X1_P = 1;
double X2_P = 310;

//Y1 & Y2 are calculated from x1 and x2 in the startup function based on the function being used
double Y1;
double Y2;

//vibration amount being mapped to, x1_p and x2_p are distance values that should correspond to these vibration values
double Y1_P = 255;
double Y2_P = 34;

//slopes for the mapping for both the x-values and y-values
double dy_x;
double dy_y;

//constants calculated for offset
double c_x;
double c_y;
}

void setup() 
{
  Serial.begin(9600);
  prevVibAmount = 0;

  //calculate Y1 & Y2
  Y1 = vibFunc(X1);
  Y2 = vibFunc(X2);
  
  //calculate dy_x and dy_y
  dy_x = (X2 - X1) / (X2_P - X1_P);
  dy_y = (Y2_P - Y1_P) / (Y2 - Y1);

  //calculate offset constants
  c_x = X1 - dy_x * X1_P;
  c_y = Y1_P - dy_y * Y1;
  
}
  
void loop() 
{
  double distance = proximity.getProximity();

  //610 cm's = max range
  
  //int vibAmount = (610/((distance + 70 )) - 0.8) * 35;
  int vibAmount = calculateVibration( distance );
  
  if(distance > 610 || vibAmount < 0)
  {
    vibAmount = 0;
  }
  if( vibAmount > 255 )
  {
    vibAmount = 255;
  }

  /* Update the vibAmount based on previous values */
  if( (abs(vibAmount-prevVibAmount)/255.0) > 0.5 )
  {
    int temp = prevVibAmount;
    prevVibAmount = vibAmount;
    vibAmount = temp;
  }
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("  VibrationAmount: ");
  Serial.println(vibAmount);
  
  motor.setSpeed(vibAmount);
}

double calculateVibration( double distance )
{
  double x_val = (distance * dy_x) + c_x;
  double func_val = vibFunc(x_val);
  return ((func_val * dy_y) + c_y);
}

/* function used for calculating the vibration rate, f(x) = 1/x */
double vibFunc( double x )
{
  return 1 / x;
}

