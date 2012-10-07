#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    // Mēģināt pārveidot programmu tā, lai tā izmantotu tikai viena līmeņa ciklu, bet veiktu precīzi tādu pašu darbu – izdrukātu reizrēķina tabulu 4X4 (lab5.3a.cpp).
    // Ieteikums: visticamāk, lai kompensētu iekšējo ciklu, nāksies izmantot papildus if operatoru, kā arī veselo skaitļu dalīšanas / un atlikuma % operācijas.
    //inner cycle
    for (int i = 0; i < 16; i++)
    {
        cout << setw(4) << (i/4+1) * (i%4+1);
        if (i%4 == 3) cout << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}
