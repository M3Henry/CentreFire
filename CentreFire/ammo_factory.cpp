#include "ammo_factory.h"

ammo_factory::ammo_factory() :
NineMil(9.0f),
Bullet(NineMil, 7.45f / 1000, "9mm FMJ"),
Case(NineMil, 5.0f, 0.862f, "9x19mm Case"),
Prop(3000.0f, "Gunpowder"),
Primer(5.0f, 1.0f, "Cap"),
Ammo(cartridge(Case, &primer(Primer), &Prop, &Bullet, "9x19mm Parabellum"), 5) {
}

std::unique_ptr<ammo_box> ammo_factory::make() {
	return Ammo.clone();
}