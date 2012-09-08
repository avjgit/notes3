#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
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
