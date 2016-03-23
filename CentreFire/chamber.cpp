#include "chamber.h"


chamber::chamber(const case_type & Type) :
_Type(Type) {
}


bool chamber::loaded() const {
	return (bool)_Cartridge;
}

chamber::operator const case_type &() const {
	return _Type;
}

std::string chamber::name() const {
	return _Type.name() + " Chamber";
}


cartridge::ejecta chamber::strike(float Impulse) {
	if (loaded()) {
		return _Cartridge->strike(Impulse);
	} else {
		return cartridge::NO_EJECTA;
	}
}
cartridge::instance chamber::load(cartridge::instance Cartridge) {
	if (!loaded()) {
		if (Cartridge) {
			if (((const case_type &)_Type) == *Cartridge) {
				_Cartridge = std::move(Cartridge);
				return cartridge::instance();
			}
		}
	}
	return Cartridge;
}
cartridge::instance chamber::unload() {
	return std::move(_Cartridge);
}