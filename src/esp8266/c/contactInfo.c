#include "contactInfo.h"

#define NULL (0)

/// Returns the member of the input array that has the least recent key-owning time.
const contactInfo* const findLeastRecentTime(const size_t argc, const contactInfo* const argv) {
	int i;
	const contactInfo* retVal = argv;
	
	if (argc <= 0) {return NULL;}
	
	for (i = 1; i < argc; i++) {
		if (argv[i].mostRecentKeyOwnTime < retVal->mostRecentKeyOwnTime) {
			retVal = argv + i;
		}
	}
	return retVal;
}
