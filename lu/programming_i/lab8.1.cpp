#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const int arr_size = 11;
 
int main ()
{
    int signswitched = 0;
    int arr[arr_size]={0,-2,0,-10,2,-1,0,0,3,2,-3};
    for (int i = 0; i < (arr_size-1); i++)
    {
        //if 
//        (
//           ((arr[i] > 0) && (arr[i+1] < 0)) || 
//           ((arr[i] < 0) && (arr[i+1] > 0))
//        )
        if ((arr[i] * arr[i+1]) < 0)
        {
            signswitched += 1;
        }
    }
    cout << signswitched;
    cout << endl;
    system("pause");
    return 0;
}
