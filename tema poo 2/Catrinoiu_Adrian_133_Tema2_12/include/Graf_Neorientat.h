#include "Graf.h"
#include "Lista.h"

class Graf_Neorientat:public Graf
{
    protected:
    Lista L;
    public:

        explicit Graf_Neorientat(int nr=1,Lista lista=Lista());
        Graf_Neorientat(const Graf_Neorientat &gn);
        ~Graf_Neorientat() override=default;
        void pure_virutal(int nrvirtual) override;
        friend void swap(Graf_Neorientat &nr1, Graf_Neorientat &nr2);
        friend std::ostream& operator<<(std::ostream &output,const Graf_Neorientat &gn);
        friend std::istream& operator>>(std::istream &input,Graf_Neorientat &gn);
        Graf_Neorientat& operator =(Graf_Neorientat Copy);

};
