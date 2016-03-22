#include "break_rifle.h"
#include <iostream>

break_rifle::break_rifle(const chamber_type & Chamber, const barrel_type & Barrel) :
_Chamber(Chamber), _Barrel(Barrel) {
}


std::unique_ptr<cartridge> break_rifle::open() {
	_Open = true;
	return unload();
}
void break_rifle::close() {
	_Open = false;
}
bool break_rifle::load(std::unique_ptr<cartridge> Cartridge) {
	if (_Open && (bool)Cartridge) {
		if (!_Chamber.loaded()) {
			if ((const case_type &)_Chamber == (const case_type &)*Cartridge) {
				_Chamber.load(std::move(Cartridge));
				return true;
			}
		}
	}
	return false;
}
std::unique_ptr<cartridge> break_rifle::unload() {
	if (_Open) {
		return _Chamber.unload();
	} else {
		return std::unique_ptr<cartridge>();
	}
}

void break_rifle::cock() {
	_Cocked = true;
}
void break_rifle::fire() {
	if (_Cocked)
		std::cout << "Click." << std::endl;
	_Cocked = false;
	if (!_Open) {
		_Barrel.fire(_Chamber.strike(5.0f));
	}
}