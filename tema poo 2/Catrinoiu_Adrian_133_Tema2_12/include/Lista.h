#include "Vector.h"
#pragma once

class Lista
{
    Vector *l;
    int lsize;
    public:
        explicit Lista(int lsize=1);
        ~Lista();
        friend void swap(Lista &nr1,Lista &nr2);
        int getLSize() const;
        Vector* getV() const;
        Lista(const Lista &li);
        friend std::ostream& operator<<(std::ostream&,const Lista&li);
        friend std::istream& operator>>(std::istream&, Lista&li);

        Lista& operator = ( Lista Copy);
};
