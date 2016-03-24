#include "magazine.h"

magazine::magazine(const magazine_type & Type) :
_Type(Type) {
}

magazine::operator const magazine_type &() const {
	return _Type;
}

std::string magazine::name() const {
	return (empty() ? "Empty " : "Loaded " ) + _Type.name();
}

bool magazine::empty() const {
	return Stack.empty();
}

bool magazine::full() const {
	return Stack.size() >= _Type.capacity();
}

cartridge::instance magazine::load(cartridge::instance Cartridge) {
	if (full()) {
		return Cartridge;
	} else {
		Stack.push(std::move(Cartridge));
		return cartridge::instance();
	}
}
cartridge::instance magazine::unload() {
	if (Stack.size()) {
		auto Cartridge = std::move(Stack.top());
		Stack.pop();
		return Cartridge;
	} else {
		return cartridge::instance();
	}
}