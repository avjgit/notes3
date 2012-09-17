#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const int arr_size = 6;
 
int main ()
{
    double sum = 0;
    double avg;
    double arr[arr_size]={1, 2, 3.5, -5, 6.2, 0};
    for (int i=0; i<arr_size; i++) 
    {
        sum += arr[i];
        avg = sum/ (i+1);
        arr[i] = avg;
        
        cout << arr[i] << endl;
    }
    
//    for (int i=1; i<arr_size; i++)
//    {
//        arr[i] = (arr[i-1] * i + arr[i]) / (i+1);
//    };
    
    cout << endl;
    system("pause");
    return 0;
}
