#pragma once
#include "Car.h"
#include <list>
#include <memory>
#include <functional>
#include <algorithm>

using uPtrCar = unique_ptr<Car>;
using carList = list<uPtrCar>;

class CarPark
{
private:
	carList List;
	string Name;
public:
	CarPark(string name = " ");
	string getName() const;
	void setName(string name);
	void addByOrder(uPtrCar car);
	void addToBegin(uPtrCar car);
	void addToEnd(uPtrCar car);
	void remove(const Car& car);
	void eraseIf(function<bool(const uPtrCar&)> lambda);
	void sort();
	void print();
	carList::iterator getBegin();
	carList::iterator getEnd();
};

