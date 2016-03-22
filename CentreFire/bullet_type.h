#pragma once
#include "named.h"
#include "calibre.h"

class bullet_type :
	public named {
public:		//	Memory
	bullet_type(const calibre &, float Mass, std::string Name = "Unnamed Bullet");
	bullet_type(const bullet_type &) = delete;
	bullet_type & operator= (const bullet_type &) = delete;
public:		//	Methods
	const calibre & getCalibre() const;
	operator const calibre &() const;
	unsigned_float mass() const;
private:	//	Helpers
private:	//	Members
	const calibre & _Calibre;
	const unsigned_float _Mass;
};