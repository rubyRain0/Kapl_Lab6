#include "Cargo_car.h"

CargoCar::CargoCar(string brand, Type type, int tonnage, string number, string name, string surname, string patronymic) 
	: Car(brand, number, name, surname, patronymic), tonnage(tonnage), type(type) {}

int CargoCar::getTonnage()
{
	return tonnage;
}

Type CargoCar::getType()
{
	return type;
}

string CargoCar::getStringType() const
{
    string str;
    switch (type)   
    {
    case Cistern:
        str = "Cistern";
    case Van:
        str = "Van";
    case Flatbed:
        str = "Flatbed";
    }
    return str;
}

Type CargoCar::stringToType(string str)
{
    Type type = Cistern;
    if (str == "Cistern")
        type = Cistern;
    else if (str == "Van")
        type = Van;
    else if (str == "Flatbed")
        type = Flatbed;
    return type;
}

void CargoCar::print() const
{
    cout << "Cargo car: " << "\n" << getBrand() << " " << getNumber() << "\n" << "Tonnage: " << tonnage << "\n" << "Type: " << getStringType() << "\n" << getFIO() << "\n\n";
}
