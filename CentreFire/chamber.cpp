#include "chamber.h"


chamber::chamber(const chamber_type & Type) :
_Type(Type) {
}


bool chamber::loaded() const {
	return (bool)_Cartridge;
}

chamber::operator const case_type &() const {
	return _Type;
}

std::string chamber::name() const {
	return _Type.name();
}


ejecta chamber::strike(float Impulse) {
	if (loaded()) {
		return _Cartridge->strike(Impulse);
	} else {
		return ejecta(nullptr, 0.0f);
	}
}
bool chamber::load(std::unique_ptr<cartridge> Cartridge) {
	if (!loaded()) {
		if (((const case_type &)_Type) == *Cartridge) {
			_Cartridge = std::move(Cartridge);
			return true;
		}
	}
	return false;
}
std::unique_ptr<cartridge> chamber::unload() {
	return std::move(_Cartridge);
}