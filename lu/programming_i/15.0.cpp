#include <iostream>
using namespace std;

class charchar
{
    char x;
    char y;
public:    
    charchar (char a, char b) { x=a; y=b; };
    void print ()
    {
        cout << x << endl;
        cout << y << endl;
    };
    void change (char a, char b) { x=a; y=b; };
};

class charint
{
    char x;
    int y;
public:    
    charint (char a, int b) { x=a; y=b; };
    void print ()
    {
        cout << x << endl;
        cout << y << endl;
    };
    void change (char a) { x=a; y++; };
};

int main()
{
    charchar cc ('A', 'B');
    cc.print ();
    cc.change ('X', 'Y');
    cc.print ();
    cout << endl;
    charint *ci = new charint ('G', 99);
    ci->print ();
    ci->change ('K');
    ci->print ();
    delete ci;
    system ("pause");
    return 0;
}
