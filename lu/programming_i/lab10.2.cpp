#include <iostream>
using namespace std;
 
void array_copy(int *arr_from, int *arr_to, int elements)
{
     for (int i = 0; i < elements; i++)
         arr_to[i] = arr_from[i];
};
 
int main()
{
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {11,22,33,44,55,66};
    array_copy (arr2 ,arr1, 4);
    for (int i=0; i<6; i++) cout << arr1[i] << endl;

    cout << endl;
    system("pause");
    return 0;
}
