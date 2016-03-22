#pragma once
#include "nameable.h"
#include "unsigned_float.h"

class calibre :
	public nameable {
public:
	explicit calibre(float);
	calibre(const calibre &) = delete;
	calibre & operator=(const calibre &) = delete;
public:
	bool operator==(const calibre &) const;
	bool operator!=(const calibre &) const;
	std::string name() const;
private:
	const unsigned_float _Diameter;
};