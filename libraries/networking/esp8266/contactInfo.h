#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <string>


/// Information about other devices
/// 
class ContactInfo
{
public:
	
	ContactInfo();
	
	ContactInfo(
			const long keyTime,
			const long pingTime
	);
	
	bool operator==(const ContactInfo& rhs) const;
	
	/// returns the node's name
	const std::string getName() const;
	
	/// determines whether 
	bool isStale(long currentTime) const;
	/// set the time that this node most recently pinged
	void setPingTime(long i);
	
	/// get the time that this node most recently had a key
	long getKeyTime() const;
	/// set the time that this node most recently had a key
	void setKeyTime(long i);
	
	
private:
	long mostRecentKeyOwnTime;
	long mostRecentPingTime;
	
	/*
	 * The damned thing explodes if a class containing a std:string member
	 * is put anywhere near a malloc'd pointer.
	 */
//	std::string name;
};


#endif        //  #ifndef CONTACTINFO_H
