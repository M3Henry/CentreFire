#pragma once
#include "receiver.h"
#include "magazine.h"
class bolt_action :
	public receiver {
public:
	bolt_action(const magazine_type &);
	bolt_action(const bolt_action &) = delete;
	bolt_action bolt_action::operator =(const chamber &) = delete;
	receiver::instance clone() const;
public:
	bool open();
	bool close();
	cartridge::instance load(cartridge::instance);
	cartridge::instance unload();
protected:
	cartridge::ejecta fire();
protected:
	chamber _Chamber;
	magazine _Magazine;
	bool _Cocked;
};