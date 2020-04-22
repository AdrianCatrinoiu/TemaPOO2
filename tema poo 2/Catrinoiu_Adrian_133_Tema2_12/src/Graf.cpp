#include "Graf.h"
#include <iostream>
using std::swap;
Graf::Graf(int nr_noduri):nr_noduri{nr_noduri}
{

}

Graf::~Graf()
{
    nr_noduri=0;
}
Graf::Graf(const Graf &g)
{
    nr_noduri=g.nr_noduri;
}
void swap(Graf &nr1,Graf &nr2)
{
    swap(nr1.nr_noduri,nr2.nr_noduri);
}
void Graf :: pure_virutal(int nrvirtual){
    std :: cout << nrvirtual << '\n';
}
