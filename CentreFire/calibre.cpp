#include "calibre.h"

calibre::calibre(float Diameter) :
_Diameter(Diameter) {
}

bool calibre::operator==(const calibre & that) const {
	return _Diameter == that._Diameter;
}

bool calibre::operator!=(const calibre & that) const {
	return !(*this == that);
}

std::string calibre::name() const {
	return std::to_string(_Diameter) + "mm";
}