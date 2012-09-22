#include <iostream>
using namespace std;

// nemainot main funkciju, 
// atkomentejiet tas kodu (iznemot komentarus) pa rindinai, 
// un, rakstot savu kodu seit (pirms main),
// panaciet, lai programma kompilejas

// beigas uz displeja jabut izprintetam:
// skaitlis sobrid ir pieci/ 5
// skaitlis sobrid ir desmit/ 10
// skaitlis sobrid ir divdesmit/ 20

class skaitlis
{
    string x;
    int y;
public:
    skaitlis(string new_x, int new_y)
    {
        x = new_x;
        y = new_y;
    };
    void print()
    {
        cout << "skaitlis sobrid ir " << x << "/ " << y << endl;
    }
    void change(string new_x, int new_y)
    {
        x = new_x;
        y = new_y;
    }

    skaitlis &operator+= (string new_x)
    {
        x = new_x;
    }

    skaitlis &operator+= (int new_y)
    {
        y = new_y;
    }

    friend ostream &operator<< (ostream &out, skaitlis &s);
};

ostream &operator<< (ostream &out, skaitlis &s)
{
    cout << "skaitlis sobrid ir " << s.x << "/ " << s.y << endl;
}

int main()
{    
    // sai rindinai ir jaizveido klase skaitlis
    // un klases konstruktors, kas akcepte teksta un cipara tipa parametrus 
    // (tatad, siem laukiem jabut klases ieksa; uztaisiet tos privatus)
    skaitlis s1 ("pieci", 5);

    // jauzraksta klases "skaitlis" metode print
    // piemeram, lai izvada abus privatus laukus
    s1.print ();

    // uzrakstiet metodi "change", tadu, 
    // kas ieraksta klases laukos jaunas vertibas
    s1.change ("desmit", 10);
    s1.print ();

    // lai sis rindinas darbotos, ir japarslogo operators "+="
    // uztaisiet to ka klases funkciju
    s1 += "divdesmit";
    s1 += 20;
    
    // un, lai darbinatu pedejo rindinu, jums japarslogo operators "<<"
    // uztaisiet to areji
    cout << s1;

    system ("pause");
    return 0;
}
