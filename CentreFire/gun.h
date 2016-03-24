#pragma once
#include "barrel_type.h"
#include "receiver.h"
class gun :
	public named {
public:
	gun(const receiver &, const barrel_type &, std::string);
	gun(const gun &) = delete;
	const gun & operator=(const gun &) = delete;
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
	receiver::instance _Receiver;
	const barrel_type & _Barrel;
};

