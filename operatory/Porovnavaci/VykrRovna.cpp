//Slouží ke zjištění, jestli jsou dva objekty různé.
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

    bool operator!=(const Vektor2D& v) const
    {
        return x != v.x || y != v.y;
    }
};

int main()
{
    Vektor2D v1(3,5);
    Vektor2D v2(8,2);

    if(v1 != v2)
        cout << "Jine" << endl;
    else
        cout << "Stejne" << endl;

    // C++ zavolá:
    // v1.operator!=(v2);

    return 0;
}