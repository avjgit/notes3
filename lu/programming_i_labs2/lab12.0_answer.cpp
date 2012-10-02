#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// 12

class twointegers
{
public:
    int a;
    int b;
};

int main()
{
    twointegers t;
    t.a = 5;
    t.b = 7;
    cout << t.a+t.b << endl;
    system("pause");
    return 0;
}
