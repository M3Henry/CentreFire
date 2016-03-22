#pragma once
#include <vector>
#include "ammo_box.h"

class ammo_factory {
public:
	ammo_factory();
	ammo_factory(const ammo_factory &) = delete;
	ammo_factory & operator=(const ammo_factory &) = delete;
	std::unique_ptr<ammo_box> make();
private:
	calibre NineMil;
	bullet_type Bullet;
	case_type Case;
	propellant_type Prop;
	primer_type Primer;
	ammo_box Ammo;
};

