#include <iostream>
using namespace std;

class twointegers
{
    int a;
    int b;
public:
    twointegers (int a_, int b_)
    {
        a = a_;
        b = b_;
    }
    int sum()
    {
         return a+b;
    }
};

int main()
{
//    twointegers t;
//    t.a = 5;
//    t.b = 7;
//    cout << t.a+t.b << endl;
    
    twointegers t (5, 7);
    cout << t.sum() << endl;

    
    system("pause");
    return 0;
}
