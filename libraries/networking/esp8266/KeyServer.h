#ifndef KEYSERVER_H
#define KEYSERVER_H

#include <ESP8266WiFi.h>

const int KEY_SERVER_PORT(27670);

class KeyServer {
public:
	// Set GPIO_TX to output
	// Set GPIO_RX to input
	KeyServer(uint8_t inputPin, uint8_t outputPin);
	
	// recieve messages from the access point
	void handle();
	
	bool hasKey();
	bool canReturnKey();
	
	/// @pre canReturnKey() == true
	void returnKey();
	
	
private:
	uint8_t inputPin;
	uint8_t outputPin;
	WiFiServer server;
	bool hasKey;
}

#endif        //  #ifndef KEYSERVER_H
