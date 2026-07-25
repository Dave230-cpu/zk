//Slouží ke zkopírování hodnot z jednoho objektu do druhého.
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

    // v = objekt, který kopírujeme

    Vektor2D& operator=(const Vektor2D& v)
    {
        x = v.x;
        y = v.y;

        // vrátí aktuální objekt
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
    Vektor2D v1(5,8);
    Vektor2D v2;

    v2 = v1;

    cout << v2 << endl;

    // C++ zavolá:
    // v2.operator=(v1);

    return 0;
}