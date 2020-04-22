#include "Matrice.h"
#include "Graf.h"
#include <iostream>
class Graf_Orientat:public Graf
{
    Matrice A;
    public:
        explicit Graf_Orientat(int nr=1,Matrice matrice=Matrice());
         ~Graf_Orientat() override=default;
         Graf_Orientat(const Graf_Orientat &go);
         friend std::ostream& operator <<(std::ostream &output, const Graf_Orientat &go);
         friend std::istream& operator >>(std::istream &input, Graf_Orientat &go);
         friend void swap(Graf_Orientat &nr1, Graf_Orientat &nr2);
         Graf_Orientat& operator =(Graf_Orientat Copy);
         void pure_virutal(int nrvirtual) override ;
         int verifgraf();
};
