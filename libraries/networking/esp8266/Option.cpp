
StringOption::StringOption() : isNone(true) {}
StringOption::StringOption(String s) : isNone(false), value(s) {}
StringOption::isNone() {return this->isNone;}
StringOption::getValue() {return this->value;}
