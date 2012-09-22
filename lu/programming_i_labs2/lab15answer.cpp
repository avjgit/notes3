#include <iostream>
using namespace std;

// nemainot main funkciju, 
// atkomentejiet tas kodu (iznemot komentarus) pa rindinai, 
// un, rakstot savu kodu seit (pirms main),
// panaciet, lai programma kompilejas

// beigas uz displeja jabut izprintetam:
// charchar ir AB
// charchar ir XY
// charint ir G99
// charint ir K100

class charsimple
{
    char x;
public:
    charsimple(char new_x)
    {
        x = new_x;
    }
    virtual void change(char new_x)
    {
        x = new_x;
    }
    virtual void print()
    {
        cout << x;
    }
};

class charchar: public charsimple
{
    char y;
public:    
    charchar (char a, char b): charsimple(a)
    { 
        y=b; 
    };
    void print ()
    {
        cout << "charchar ir ";
        charsimple::print();
        cout << y << endl;
    };
    void change (char a, char b) 
    { 
        charsimple::change(a); 
        y=b; 
    };
};

class charint: public charsimple
{
    int y;
public:    
    charint (char a, int b): charsimple(a)
    { 
        y=b; 
    };
    void print ()
    {
        cout << "charint ir ";
        charsimple::print();
        cout << y << endl;
    };
    void change (char a) 
    {
        charsimple::change(a); 
        y++; 
    };
};

int main()
{
    // sai rindinai ir jaizveido klase charchar
    // un klases konstruktors, kas akcepte divas char vertibas
    charchar cc ('A', 'B');

    // jaizveido metode print
    cc.print ();

    // jaizveido metode change;
    // tai jaieraksta klases laukos jaunas vertibas
    cc.change ('X', 'Y');
    cc.print ();
    cout << endl;

    // jaizveido klase charint, ar tam pasam metodem, kas charchar
    // iznemot change - kas maina char lauka vertibu, 
    // bet int lauka vertibu vienkarsi palielina par 1
    charsimple *ci = new charint ('G', 99);
    ci->print ();
    ci->change ('K');
    ci->print ();
    delete ci;

    // ta ka klasem charchar un charint ir viens kopigs lauks (char),
    // izveidojiet klasi charsimple, un mantojiet charchar un charint no tas.
    // Klasee charsimple jabut: privatam char laukam, 
    // konstruktoram ar vienu char parametru un print metodei 
    // rezultatam uz displeja jabut tadam pasam


    system ("pause");
    return 0;
}
