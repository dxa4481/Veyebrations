#ifndef KEYPERMISSIONS_H
#define KEYPERMISSIONS_H

#include <Arduino.h>

typedef void (*callback)();

/// The hardware interface is two pins.
/// 1. is an input pin, preferably with interrupt capabilities.
///    This pin will pulse for XXX microseconds when the reciever
///    is allowed 
/// 2. is an output pin that will pulse when the client is done with
///    its key

class KeyPermissionClient
{
public:
	
	KeyPermissionClient(
			const uint8_t inputPin,
			const uint8_t outputPin,
			const uint8_t inputInterrupt,
			const callback interruptServiceRequest
	);
	
	
	
private:
	const callback isr;
};

#endif // KEYPERMISSIONS_H
