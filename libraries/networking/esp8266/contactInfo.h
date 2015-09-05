#ifndef CONTACTINFO_H
#define CONTACTINFO_H


/// Information about other devices
/// 
class ContactInfo
{
public:
	
	ContactInfo();
	
	ContactInfo(
			const long mostRecentKeyOwnTime
	);
	
	bool operator== (const ContactInfo& rhs) const;
	 
	long mostRecentKeyOwnTime;
	
private:
};



#include <algorithm>    // std::min_element, std::max_element

/// used by `determineWhoToSendKeyTo` and should only be used
/// by `determineWhoToSendKeyTo`, but enfocing that is impossible
/// as template implementations mut be in header files.
bool byLeastRecentlyOwnedKey(const ContactInfo a, const ContactInfo b);


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
ContactInfo determineWhoToSendKeyTo(const ForwardIterator begin, const ForwardIterator end) {
	return *(std::min_element(begin, end, byLeastRecentlyOwnedKey));
}

#endif        //  #ifndef CONTACTINFO_H
