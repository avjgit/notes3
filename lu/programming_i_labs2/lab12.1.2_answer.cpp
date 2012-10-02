#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// 1. un 2. skaitla summai (12)

class twointegers
{
    int a;
    int b;
public:
    twointegers(int new_a, int new_b)
    {
        a = new_a;
        b = new_b;
    }
    int sum()
    {
        return a + b;
    }
};

int main()
{
    twointegers t (5, 7);       // uztaisiet klasi ar diviem privatiem laukiem
    cout << t.sum() << endl;    // izdruka 1. un 2. skaitla summu (12)
    system("pause");
    return 0;
}
