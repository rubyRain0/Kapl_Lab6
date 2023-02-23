#include "Car.h"

Car::Car(string brand, string number, string name, string surname, string patronymic) 
	: brand(brand), number(number), Name(name), Surname(surname), Patronymic(patronymic) {}

string Car::getBrand() const
{
	return brand;
}

string Car::getNumber() const
{
	return number;
}

string Car::getName() const
{
	return Name;
}

string Car::getSurname() const
{
	return Surname;
}

string Car::getPatronymic() const
{
	return Patronymic;
}

string Car::getFIO() const
{
	return Surname + " " + Name + " " + Patronymic;
}

void Car::setNumber(string number)
{
	this->number = number;
}

void Car::setName(string name)
{
	Name = name;
}

void Car::setSurname(string surname)
{
	Surname = surname;
}

void Car::setPatronymic(string patronymic)
{
	Patronymic = patronymic;
}

int Car::compare(const Car& obj) const
{
	int result = 1;
	if (brand < obj.brand)
		result = -1;
	else if (brand == obj.brand)
		result = 0;
	return result;
}

void Car::print() const
{
	cout << brand << " " << number << " " << Name << " " << Surname << " " << Patronymic << '\n';
}

