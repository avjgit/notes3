#include <iostream>
using namespace std;

void array_recreate(int *&arr, int newnum, int oldnum)
{
    
};

int main()
{
    int num = 4;
    int *arr;
    array_recreate (arr, num, 0);
    for (int i=0; i<num; i++) arr[i] = (i+1)*10+i+1;
    for (int i=0; i<num; i++) cout << arr[i] << endl;
    cout << endl;
    num = 6;
    array_recreate (arr, num, 4);
    arr[4] = 100;
    arr[5] = 101;
    for (int i=0; i<num; i++) cout << arr[i] << endl;
    array_recreate (arr, 0, num);
    SYSTEM("pause");
    return 0;
}

/*

Programma izdruk?:

11
22
33
44

11
22
33
44
100
101

*/
