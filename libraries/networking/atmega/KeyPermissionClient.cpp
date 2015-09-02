#include "Arduino.h"
#include "KeyPermissions.h"

template <int interrupt>
void interruptServiceRequest() {
	inputIsr();
	digitalWrite(outPin, HIGH);
	// a few micro seconds later
	digitalWrite(outPin, LOW);
}

KeyPermissionClient::KeyPermissionClient(
		const byte inputPin,
		const byte outputPin,
		const byte inputInterrupt,
		const callback interruptServiceRequest
) {
	pinMode(inputPin, INPUT);
	pinMode(outputPin, OUTPUT);
	attachInterrupt(inputInterrupt, interruptServiceRequest<inputInterrupt>, RISING);
}
