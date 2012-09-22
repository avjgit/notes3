#include <iostream>
using namespace std;

class threedoubles
{
public:
    double x;
    double y;
    double z;
};

int main()
{
    threedoubles t;
    t.x = 1.1;
    t.y = 2.2;
    t.z = 3.3;
    cout << t.x+t.y+t.z << endl;
    threedoubles *tp = new threedoubles;
    tp->x = 0.2;
    tp->y = 0.3;
    tp->z = 0.4;
    cout << tp->x+tp->y+tp->z << endl;
    delete tp;
    system("pause");
    return 0;
}

