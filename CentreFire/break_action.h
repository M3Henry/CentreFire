#pragma once
#include "receiver.h"
class break_action :
	public receiver,
	public loadable<cartridge> {
public:
	break_action(const case_type &);
	std::unique_ptr<receiver> clone() const;
public:
	void open();
	void close();
	cartridge::instance load(cartridge::instance);
	cartridge::instance unload();
	void cock();
private:
	cartridge::ejecta fire();
private:
	chamber _Chamber;
	bool _Cocked;
	bool _Open;
};