//Slouží k výpisu objektu pomocí cout
#include <iostream>
using namespace std;

class Vektor2D
{
private:
    double x, y;     // souřadnice vektoru

public:

    // Konstruktor
    Vektor2D(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    // friend = funkce není členem třídy,
    // ale může používat private proměnné

    // ostream& = vrací výstupní proud (cout)

    // os = výstupní proud (většinou cout)

    // v = objekt, který chceme vypsat

    friend ostream& operator<<(ostream& os, const Vektor2D& v);
};


// os = cout
// v = objekt, který vypisujeme

ostream& operator<<(ostream& os, const Vektor2D& v)
{
    os << "Vektor(" << v.x << ", " << v.y << ")";

    return os;
}

int main()
{
    Vektor2D v(3, 5);

    cout << v << endl;

    // C++ zavolá:
    // operator<<(cout, v);

    return 0;
}