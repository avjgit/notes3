#include <iostream>
using namespace std;

int main()
{
    int game[3][3];
    int turns = 0;
    int tmp;
    while (turns < 9)
    {
        cout << "enter your turn: ";
        cin >> tmp;
        turns++;
    }
    system("pause");
    return 0;
}