#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    const int arr_size = 5;
    int arr[arr_size] = {11, 22, 33, 44, 55};
//    int arr2[arr_size];
//    arr2 = arr; //fail

    int *arr2;
    arr2 = arr;
    
    arr2[2] = 999; //points to arr!
    
    for (int i=0; i<arr_size; i++) cout << arr[i] << endl;
    cout << "-------------" << endl;
    arr2 = new int[arr_size];
    for (int i=0; i<arr_size; i++) arr2[i] = arr[i]*arr[i];
    for (int i=0; i<arr_size; i++) cout << arr2[i] << endl;
    delete[] arr2;
    
    cout << "-------------" << endl;    
    const int arr_size2 = 6;
    int arr3[arr_size2-1] = {11, 22, 33, 44, 55};

    for (int i=0; i<arr_size2; i++) cout << arr3[i] << endl;
            
    cout << endl;
    system("pause");
    return 0;
}
