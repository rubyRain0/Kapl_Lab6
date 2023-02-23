#pragma once
#include "Car.h"

class PassengerCar : public Car
{
private:
	string type;
	string model;
	string color;
public:
	PassengerCar(string brand = " ", string model = " ",
		string type = " ", string color = " ", string number = " ", 
		string name = " ", string surname = " ", string patronimic = " ");
	string getType();
	string getModel();
	string getColor();
	void print() const override;
};

