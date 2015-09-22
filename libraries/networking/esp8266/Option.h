#ifndef OPTION_H
#define OPTION_H

class StringOption {
public:
	StringOption();
	StringOption(String s);
	
	const bool isNone() const;
	const String getValue() const;
	// I'm sure the C++ way to do this is operator*
	
private:
	const bool _isNone;
	const String value;
};

#endif        //  #ifndef OPTION_H
