#include "Grafo.h"


void Grafo::insertarVer(Vertice nver)
{
    bool band(exiVer(nver.id));
    if(band)
        cout<< "El vertice ya existe"<<endl;
    else{
        if(headV==nullptr){
            headV= new Vertice(nver);
            guardarV(headV);
        }
        else{
            Vertice *aux= new Vertice(nver);
            aux->sigV=headV;
            headV=aux;
            guardarV(aux);
        }
        cout<< "Vertice agregado"<<endl;
    }
}

void Grafo::insertarVerArchivo(Vertice nver)
{
    bool band(exiVer(nver.id));
    if(band)
        cout<< "El vertice ya existe"<<endl;
    else{
        if(headV==nullptr){
            headV= new Vertice(nver);
        }
        else{
            Vertice *aux= new Vertice(nver);
            aux->sigV=headV;
            headV=aux;
        }
        cout<< "Vertice agregado"<<endl;
    }
}

void Grafo::insertarAri(int org, int dst, int peso)
{
    bool band1=exiVer(org);
    bool band2=exiVer(dst);

    if(band1 && band2)
    {
        bool band3=exiAri(org, dst);

        if(band3)
        {
            cout<< "La arista entre "<< getVerID(org)->f.getName()<< " y "<< getVerID(dst)->f.getName() << " ya existe"<<endl;
        }
        else{

            Vertice *aux=headV;
            Vertice *origen=getVerID(org);
            Vertice *destino=getVerID(dst);
            while(aux)
            {
                if(aux->id==org){
                    Arista *tmp= new Arista(dst, peso, origen->headA);
                    origen->headA=tmp;
                }
                else if(aux->id==dst){
                    Arista *tmp= new Arista(org, peso, destino->headA);
                    destino->headA=tmp;
                }
                aux=aux->sigV;
            }
            guardarA(org,dst,peso);
            cout<<"Arista agregada correctamente"<<endl;
        }
    }
}


void Grafo::insertarAriArchivo(int org, int dst, int peso)
{
    bool band1=exiVer(org);
    bool band2=exiVer(dst);

    if(band1 && band2)
    {
        bool band3=exiAri(org, dst);

        if(band3)
        {
            cout<< "La arista entre "<< getVerID(org)->f.getName()<< " y "<< getVerID(dst)->f.getName() << " ya existe"<<endl;
        }
        else{

            Vertice *aux=headV;
            Vertice *origen=getVerID(org);
            Vertice *destino=getVerID(dst);
            while(aux)
            {
                if(aux->id==org){
                    Arista *tmp= new Arista(dst, peso, origen->headA);
                    origen->headA=tmp;
                }
                else if(aux->id==dst){
                    Arista *tmp= new Arista(org, peso, destino->headA);
                    destino->headA=tmp;
                }
                aux=aux->sigV;
            }
            cout<<"Arista agregada correctamente"<<endl;
        }
    }
}


void Grafo::eliminarAris(int org, int dst)
{
    bool band= exiAri(org, dst);
    Vertice *origen;
    Vertice *destino;
    Arista *ariorigen;
    Arista *aridestino;
    if(band)
    {
        //Origen-destino
        origen=getVerID(org);
        ariorigen=origen->getArisId(dst);
        if(ariorigen==origen->headA){
            origen->headA=origen->headA->sigA;
        }
        else{
            origen->getPrev(ariorigen)->sigA=ariorigen->sigA;
        }
        delete ariorigen;

        //Destino-origen
        destino=getVerID(dst);
        aridestino=destino->getArisId(org);

        if(aridestino==destino->headA){
            destino->headA=destino->headA->sigA;
        }
        else{
            destino->getPrev(aridestino)->sigA=aridestino->sigA;
        }
        delete aridestino;
    }
}

