#include "Option.h"

StringOption::StringOption() : _isNone(true) {}
StringOption::StringOption(String s) : _isNone(false), value(s) {}
const StringOption::isNone() {return this->_isNone;}
const StringOption::getValue() {return this->value;}
