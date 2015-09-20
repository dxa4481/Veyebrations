#include <ESP8266WiFi.h>
#include "findNewAccessPoint.h"
#include "algorithm.h"



// used by findNewAccessPoint
class WiFiSsidIterator {
public:
	WiFiSsidIterator(uint8_t networkItem = 0) : networkItem(networkItem) {};
	const char* operator*() {return WiFi->SSID(networkItem);}
	WiFiSsidIterator operator++(int) {WiFiSsidIterator retVal(networkItem); ++(*this); return retVal;}
	bool operator!=(WiFiSsidIterator rhs) {return (this->networkItem != rhs.networkItem);}
	bool operator==(WiFiSsidIterator rhs) {return (this->networkItem == rhs.networkItem);}
	
	WiFiSsidIterator& operator++() {
		do {
			++networkItem;
		} while (String(this*).indexOf(ACCESS_POINT_SSID_PREFIX) != -1) 
		
		return *this;
	}
	
private:
	uint8_t networkItem;
}

template<class InputIterator>
InputIterator findContactWithIp(InputIterator first, InputIterator last, IPAddress v) {
	while (first!=last) {
		if (first->getIp == v) return first;
		++first;
	}
	return last;
}

bool byLeastRecentlyOwnedKey(const Contact a, const Contact b) {
	return a.getKeyTime() < b.getKeyTime();
}


/***********************************************/

AccessPoint::AccessPoint() : server(ACCESS_POINT_SSID_PREFIX) {}




StringOption AccessPoint::findNewAccessPoint() {
	int n = WiFi.scanNetworks();
	if (n >= 0) {
		WiFiSsidIterator end(n);
		WiFiSsidIterator result = std::min_element(WiFiSsidIterator(), end);
		if (end == result) {
			return StringOption();
		} else {
			return StringOption(*result);
		}
	} else {
		return StringOption();
	}
}

void AccessPoint::createAccessPoint() {
	WiFi.disconnect();
	String ssid(String(ACCESS_POINT_SSID_PREFIX) + String(random(), HEX));
	WiFi.softAP(ssid, password);
}

void AccessPoint::connectToAccessPoint(String ssid) {
	WiFi.disconnect();
	WiFi.begin(ssid, password);
}

void AccessPoint::handleServer() {
	WiFiClient client = this->server.available();
	if (!client) { return; }
	while (!client.available()) { delay(1); }
	
	int msg(client.read());
	switch (msg) {
		case VEYEB_PING: {
			Contact* c = findContactWithIp(this->clientv, this->clientv + this->clientc, client.remoteIP());
			if (c != (this->clientv + this->clientc)) {
				// if existing entry; update existing entry
				c->setPingTime(millis());
				client.write(VEYEB_OK);
			} else if (this->clientc == MAX_CLIENTS) {
				// unknown client, but can't handle more clients -> fail
				client.write(VEYEB_ERR);
			} else {
				// add new client
				c = Contact(client.remoteIP(), 0, millis());
				client.write(VEYEB_OK);
			}
		} break;
			
		case VEYEB_SEND_KEY: {
			client.write(VEYEB_OK);
			
			Contact* c = std::min_element(this->clientv, this->clientv + this->clientc, byLeastRecentlyOwnedKey));
			if (c == this->clientv + this->clientc) {
				// TODO: store key, try again later
				// no one to send key to, somehow.
			} else {
				c->sendKey()
			}
			
		} break;
	}
}