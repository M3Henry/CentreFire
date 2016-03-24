#pragma once
#include "magazine_type.h"
#include "loadable.h"
#include <stack>
class magazine :
	public nameable,
	loadable <cartridge> {
public:
	typedef std::unique_ptr<magazine> instance;
public:
	magazine(const magazine_type &);
	magazine(const magazine &) = delete;
	magazine operator=(const magazine &) = delete;
public:
	operator const magazine_type &() const;
	std::string name() const;
	bool empty() const;
	bool full() const;
public:
	cartridge::instance load(cartridge::instance);
	cartridge::instance unload();
private:
	const magazine_type & _Type;
	std::stack<cartridge::instance> Stack;
};