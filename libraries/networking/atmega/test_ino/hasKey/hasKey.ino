#include <KeyPermissionClient.h>
/*
 * Test sketch
 *
 * Connect either V_DD or GND to pin 7. Serial should periodically print
 * "Has Key" if connected to V_DD, or "No Key" if connected to GND. Feel
 * free to switch partway through. And which is printed should change if
 * the voltage connected to pin 7 changes.
 */

const uint8_t KEY_READ   = 7;
const uint8_t DONE_WRITE = 8;


// Do we trust initialization order of globals?
KeyPermissionClient dut(KEY_READ, DONE_WRITE);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(100);
  if (dut.hasKey())
  {
    Serial.println("Got Key; Doing Thing");
    delay(50);
    Serial.println("Done doing thing");
  }
  else
  {
    Serial.println("No Key; Not doing thing");
  }
}
