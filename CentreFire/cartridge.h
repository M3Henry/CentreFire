#pragma once
#include "case_type.h"
#include "propellant_type.h"
#include "primer.h"
#include <tuple>
#include <memory>

class cartridge :
	public named {
public:		//	Typedefs
	typedef std::tuple<const bullet_type *, float> ejecta;
	static const ejecta NO_EJECTA;
	typedef std::unique_ptr<cartridge> instance;
public:		//	Memory
	explicit cartridge(const case_type &,
		const primer * = nullptr,
		const propellant_type * = nullptr,
		const bullet_type * = nullptr,
		std::string = "Unnamed Cartidge");
	cartridge & operator= (const cartridge &) = delete;
private:
	cartridge(const cartridge &);
public:		//	Methods
	cartridge::instance clone() const;
	bool hasBullet() const;
	bool hasPropellant() const;
	bool hasPrimer() const;
	std::string contents() const;
	operator const case_type &() const;
	operator const calibre &() const;
public:		//	Modifiers
	bool insert(const bullet_type * &);
	const bullet_type * releaseBullet();
	bool insert(std::unique_ptr<primer> &);
	std::unique_ptr<primer> releasePrimer();
	ejecta strike(float = 0.0f);
private:	//	Helpers
private:	//	Members
	const case_type & _Case;
	const propellant_type * _Propellant;
	const bullet_type * _Bullet;
	std::unique_ptr<primer> _Primer;
};