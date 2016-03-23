#pragma once
#include "cartridge.h"
#include "chamber_type.h"

class chamber :
	public nameable {
public:
	chamber(const chamber_type &);
public:
	bool loaded() const;
	operator const chamber_type &() const;
	std::string name() const;
public:
	std::unique_ptr<cartridge> load(std::unique_ptr<cartridge>);
	std::unique_ptr<cartridge> unload();
	ejecta strike(float Impulse);
private:
	const chamber_type & _Type;
	std::unique_ptr<cartridge> _Cartridge;
};

