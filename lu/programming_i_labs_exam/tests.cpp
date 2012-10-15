#include <iostream>
#include <math.h>
using namespace std;

int number_order(const int number)
{
    const int base = 10;
    int order = 0;
    while (pow(base, order) <= number) order++;
    return --order;
}

int test()
{
    int x = 1;
    return x--;
}

int main()
{
    // int arr[5] = {};
    // cout << number_order(12345);
    cout << test();
    system("pause");
    return 0;
}