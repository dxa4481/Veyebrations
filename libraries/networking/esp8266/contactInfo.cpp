#include <vector>
#include <algorithm>    // std::min_element, std::max_element
#include "contactInfo.h"

const long DEFAULT_KEY_OWN_TIME = 0;

ContactInfo::ContactInfo() {
	this->mostRecentKeyOwnTime = DEFAULT_KEY_OWN_TIME;
}

ContactInfo::ContactInfo(const long keyOwnTime) {
	this->mostRecentKeyOwnTime = keyOwnTime;
}

bool ContactInfo::operator==(const ContactInfo& rhs) const {
	return this->mostRecentKeyOwnTime == rhs.mostRecentKeyOwnTime;
}


bool byLeastRecentlyOwnedKey(const ContactInfo a, const ContactInfo b) {
	return a.mostRecentKeyOwnTime < b.mostRecentKeyOwnTime;
}
