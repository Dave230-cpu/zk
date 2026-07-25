//Slouží k porovnání, jestli je jeden objekt menší než druhý.
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

    // porovnává součet souřadnic

    bool operator<(const Vektor2D& v) const
    {
        return (x + y) < (v.x + v.y);
    }
};

int main()
{
    Vektor2D v1(2,3);
    Vektor2D v2(6,5);

    if(v1 < v2)
        cout << "v1 je mensi" << endl;

    // C++ zavolá:
    // v1.operator<(v2);

    return 0;
}