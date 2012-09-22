#include <iostream>
using namespace std;

// nemainot main un test funkcijas,
// atkomentejiet test funkcijas kodu (iznemot komentarus) pa rindinai,
// un, rakstot savu kodu seit (pirms main un test),
// panaciet, lai programma kompilejas

// uzrakstiet destruktoru un init metodi arpus klases
// atkalizmantojiet init metodi konstruktoraa

// beigas uz displeja jabut izprintetam:
// Liz 19
// Peter 20
// Deleting: Peter
// Deleting: Liz

class person
{
    char *name;
    int age;
public:
    person(){}
    ~person();
    void init(char *new_name, int new_age);

    person (char *new_name, int new_age)
    {
        init(new_name,  new_age);
    }
    void print()
    {
        cout << name << " " << age << endl;
    }

};
void person::init(char *new_name, int new_age)
{
    name = new_name;
    age = new_age;
}

person::~person()
{
    cout << "Deleting: " << name << endl;
    delete[] name;
}

void test()
{
    // objekti tiek izveidoti 2 veidos:
    // · tiešā veidā (mainīgais ir ar tipu klase; laukiem un metodēm pieeja notiek ar punkta (.) notāciju);
    // · dinamiskā veidā (mainīgais ir ar tipu klase*, t.i., norāde uz klase; laukiem un metodēm pieeja notiek ar bultiņas (->) notāciju)
    person p;
    p.init ("Liz", 19);
    p.print ();
    person *pp = new person ("Peter", 20);
    pp->print ();

    // Destruktors ir tāda metode, kas tiek automātiski izsaukta tieši pirms objekta likvidēšanas.
    // Pievērst uzmanību dotajā programmā destruktora izsaukšanai –
    // vispirms tiek izsaukts Peter destruktors, pēc tam Liz destruktors.
    // Tas tāpēc, ka dinamiskiem objektiem destruktors tiek izsaukts tad, kad tiek izsaukts delete,
    // bet tiešā veidā izmantotam objektam tas tiek izsaukts tā figūriekavu bloka beigās, kur tas deklarēts.
    delete pp;
}

int main ()
{
    test();
    system("pause");
    return 0;
};
