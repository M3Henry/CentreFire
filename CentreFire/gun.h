#pragma once
#include "barrel_type.h"
#include "receiver.h"
class gun :
	public named {
public:
	gun(const receiver &, const barrel_type &, std::string);
public:
	operator receiver &();
	void fire();
private:
	std::unique_ptr<receiver> _Receiver;
	const barrel_type & _Barrel;
};

