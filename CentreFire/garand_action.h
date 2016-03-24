#pragma once
#include "receiver.h"
#include "bolt_action.h"
#include "magazine.h"
class garand_action :
	public bolt_action {
public:
	garand_action(const magazine_type &);
	garand_action(const garand_action &) = delete;
	garand_action garand_action::operator =(const chamber &) = delete;
	receiver::instance clone() const;
public:
	cartridge::instance load(cartridge::instance);
private:
	cartridge::ejecta fire();
};