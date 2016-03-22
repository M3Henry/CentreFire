#pragma once
#include "primer_type.h"
#include <memory>

class primer :
	
	public nameable {
public:
	explicit primer(const primer_type &, bool New = true);
	primer(const primer &) = delete;
	primer & operator= (const primer &) = delete;
public:
	std::unique_ptr<primer> clone() const;
	const primer_type & type() const;
	std::string name() const;
	operator const primer_type&() const;
public:
	bool strike(float Impulse);
private:
	const primer_type & _Type;
	bool _New;
};