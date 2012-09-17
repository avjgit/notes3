#include <iostream>
using namespace std;
 
char *strcpy2 (char *dest, const char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
    {
       dest[i] = src[i];
    }
    return dest;
};
 
int main()
{
    char target[20] = "target";
    char source[20] = "source";
    cout << target << endl << source << endl;
//    strcpy (target, source);
    strcpy2 (target, source);
    cout << target << endl << source << endl;
    system("pause");
    return 0;
}
