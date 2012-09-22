#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void concat(string in)
{
    // in += ".in";
    cout << in + ".in";
}
int main()
{
    string task = "task";


    concat(task);
    system("pause");
    return 0;
}
