#pragma once
#include "named.h"
#include "unsigned_float.h"

class primer_type :
	public named {
public:
	primer_type(float Diameter, float MinImpulse, const std::string & = "Unnamed Primer");
	primer_type(const primer_type &) = delete;
	primer_type & operator= (const primer_type &) = delete;
public:
	unsigned_float diameter() const;
	bool strike(float) const;
private:
private:
	const unsigned_float _MinImpulse;
	const unsigned_float _Diameter;
};