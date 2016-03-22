#include "propellant_type.h"
#include <array>
#include <iostream>

propellant_type::propellant_type(float EnergyDensity, std::string Name) :
_EnergyDensity(EnergyDensity), named(Name) {
}

unsigned_float propellant_type::energyDensity() const {
	return _EnergyDensity;
}

bool propellant_type::unitTest() {
	using namespace std;
	bool Passed = true;
	array<const float, 3> EnergyDensities = { 1.0f, 0.0f, -1.0f };
	array<const bool, 3> ExpectThrows = { false, true, true };
	auto It = ExpectThrows.begin();
	for (auto & Energy : EnergyDensities) {
		try {
			propellant_type Test(Energy, "propellant_type");
			if (*It) {
				Passed = false;
				cout << "propellant_type failed to throw";
			}
			if (Test.energyDensity() != Energy) {
				Passed = false;
				cout << "propellant_type failed to return correct energyDensity" << endl;
			}
		} catch (string Error) {
			if (!(*It)) {
				Passed = false;
				cout << "propellant_type threw [" << Error << "] incorrectly." << endl;
			}
		}
		It++;
	}
	cout << "propellant_type " << (Passed ? "PASSED" : "FAILED") << " unit test." << endl;
	return Passed;
}