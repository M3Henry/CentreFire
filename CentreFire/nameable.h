#pragma once
#include <string>
#include <vector>

class nameable {
public:
	virtual std::string name() const = 0;
public:
	static std::string englishList(std::vector<const nameable *> Nameables) {
		std::string Str;
		if (!Nameables.empty()) {
			auto It = Nameables.begin();
			auto End = Nameables.end();
			//capture first element
			Str = (*It++)->name();
			//capture middle elements, if any
			while (distance(It, End) > 1) {
				Str += ", " + (*It++)->name();
			}
			//capture last element, if different to first
			if (It != End) {
				Str += " and " + (*It)->name();
			}
			
		}
		return Str;
	}
};