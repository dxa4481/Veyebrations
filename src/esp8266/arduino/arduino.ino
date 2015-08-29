/// The ESP866 is responsible for key and network management.
/// GPIO_TX and GPIO_RX are both connected to the main unit;
/// for output and input respectively.

/// Side effect heavy
void setup() {
  // Set GPIO_TX to output
  // Set GPIO_RX to input
}

/// Side effect heavy
void loop() {
  // add/remove clients or make sure server is still in range or
  // other network management tasks
  
  // maybe onRecieveKey(), if it is impossible to do that via interrupts 
}

/// Side effect heavy
/// called via interrupt, ideally
///
/// These are the actions performed when a unit is done using its key.
/// Basically, it revokes the proximity sensor's permission to act, and
/// it transmits a message giving the key to someone else.
///
/// As this is an interrupt, and it needs to know the next, the overall
/// program design should ensure that the next is stored and easily retrievable.
void on_GPIO_RX_Fall() {
  // set GPIO_TX to low
  // give key to someone other unit
}

/// Side effect heavy
/// called via interrupt, idealy
/// 
/// These are the actions performed when a unit has been given a key;
/// basically, it then tells the main half that it has permission to do the chirp thing.
void onRecieveKey() {
  // set GPIO_TX to (has permission)
  // wait for GPIO_RX to rise (? depending on whether interrupts can be on fall, or must be on change.
}
