#include "ammo_box.h"

ammo_box::ammo_box(const cartridge & Template, unsigned int Count) :
_Template(Template.clone()), _Count(Count) {
}

unsigned int ammo_box::empty() const {
	return _Count == 0u;
}

const cartridge & ammo_box::contents() const {
	return *_Template;
}

std::string ammo_box::name() const {
	std::string Name;
	if (empty()) {
		Name = "Empty box of ";
	} else {
		Name = "Box of " + std::to_string(_Count) + ' ';
	}
	Name += _Template->name();
	return Name;
}

std::unique_ptr<cartridge> ammo_box::extract() {
	if (!empty()) {
		--_Count;
		return _Template->clone();
	} else {
		return std::unique_ptr<cartridge>();
	}
}

std::unique_ptr<ammo_box> ammo_box::clone() {
	return std::unique_ptr<ammo_box>(new ammo_box(*this));
}

ammo_box::operator const calibre &() const {
	return *_Template;
}
ammo_box::operator const case_type &() const {
	return *_Template;
}