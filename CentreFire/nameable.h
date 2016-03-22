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
			for (;;) {
				Str += (*It)->name();
				It++;
				if (It == Nameables.end()) {
					break;
				}
				if (std::next(It) != Nameables.end()) {
					Str += ", ";
				} else {
					Str += " and ";
				}
			}
		}
		return Str;
	}
};