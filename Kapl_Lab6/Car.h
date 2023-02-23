#pragma once
#include <string>
#include <iostream>

using namespace std;

class Car
{
private:
	string brand;
	string number;
	string Name;
	string Surname;
	string Patronymic;
public:
	Car(string brand = " ", string number = " ", string name = " ", string surname = " ", string patronymic = " ");
	string getBrand() const;
	string getNumber() const;
	string getName() const;
	string getSurname() const;
	string getPatronymic() const;
	string getFIO() const;
	void setNumber(string number);
	void setName(string name);
	void setSurname(string surname);
	void setPatronymic(string patronymic);
	int compare(const Car& obj) const;
	virtual void print() const;
};


