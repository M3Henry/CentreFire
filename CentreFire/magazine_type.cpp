#include "magazine_type.h"


magazine_type::magazine_type(const case_type & CaseType, size_t Capacity) :
_CaseType(CaseType),
_Capacity(Capacity),
named(std::to_string(Capacity) + "rnd " + CaseType.name() + " Magazine") {
}

magazine_type::operator const case_type &() const {
	return _CaseType;
}

bool magazine_type::compatible(const magazine_type & that) const {
	return _CaseType == that._CaseType;
}

size_t magazine_type::capacity() const {
	return _Capacity;
}