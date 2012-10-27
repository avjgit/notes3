// REQUIREMENTS:
// C15. Skaitļu trijnieks nosaka taisni, kas uzdota sekojošā veidā: ax+by=c.
// Dotas n (n<=6) taisnes.
// Noteikt, kuras no taisnēm ir paralēlas.
// Vai eksistē trīs tādas taisnes, kas krustojas vienā punktā.
// Ja eksistē, tad izdrukāt šo taišņu parametrus.
// ----------------------------------------------
#include "utils.h"

int main()
{
    int a, b, c;
    cout << "Enter ax + by = c line's parameters, as integers a b c: ";
    cin >> a;
    cin >> b;
    cin >> c;
    cout << "Your input is being interpreted as " << a << ", " << b << " and " << c << endl;
    system("pause");
    return 0;
}