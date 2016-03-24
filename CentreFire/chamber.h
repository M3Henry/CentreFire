#pragma once
#include "cartridge.h"
#include "loadable.h"

class chamber :
	public nameable,
	loadable<cartridge> {
public:
	typedef std::unique_ptr<chamber> instance;
public:
	chamber(const case_type &);
public:
	bool loaded() const;
	operator const case_type &() const;
	std::string name() const;
public:
	cartridge::instance load(cartridge::instance);
	cartridge::instance unload();
	cartridge::ejecta strike(float Impulse);
private:
	const case_type & _Type;
	cartridge::instance _Cartridge;
};