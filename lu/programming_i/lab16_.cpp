#include <iostream>
using namespace std;

class skaitlis
{
    string x;
    int y;
public:
    skaitlis (const string &a, int b) { x=a; y=b; };
    void change (const string &a, int b) { x=a; y=b; };
    friend ostream &operator<< (ostream &out, const skaitlis &s);
    skaitlis &operator+= (const string &s) { x = s; };
    skaitlis &operator+= (int i) { y = i; };
};

int main()
{
    skaitlis s1 ("pieci", 5);
    cout << s1;
    s1 += "desmit";
    s1 += 10;
    cout << s1;
    system ("pause");
    return 0;
};

ostream &operator<< (ostream &out, const skaitlis &s)
{
    cout << s.x << endl;
    cout << s.y << endl;
}
