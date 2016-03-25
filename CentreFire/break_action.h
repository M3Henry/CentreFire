#pragma once
#include "receiver.h"
class break_action :
	public receiver {
public:
	break_action(const case_type &);
	instance clone() const;
public:
	void open();
	cartridge::instance load(cartridge::instance);
	cartridge::instance unload();
	void cock();
private:
	cartridge::ejecta fire();
private:
	chamber _Chamber;
	bool _Cocked;
};