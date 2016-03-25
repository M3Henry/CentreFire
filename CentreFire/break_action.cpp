#include "break_action.h"

#include <iostream>

break_action::break_action(const case_type & Chamber) :
_Chamber(Chamber), _Cocked(false) {
}
receiver::instance break_action::clone() const {
	auto p = new break_action(_Chamber);
	return instance(p);
}

void break_action::open() {
	if (openable::open()) {
		if (auto Cartridge = unload()) {
			std::cout << "A " << Cartridge->contents() << " flew out." << std::endl;
		}
	}
}
cartridge::instance break_action::load(cartridge::instance Cartridge) {
	if (isOpen()) {
		return _Chamber.load(std::move(Cartridge));
	}
	return Cartridge;
}
cartridge::instance break_action::unload() {
	if (isOpen()) {
		return _Chamber.unload();
	} else {
		return cartridge::instance();
	}
}

void break_action::cock() {
	_Cocked = true;
}
cartridge::ejecta break_action::fire() {
	if (_Cocked) {
		std::cout << "Click." << std::endl;
		_Cocked = false;
		if (isClosed()) {
			return _Chamber.strike(5.0f);
		}
	}
	return cartridge::NO_EJECTA;
}