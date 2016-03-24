#pragma once
template <typename T>
class loadable {
public:
	virtual typename T::instance load(typename T::instance) = 0;
	virtual typename T::instance unload() = 0;
};

