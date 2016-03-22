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
			auto Begin = Nameables.begin();
			auto End = Nameables.end();
			auto It = Begin;
			//capture first element
			Str = (*It++)->name();
			//capture middle elements, if any
			while (distance(It, End) > 1) {
				Str += ", " + (*It++)->name();
			}
			//capture last element, if different to first
			if (Begin != It && It != End) {
				Str += " and " + (*It)->name();
			}
			
		}
		return Str;
	}
};