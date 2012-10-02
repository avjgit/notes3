#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// piezime: "C1 (..)" japrinte konstruktoram
//
// C1 8:20
// 8:20
// C2 9:21
// 9:21
// C4
// 8:20
// C3 23:0
// 23:0

class timesimple
{
    int hours, minutes;
public:
    timesimple(int hours_, int minutes_)
    {
        hours = hours_;
        minutes = minutes_;
        cout << "C1 ";
        print();
    }
    timesimple(const timesimple &t)
    {
        hours = t.hours + 1;
        minutes = t.minutes + 1;
        cout << "C2 ";
        print();
    }
    timesimple (int h)
    {
        hours = h;
        minutes = 00;
        cout << "C3 ";
        print();
    };
    timesimple ()
    {
        cout << "C4" << endl;
    };
    void print()
    {
        cout << hours << ":" << minutes << endl;
    }
};

int main ()
{
    // Konstruktors ir tāda metode, kas tiek automātiski izsaukta tieši pēc objekta izveidošanas.
    // Klase var saturēt vairākus konstruktorus.
    // Īpaši konstruktori ir tie, kam ir viens parametrs, jo tie tiek netieši izsaukti,
    //   veicot objekta inicializāciju pie deklarēšanas ar piešķiršanas operatoru =.
    // Veicot parastu piešķiršanu pēc deklarēšanas tas nestrādā!.
    // Pievērst uzmanību konstruktoru izsaukšanai dotajā programmā – īpaši konstruktoriem ar vienu parametru (C2, C3).

    timesimple t (8, 20); // uztaisiet klasi ar laukiem HOURS un MINUTES
                          // konstruktors lai printe "C1"
    t.print ();           // si metode vienkarsi printe stundas un minutes
    timesimple u = t;     // uztaisiet ta, ka, konstruejot objektu no cita objekta (konstuktors "C2"),
                          // jauna objekta stundas un minutes bus par 1 lielaki (u tagad bus 9:21)
    u.print ();

    timesimple v;         // konstruktors "C4"; HOURS un MINUTES gan bus tuksi
    v = t;                // tagad V objekts norada uz to pasu T
    v.print ();           // izprintejot V, to var redzet!

    timesimple w = 23;    // konstuktors "C3"; 23 bus stundas
    w.print ();

    system("pause");
    return 0;
};
