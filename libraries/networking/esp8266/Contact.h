#ifndef CONTACT_H
#define CONTACT_H

#include <IPAddress.h>


/// Information about other devices
/// 
class Contact
{
public:
	
	Contact();
	
	Contact(
			const IPAddress ip,
			const long keyTime,
			const long pingTime
	);
	
	bool operator==(const Contact& rhs) const;
	
	/// returns the node's name
	const IPAddress getIp() const;
	
	/// determines whether 
	bool isStale(long currentTime) const;
	/// set the time that this node most recently pinged
	void setPingTime(long i);
	
	/// get the time that this node most recently had a key
	long getKeyTime() const;
	/// set the time that this node most recently had a key
	void setKeyTime(long i);
	
	
	void sendKey();
	
private:
	const IPAddress ip;
	long mostRecentKeyOwnTime;
	long mostRecentPingTime;
};


#endif        //  #ifndef Contact_H
