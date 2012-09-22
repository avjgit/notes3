#include <iostream>
using namespace std;

class interval
{
      double x, y;
public:
       interval () {x = 0; y = 100;}
       void setX(double new_x) 
       {
            if (new_x > y) 
            {
               cout << "Error: " << new_x << endl;
            }
            else
            {
                x = new_x;
            }
       }      
       void setY(double new_y) 
       {
            if (new_y < x) 
            {
                  cout << "Error: " << new_y << endl;
            }
            else
            {
                  y = new_y;
            }
       }      
       double length() { return y-x;}
       double center() { return (x+y)/2; }
};

int main()
{
    interval i; // s?kum? dots interv?ls 0..100
    i.setX (1);
    i.setY (-5.5); // p?rbaude X<=Y!!!
    i.setY (5.5);
    i.setX (6); // p?rbaude X<=Y!!!
    cout << "Length: " << i.length() << endl;
    cout << "Center: " << i.center() << endl;
    system("pause");
    return 0;
}

