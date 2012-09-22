#include <iostream>
using namespace std;

class charsimple
{
    char x;
public:
    charsimple  (char a) { x = a; };
    void change (char a) { x = a; };    
    void print() { cout << x << endl; }
};

class charchar: charsimple
{
    char x;
    char y;
public:    
    charchar (char a, char b): charsimple (a) { y=b; };
    void print ()
    {
        charsimple::print();
        cout << y << endl;
    };
    void change (char a, char b) { charsimple::change(a); y=b; };
};

class charint: charsimple
{
    char x;
    int y;
public:    
    charint (char a, int b): charsimple(a) { y=b; };
    void print ()
    {
        charsimple::print();
        cout << y << endl;
    };
    void change (char a) { charsimple::change(a);; y++; };
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
