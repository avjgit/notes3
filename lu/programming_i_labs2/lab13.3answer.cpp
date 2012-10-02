#include <iostream>
using namespace std;

// beigas uz displeja jabut izprintetam:
// 11
// 22
// 33
// 3 elements deleted.

class dynamicarray
{
    int size;
    int *array;
public:
    dynamicarray (int s=0)
    {
        size = s;
        if (size > 0) array = new int[size];
    };
    ~dynamicarray ()
    {
        if (size > 0)
        {
            cout << size << " elements deleted." << endl;
            delete[] array;
        }
    };
    void append (int value)
    {
        int *tmparray = new int[size+1];
        for (int i=0; i<size; i++) tmparray[i] = array[i];
        tmparray[size] = value;
        size++;
        array = tmparray;
    };
    void print ()
    {
        for (int i=0; i<size; i++) cout << array[i] << endl;
    };
    int& operator[] (int i) { return array[i]; };
};
/////////////////////// rakstiet savu kodu virs sis linijas
void test()
{
    dynamicarray arri(2); // jauztaisa klase DYNAMICARRAY
                          // tai javeido masivs (array),
                          // dinamiski (t.i. tik liels, cik pateiks ar parametru)
                          // (2 saja piemera)
    arri[0] = 11;         // pirmaja elementa jaieraksta 11.
                          // lai to izdaritu, jums ir japarslogo operators "[]"
    arri[1] = 22;
    arri.append (33);     // masivs japalielina par vienu elementu,
                          // un tur jaieraksta 33
    arri.print ();        // sai metodei jaizprinte visi masiva elementi
}

int main ()
{
    test();

    // rindinu "3 elements deleted" ir jaievieto destruktora
    // kad masiva elementi beigs pastavet (tie eksiste tikai test() bloka robezas),
    // automatiski iedarbosies destruktors

    system("pause");
    return 0;
}
