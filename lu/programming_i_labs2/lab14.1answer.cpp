#include <iostream>
using namespace std;

// nemainot main funkciju,
// atkomentejiet tas kodu (iznemot komentarus) pa rindinai,
// un, rakstot savu kodu seit (pirms main),
// panaciet, lai programma kompilejas

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
        return y-x;
    }
    double center()
    {
        return (x+y)/2;
    }
};

int main()
{
    interval i; // sâkumâ dots intervâls 0..100
    i.setX (1);
    i.setY (-5.5); // pârbaude X<=Y!!!
    i.setY (5.5);
    i.setX (6); // pârbaude X<=Y!!!
    cout << "Length: " << i.length() << endl;
    cout << "Center: " << i.center() << endl;
    system("pause");
    return 0;
}

