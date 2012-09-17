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

char *strcat2 (char *dest, const char *src)
{
    int length, i;
    for(length = 0; dest[length] != '\0'; length++){};
    cout << "length is " << length << endl;
//  why this doesn't work?  
    for(i = 0; src[i] != '\0'; i++)
    {
        cout << "adding " << src[i] << " to nr " << length + i << endl;
        dest[length+i] = src[i];
    }

    dest[i] = '\0';
//   strcpy2(&dest[length], src);
    return dest;
};
 
int main()
{
    char s1[20] = "first";
    char s2[20] = "second";
    cout << s1 << endl << s2 << endl;
    //strcat (s1, s2);
    strcat2 (s1, s2);
    cout << s1 << endl << s2 << endl;
    system("pause");
    return 0;
}
