#include "bullet_type.h"
bullet_type::bullet_type(const calibre & Calibre, float Mass, std::string Name) :
_Calibre(Calibre), _Mass(Mass), named(Name) {
}

unsigned_float bullet_type::mass() const {
	return _Mass;
}

bullet_type::operator const calibre &() const {
	return _Calibre;
}