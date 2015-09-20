#include "Contact.h"

/// value given to times if not explicitly stated in constructor
const long DEFAULT_TIME = 0;
/// if (ping_time + STALE_TIME_DELTA < current_time), then a contact
/// is 'stale' - to be treated as if it is out of range or no longer extant.
const long STALE_TIME_DELTA = 100000; //TODO: figure out a real number to put here

Contact::Contact() :
	mostRecentKeyOwnTime(DEFAULT_TIME),
	mostRecentPingTime(DEFAULT_TIME)
{}

Contact::Contact(
	const IPAddress ip,
	const long keyOwnTime,
	const long pingTime
) :
	ip(ip),
	mostRecentKeyOwnTime(keyOwnTime),
	mostRecentPingTime(pingTime)
{}

bool Contact::operator==(const Contact& rhs) const {
	return //(this->name == rhs.name) &&
	       (this->mostRecentKeyOwnTime == rhs.mostRecentKeyOwnTime) &&
	       (this->mostRecentPingTime == rhs.mostRecentPingTime);
}

//const std::string Contact::getName() const { return this->name; }
long Contact::getKeyTime() const { return this->mostRecentKeyOwnTime; }
void Contact::setKeyTime(long i) { this->mostRecentKeyOwnTime = i; }
void Contact::setPingTime(long i) { this->mostRecentPingTime = i; }

bool Contact::isStale(long currentTime) const {
	return this->mostRecentPingTime + STALE_TIME_DELTA < currentTime;
}

void Contact::sendKey() {
	
}
