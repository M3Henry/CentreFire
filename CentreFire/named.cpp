#include "named.h"

named::named(std::string Name) :
_Name(Name) {
}

std::string named::name() const {
	return _Name;
}