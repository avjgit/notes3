#include <iostream>
using namespace std;
 
int array_sum(int *arr, int num1, int num2)
{
    int sum = 0;
    for(int i = num1; i <= num2; i++)
            sum += arr[i];
    return sum;
};
 
int main()
{
    int arr[] = {1,2,5,7,3,6};
    cout << array_sum(arr,1,3) << endl;

    cout << endl;
    system("pause");
    return 0;
}
 
/*
 
Programma izdrukâ:
 
14
 
*/
