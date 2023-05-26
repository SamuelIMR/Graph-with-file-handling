#ifndef NODO_H
#define NODO_H
#include "Futbol.h"
using namespace std;
#include <iostream>
class Arista;

class Vertice
{
    public:
        Vertice();
        Vertice(int, Futbol);

        int id;
        Futbol f;
        Vertice *sigV;
        Arista *headA;

        Arista *getPrev(Arista*);
        Arista *getArisId(int);
        void printAris();



};

class Arista
{
    public:
        Arista();
        Arista(int, int, Arista*);

        int peso;
        int destinoId;
        Vertice *dest;
        Arista *sigA;


};

#endif // NODO_H
