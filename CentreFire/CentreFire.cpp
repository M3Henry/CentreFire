// CentreFire.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ammo_factory.h"
#include <Windows.h>
#include <iostream>
#include "gun.h"
#include "break_action.h"

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
		break_action BreakerTemplate(Chamber);
		gun Rifle(BreakerTemplate, Barrel, "Sporter");
		cout << "Successfully created " << Rifle.name() << " to fire them from." << endl << endl;
		
		while (auto Cartridge = Ammo->extract()) {
			cout << "Removed " << Cartridge->name() << " from ammo box." << endl;
			if (auto Breaker = Rifle.action<break_action>()) {
				Breaker->open();
				Cartridge = Breaker->load(move(Cartridge));
				if (Cartridge) {
					cout << "I still have a " << Cartridge->name() << " in-hand?" << endl;
				}
				Breaker->close();
				Breaker->cock();
				Rifle.fire();
				Cartridge = Breaker->open();
				if (Cartridge) {
					cout << "Took a " << Cartridge->contents() << " from " << Rifle.name() << endl << endl;
				}
			} else {
				cout << "I don't know what to do with non break-action!" << endl;
				break;
			}
		}
		cout << "Left with " << Ammo->name() << endl << endl;
	} catch (string Error) {
		cout << "ERROR: " << Error << endl << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	system("pause");
	exit(EXIT_SUCCESS);
}