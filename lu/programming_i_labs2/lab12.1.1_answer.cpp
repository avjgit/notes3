#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// 1. un 2. skaitla summai (12)

class twointegers
{
public:
    int a;
    int b;
};

int main()
{
    twointegers t;              // uztaisiet klasi ar diviem laukiem
    t.a = 5;                    // te tiem tiek pieskirtas vertibas
    t.b = 7;
    cout << t.a+t.b << endl;    // tiek izprinteta abu lauku summa
    system("pause");
    return 0;
}
