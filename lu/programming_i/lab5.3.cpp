#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;



int main()
{
    // Programma izprinte rezinajuma tabulu 4X4
    // beigas uz displeja jabut izprintetam:
    // 1 2  3  4
    // 2 4  6  8
    // 3 5  9 12
    // 4 8 12 16

    //outer cycle
    for (int i=1; i<=4; i++)
    {
    // Sets the number of characters to be used as the field width for the next insertion operation.
        for (int k=1; k<=4; k++)
        {
                cout << setw(4) << i*k;
        }
        cout << endl;
    };

    cout << endl;
    system("pause");
    return 0;
}
