#include "bolt_action.h"
#include <iostream>

bolt_action::bolt_action(const magazine_type & Type) :
_Chamber(Type),
_Magazine(Type) {
}
receiver::instance bolt_action::clone() const {
	return instance(new bolt_action(_Magazine));
}

bool bolt_action::open() {
	auto Changed = openable::open();
	if (Changed) {
		if (auto Cartridge = _Chamber.unload()) {
			std::cout << "A " << Cartridge->contents() << " flew out." << std::endl;
		}
	}
	return Changed;
}
bool bolt_action::close() {
	auto Changed = openable::close();
	if (Changed) {
		_Cocked = true;
		_Chamber.load(_Magazine.unload());
	}
	return Changed;
}
cartridge::instance bolt_action::load(cartridge::instance Cartridge) {
	if (isOpen()) {
		return _Magazine.load(std::move(Cartridge));
	} else {
		return cartridge::instance();
	}
}
cartridge::instance bolt_action::unload() {
	if (isOpen()) {
		return _Magazine.unload();
	} else {
		return cartridge::instance();
	}
}
cartridge::ejecta bolt_action::fire() {
	if (_Cocked && isClosed()) {
		_Cocked = false;
		std::cout << "Click." << std::endl;
		return _Chamber.strike(5.0f);
	} else {
		return cartridge::NO_EJECTA;
	}
}