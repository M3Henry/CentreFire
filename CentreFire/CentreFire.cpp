// CentreFire.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include "ammo_factory.h"
#include <Windows.h>
#include <iostream>
#include "gun.h"
#include "break_action.h"
#include "bolt_action.h"

int _tmain(int argc, _TCHAR* argv[]) {
	using namespace std;
	bool Passed = propellant_type::unitTest();
	if (!Passed) {
		return 1;
	}
	try {
		ammo_factory Factory;
		auto Ammo = Factory.make();
		cout << endl << "Successfully created " << Ammo->name() << " cartridges comprising:" << endl << "  " << Ammo->contents().contents() << "." << endl;

		barrel_type Barrel(*Ammo, 300.0f, "Rifle Barrel");
		//break_action BreakerTemplate(*Ammo);
		//gun Rifle(BreakerTemplate, Barrel, "Sporter");
		magazine_type BoxMag(*Ammo, 5);
		bolt_action BolterTemplate(BoxMag);
		gun Rifle(BolterTemplate, Barrel, "Karabiner 98 kurz");
		cout << "Successfully created " << Rifle.name() << " to fire them from." << endl << endl;
		if (auto Bolter = Rifle.action<bolt_action>()) {
			Bolter->open();
		}
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
					cout << "A " << Cartridge->contents() << " flew from " << Rifle.name() << endl;
				}
			} else if (auto Bolter = Rifle.action<bolt_action>()) {
				Cartridge = Bolter->load(move(Cartridge));
				if (Cartridge) {
					cout << "I still have a " << Cartridge->name() << " in-hand?" << endl;
				}
			} else {
				cout << "I don't know what to do with non break-action!" << endl;
				break;
			}
		}
		if (auto Bolter = Rifle.action<bolt_action>()) {
			for (unsigned int I = 0; I < 5; ++I) {
				Bolter->close();
				Rifle.fire();
				auto Cartridge = Bolter->open();
				if (Cartridge) {
					cout << "A " << Cartridge->contents() << " flew from " << Rifle.name() << endl;
				}
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