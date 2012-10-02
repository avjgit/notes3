#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// 6.6
// 0.9

class threedoubles
{
public:
    double x;
    double y;
    double z;
};

int main()
{
    threedoubles t;                     // jaizveido klase
    t.x = 1.1;                          // ar trim laukiem
    t.y = 2.2;                          // visi tris tiek aizpilditi
    t.z = 3.3;
    cout << t.x+t.y+t.z << endl;        // tiek izprinteta to summa

    threedoubles *tp = new threedoubles;// tas pats, tikai dinamiski
    tp->x = 0.2;
    tp->y = 0.3;
    tp->z = 0.4;
    cout << tp->x+tp->y+tp->z << endl;

    delete tp;
    system("pause");
    return 0;
}

