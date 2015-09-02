#ifndef CONTACTINFO_H
#define CONTACTINFO_H


/// Information about other devices
/// 
typedef struct {
	/// The time when this object most recently obtained a key.
	/// Units: Seconds since the epoch
	long mostRecentKeyOwnTime;
} contactInfo;

/// Returns the member of the input array that has the least recent key-owning time.
/// 
/// functional
/// This does not take ownership of the input array.
/// The returned pointer is a member of the input array, and thus has the same owner as the input array.
/// If the array contains multiple minimum values, this does not guarantee which one it will return.
/// 
/// @pre the array size is greater than zero
/// @post the return value is non-null
const contactInfo* const findLeastRecentTime(const size_t argc, const contactInfo* const argv);

#endif        //  #ifndef CONTACTINFO_H
