#include <iostream>
#include <ostream>
#pragma once
class Vector
{
    int *v;
    int dim;
    public:
        explicit Vector(int dim=1,int data=0);
        Vector(const Vector& ve);
        virtual ~Vector();
        int getSize() const;
        int* getElem() const;
        friend void swap(Vector &nr1,Vector &nr2);
        friend std::ostream& operator<<(std::ostream &output,const Vector&ve);
        friend std::istream& operator>>(std::istream &input, Vector&ve);


        Vector& operator = (Vector Copy);

};
