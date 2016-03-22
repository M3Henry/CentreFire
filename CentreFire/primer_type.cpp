#include "primer_type.h"

primer_type::primer_type(float Diameter, float MinImpulse, const std::string & Name) :
named(Name), _Diameter(Diameter), _MinImpulse(MinImpulse) {
}

unsigned_float primer_type::diameter() const {
	return _Diameter;
}

bool primer_type::strike(float Impulse) const {
	return Impulse >= _MinImpulse;
}