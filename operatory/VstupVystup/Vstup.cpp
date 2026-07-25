//Slouží k načtení objektu pomocí cin.
#include <iostream>
using namespace std;

class Vektor2D
{
private:
    double x, y;     // souřadnice vektoru

public:

    // Konstruktor
    Vektor2D(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    // friend = funkce není členem třídy,
    // ale může používat private proměnné

    // istream& = vrací vstupní proud (cin)

    // is = vstupní proud (většinou cin)

    // v = objekt, do kterého načítáme hodnoty

    friend istream& operator>>(istream& is, Vektor2D& v);

    friend ostream& operator<<(ostream& os, const Vektor2D& v);
};


// is = cin
// v = objekt, do kterého zapisujeme

istream& operator>>(istream& is, Vektor2D& v)
{
    is >> v.x >> v.y;

    return is;
}

ostream& operator<<(ostream& os, const Vektor2D& v)
{
    os << "Vektor(" << v.x << ", " << v.y << ")";

    return os;
}

int main()
{
    Vektor2D v;

    cout << "Zadej x a y: ";
    cin >> v;

    cout << v << endl;

    // C++ zavolá:
    // operator>>(cin, v);
    // operator<<(cout, v);

    return 0;
}