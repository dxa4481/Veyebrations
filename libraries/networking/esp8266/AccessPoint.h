#ifndef FINDNEWACCESSPOINT_H
#define FINDNEWACCESSPOINT_H

#include <ESP8266WiFi.h>
#include "Contact.h"
#include "Option.h"

const char* const ACCESS_POINT_SSID_PREFIX("veyeb");
// TODO: keep password somewhere else(?)
const char* const password("the rain is gone");

const int ACCESS_POINT_PORT(27669);
const int MAX_CLIENTS(6);

enum veyeb_protocol_messages : int {
	VEYEB_OK = 0,
	VEYEB_ERR = 1,
	
	VEYEB_SEND_KEY = 64,
	VEYEB_PING = 65
};



class AccessPoint {
public:
	AccessPoint();

	/// Determines which SSID this should connect to, which will be the access point
	/// that came from a Veyeb device with the lowest suffix
	StringOption findNewAccessPoint();
	
	void createAccessPoint();
	void connectToAccessPoint(String ssid);
	
	void handle();

private:
	WiFiServer server;
	int clientc;
	Contact clientv[MAX_CLIENTS];
};



#endif        //  #ifndef FINDNEWACCESSPOINT_H
