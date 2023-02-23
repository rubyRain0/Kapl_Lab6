#pragma once
#include "Car.h"

enum Type { 
	Cistern, Van, Flatbed 
};

class CargoCar : public Car
{
private:
	int tonnage;
	Type type;
public:
	CargoCar(string brand = " ", Type type = Cistern, int tonnage = 0, string number = " ", string name = " ", string surname = " ", string patronymic = " ");
	int getTonnage();
	Type getType();
	string getStringType() const;
	static Type stringToType(string str);
	void print() const override;
};

