#include "garand_action.h"
#include <iostream>
garand_action::garand_action(const magazine_type & MagType) :
bolt_action(MagType) {
}

receiver::instance garand_action::clone() const {
	return instance(new garand_action(_Magazine));
}

bool garand_action::open() {
	auto Changed = bolt_action::open();
	if (_Magazine.empty() && Changed) {
		std::cout << "PING!" << std::endl;
	}
	return Changed;
}

cartridge::instance garand_action::load(cartridge::instance Cartridge) {
	Cartridge = bolt_action::load(std::move(Cartridge));
	if (isOpen() && _Magazine.full()) {
		close();
	}
	return Cartridge;
}

cartridge::ejecta garand_action::fire() {
	auto Ejecta = bolt_action::fire();
	if (std::get<1>(Ejecta)) {
		open();
		if (!_Magazine.empty()) {
			close();
		}
	}
	return Ejecta;
}