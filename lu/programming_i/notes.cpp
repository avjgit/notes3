// masīva vārds ir rādītājs uz pirmo masīva elementu

#include <iostream>
using namespace std;
int printString (const char s[])
{
    cout << s << endl;
};
int main ()
{
    char name[10]; // statisks masīvs
    strcpy (name, "snow");
    printString (name); // masīva padošana funkcijai
    char *name2 = new char[10]; // dinamisks masīvs
    strcpy (name2, "snow2");
    printString (name2); // masīva padošana funkcijai
    delete[] name2;
    return 0;
}
snow
snow2
Kā jau sākumā tika pieminēts,
int printString (const char s[])
vietā varēja rakstīt
int printString (const char *s)

#include <iostream>
using namespace std;
int printStrings (char **s, int count)
{
    for (int i=0; i<count; i++) cout << s[i] << endl;
};
int main ()
{
    char **darr = new char*[2]; // pirmā dimensija
    for (int i=0; i<2; i++) darr[i] = new char[4]; // 2. dim.
    strcpy (darr[0], "THE");
    strcpy (darr[1], "COW");
    printStrings (darr, 2);
        // abu dimensiju likvidēšana, sākot ar 2.:
    for (int i=0; i<2; i++) delete[] darr[i];
    delete[] darr;
    return 0;
}
THE
COW

statisks masīvs kā norāde – automātiski pie deklarēšanas,
char arr[20]
•
iegūstot to no citas norādes,
char *arr2 = arr;
•
noteiktam mainīgajam – izmantojot adreses ņemšanas operatoru &.
int i;
int *pointer = &i;


Att. -9. Vairākas norādes uz vienu un to pašu masīvu.
char arr[20] = "LU is OK";
char *arr2 = arr;
cout << arr2 << endl;
LU is OK

Att. -10. Norāde uz masīva vidu un adresu aritmētika.
char arr[20] = "LU is OK";
char *arr2 = &arr[3]; // paņem adresi no elementa nr. 3
cout << arr2 << endl; // izdrukā simbolu virkni no tās vietas
arr2 += 3; // pārvieto norādi 3 vienības uz priekšu
cout << arr2 << endl; // izdrukā simbolu virkni no tās vietas
is OK
OK

Att. -12. Adreses iegūšana un vērtības iegūšana pēc adreses.
int arr[4] = {33,88,11,66};
int *p; // norādes mainīgā deklarēšana
p = &arr[2]; // arr[2] adreses piešķiršana mainīgajam p
cout << *p << endl; // satura (int) izdruka pēc adreses p
11

Att. -13. Norādes, adreses un references.
#include <iostream>
using namespace std;
int main ()
{
    int a = 999;
    int &ra = a; // reference (sinonīms) uz a
    int *pa = &ra; // mainīgā a adrese
    (*pa)++; // a vērtība tiek palielināta caur adresi pa
    cout << a << endl; // izdrukā izmainīto a vērtību
    return 0;
}
1000


14. Atsauces

Visi programmas objekti ir divējādi pēc savas būtības. Katram objekta nosaukumam atbilst vieta datorā atmiņā, kuru tas aizņem un tekoša vērtība, kas ir ierakstīta šajā atmiņas vietā. Atsauce tas ir pats objekts, kas nav mākslīgi sadalīts divas sastāvdaļas. Pēc programmas konteksta ir skaidrs, kāda sastāvdaļā tiks izmantota konkrētā gadījumā. Atsauci var definēt veidā:
tipa_nosaukums& atsauces nosaukums = objekts;
Piemērs: definēt atsauci uz int  tipu un inicializēt to ar int tipa objektu:
int i=0;
int& iref=i;
Inicializācijas laikā atsauce uzvedās kā rādītājs: atsaucei iref tiks piešķirta objekta i adrese. Atsauce no rādītāja atšķiras ar to, kā tā tiek izmantota ne tā, kā rādītājs, bet kā tas mainīgais, ar kura adresi atsauce tika inicializēta.
Piemēram:
iref++;             // ekvivalents i++;
int *ip = &iref;        // ekvivalents ip = &i;
Atsauces bieži tiek izmantotas lai nodotu funkcijām parametrus un atgrieztu atpakaļ rezultātu (sk. 14.2).


