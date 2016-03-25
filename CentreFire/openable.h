#pragma once
class openable {
public:
	openable();
public:
	bool open();
	bool close();
public:
	bool isOpen() const;
	bool isClosed() const;
private:
	bool _Open = false;
};