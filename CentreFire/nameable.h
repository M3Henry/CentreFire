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

			size_t i = 0;
			//auto It = Nameables.begin();
			//capture first element
			Str = Nameables[i++]->name();
			//capture middle elements, if any
			while (i < Nameables.size()-1){
				Str += ", " + Nameables[i++]->name();
			}
			//capture last element, if different to first
			if (Nameables.size() > 1){
				Str += " and " + Nameables[i]->name();
			}
		}
		return Str;
	}
};