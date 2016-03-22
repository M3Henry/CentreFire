// CentreFire.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ammo_factory.h"
#include "break_rifle.h"
#include <Windows.h>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[]) {
	using namespace std;
	bool Passed = propellant_type::unitTest();
	if (!Passed) {
		return 1;
	}
	try {
		ammo_factory Factory;
		auto Ammo = Factory.make();
		cout << "Successfully created " << Ammo->name() << " cartridges comprising:" << endl << Ammo->contents().contents() << "." << endl << endl;

		barrel_type Barrel(*Ammo, 300.0f, "Rifle Barrel");
		chamber_type Chamber(*Ammo, "9x19mm Chamber");
		break_rifle Rifle(Chamber, Barrel);
		cout << "Successfully created " << Barrel.name() << " to fire them from." << endl << endl;

		for (;;) {
			auto Cartridge = Ammo->extract();
			if (!Cartridge) {
				cout << "Left with " << Ammo->name() << endl << endl;
				break;
			}
			cout << "Removed " << Cartridge->name() << " from ammo box." << endl;
			Rifle.open();
			Rifle.load(move(Cartridge));
			Rifle.close();
			Rifle.cock();
			Rifle.fire();
			Cartridge = Rifle.open();

			cout << Cartridge->name() << " now comprises of:" << endl << Cartridge->contents() << "." << endl << endl;
		}
	} catch (string Error) {
		cout << "ERROR: " << Error << endl << endl;
	}
	system("pause");
	return 0;
}