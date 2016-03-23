#pragma once
#include "chamber.h"

class receiver : nameable {
public:
	virtual std::unique_ptr<receiver> clone() const = 0;

	std::string name() const {
		return typeid(*this).name();
	}
private:
	friend class gun;
	virtual cartridge::ejecta fire() = 0;
};