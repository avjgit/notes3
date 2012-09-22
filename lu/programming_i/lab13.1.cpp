#include <iostream>
using namespace std;

class person
{
private:
    char *name;
    int age;
public:
    person (const char *n, int a) { init (n,a); };
    person () {};
    ~person ();
    void init (const char*, int);
    void print () { cout << name << " " << age << endl; }
};
void test()
{
    person p;
    p.init ("Liz", 19);
    p.print ();
    person *pp = new person ("Peter", 20);
    pp->print ();
    delete pp;
}
int main ()
{
    test();
    system("pause");
    return 0;
};

person::~person ()
{
    cout << "Deleting: " << name << endl;
    delete[] name;
};

void person::init (const char *n, int a)
{
    name = new char[strlen(n)+1];
    strcpy (name, n);
    age = a;
}
