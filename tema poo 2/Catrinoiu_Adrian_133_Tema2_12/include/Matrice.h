#include <iostream>
#include <ostream>
#pragma once
class Matrice
{
    int **a;
    int m,n;
    public:
        explicit Matrice(int m=1,int n=1,int data=0);
        Matrice(const Matrice &ma);
        ~Matrice();
        friend void swap(Matrice &nr1,Matrice &nr2);
        int getLinie() const;
        int getCol() const;
        int** getMatrice() const;
        friend std::istream& operator>>(std::istream&input, Matrice &ma);
        friend std::ostream& operator<<(std::ostream&output, const Matrice &ma);
        Matrice& operator = (Matrice Copy);
};
