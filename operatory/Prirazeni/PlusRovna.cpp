//Přičte druhý objekt k aktuálnímu objektu.
#include <iostream>
using namespace std;

class Vektor2D
{
private:
    double x, y;

public:

    Vektor2D(double x = 0,double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    // v = druhý objekt

    Vektor2D& operator+=(const Vektor2D& v)
    {
        x += v.x;
        y += v.y;

        return *this;
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

    v1 += v2;

    cout << v1 << endl;

    // C++ zavolá:
    // v1.operator+=(v2);

    return 0;
}