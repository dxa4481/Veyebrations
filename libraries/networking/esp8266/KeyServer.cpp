#include "KeyServer.h"
#include "AccessPoint.h"



KeyServer::KeyServer(
		uint8_t inputPin,
		uint8_t outputPin
) :
		inputPin(inputPin),
		outputPin(outputPin),
		server(KEY_SERVER_PORT),
		hasKey(false)
{
	pinMode(inputPin, INPUT);
	pinMode(outputPin, OUTPUT);
}


void KeyServer::handle() {
	WiFiClient client = this->server.available();
	if (!client) { return; }
	while (!client.available()) { delay(1); }
	
	int msg(client.read());
	switch (msg) {
		case VEYEB_SEND_KEY: {
			client.write(VEYEB_OK);
			
			this->hasKey = true;
			digitalWrite(outputPin, HIGH);
			
		} break;
	}
}

void hasKey() {return this->hasKey;}

void canReturnKey() {return (HIGH == digitalRead(inputPin));}

void returnKey() {
	digitalWrite(outputPin, LOW);
	
	WiFiClient client(
		WiFi.softAPIP(),
		ACCESS_POINT_PORT
	);
	client.write(VEYEB_SEND_KEY);
	// TODO: care about response {OK, ERR}
}
