#include "Futbol.h"

Futbol::Futbol()
{
    name="";
    pais="";
    age=0;
}

Futbol::Futbol(string name, string pais, int age)
{
    this->name=name;
    this->pais=pais;
    this->age=age;
}

void Futbol::setName(string n)
{
    this->name=n;
}

void Futbol::setPais(string p)
{
    this->pais=p;
}

void Futbol::setAge(int a)
{
    this->age=a;
}

string Futbol::getName()
{
    return name;
}

string Futbol::getPais()
{
    return pais;
}

int Futbol::getAge()
{
    return age;
}
