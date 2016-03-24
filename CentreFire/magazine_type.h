#pragma once
#include "cartridge.h"
class magazine_type :
	public named {
public:
	magazine_type(const case_type & CaseType, size_t Capacity);
	magazine_type(const magazine_type &) = delete;
	magazine_type operator=(const magazine_type &) = delete;
public:
	operator const case_type &() const;
	bool compatible(const magazine_type &) const;
	size_t capacity() const;
private:
	const size_t _Capacity;
	const case_type & _CaseType;
};

