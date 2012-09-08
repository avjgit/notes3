#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
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
