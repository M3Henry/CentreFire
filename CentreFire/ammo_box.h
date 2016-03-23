#pragma once
#include "cartridge.h"

class ammo_box :
	public nameable {
public:
	ammo_box(const cartridge & Template, unsigned int Count);
	ammo_box & operator= (const ammo_box &) = delete;
private:
	ammo_box(const ammo_box &) = default;
public:
	unsigned int empty() const;
	const cartridge & contents() const;
	std::string name() const;
	operator const calibre &() const;
	operator const case_type &() const;
public:
	std::unique_ptr<ammo_box> clone();
	cartridge::instance extract();
private:
	std::shared_ptr<cartridge> _Template;
	unsigned int _Count;
};