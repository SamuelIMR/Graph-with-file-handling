#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"
#include "Futbol.h"
#include <iostream>
#include <fstream>

class Grafo
{
    public:
        Grafo():headV{nullptr}{}
        Grafo(Vertice *ptr):headV{ptr}{}

        Vertice *headV;

        void insertarVer(Vertice);
        void insertarVerArchivo(Vertice);
        void insertarAri(int,int, int);
        void insertarAriArchivo(int,int, int);

        void eliminarVer(int);
        void eliminarAris(int, int);

        bool exiVer(int);
        bool exiAri(int, int);

        void mostrarG();

        Vertice *getVerID(int);
        Vertice *getprevVer(Vertice *);

        void recuperar();
        void guardarV(Vertice*);
        void guardarA(int, int, int);


};

#endif // GRAFO_H
