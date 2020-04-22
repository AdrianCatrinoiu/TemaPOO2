#include <istream>
#include <ostream>
#include <iostream>
#include "Lista.h"
#include "Graf_Neorientat.h"
Graf_Neorientat :: Graf_Neorientat(int nr, Lista lista) : Graf{nr}, L{lista}
{

}


std ::istream& operator>>(std :: istream& in, Graf_Neorientat &src){

    in >> src.nr_noduri;
    in >> src.L;
    return in;
}

std :: ostream& operator<<(std::ostream& out,const Graf_Neorientat &src){
    out << src.nr_noduri <<'\n';
    out << src.L;
    return out;
}

void swap(Graf_Neorientat &first, Graf_Neorientat &second){
    using std :: swap;
    swap(first.L, second.L);
}

Graf_Neorientat :: Graf_Neorientat(const Graf_Neorientat& src) : Graf{src}, L{src.L}
{

}

Graf_Neorientat &Graf_Neorientat ::operator=(Graf_Neorientat src){
    if (this != &src) {
        nr_noduri = src.nr_noduri;
        swap(src, *this);
    }
    return *this;
}

void Graf_Neorientat :: pure_virutal(int nrvirtual){    //Metoda care returneaza vectorul de tati

    int tata[100];
    int poz = nrvirtual-1;
    for (int i = 0; i < 100; i++)
        tata[i] = 0;
    tata[nrvirtual] = -1;
    int dimensiune_lista = L.getLSize();
    Vector* listele = L.getV();
    while (poz < dimensiune_lista) {
        int dimensiune_locala = listele[poz].getSize();
        int* elemente = listele[poz].getElem();
        for (int i = 0; i < dimensiune_locala; i++)
            if(tata[elemente[i]] == 0)
                tata[elemente[i]] = poz+1;
        poz++;
    }

    for (int i = 1; i <= dimensiune_lista; i++)
        if (tata[i] == -1)
            std :: cout << "Elementul " << i << " este radacina"<<'\n';
        else
            std :: cout << "Tatal lui " << i << " este " << tata[i] << '\n';
}

