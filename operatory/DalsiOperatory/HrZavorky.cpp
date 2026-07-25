//Slouží k přístupu k prvkům pomocí indexu.
#include <iostream>
using namespace std;

class Pole
{
private:
    int data[5] = {10,20,30,40,50};

public:

    // index = pořadí prvku

    int& operator[](int index)
    {
        return data[index];
    }
};

int main()
{
    Pole p;

    cout << p[2] << endl;

    p[2] = 100;

    cout << p[2] << endl;

    // C++ zavolá:
    // p.operator[](2);

    return 0;
}