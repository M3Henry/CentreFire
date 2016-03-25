#include "openable.h"

openable::openable() {
}
bool openable::open() {
	auto Was = _Open;
	return Was != (_Open = true);
}
bool openable::close() {
	auto Was = _Open;
	return Was != (_Open = false);
}
bool openable::isOpen() const {
	return _Open;
}
bool openable::isClosed() const {
	return !_Open;
}