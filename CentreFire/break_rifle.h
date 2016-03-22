#pragma once
#include "gun.h"
#include "chamber.h"
#include "barrel_type.h"

class break_rifle : 
	public gun {
public:
	break_rifle(const chamber_type &, const barrel_type &);
public:
	std::unique_ptr<cartridge> open();
	void close();
	bool load(std::unique_ptr<cartridge>);
	std::unique_ptr<cartridge> unload();
	void cock();
	void fire();
private:
	bool _Cocked;
	bool _Open;
	chamber _Chamber;
	const barrel_type & _Barrel;
};