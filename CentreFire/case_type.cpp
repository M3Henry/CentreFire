#include "case_type.h"

case_type::case_type(const calibre & Calibre, float PrimerDiameter, float Volume, std::string Name) :
_Calibre(Calibre), _PrimerDiameter(PrimerDiameter), _Volume(Volume), named(Name) {
	if (_PrimerDiameter <= 0.0f) {
		throw(name() + " must have positive primer diameter!");
	} else if (_Volume <= 0.0f) {
		throw(name() + " must have positive mass!");
	}
}

bool case_type::accepts(const calibre & Bullet) const {
	return _Calibre == Bullet;
}
bool case_type::accepts(const primer_type & Primer) const {
	return _PrimerDiameter == Primer.diameter();
}

const calibre & case_type::getCalibre() const {
	return _Calibre;
}

float case_type::volume() const {
	return _Volume;
}

case_type::operator const calibre &() const {
	return _Calibre;
}

bool case_type::operator ==(const case_type & that) const {
	return _Calibre == that._Calibre;
}
bool case_type::operator !=(const case_type & that) const {
	return *this != that;
}