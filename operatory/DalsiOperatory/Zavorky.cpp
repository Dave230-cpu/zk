//Slouží k volání objektu jako funkce.
#include <iostream>
using namespace std;

class Kalkulacka
{
public:

    // a = první číslo
    // b = druhé číslo

    int operator()(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Kalkulacka k;

    cout << k(10,20) << endl;

    // C++ zavolá:
    // k.operator()(10,20);

    return 0;
}