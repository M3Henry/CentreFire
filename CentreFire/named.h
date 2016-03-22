#pragma once
#include "nameable.h"

class named : public nameable {
public:
	named(std::string = "Unnamed Thing");
public:
	std::string name() const;
private:
	const std::string _Name;
};