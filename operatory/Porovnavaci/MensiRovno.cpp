//Slouží k porovnání, jestli je objekt menší nebo stejný.
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

    bool operator<=(const Vektor2D& v) const
    {
        return (x + y) <= (v.x + v.y);
    }
};

int main()
{
    Vektor2D v1(2,3);
    Vektor2D v2(2,3);

    if(v1 <= v2)
        cout << "Ano" << endl;

    // C++ zavolá:
    // v1.operator<=(v2);

    return 0;
}