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
	virtual ejecta fire() = 0;
};
/*
class bolt_action : public receiver {
public:
	std::unique_ptr<receiver> clone() const {
		return std::unique_ptr<receiver>(new bolt_action());
	}
	ejecta fire() {
		return ejecta();
	}
};
*/