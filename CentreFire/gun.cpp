#include "gun.h"

gun::gun(const receiver & Receiver, const barrel_type & Barrel, std::string Name = "Unnamed gun") :
_Receiver(Receiver.clone()),
_Barrel(Barrel),
named(Name) {
	if (!_Receiver) {
		throw std::string("Cannot pass invalid receiver to gun");
	}
}

gun::operator receiver &() {
	return *_Receiver;
}

void gun::fire() {
	_Barrel.fire(_Receiver->fire());
}