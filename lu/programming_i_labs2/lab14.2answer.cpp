#include <iostream>
using namespace std;

// nemainot main funkciju,
// atkomentejiet tas kodu (iznemot komentarus) pa rindinai,
// un, rakstot savu kodu seit (pirms main),
// panaciet, lai programma kompilejas

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
    triangle a (3,4,5);
    a.change (0,0,1); // katras malas izmaiòa
    triangle b (2); // visas trîs malas aizpildâs ar 2
    triangle *c = new triangle (a); // aizpilda kâ a
    a.print (); // izdrukâ 3,4,6
    a.perimeter (); // izdrukâ 13
    c->change (2); // visu malu izmaiòa vienâdi
    c->perimeter (); // izdrukâ 19
    a.longest (); // garâkâ mala: izdrukâ 6
    b.print();    // izdruka 2 2 2
    b.longest (); // garâkâ mala: izdrukâ 2
    // delete c;
    system ("pause");
    return 0;
 }

