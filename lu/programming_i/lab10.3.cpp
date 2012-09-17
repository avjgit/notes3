#include <iostream>
using namespace std;

void array_create(int *&arr, int num)
{
     arr = new int[num];  
};

int main()
{
    int num = 6;
    int *arr;
    array_create (arr, num);
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

