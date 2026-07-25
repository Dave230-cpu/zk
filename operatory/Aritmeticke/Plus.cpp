//Slouží ke sčítání dvou objektů.
#include <iostream>
using namespace std;

class Vektor2D
{
private:
    double x, y;     // souřadnice vektoru

public:

    Vektor2D(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    // const = objekt se nezmění
    // v = druhý objekt

    Vektor2D operator+(const Vektor2D& v) const
    {
        return Vektor2D(x + v.x, y + v.y);
    }

    friend ostream& operator<<(ostream& os,const Vektor2D& v);
};

ostream& operator<<(ostream& os,const Vektor2D& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main()
{
    Vektor2D v1(2,3);
    Vektor2D v2(5,4);

    Vektor2D vysledek = v1 + v2;

    cout << vysledek << endl;

    // C++ zavolá:
    // v1.operator+(v2);

    return 0;
}