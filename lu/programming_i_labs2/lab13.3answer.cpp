#include <iostream>
using namespace std;

// nemainot main funkciju,
// atkomentejiet tas kodu (iznemot komentarus) pa rindinai,
// un, rakstot savu kodu seit (pirms main),
// panaciet, lai programma kompilejas

// beigas uz displeja jabut izprintetam:
// 11
// 22
// 33
// 3 elements deleted.

// hint: vajadzes parslogot operatoru []

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
void test()
{
    dynamicarray arri(2);
    arri[0] = 11;
    arri[1] = 22;
    arri.append (33);
    arri.print ();
}

int main ()
{
    test();
    system("pause");
    return 0;
}
