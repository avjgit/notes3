#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// 6.6
// 0.9

class threedoubles
{
    double x;
    double y;
    double z;
public:
    threedoubles()
    {

    }
    threedoubles(double new_x, double new_y, double new_z)
    {
        set(new_x, new_y, new_z);
    }
    void set(double new_x, double new_y, double new_z)
    {
        x = new_x;
        y = new_y;
        z = new_z;
    }
    void printsum()
    {
        cout << x + y + z << endl;
    }
};

int main()
{
    threedoubles t;         // jaizveido klase, ar konstuktoru bez laukiem
    t.set (1.1, 2.2, 3.3);  // metode set, kas pieskir laukiem vertibas
    t.printsum ();
                            // tas pats, tikai dinamiski
    threedoubles *tp = new threedoubles (0.2, 0.3, 0.4);
    tp->printsum();

    delete tp;
    system("pause");
    return 0;
}
