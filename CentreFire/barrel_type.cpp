#include "barrel_type.h"
#include <iostream>

barrel_type::barrel_type(const calibre & Calibre, float Length, const std::string & Name) :
named(Name),
_Calibre(Calibre),
_Length(Length) {
}

barrel_type::operator const calibre &() const {
	return _Calibre;
}

void barrel_type::fire(ejecta Ejecta) const {
	using namespace std;
	auto Bullet = get<0>(Ejecta);
	auto Energy = get<1>(Ejecta);

	///TODO: move the endpoint handling of bullet into the gun
	if (Energy > 0.0f) {
		cout << "Bang";
		if (Bullet != nullptr) {
			cout << ", plink";
		}
		cout << "." << endl;
	}
}