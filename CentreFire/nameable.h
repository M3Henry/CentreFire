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

			int i = 0;
			//capture first element
			Str = Nameables[i++];

			//capture middle elements, if any
			while (i < Nameables.Size()-2){
				Str += ", " + Nameables[i++]->name();
			}
			//capture last element, if different to first
			if (Nameables.Size() > 1){
				Str += " and " +Nameables[i];
			}
		}
		return Str;
	}
};