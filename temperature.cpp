#include <math.h>
#include <temperature.h>

Temperature::Temperature(){
}

double Temperature::getTemp() {
  double Temp;
  int RawADC = analogRead(0);
  Temp = log(10000.0*((1024.0/RawADC-1))); // for pull-down configuration
  //    =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sq(Temp) ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
  return Temp;
}
