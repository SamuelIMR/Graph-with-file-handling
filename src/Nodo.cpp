#include "Nodo.h"

Vertice::Vertice()
{
    headA=nullptr;
    sigV=nullptr;
}

Vertice::Vertice(int vid, Futbol f)
{
    this->id=vid;
    this->f=f;
    this->headA=nullptr;
    this->sigV=nullptr;
}


Arista *Vertice::getPrev(Arista *a)
{
    if(a==headA)
        return nullptr;
    Arista *aux=headA;

    while(aux && aux->sigA != a)
    {
        aux=aux->sigA;
    }
    return aux;
}

Arista *Vertice::getArisId(int idDest)
{
     Arista *aux=headA;
     while(aux)
     {
         if(aux->destinoId==idDest)
            return aux;
         aux=aux->sigA;
     }
     return nullptr;

}

void Vertice::printAris()
{
    Arista *aux= headA;
    if(!aux)
        cout<< "| |";
    while(aux)
    {
        cout<< "| "<< aux->destinoId<< " ," << aux->peso<< " |";
        aux= aux->sigA;
    }
}

Arista::Arista()
{
    destinoId=-1;
    peso=-1;
    sigA=nullptr;
}

Arista::Arista(int desId, int p, Arista *a)
{
    destinoId=desId;
    peso=p;
    sigA=a;
}
