#include "Matrice.h"
#include <iostream>


Matrice :: Matrice(int m, int n, int data) : m{m}, n{n} {
    a = new int* [m];
    for (int i = 0; i < m; i++)
        a[i] = new int [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = data;
}

Matrice ::~Matrice() {
    for (int i = 0; i < m; i++)
        delete [] a[i];
    delete [] a;
    m = 0;
    n = 0;

}

Matrice ::Matrice(const Matrice &ma) {
    m = ma.m;
    n = ma.n;
    a = new int* [m];
    for (int i = 0; i < m; i++)
        a[i] = new int [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = ma.a[i][j];

}

void swap(Matrice &nr1, Matrice &nr2){
    using std :: swap;
    swap(nr1.m, nr2.m);
    swap(nr1.n, nr2.n);
    swap(nr1.a,nr2.a);
}

std :: istream &operator >>(std :: istream &input, Matrice &ma){
    for (int i = 0; i < ma.m; i++)
        delete [] ma.a[i];
    delete [] ma.a;
    input >> ma.m >> ma.n;
    ma.a = new int* [ma.m];
    for (int i = 0; i < ma.n; i++)
        ma.a[i] = new int [ma.n];
    for (int i = 0; i < ma.m; i++)
        for (int j = 0; j < ma.n; j++)
            input >> ma.a[i][j];
    return input;
}

std :: ostream &operator <<(std :: ostream &output, const Matrice &ma){
    for (int i = 0; i < ma.m; i++){
        for (int j = 0; j < ma.n; j++)
            output << ma.a[i][j] << " ";
        output << '\n';
    }
    return output;
}

Matrice  &Matrice :: operator =(Matrice ma){
    if(this != &ma)
        swap(*this, ma);
    return *this;

}

int Matrice :: getLinie() const {
    return m;
}

int Matrice :: getCol() const {
    return n;
}

int ** Matrice :: getMatrice() const {
    return a;
}
/*
Matrice::Matrice(const Matrice &ma)
{
    if(this!=&ma)
    {
        this->n=ma.n;
        this->a=new int*[ma.n];
        for(int i=0;i<ma.n;i++)
        {
            this->a[i]=new int[this->n];
            for(int j=0;j<ma.n;j++)
                this->a[i][j]=ma.a[i][j];
        }
    }
}
void Matrice::add_edge(int origin,int destin)
{
    try
    {
        if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                throw my_exceptions("Muchie invalida");
            }
            else
            {
                a[origin][destin] = 1;
            }
    }catch(my_exceptions b){}
}
std::istream& operator>>(std::istream &input, Matrice &mat)
{
    int origin,destin;
    std::cout<<"Numar Noduri:";
    input>>mat.n;
    std::cout<<"Numar Muchii:";
    input>>mat.m;
    for(int i=0;i<mat.m;i++)
    {
        std::cout<<"Nod 1:";
        input>>origin;
        std::cout<<"Nod 2:";
        input>>destin;
        mat.add_edge(origin,destin);
    }
    return input;
}
std::ostream& operator<<(std::ostream &output, Matrice &mat)
{
    int i,j;
    for(i=0;i<mat.n;i++)
    {
        for(j=0;j<mat.n;j++)
            std::cout<<mat.a[i][j]<<" ";
            std::cout<<'\n';
    }
    return output;
}
Matrice & Matrice::operator=(const Matrice &Copy)
{
    this->n=Copy.n;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            this->a[i][j]=Copy.a[i][j];
    return *this;
}
Matrice::~Matrice()
{
    for(int i=0;i<n;i++)
        delete [] a[i];
    delete [] a;
    n=0;
}*/
