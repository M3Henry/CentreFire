#pragma once
#include "cartridge.h"
#include "chamber_type.h"

class chamber :
	public nameable {
public:
	chamber(const chamber_type &);
public:
	bool loaded() const;
	operator const case_type &() const;
	std::string name() const;
public:
	bool load(std::unique_ptr<cartridge>);
	std::unique_ptr<cartridge> unload();
	std::tuple<const bullet_type *, float> strike(float Impulse);
private:
	const chamber_type & _Type;
	std::unique_ptr<cartridge> _Cartridge;
};

