#pragma once
#include "named.h"
#include "bullet_type.h"
#include "primer_type.h"

class case_type :
	public named {
public:
	case_type(const calibre &, float PrimerDiameter, float Volume, std::string Name = "Unnamed Case");
	case_type(const case_type &) = delete;
	case_type & operator= (const case_type &) = delete;
public:		//	Methods
	bool accepts(const calibre &) const;
	bool accepts(const primer_type &) const;
	const calibre & getCalibre() const;
	float volume() const;
	operator const calibre &() const;
	bool operator ==(const case_type & that) const;
	bool operator !=(const case_type & that) const;
private:	//	Helpers
private:	//	Members
	const calibre & _Calibre;
	const float _PrimerDiameter;
	const float _Volume;
};