#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int rows;
    int star_one;
    int star_two;
    
    cout << "Ievadiet naturalu nepara skaitli: ";
    cin >> rows;
    
    for (int i = 1; i <= rows; i++)
    {        
        for (int k = 1; k <= rows; k++)
        {
            if (k%3 == i%3) cout << '*';
            else          cout << '-';
        }
        cout << endl;
    }
        
    cout << endl;
    system("pause");
    return 0;
}
