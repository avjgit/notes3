#include <iostream>
using namespace std;

int *array_create(int num)
{
    return new int[num];
};

int main()
{
    int num = 6;
    int *arr;
    arr = array_create (num);
    for (int i=0; i<num; i++) arr[i] = (i+1)*10+i+1;
    for (int i=0; i<num; i++) cout << arr[i] << endl;
    delete[] arr;
    system("pause");
    return 0;
}

/*

Programma izdruk?:

11
22
33
44
55
66

*/

