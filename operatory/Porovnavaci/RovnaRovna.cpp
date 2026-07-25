//Slouží k porovnání, jestli jsou dva objekty stejné.
#include <iostream>
using namespace std;

class Vektor2D
{
private:
    double x, y;

public:

    Vektor2D(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    // v = druhý objekt
    // vrací true nebo false

    bool operator==(const Vektor2D& v) const
    {
        return x == v.x && y == v.y;
    }
};

int main()
{
    Vektor2D v1(3,5);
    Vektor2D v2(3,5);

    if(v1 == v2)
        cout << "Stejne" << endl;
    else
        cout << "Jine" << endl;

    // C++ zavolá:
    // v1.operator==(v2);

    return 0;
}