#include <iostream>
using namespace std;

void array_recreate (int *&arr, int num, int num0)
{
    int *tmp;
    if (num>0) tmp = new int[num];
    for (int i=0; i<num && i<num0; i++) tmp[i] = arr[i];
    if (num0>0) delete[] arr;
    arr = tmp;
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
system("pause");
    return 0;
}