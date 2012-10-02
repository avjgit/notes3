#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// 3 4 6
// 13
// 19
// 6
// 2 2 2
// 2
class triangle
{
    int a, b, c;
public:
    triangle (int new_a, int new_b, int new_c)
    {
        a = new_a;
        b = new_b;
        c = new_c;
    }
    triangle(int new_a)
    {
        a = new_a;
        b = new_a;
        c = new_a;
    }
    triangle(const triangle &t)
    {
        a = t.a;
        b = t.b;
        c = t.c;
    }
    void change (int add_a, int add_b, int add_c)
    {
        a += add_a;
        b += add_b;
        c += add_c;
    }
    void change(int add_a)
    {
        change (add_a, add_a, add_a);
    }
    void print()
    {
        cout << a << ' ' << b << ' ' << c << endl;
    }
    void perimeter()
    {
        cout << a + b + c << endl;
    }
    void longest()
    {
        int longest = a;
        if (b > longest) longest = b;
        if (c > longest) longest = c;
        cout << longest << endl;
    }
};

int main ()
{
    // tatad,  jauztaisa klase TRIANGLE, kura jabut:

    triangle a (3,4,5);             // konstruktoram pec tris malasm
    a.change (0,0,1);               // metodei, kas izmaina malas
    triangle b (2);                 // konstruktoram vienadmalu trijsturim
    triangle *c = new triangle (a); // konstruktoram pec trisstura kopijas
    a.print ();                     // metodei, kas izdrukâ malas (3,4,6)
    a.perimeter ();                 // izdruka perimetru 13
    c->change (2);                  // visu malu izmaina vienadi
    c->perimeter ();                // izdruka perimetru velreiz
    a.longest ();                   // izdruka A trisstura garako malu (6)
    b.print();                      // izdruka B malas (2 2 2)
    b.longest ();                   // izdruka B trisstura garako malu (2)
    delete c;
    system ("pause");
    return 0;
 }

