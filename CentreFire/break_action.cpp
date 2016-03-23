#include "break_action.h"

#include <iostream>

break_action::break_action(const chamber_type & Chamber) :
_Chamber(Chamber), _Cocked(false), _Open(false) {
}
std::unique_ptr<receiver> break_action::clone() const {
	auto p = new break_action(_Chamber);
	return std::unique_ptr<receiver>(p);
}

std::unique_ptr<cartridge> break_action::open() {
	_Open = true;
	return unload();
}
void break_action::close() {
	_Open = false;
}
std::unique_ptr<cartridge> break_action::load(std::unique_ptr<cartridge> Cartridge) {
	if (_Open) {
		return _Chamber.load(std::move(Cartridge));
	}
	return Cartridge;
}
std::unique_ptr<cartridge> break_action::unload() {
	if (_Open) {
		return _Chamber.unload();
	} else {
		return std::unique_ptr<cartridge>();
	}
}

void break_action::cock() {
	_Cocked = true;
}
ejecta break_action::fire() {
	if (_Cocked) {
		std::cout << "Click." << std::endl;
		_Cocked = false;
		if (!_Open) {
			return _Chamber.strike(5.0f);
		}
	}
	return ejecta();
}