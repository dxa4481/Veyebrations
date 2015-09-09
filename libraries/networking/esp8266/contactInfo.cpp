#include <vector>
#include "contactInfo.h"

const long DEFAULT_TIME = 0;

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

bool byLeastRecentlyOwnedKey(const ContactInfo a, const ContactInfo b) {
	return a.getKeyTime() < b.getKeyTime();
}
