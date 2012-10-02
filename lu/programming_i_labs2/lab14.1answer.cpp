#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// Error: -5.5
// Error: 6
// Length: 4.5
// Center: 3.25

class interval
{
    double x;
    double y;
public:
    interval()
    {
        x = 0;
        y = 100;
    }
    void setX(double new_x)
    {

        if (new_x > y)
        {
            cout << "Error: " << new_x << endl;
            return;
        }
        x = new_x;
    }
    void setY(double new_y)
    {
        if (new_y < x)
        {
            cout << "Error: " << new_y << endl;
            return;
        }
        y = new_y;
    }
    double length()
    {
        cout << "Length: " << y-x << endl;
    }
    double center()
    {
        cout << "Center: " << (x+y)/2 << endl;
    }
};

int main()
{
    interval i;     // jauztaisa klase INTERVAL
                    // izveidojiet privatos laukus X un Y
                    // ar sakuma vertibam 0 un 100
    i.setX (1);     // lauka X ierakstam 1
    i.setY (-5.5);  // seit noblausies parbaude, kurai nepatik, ka Y mazak par X
    i.setY (5.5);   // lauka Y tiek ierakstita korekta vertiba
    i.setX (6);     // seit bus kludas pazinojums par to,
                    // ka X megina ierakstit lielaku par Y
    i.length();     // izprinte intervala garumu
    i.center();     // izvada uz ekrana intervala centru
    system("pause");
    return 0;
}

