#include "CarPark.h"

CarPark::CarPark(string name) : Name(name) {}

string CarPark::getName() const
{
	return Name;
}

void CarPark::setName(string name)
{
	Name = name;
}

void CarPark::addByOrder(uPtrCar car)
{
	auto i = List.begin();
	while (i != List.end() && (*i)->compare(*car) == -1)
		++i;
	List.insert(i, move(car));
}

void CarPark::addToBegin(uPtrCar car)
{
	List.push_front(move(car));
}

void CarPark::addToEnd(uPtrCar car)
{
	List.push_back(move(car));
}

void CarPark::remove(const Car& car)
{
	for (auto i = List.begin(); i != List.end();)
		if ((*i)->compare(car) == 0)
			i = List.erase(i);
		else ++i;
}

void CarPark::eraseIf(function<bool(const uPtrCar&)> lambda)
{
	auto i = remove_if(List.begin(), List.end(), lambda);
	List.erase(i, List.end());
}

void CarPark::sort()
{
	List.sort([](const uPtrCar& pCar1, const uPtrCar& pCar2) {return pCar1->compare(*pCar2) == -1; });
}

void CarPark::print()
{
	for (const uPtrCar& p_Car : List)
	{
		p_Car->print();
	}
}

carList::iterator CarPark::getBegin()
{
	return List.begin();
}

carList::iterator CarPark::getEnd()
{
	return List.end();
}
