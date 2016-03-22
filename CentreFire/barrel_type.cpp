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

void barrel_type::fire(std::tuple<const bullet_type *, float> Ejecta) const {
	using namespace std;
	auto Bullet = get<0>(Ejecta);
	auto Energy = get<1>(Ejecta);
	if (Bullet != nullptr) {
		cout << "Bang, plink." << endl;
	} else if (Energy > 0.0f) {
		cout << "Bang." << endl;
	}
}