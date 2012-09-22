#include <iostream>
using namespace std;

char *strcpy2 (char *dest, const char *src)
{
    int i;
    for (i=0; src[i]!='\0'; i++) dest[i] = src[i];
    dest[i] = '\0';
    return dest;
};

int main()
{
    char s1[20] = "first";
    char s2[20] = "second";
    cout << "s1 is " << s1 << ", s2 is " << s2 << endl;
    strcpy2 (s1, s2);
    cout << "copying...";
    cout << "now s1 is " << s1 << ", s2 is " << s2 << endl;
    system("pause");
    return 0;
}
