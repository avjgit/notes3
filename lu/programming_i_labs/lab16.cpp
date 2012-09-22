#include <iostream>
using namespace std;

class skaitlis
{
    string x;
    int y;
public:    
    skaitlis (const string &a, int b) { x=a; y=b; };
    void print ()
    {
        cout << x << endl;
        cout << y << endl;
    };
    void change (const string &a, int b) { x=a; y=b; };
};

void lab16_1()
{
    skaitlis s1 ("pieci", 5);
    s1.print ();
    s1.change ("desmit", 10);
    s1.print ();
}
