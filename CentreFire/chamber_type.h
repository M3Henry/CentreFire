#pragma once
#include "case_type.h"

class chamber_type :
	public named {
public:
	chamber_type(const case_type &, std::string);
public:
	operator const case_type &() const;
private:
	const case_type & _Case;
};

