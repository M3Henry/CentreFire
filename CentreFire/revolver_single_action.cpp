#include "revolver_single_action.h"
#include <iostream>

revolver_single_action::revolver_single_action(const case_type & CaseType, size_t Size) :
_Cocked(false),
_Open(false) {
	_Cylinder.reserve(Size);
	while (Size--) {
		_Cylinder.emplace_back(new chamber(CaseType));
	}
	_FiringChamber = _Cylinder.begin();
	if (_Cylinder.size() < 2) {
		throw std::string("A revolver must have at least 2 chambers");
	}
}

receiver::instance revolver_single_action::clone() const {
	return instance(new revolver_single_action(*_Cylinder.front(), _Cylinder.size()));
}

void revolver_single_action::open() {
	if (!_Open) {
		_Open = true;
	}
}

cartridge::instance revolver_single_action::load(cartridge::instance Cartridge) {
	if (_Open) {
		for (auto & Chamber : _Cylinder) {
			Cartridge = Chamber->load(std::move(Cartridge));
			if (!Cartridge) {
				break;
			}
		}
	}
	return Cartridge;
}
cartridge::instance revolver_single_action::unload() {
	if (_Open) {
		for (auto & Chamber : _Cylinder) {
			if (auto Cartridge = Chamber->unload()) {
				return Cartridge;
			}
		}
	}
	return cartridge::instance();
}

void revolver_single_action::unloadAll() {
	unsigned int Count = 0;
	if (!_Open) {
		return;
	}
	for (auto & Chamber : _Cylinder) {
		if (auto Cartridge = Chamber->unload()) {
			++Count;
		}
	}
	if (Count) {
		std::cout << Count << " " << ((const case_type &)*_Cylinder.front()).name() << " fell out." << std::endl;
	}
}

void revolver_single_action::close() {
	if (_Open) {
		_Open = false;
	}
}

void revolver_single_action::cock() {
	_Cocked = true;
	if (_Cylinder.end() == ++_FiringChamber) {
		_FiringChamber = _Cylinder.begin();
	}
}

cartridge::ejecta revolver_single_action::fire() {
	if (_Cocked) {
		std::cout << "Click." << std::endl;
		_Cocked = false;
		if (!_Open) {
			return (*_FiringChamber)->strike(5.0f);
		}
	}
	return cartridge::NO_EJECTA;
}