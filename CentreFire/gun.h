#pragma once
#include "barrel_type.h"
#include "receiver.h"
class gun :
	public named {
public:
	gun(const receiver &, const barrel_type &, std::string);
public:
	operator receiver &();
	template <class A>
	A * action() {
		if (typeid(A) == typeid(*_Receiver)) {
			return static_cast<A *>(_Receiver.get());
		} else {
			return nullptr;
		}
	}
	void fire();
private:
	std::unique_ptr<receiver> _Receiver;
	const barrel_type & _Barrel;
};

