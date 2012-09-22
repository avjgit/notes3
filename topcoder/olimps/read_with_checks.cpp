#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string line;
    ifstream input ("reiz.in");

    while (input.good() )
    {
      getline (input, line);
      cout << line << endl;
    }
    input.close();

    ofstream myfile;
    myfile.open ("reiz.out");
    myfile << line;
    myfile.close();

    system("pause");
    return 0;
}
