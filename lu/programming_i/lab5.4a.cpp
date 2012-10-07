#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    // Doti naturāls skaitlis n.
    // Izdrukāt „eglīti” no zvaigznītēm ‘*’, kas sastāv no n rindiņām tādējādi, ka pirmajā rindā ir 1 zvaigznīte, bet katrā nākamajā par vienu vairāk.
    // Piemērs. n=6; rezultāts:
    // *
    // **
    // ***
    // ****
    // *****
    // ******
    int rows;
    cout << "Cik rindu?";
    cin >> rows;
    for (int i = 1; i <= rows; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            cout << '*';
        }
        cout << endl;
    }

    cout << endl;
    system("pause");
    return 0;
}
