#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    //inner cycle
    for (int i=1; i<=4; i++)
    {
//        Sets the number of characters to be used as the field width for the next insertion operation.
        for (int k=1; k<=4; k++) cout << setw(4) << i*k;
        cout << endl;
    };
    
    cout << endl;
    system("pause");
    return 0;
}
