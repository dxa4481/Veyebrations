/// The ESP866 is responsible for key and network management.
/// GPIO_TX and GPIO_RX are both connected to the main unit;
/// for output and input respectively.
#include <ESP8266WiFi.h>
#include <AccessPoint.h>
#include <KeyServer.h>

AccessPoint accessPoint;
KeyServer keyServer(3,4);

/// Side effect heavy
void setup() {
	accessPoint.createAccessPoint();
	keyServer.reconnect();
}

/// Side effect heavy
void loop() {
	StringOption newSsid(accessPoint.findNewAccessPoint());
	if (newSsid.isNone()) {
		// no access points in range; create one
		accessPoint.createAccessPoint();
		keyServer.reconnect();
	} else if (newSsid.getValue() != WiFi.SSID()) {
		// new desirable access point
		accessPoint.connectToAccessPoint(newSsid.getValue());
		keyServer.reconnect();
	} else {
		// stay connected to the current access point	
	}
	
	accessPoint.handle();
	keyServer.handle();
	
	if (keyServer.hasKey() && keyServer.canReturnKey()) {
		keyServer.returnKey();
	}
}
