#include <iostream>
using namespace std;

// nemainot main funkciju,
// atkomentejiet tas kodu (iznemot komentarus) pa rindinai,
// un, rakstot savu kodu seit (pirms main),
// panaciet, lai programma kompilejas

// Tā izdrukā skaitļu 5 un 7 summu. Pārveidot (papildināt) programmu (klasi twointegers) ar šādiem nosacījumiem:
// ·        lauki a un b jāpārveido par private,
// ·        programmai jādarbojas, funkciju main aizstājot ar komentēto funkciju main;
// ·        programmai no lietotāja viedokļa jāveic tā pati darbība.

// beigas uz displeja jabut izprintetam:
// charchar ir AB
// charchar ir XY
// charint ir G99
// charint ir K100

class twointegers
{
    int a;
    int b;
public:
    twointegers(int new_a, int new_b)
    {
        a = new_a;
        b = new_b;
    }
    int sum()
    {
        return a + b;
    }
};

int main()
{
    twointegers t (5, 7);
    cout << t.sum() << endl;
    system("pause");
    return 0;
}
