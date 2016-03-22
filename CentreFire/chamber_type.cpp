#include "chamber_type.h"


chamber_type::chamber_type(const case_type & Case, std::string Name = "Unnamed Chamber") :
named(Name), _Case(Case) {
}

chamber_type::operator const case_type &() const {
	return _Case;
}