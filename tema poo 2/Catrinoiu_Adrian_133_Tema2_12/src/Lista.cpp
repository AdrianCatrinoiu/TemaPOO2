#include "Lista.h"
#include "Vector.h"
#include <iostream>
using std::swap;
Lista::Lista(int lsize): lsize{lsize}
{
    l=new Vector[lsize];
    Vector lista(1,1);            //Vector(dimensiune,info)
    for (int i=0;i<lsize;i++)
        l[i]=lista;
}
Lista::Lista(const Lista&li)
{
    lsize=li.lsize;
    l=new Vector[lsize];
    for(int i=0;i<lsize;i++)
        l[i]=li.l[i];
}
void swap(Lista &nr1,Lista &nr2)
{
    swap(nr1.lsize,nr2.lsize);
    swap(nr1.l,nr2.l);
}
std::istream& operator>>(std::istream &input, Lista &li)
{
    input>>li.lsize;
    li.l=new Vector[li.lsize];
    for(int i=0;i<li.lsize;i++)
        input>>li.l[i];
    return input;
}
std::ostream& operator<<(std::ostream &output,const Lista &li)
{
    int i;
    for(i=0;i<li.lsize;i++)
    {
        output<<li.l[i]<<'\n';
    }
    return output;
}
Lista & Lista::operator=(Lista Copy)
{
    if(this!=&Copy)
        swap(*this,Copy);
    return *this;
}
Lista::~Lista()
{
    lsize=0;
    delete []l;
}
int Lista ::getLSize()const
{
    return lsize;
}
Vector* Lista ::getV() const
{
    return l;
}
/*void Lista::add_edge(int origin,int destin)
{
    try
    {
        if( origin > n || destin > n || origin < 0 || destin < 0)
            {
                throw my_exceptions("Muchie invalida");
            }
            else
            {
                l[origin].push_back(destin);
                l[destin].push_back(origin);

            }
    }catch(my_exceptions c){}
}*/
