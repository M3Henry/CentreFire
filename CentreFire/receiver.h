#pragma once
#include "chamber.h"

class receiver :
	nameable,
	public loadable<cartridge> {
public:
	typedef std::unique_ptr<receiver> instance;
public:
	virtual instance clone() const = 0;

	std::string name() const {
		return typeid(*this).name();
	}
private:
	friend class gun;
	virtual cartridge::ejecta fire() = 0;
};