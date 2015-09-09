#include <vector>
#include "contactInfo.h"

/// value given to times if not explicitly stated in constructor
const long DEFAULT_TIME = 0;
/// if (ping_time + STALE_TIME_DELTA < current_time), then a contact
/// is 'stale' - to be treated as if it is out of range or no longer extant.
const long STALE_TIME_DELTA = 100000; //TODO: figure out a real number to put here

ContactInfo::ContactInfo() :
	mostRecentKeyOwnTime(DEFAULT_TIME),
	mostRecentPingTime(DEFAULT_TIME)
{}

ContactInfo::ContactInfo(
	const long keyOwnTime,
	const long pingTime
) :
	mostRecentKeyOwnTime(keyOwnTime),
	mostRecentPingTime(pingTime)
{}

bool ContactInfo::operator==(const ContactInfo& rhs) const {
	return //(this->name == rhs.name) &&
	       (this->mostRecentKeyOwnTime == rhs.mostRecentKeyOwnTime) &&
	       (this->mostRecentPingTime == rhs.mostRecentPingTime);
}

//const std::string ContactInfo::getName() const { return this->name; }
long ContactInfo::getKeyTime() const { return this->mostRecentKeyOwnTime; }
void ContactInfo::setKeyTime(long i) { this->mostRecentKeyOwnTime = i; }
void ContactInfo::setPingTime(long i) { this->mostRecentPingTime = i; }

bool ContactInfo::isStale(long currentTime) const {
	return this->mostRecentPingTime + STALE_TIME_DELTA < currentTime;
}

bool byLeastRecentlyOwnedKey(const ContactInfo a, const ContactInfo b) {
	return a.getKeyTime() < b.getKeyTime();
}
