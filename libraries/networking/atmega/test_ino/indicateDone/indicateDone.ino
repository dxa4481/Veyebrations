#include <KeyPermissionClient.h>
/*
 * Test sketch
 *
 * 1. Connect pin 6 to pin 7.
 * 2. Connect an oscilloscope to pin 8.
 * 3. turn on
 * 4. Type something into Serial
 * 5. Observe. There should be a pulse at pin 8 not too long after.
 */

const uint8_t KEY_WRITE  = 6;
const uint8_t KEY_READ   = 7;
const uint8_t DONE_WRITE = 8;

// Do we trust initialization order of globals?
KeyPermissionClient dut(KEY_READ, DONE_WRITE);

void setup()
{
  Serial.begin(9600);
  pinMode(KEY_WRITE, OUTPUT);
  
  // because this involves timer interrupts, and therefore not in this thread
  tone(KEY_WRITE, 100);
}

void loop()
{
  delay(100);
  if (Serial.available() > 0)
  {
    Serial.println("Wait for Key");
    while (dut.hasKey()) { yield(); }
    Serial.println("Has Key; Return Key;");
    dut.indicateDone();
    Serial.println("Key returned;");
    Serial.read();
  }
}
