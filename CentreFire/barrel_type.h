#pragma once
#include "cartridge.h"

class barrel_type :
	public named {
public:
	barrel_type(const calibre &, float Length, const std::string & = "Unnamed Barrel");
public:
	operator const calibre &() const;
	void fire(std::tuple<const bullet_type *, float>) const;
private:
	const calibre & _Calibre;
	const unsigned_float _Length;
};

