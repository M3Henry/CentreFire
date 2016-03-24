#include "bolt_action.h"
#include <iostream>

bolt_action::bolt_action(const magazine_type & Type) :
_Chamber(Type),
_Magazine(Type) {
}
receiver::instance bolt_action::clone() const {
	return instance(new bolt_action(_Magazine));
}

void bolt_action::open() {
	if (!_Open) {
		_Open = true;
		if (auto Cartridge = _Chamber.unload()) {
			std::cout << "A " << Cartridge->contents() << " flew out." << std::endl;
		}
	}
}
cartridge::instance bolt_action::load(cartridge::instance Cartridge) {
	if (_Open) {
		return _Magazine.load(std::move(Cartridge));
	} else {
		return cartridge::instance();
	}
}
cartridge::instance bolt_action::unload() {
	if (_Open) {
		return _Magazine.unload();
	} else {
		return cartridge::instance();
	}
}
void bolt_action::close() {
	if (_Open) {
		_Open = false;
		_Cocked = true;
		_Chamber.load(_Magazine.unload());
	}
}
cartridge::ejecta bolt_action::fire() {
	if (_Cocked && !_Open) {
		_Cocked = false;
		std::cout << "Click." << std::endl;
		return _Chamber.strike(5.0f);
	} else {
		return cartridge::NO_EJECTA;
	}
}