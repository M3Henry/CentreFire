#include "break_action.h"

#include <iostream>

break_action::break_action(const case_type & Chamber) :
_Chamber(Chamber), _Cocked(false), _Open(false) {
}
std::unique_ptr<receiver> break_action::clone() const {
	auto p = new break_action(_Chamber);
	return std::unique_ptr<receiver>(p);
}

cartridge::instance break_action::open() {
	_Open = true;
	return unload();
}
void break_action::close() {
	_Open = false;
}
cartridge::instance break_action::load(cartridge::instance Cartridge) {
	if (_Open) {
		return _Chamber.load(std::move(Cartridge));
	}
	return Cartridge;
}
cartridge::instance break_action::unload() {
	if (_Open) {
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
		if (!_Open) {
			return _Chamber.strike(5.0f);
		}
	}
	return cartridge::NO_EJECTA;
}