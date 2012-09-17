#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
const int arr_size = 3;
 
int main ()
{
    const int n = 4;
    const int m = 3;
    int arr[n][m];
    // init fill in
    for(int i  = 0; i < n; i++)//{
//        for(int j = 0; j < m; j++){
//            arr[i][j] = 1;
//        }
//    }
    //
//        0  1  2
//       __ __ __
//    0:  1  2  3
//    1: 10 11  4
//    2:  9 12  5
//    3:  8  7  6
    for(int i  = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = i*m + j + 1;
        }
    }
    
        
    // output
    cout << "currently array is: " << endl;
    for(int i  = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    
    cout << endl;
    system("pause");
    return 0;
}

