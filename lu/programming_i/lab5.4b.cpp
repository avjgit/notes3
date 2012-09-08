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
        star_one = i;
        star_two = rows-i+1;
        
        for (int k = 1; k <= rows; k++)
        {
            if (k == star_one)      cout << '*';
            else if (k == star_two) cout << '*';
            else                    cout << '-';
        }
        cout << endl;
    }
        
    cout << endl;
    system("pause");
    return 0;
}
