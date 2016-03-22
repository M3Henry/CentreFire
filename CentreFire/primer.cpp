#include "primer.h"


primer::primer(const primer_type & Type, bool New) :
_Type(Type), _New(New) {
}

std::unique_ptr<primer> primer::clone() const {
	return std::unique_ptr<primer>(new primer(_Type, _New));
}

bool primer::strike(float Impulse) {
	auto Bang = _New && _Type.strike(Impulse);
	if (Bang) {
		_New = false;
	}
	return Bang;
}

std::string primer::name() const {
	std::string Name;
	if (_New) {
		Name = "New ";
	} else {
		Name = "Spent ";
	}
	Name += _Type.name();
	return Name;
}

primer::operator const primer_type&() const {
	return _Type;
}