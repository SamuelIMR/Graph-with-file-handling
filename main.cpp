#include <iostream>
#include "Grafo.h"
#include "Futbol.h"
#include "Nodo.h"

using namespace std;

void menu();

int main()
{
    menu();
    return 0;
}


void menu()
{
    int opc;
    Grafo *g = new Grafo(nullptr);
    //Vertice v;
    Futbol f;
    string name, pais;
    int id, age;
    int idVer;
    int idOri, idDest, peso;
    int org, dst;

    do{

        system("cls");
        cout<< "\t-*-*-*-*-MENU-*-*-*-*-"<<endl;
        cout<< "[1] Agregar Vertice "<<endl;
        cout<< "[2] Eliminar Vertice "<<endl;
        cout<< "[3] Agregar Arista"<<endl;
        cout<< "[4] Eliminar Arista"<<endl;
        cout<< "[5] Imprimir Grafo"<<endl;
        cout<< "[6] Recuperar"<<endl;
        cout<< "[7] Salir"<<endl;
        cout<< "Seleccione una opcion: ";
        cin>>opc;

        switch(opc){
            case 1:{
                cout<< "Ingrese id: ";
                cin>>id;
                cout<< "Ingrese nombre del jugador: ";
                cin>>name;
                f.setName(name);
                cout<< "Ingrese nacionalidad del jugador: ";
                cin>>pais;
                f.setPais(pais);
                cout<< "Ingrese edad del jugador: ";
                cin>>age;
                f.setAge(age);
                //f(name, pais, age);
                Vertice v(id, f);
                g->insertarVer(v);
            }
                break;
            case 2:
                cout<< "Ingrese el Id del vertice a eliminar: ";
                cin>>idVer;
                g->eliminarVer(idVer);
                break;
            case 3:
                cout<< "Ingrese Id del origen: ";
                cin>>idOri;
                cout<< "Ingrese Id del destino: ";
                cin>>idDest;
                cout<< "Ingrese peso de la arista: ";
                cin>>peso;

                g->insertarAri(idOri, idDest, peso);

                break;
            case 4:
                cout<< "Ingrese Id del vertice origen: ";
                cin>>org;
                cout<< "Ingrese Id del vertice destino: ";
                cin>>dst;
                g->eliminarAris(org, dst);
                break;
            case 5:
                g->mostrarG();
                system("pause");
                break;
            case 6:
                g->recuperar();
                cout<< "Recuperando datos...";
                system("pause");
                break;
            case 7:
                break;
        }

    }while(opc!=7);
}
