#include "KeyPermissionClient.h"

template <int interrupt>
void interruptServiceRequest() {
	inputIsr();
	digitalWrite(outPin, HIGH);
	// a few micro seconds later
	digitalWrite(outPin, LOW);
}

KeyPermissionClient::KeyPermissionClient(
		const uint8_t inputPin,
		const uint8_t outputPin,
		const uint8_t inputInterrupt,
		const callback interruptServiceRequest
) : isr(0) {
	pinMode(inputPin, INPUT);
	pinMode(outputPin, OUTPUT);
//	attachInterrupt(inputInterrupt, interruptServiceRequest<inputInterrupt>, RISING);
}
