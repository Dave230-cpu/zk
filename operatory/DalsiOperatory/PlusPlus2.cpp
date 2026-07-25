//Slouží ke zvýšení hodnot objektu po použití.
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

    // int = pouze rozliší postfix od prefixu

    Vektor2D operator++(int)
    {
        Vektor2D temp = *this;

        x++;
        y++;

        return temp;
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

    cout << v++ << endl;
    cout << v << endl;

    // C++ zavolá:
    // v.operator++(0);

    return 0;
}