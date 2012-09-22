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

class twointegers
{
public:
    int a;
    int b;
};

int main()
{
    twointegers t;
    t.a = 5;
    t.b = 7;
    cout << t.a+t.b << endl;
    system("pause");
    return 0;
}
