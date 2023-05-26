#ifndef FUTBOL_H
#define FUTBOL_H
#include <iostream>
using namespace std;

class Futbol
{
    public:
        Futbol();
        Futbol(string, string, int);

        void setName(string);
        void setPais(string);
        void setAge(int);

        string getName();
        string getPais();
        int getAge();

    private:
        int age;
        string name, pais;
};

#endif // FUTBOL_H
