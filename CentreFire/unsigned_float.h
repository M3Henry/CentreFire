#pragma once

class unsigned_float {
public:
	explicit unsigned_float(float Source) :
	_Value(Source) {
		if (_Value <= 0.0f) {
			throw(std::string("unsigned_float must have positive value!"));
		}
	}

	operator float() const {
		return _Value;
	}

	bool operator==(const unsigned_float & that) const {
		return _Value == that._Value;
	}
	bool operator!=(const unsigned_float & that) const {
		return !(*this == that);
	}

private:
	float _Value;
};