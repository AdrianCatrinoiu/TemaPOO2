#include <iostream>
#include "Vector.h"
#include "Matrice.h"
#include "Lista.h"
#include "Graf.h"
#include "Graf_Orientat.h"
#include "Graf_Neorientat.h"
#include <fstream>
using namespace std;
ifstream fin("graf.in");
int main()
{
    int grafuri_neorientate, poz_nod_start, grafuri_orientate, matrice;
    fin >> grafuri_orientate >> grafuri_neorientate;
    cout<<"Clasa de grafuri neorientate\n";
    cout<<'\n';
    Graf_Neorientat* gn;
    gn = new Graf_Neorientat[grafuri_neorientate];
    for (int i = 0; i < grafuri_neorientate; i++)
    {
        fin>>poz_nod_start;
        fin>>gn[i];
        gn[i].pure_virutal(poz_nod_start);
    }
    cout<<'\n';
    cout<<"Clasa de grafuri orientate\n";
    cout<<'\n';
    Graf_Orientat* go;
    go = new Graf_Orientat[grafuri_orientate];
    for (int i = 0; i < grafuri_orientate; i++)
    {
        fin >> poz_nod_start;
        fin >> go[i];
        try {
                matrice = go[i].verifgraf();
                throw matrice;
        }
        catch(int matrice)
        {   if (matrice == 0)
                cout << "Matrice de adiacenta invalida ";
            else
                go[i].pure_virutal(poz_nod_start);
        }

    }
    return 0;
}
