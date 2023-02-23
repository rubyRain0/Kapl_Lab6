#include <fstream>
#include "CarPark.h"
#include "Passenger_car.h"
#include "Cargo_car.h"
#include <Windows.h>

void parkFileInput(CarPark& park, ifstream& file)
{
	char t;
	string brand, number, name, surname, Patronymic;
	string model, type, color;
	int tonnage;
	while (file >> t)
	{
		file >> brand >> number >> surname >> name >> Patronymic;
		if (t == 'P')
		{
			file >> type >> model >> color;
			PassengerCar pCar = PassengerCar(brand, model, type, color, number, name, surname, Patronymic);
			park.addByOrder(move(make_unique<PassengerCar>(pCar)));
		}
		else if (t == 'C')
		{
			file >> type >> tonnage;
			CargoCar cCar = CargoCar(brand, CargoCar::stringToType(type), tonnage, number, name, surname, Patronymic);
			park.addByOrder(move(make_unique<CargoCar>(cCar)));
		}
	}
	file.close();
}

int task6(CarPark& park)
{
	carList::iterator carsIterator = park.getBegin();
	int cargoCounter = 0; string govNumber;
	bool hasNumberSeven;
	while (carsIterator != park.getEnd())
	{
		hasNumberSeven = false;
		CargoCar* cargoPtr = dynamic_cast<CargoCar*>(carsIterator->get());
		if(cargoPtr)
		{	
			govNumber = cargoPtr->getNumber();
			
			for (size_t i = 0; i < govNumber.length(); ++i)
			{
				if (govNumber[i] == '7')
					hasNumberSeven = true;
			}
		}
		if (hasNumberSeven && cargoPtr->getType() == Type::Cistern)
		{
			cargoCounter++;
		std::cout << govNumber << '\n';
		}
		carsIterator++;
	}
	return cargoCounter;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream file("data.txt");

	CarPark myCarParking;
	parkFileInput(myCarParking, file);

	myCarParking.print();
	cout << "==========================\n";

	int resultCounter = task6(myCarParking);
	if (resultCounter)
	{
		std::cout << resultCounter << " result(s) found!\n";
	}
	else std::cout << "No results were found..\n";

	std::cin.get();
	return 0;
}