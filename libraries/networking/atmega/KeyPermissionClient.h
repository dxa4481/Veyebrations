#ifndef KEYPERMISSIONS_H
#define KEYPERMISSIONS_H

#include <Arduino.h>

typedef void (*callback)();

/// The hardware interface is two pins.
/// 1. is an input pin that will be high when this has a key, and is
///    allowed to do whatever the key gives permission for
/// 2. is an output pin that will pulse when the client is done with
///    its key

class KeyPermissionClient
{
public:
	
	/// Connect to KeyPermissions using the specified pins
	/// Side-effecting
	KeyPermissionClient(
			const uint8_t inputPin,
			const uint8_t outputPin
	);
	
	/// polls to determine whether this currently has a key
	/// Side-effecting
	bool hasKey();
	
	/// Tell server to give key to someone else
	/// Side-effecting
	void indicateDone();
	
	
private:
	const uint8_t inputPin;
	const uint8_t outputPin;
};

#endif // KEYPERMISSIONS_H
