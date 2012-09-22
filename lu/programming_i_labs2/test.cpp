#include <iostream>
using namespace std;

class timesimple
{
    int hours, minutes;
public:
    timesimple (int h, int m)
    {
        hours = h;
        minutes = m;
        cout << "C1 ";
        print();
    };
    timesimple (const timesimple &t)
    {
        hours = t.hours + 1;
        minutes = t.minutes + 1;
        cout << "C2 ";
        print();
    };
    timesimple (int h)
    {
        hours = h;
        minutes = 0;
        cout << "C3 ";
        print();
    };
    timesimple ()
    {
        cout << "C4" << endl;
    };
    void print () const;
};

int main ()
{
    timesimple t (8, 20);
    t.print ();
    timesimple u = t;
    u.print ();
    timesimple v;
    v = t;
    v.print ();
    timesimple w = 23;
    w.print ();
    system("pause");
    return 0;
};

void timesimple::print () const
{
    cout << hours << ":" << minutes << endl;
}
