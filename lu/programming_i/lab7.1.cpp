#include <iostream>
using namespace std;
const int arr_size = 3;
 
int main ()
{
    int arr[arr_size*arr_size]={11,22,33,44,55,66,77,88,99};
//    for (int i=0; i<arr_size; i++) cout << arr[i] << endl;
    int mda[arr_size][arr_size];
    int element;
    
    for(int i = 0; i < arr_size; i++)
    {
        for(int j = 0; j < arr_size; j++)
        {
            element = arr[i*arr_size + j];
            cout << element << endl;
            mda[i][j] = element;
        }
    }
    
    int sum;
    
    sum = 0;
    for(int i = 0; i < arr_size; i++)
    {
            sum += mda[i][i];
    }
    
    cout << "1.diagonales summa ir " << sum << endl;


    sum = 0;
    for(int i = 0; i < arr_size; i++)
    {
            sum += mda[i][arr_size-1-i];
    }
    cout << "2.diagonales summa ir " << sum << endl;
    

    cout << endl;
    system("pause");
    return 0;
}

