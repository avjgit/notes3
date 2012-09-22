#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

int* fill_array(int size)
{
    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
    return array;
}
int main()
{
    int size = 2;
    int *array = fill_array(size);

        for (int i = 0; i < size; i++)
    {
        cout << array[i];
    }


    system("pause");
    return 0;
}
