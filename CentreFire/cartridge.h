#pragma once
#include "case_type.h"
#include "propellant_type.h"
#include "primer.h"
#include <tuple>
#include <memory>

class cartridge :
	public named {
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
	std::unique_ptr<cartridge> clone() const;
	bool hasBullet() const;
	bool hasPropellant() const;
	bool hasPrimer() const;
	std::string contents() const;
	operator const case_type &() const;
	operator const calibre &() const;
public:		//	Modifiers
	bool insertBullet(const bullet_type * &);
	const bullet_type * releaseBullet();
	bool insertPrimer(std::unique_ptr<primer> &);
	std::unique_ptr<primer> releasePrimer();
	std::tuple<const bullet_type *, float> strike(float = 0.0f);
private:	//	Helpers
private:	//	Members
	const case_type & _Case;
	const propellant_type * _Propellant;
	const bullet_type * _Bullet;
	std::unique_ptr<primer> _Primer;
};