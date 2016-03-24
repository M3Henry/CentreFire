#pragma once
#include "receiver.h"
class revolver_single_action :
	public receiver {
public:
	revolver_single_action(const case_type &, size_t);
	revolver_single_action(const revolver_single_action &) = delete;
	revolver_single_action(revolver_single_action &&) = delete;
	const revolver_single_action & operator=(const revolver_single_action &) = delete;
	const revolver_single_action & operator=(revolver_single_action &&) = delete;
	receiver::instance clone() const;
public:
	void open();
	void close();
	cartridge::instance load(cartridge::instance);
	cartridge::instance unload();
	void unloadAll();
	void cock();
private:
	cartridge::ejecta fire();
private:
	std::vector<chamber::instance> _Cylinder;
	std::vector<chamber::instance>::iterator _FiringChamber;
	bool _Cocked;
	bool _Open;
};