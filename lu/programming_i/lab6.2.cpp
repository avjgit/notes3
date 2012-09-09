#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    char s[20]="Hello, World!";
    // zdrukajas normali
    cout << s << endl;
            
    s[5] = '\0';
    // druka, kamer nesatiek \0
    cout << s << endl;
    
    // bet var izdrukat ari pec 0 -7.simbolu
    cout << s[7] << endl;

    // sakot ar 7.simbolu, lidz beigam (nakamajai 0)
    cout << &s[7] << endl;


    // sakot ar 2.simbolu, lidz beigam (nakamajai 0)
    cout << &s[2] << endl;
        
    // tas pats, ka << s
    cout << &s[0] << endl;
    
    cout << endl;
    system("pause");
    return 0;
}
