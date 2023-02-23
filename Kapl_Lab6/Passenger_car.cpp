#include "Passenger_car.h"

PassengerCar::PassengerCar(string brand, string model, string type, string color, string number, string name, string surname, string patronimic) 
	: Car(brand, number, name, surname, patronimic), type(type), model(model), color(color) {}

string PassengerCar::getType()
{
	return type;
}

string PassengerCar::getModel()
{
	return model;
}

string PassengerCar::getColor()
{
	return color;
}

void PassengerCar::print() const
{
	cout << "Passenger car: " << "\n" <<  getBrand() << " " << model << " " << getNumber() << "\n" << "Type: " << type << "\n" << "Color: " << color << "\n" << getFIO() << "\n\n";
}
