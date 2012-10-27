// REQUIREMENTS:
// C15. Skaitļu trijnieks nosaka taisni, kas uzdota sekojošā veidā: ax+by=c.
// Dotas n (n<=6) taisnes.
// Noteikt, kuras no taisnēm ir paralēlas.
// Vai eksistē trīs tādas taisnes, kas krustojas vienā punktā.
// Ja eksistē, tad izdrukāt šo taišņu parametrus.
// ----------------------------------------------
#include "utils.h"

const int parameters = 3;

int* get_line()
{
    int line[parameters];
    cout << "Enter line's ax + by = c parameters, as space-separated integers a b c: ";
    cin >> line[0];
    cin >> line[1];
    cin >> line[2];
    return line;
}

int main()
{
    int* line = get_line();
    cout << "Your input is being interpreted as " << line[0] << ", " << line[1] << " and " << line[2] << endl;
    system("pause");
    return 0;
}