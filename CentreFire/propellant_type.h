#pragma once
#include "named.h"
#include "unsigned_float.h"

class propellant_type :
	public named {
public:
	propellant_type(float EnergyDensity, std::string Name = "Unnamed Propellant");
	propellant_type(const propellant_type &) = delete;
	propellant_type & operator= (const propellant_type &) = delete;
public:
	unsigned_float energyDensity() const;
private:
private:
	const unsigned_float _EnergyDensity;
public:
	static bool unitTest();
};