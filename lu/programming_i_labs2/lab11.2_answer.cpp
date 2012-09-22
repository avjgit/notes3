#include <iostream>
using namespace std;

char *strcpy2 (char *dest, const char *src)
{
    int i;
    for (i=0; src[i]!='\0'; i++) dest[i] = src[i];
    dest[i] = '\0';
    return dest;
};

char *strcat2 (char *dest, const char *src)
{
    int index  = 0;
    while (dest[index] != '\0')
    {
        index++;
    }
    return strcpy2(&dest[index], src);
};

int main()
{
    char s1[20] = "first";
    char s2[20] = "second";
    cout << s1 << endl << s2 << endl;
    // strcat (s1, s2);
    strcat2 (s1, s2);
    cout << s1 << endl << s2 << endl;
    system("pause");
    return 0;
}
