#include "Graf_Orientat.h"
using std::swap;
Graf_Orientat::Graf_Orientat(int nr, Matrice matrice): Graf{nr},A{matrice}
{

}
Graf_Orientat :: Graf_Orientat(const Graf_Orientat& go) : Graf{go}, A{go.A}
{

}
std::ostream& operator <<(std::ostream &output, const Graf_Orientat &go)
{
    output << go.nr_noduri <<'\n';
    output << go.A <<'\n';
    return output;
}
std::istream& operator >>(std::istream &input, Graf_Orientat &go)
{
    input >> go.nr_noduri;
    input >> go.A;
    return input;
}
void swap(Graf_Orientat &nr1,Graf_Orientat &nr2)
{
    swap(nr1.A,nr2.A);
}
Graf_Orientat &Graf_Orientat ::operator=(Graf_Orientat Copy){
    if (this != &Copy) {
        nr_noduri = Copy.nr_noduri;
        swap(Copy, *this);
    }
    return *this;
}
int nod_nevizitat(int v[], int n){
    for (int i = 0; i < n; i++)
        if (v[i] == 0)
            return i;
    return -1;
}
void bfs(int** a, int n, int ns, int* viz)
{
    viz[ns] = 1;
    int p = 1;
    int u = 1;
    int c[100];
    c[u] = ns;
    while (p <= u) {
        for(int i = 0; i < n; i++)
            if(a[c[p]][i] == 1 && viz[i] == 0)
            {
                u++;
                c[u] = i;
                viz[i] = 1;
            }
        p++;
    }
}
void Graf_Orientat :: pure_virutal(int nrvirtual){
    int vizitat[100];
    for (int i = 0; i <= 100; i++)
        vizitat[i] = 0;
    int m = A.getLinie();
    int n = A.getCol();
    int **matrice = A.getMatrice();
    bfs(matrice, n, nrvirtual, vizitat);
    if (nod_nevizitat(vizitat, m))
        std :: cout << "Graful nu este conex\n";
    else
        std :: cout << "Graful este conex\n";

}
int Graf_Orientat :: verifgraf(){
    int m = A.getCol();
    int n = A.getLinie();
    if (m != n)
        return 0;
    return 1;
}
