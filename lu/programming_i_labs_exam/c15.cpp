// REQUIREMENTS:
// C15. Skaitļu trijnieks nosaka taisni, kas uzdota sekojošā veidā: ax+by=c.
// Dotas n (n<=6) taisnes.
// Noteikt, kuras no taisnēm ir paralēlas.
// Vai eksistē trīs tādas taisnes, kas krustojas vienā punktā.
// Ja eksistē, tad izdrukāt šo taišņu parametrus.
// ----------------------------------------------
#include "utils.h"

const int parameters = 3;

int main()
{
    int a, b, c;
    int line[parameters];
    cout << "Enter ax + by = c line's parameters, as integers a b c: ";
    cin >> line[0];
    cin >> line[1];
    cin >> line[2];
    cout << "Your input is being interpreted as " << line[0] << ", " << line[1] << " and " << line[2] << endl;
    system("pause");
    return 0;
}