void Grafo::eliminarVer(int vId)
{
    Vertice *aux= headV;
    Vertice *tmp= getVerID(vId);

    while(aux)
    {
        if(aux->id != vId){
            eliminarAris(aux->id, vId);
        }
        aux=aux->sigV;
    }

    if(getprevVer(tmp)){
        getprevVer(tmp)->sigV= tmp->sigV;
    }
    else{
        headV= tmp->sigV;
    }
    delete tmp;
}
/*
Vertice *Grafo::buscarVer(string nom)
{
    Vertice *tmp= headV;
    while(tmp)
    {
        if(tmp->f.name==nom)
            return tmp;
        else
            tmp=tmp->sigV;
    }
    return nullptr;
}
*/
void Grafo::mostrarG()
{
    Vertice *tmpV=headV;

    while(tmpV)
    {
        cout<<tmpV->f.getName()<< " ("<<tmpV->id<<") -->";
        tmpV->printAris();
        cout<<endl;
        tmpV=tmpV->sigV;
    }
}

Vertice *Grafo::getprevVer(Vertice *v)
{
    if(v==headV){
        return nullptr;
    }
    Vertice *aux=headV;
    while(aux && aux->sigV != v){
        aux=aux->sigV;
    }
    return aux;
}

Vertice *Grafo::getVerID(int verid)
{
    Vertice *aux=headV;
    while(aux)
    {
        if(aux->id==verid)
            return aux;
        aux=aux->sigV;
    }
    return nullptr;
}

bool Grafo::exiVer(int verid)
{
    Vertice *aux=headV;             //Utilizamos un puntero de tipo vertice aux y lo igualamos al inicio de la lista de vertice
    while(aux)                      //Creamos un bucle y mientras el auxiliar exista compara el id del auxiliar con el id que estamos buscando
    {
        if(aux->id==verid)          //Si encuentra el el vertice retorna true
            return true;
        aux=aux->sigV;              //Recorremos la lista de vertices
    }
    return false;                   //Si no encuentra el dato retornamos false
}

bool Grafo::exiAri(int org, int dst)
{
    Vertice *aux= getVerID(org);        //Creamos un vertice auxiliar y lo igualamos al origen de la arista
    Arista *tmp=aux->headA;             //Tambien creamos un puntero de tipo Arista y lo igualamos al inicio de la lista de aristas del Vertice aux

    while(tmp)                          //Mientras el temporal exista compara el id del destino con el destino de la arista
    {
        if(tmp->destinoId==dst)         //Si es igual retorna true
            return true;
        tmp=tmp->sigA;                  //Recorre la lista de aristas
    }
    return false;                       //En caso de que no encuentra el destino regresa false
}

void Grafo::guardarV(Vertice *v)
{
    fstream archivo;
    archivo.open("file01.txt", ios::app);

    archivo<< "|#"<<v->id<<"|"<<v->f.getName()<<"|"<<v->f.getPais()<<"|"<<v->f.getAge()<<"*";
    archivo.close();
}

void Grafo::guardarA(int org, int dst, int peso)
{
    fstream archivo;
    archivo.open("file01.txt", ios::app);
    archivo<< "-#"<<org<<"-"<<dst<<"-"<<peso<< "*";
    archivo.close();
}

void Grafo::recuperar()
{
    ifstream archivo;
    string s_id, name, pais, s_age, s_ido, s_idd, s_peso;
    string c;
    int id, ido, idd, p, age;

    archivo.open("file01.txt");
    archivo.seekg(0, ios::end);
    int length=archivo.tellg();
    archivo.seekg(0, ios::beg);

    if(length==0){
        archivo.close();
        return;
    }
    else{
        while(!archivo.eof()){
            getline(archivo, c, '#');
            //mostrarG();
            if(c=="|"){
                getline(archivo,s_id, '|');
                getline(archivo,name, '|');
                getline(archivo,pais, '|');
                getline(archivo,s_age, '*');

                id=stoi(s_id);
                age=stoi(s_age);

                Futbol f(name,pais,age);
                Vertice v(id, f);

                insertarVerArchivo(v);
            }
            else{
                getline(archivo,s_ido, '-');
                getline(archivo,s_idd ,'-');
                getline(archivo,s_peso, '*');

                ido=stoi(s_ido);
                idd=stoi(s_idd);
                p=stoi(s_peso);

                insertarAri(ido, idd, p);
            }
        }
        archivo.close();
    }
}
