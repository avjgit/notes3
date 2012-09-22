#include <iostream>
using namespace std;
// Tā izdrukā skaitļu 1.1, 2.2 un 3.3 summu, kā arī skaitļu 0.2, 0.3 un 0.4 summu. Pārveidot (papildināt) programmu (klasi threedoubles) ar šādiem nosacījumiem:
// ·        lauki x, y, z jāpārveido par private,
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
    threedoubles t; //! need constructor with empty params
    t.set (1.1, 2.2, 3.3);
    t.printsum ();

    threedoubles *tp = new threedoubles (0.2, 0.3, 0.4);
    tp->printsum();
    delete tp;
    system("pause");
    return 0;
}
