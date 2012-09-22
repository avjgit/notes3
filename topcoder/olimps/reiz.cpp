#include <iostream>
#include <fstream>
// 48027   Sep 21 22:10:57 avjcoder    Reizināšana ar 2    C++  5 / 5
using namespace std;

int main()
{
    int i;
    ifstream infile("reiz.in");

    while (infile >> i) {
        cout << "Value from file is " << i << endl;
    }

    ofstream outfile("reiz.out");
    outfile << i * 2;
    outfile.close();

    return 0;
}
