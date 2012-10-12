#include <iostream.h>
using namespace std;

int main()
{
    // char *input = new char[20];
    char *input;
    // gets(input);
    cin >> input;
    int i = 0;
    while(input[i] != '\0')
    {
        cout << input[i] << endl;
        i++;
    }
    system("pause");
    return 0;
}