//Slouží ke zvýšení hodnot objektu před použitím.
#include <iostream>
using namespace std;

class Vektor2D
{
private:
    int x, y;

public:

    Vektor2D(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    // Prefix ++objekt

    Vektor2D& operator++()
    {
        ++x;
        ++y;

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
    Vektor2D v(3,5);

    ++v;

    cout << v << endl;

    // C++ zavolá:
    // v.operator++();

    return 0;
}