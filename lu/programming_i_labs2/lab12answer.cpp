#include <iostream>
using namespace std;

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

/*
int main()
{
    twointegers t (5, 7);
    cout << t.sum() << endl;
    return 0;
}
*/