#include <iostream.h>
void InputArray(int *mas, int count)
{
    for (int i=0; i<count; i++)
    {
        cout << “\nItem #” << i << “= “;
        cin >> mas[i];
    }
}
int SumArray(int *mas, int count)
{
    int S=0;
    for (int i=0; i<count; i++)
        S = S+mas[i];
    return S;
}
void main()
{
    int A[5];
    InputArray(A, 5);
    cout << SumArray(A, 5);
}


#include <iostream.h>
long Fact(int A)
{
    if (A == 0) return 1;
    else return A*Fact(A-1);
}
void main()
{
    int N;
    cout << "Input number: ";
    cin >> N;
    cout << "\nN! = " << Fact(N);
}


class KlasesNosaukums: BāzesKlasesNosaukums
{
    public:
        // to atribūtu apraksts un metožu prototipi, kas ir
        // pieejami visā programmā
    private:
        // aizsargātu atribūtu un metožu apraksts, pie kuriem
// var piekļūt tikai dota klases metodēs
    protected:
        // aizsargātu atribūtu un metožu apraksts, pie kuriem
// var piekļūt tikai dota klases un dotas klases pēcteču metodēs
};


#include <iostream>
using namespace std;

int array_sum(int *arr, int num1, int num2)
{
    int sum = 0;
    for(int i = num1; i <= num2; i++)
            sum += arr[i];
    return sum;
};

int main()
{
    int arr[] = {1,2,5,7,3,6};
    cout << array_sum(arr,1,3) << endl;

    cout << endl;
    system("pause");
    return 0;
}

    const int arr_size = 5;
    int arr[arr_size] = {11, 22, 33, 44, 55};
//    int arr2[arr_size];
//    arr2 = arr; //fail

    int *arr2;
    arr2 = arr;

    arr2[2] = 999; //points to arr!


    #include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    char s[20]="Hello, World!";
    // zdrukajas normali
    cout << s << endl;

    s[5] = '\0';
    // druka, kamer nesatiek \0
    cout << s << endl;

    // bet var izdrukat ari pec 0 -7.simbolu
    cout << s[7] << endl;

    // sakot ar 7.simbolu, lidz beigam (nakamajai 0)
    cout << &s[7] << endl;


    // sakot ar 2.simbolu, lidz beigam (nakamajai 0)
    cout << &s[2] << endl;

    // tas pats, ka << s
    cout << &s[0] << endl;

    cout << endl;
    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

void array_copy(int *arr_from, int *arr_to, int elements)
{
     for (int i = 0; i < elements; i++)
         arr_to[i] = arr_from[i];
};

int main()
{
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {11,22,33,44,55,66};
    array_copy (arr2 ,arr1, 4);
    for (int i=0; i<6; i++) cout << arr1[i] << endl;

    cout << endl;
    system("pause");
    return 0;
}


#include <iostream>
using namespace std;

void array_create(int *&arr, int num)
{
     arr = new int[num];
};

int main()
{
    int num = 6;
    int *arr;
    array_create (arr, num);
    for (int i=0; i<num; i++) arr[i] = (i+1)*10+i+1;
    for (int i=0; i<num; i++) cout << arr[i] << endl;
    delete[] arr;
    system("pause");
    return 0;
}

int *array_create(int num)
{
    return new int[num];
};

int main()
{
    int num = 6;
    int *arr;
    arr = array_create (num);
    for (int i=0; i<num; i++) arr[i] = (i+1)*10+i+1;
    for (int i=0; i<num; i++) cout << arr[i] << endl;
    delete[] arr;
    system("pause");
    return 0;
}
/*

Programma izdruk?:

11
22
33
44
55
66

*/



void array_recreate (int *&arr, int num, int num0)
{
    int *tmp;
    if (num>0) tmp = new int[num];
    for (int i=0; i<num && i<num0; i++) tmp[i] = arr[i];
    if (num0>0) delete[] arr;
    arr = tmp;
};

int main()
{
    int num = 4;
    int *arr;
    array_recreate (arr, num, 0);
    for (int i=0; i<num; i++) arr[i] = (i+1)*10+i+1;
    for (int i=0; i<num; i++) cout << arr[i] << endl;
    cout << endl;
    num = 6;
    array_recreate (arr, num, 4);
    arr[4] = 100;
    arr[5] = 101;
    for (int i=0; i<num; i++) cout << arr[i] << endl;
    array_recreate (arr, 0, num);
    return 0;
}

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
