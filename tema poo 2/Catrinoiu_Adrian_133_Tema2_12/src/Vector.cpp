#include "Vector.h"
using std::swap;
Vector::Vector(int dim, int data): dim{dim}
{
    v=new int[dim];
    for(int i=0;i<dim;i++)
        v[i]=data;
}
Vector :: Vector(const Vector &ve)
{
    dim=ve.dim;
    v=new int[dim];
    for(int i=0;i<dim;i++)
        v[i]=ve.v[i];
}
void swap(Vector &nr1, Vector&nr2)
{
    swap(nr1.dim,nr2.dim);
    swap(nr1.v,nr2.v);
}
int Vector::getSize() const
{
    return dim;
}
int* Vector::getElem() const
{
    return v;
}
std::istream& operator>>(std::istream &input, Vector&ve)
{
    delete []ve.v;
    input>>ve.dim;
    ve.v=new int [ve.dim];
    for(int i=0;i<ve.dim;i++)
        input>>ve.v[i];
    return input;
}
std::ostream &operator<<(std::ostream &output,const Vector&ve)
{
    for(int i=0;i<ve.dim;i++)
        output<<ve.v[i]<<" ";
    output<<'\n';
    return output;
}
Vector & Vector::operator=(Vector Copy)
{
    if(this!=&Copy)
        swap(*this,Copy);
    return *this;
}
Vector::~Vector()
{
    dim=0;
    delete []v;
}
