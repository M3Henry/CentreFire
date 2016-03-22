#include "cartridge.h"

cartridge::cartridge(const case_type & Case,
	const primer * Primer,
	const propellant_type * Propellant,
	const bullet_type * Bullet,
	std::string Name) :
	_Primer(Primer ? Primer->clone() : std::unique_ptr<primer>()),
_Case(Case),
_Propellant(Propellant),
_Bullet(Bullet),
named(Name) {
	if (hasBullet()) {
		if (!_Case.accepts(*_Bullet)) {
			throw(_Case.name() + " cannot be accept a " + _Bullet->name() + " bullet!");
		}
	}
	if (hasPrimer()) {
		if (!_Case.accepts(*_Primer)) {
			throw(_Case.name() + " cannot be accept a " + _Primer->name() + " primer!");
		}
	}
}

cartridge::cartridge(const cartridge & Source) :
_Primer(Source._Primer ? Source._Primer->clone() : std::unique_ptr<primer>()),
_Case(Source._Case),
_Propellant(Source._Propellant),
_Bullet(Source._Bullet),
named(Source.name() ) {
}

std::unique_ptr<cartridge> cartridge::clone() const {
	return std::unique_ptr<cartridge>(new cartridge(*this));
}

bool cartridge::hasBullet() const {
	return _Bullet != nullptr;
}
bool cartridge::hasPropellant() const {
	return _Propellant != nullptr;
}
bool cartridge::hasPrimer() const {
	return (bool)_Primer;
}

cartridge::operator const calibre &() const {
	return _Case;
}


bool cartridge::insert(const bullet_type * & Bullet) {
	if (!hasBullet()) {
		if (_Case.accepts(*Bullet)) {
			_Bullet = Bullet;
			Bullet = nullptr;
			return true;
		}
	}
	return false;
}

const bullet_type * cartridge::releaseBullet() {
	auto Bullet = _Bullet;
	_Bullet = nullptr;
	return Bullet;
}

bool cartridge::insert(std::unique_ptr<primer> & Primer) {
	if (!hasPrimer()) {
		if (_Case.accepts(*Primer)) {
			_Primer = std::move(Primer);
			return true;
		}
	}
	return false;
}
std::unique_ptr<primer> cartridge::releasePrimer() {
	return std::move(_Primer);
}

ejecta cartridge::strike(float Impulse) {
	auto Energy = 0.0f;
	const bullet_type * Bullet = nullptr;
	if (_Primer->strike(Impulse)) {
		if (hasPropellant()) {
			Energy = _Case.volume() * _Propellant->energyDensity();
			_Propellant = nullptr;
			if (Energy > 0.0f) {
				Bullet = releaseBullet();
			}
		}
	}
	return ejecta(Bullet, Energy);
}

std::string cartridge::contents() const {
	std::vector<const nameable *> Components;
	if (hasBullet()) {
		Components.push_back(_Bullet);
	}
	if (hasPropellant()) {
		Components.push_back(_Propellant);
	}
	if (hasPrimer()) {
		Components.push_back(_Primer.get());
	}
	std::string Str(nameable::englishList(Components));
	if (Components.empty()) {
		Str = "Empty ";
	} else {
		Str += " in a ";
	}
	Str += _Case.name();
	return Str;
}

cartridge::operator const case_type &() const {
	return _Case;
}