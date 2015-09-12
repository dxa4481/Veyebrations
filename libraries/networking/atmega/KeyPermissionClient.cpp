#include "KeyPermissionClient.h"

KeyPermissionClient::KeyPermissionClient(
		const uint8_t inputPin,
		const uint8_t outputPin
) : inputPin(inputPin), outputPin(outputPin) {
	pinMode(inputPin, INPUT);
	pinMode(outputPin, OUTPUT);
}

bool KeyPermissionClient::hasKey() {
	return (HIGH == digitalRead(inputPin));
}

void KeyPermissionClient::indicateDone() {
	// raise done signal
	digitalWrite(outputPin, HIGH);
	// wait until server acknoledges done signal
	while (this->hasKey()) { yield(); delay(1); }
	// lower done signal
	digitalWrite(outputPin, LOW);
}
