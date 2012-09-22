#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string s("Somewhere down the road");
    istringstream iss(s);

    string sub;
    while (iss >> sub)
    {
        cout << "Substring: " << sub << endl;
    } ;


    // char delim = ' ';
    // int i = 0;
    // int y = 0;
    // int first = 0;

    // for (i = 0; line[i] != '\0'; i++)
    // {
    //     if (line[i] == delim)
    //     {
    //         sizes[y] = atoi(line.substr(first, i).c_str());
    //     }
    // }

    system("pause");
    return 0;
}
