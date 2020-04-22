#include <iostream>
#include <ostream>
#pragma once
class Graf
{
    protected:
    int nr_noduri;
    public:
        explicit Graf(int nr_noduri=1);
        virtual ~Graf();
        virtual void pure_virutal(int nrvirtual)=0;
        Graf(const Graf& g);
        friend void swap(Graf &nr1,Graf &nr2);

};
