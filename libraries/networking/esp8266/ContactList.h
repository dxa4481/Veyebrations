#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <algorithm>    // std::min_element, std::max_element

/// used by `determineWhoToSendKeyTo` and should only be used
/// by `determineWhoToSendKeyTo`, but enfocing that is impossible
/// as template implementations mut be in header files.
bool byLeastRecentlyOwnedKey(const Contact a, const Contact b);


/// Returns the member of the input array that has the least recent key-owning time.
/// 
/// functional
/// This does not take ownership of the input array.
/// The returned pointer is a member of the input array, and thus has the same owner as the input array.
/// If the array contains multiple minimum values, this does not guarantee which one it will return.
/// 
/// @pre the array size is greater than zero
/// @post the return value is non-null
template <class ForwardIterator>
Contact determineWhoToSendKeyTo(const ForwardIterator begin, const ForwardIterator end) {
	return *(std::min_element(begin, end, byLeastRecentlyOwnedKey));
}



#endif
