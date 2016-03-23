#pragma once
#include "receiver.h"
class break_action :
	public receiver {
public:
	break_action(const chamber_type &);
	std::unique_ptr<receiver> clone() const;
public:
	std::unique_ptr<cartridge> open();
	void close();
	std::unique_ptr<cartridge> load(std::unique_ptr<cartridge>);
	std::unique_ptr<cartridge> unload();
	void cock();
private:
	ejecta fire();
private:
	chamber _Chamber;
	bool _Cocked;
	bool _Open;
};

