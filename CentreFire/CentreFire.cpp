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
		break_action Breaker(Chamber);
		gun Rifle(Breaker, Barrel, "Sporter");
		cout << "Successfully created " << Rifle.name() << " to fire them from." << endl << endl;
		
		while (auto Cartridge = Ammo->extract()) {
			cout << "Removed " << Cartridge->name() << " from ammo box." << endl;
			receiver & Receiver = Rifle;
			if (typeid(break_action) == Receiver) {
				break_action & Action = static_cast<break_action &>(Receiver);
				Action.open();
				Action.load(move(Cartridge));
				Action.close();
				Action.cock();
				Rifle.fire();
				Cartridge = Action.open();
			} else {
				cout << "Don't know what to do with non break-action" << endl;
			}
			cout << Cartridge->name() << " now comprises of:" << endl << Cartridge->contents() << "." << endl << endl;
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