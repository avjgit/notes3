#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//Laboratorijas darbs 6.3. Vingrin�jumi par mas�viem un simbolu virkn�m
//Vingrin�jums 1. (lab6.3a.cpp)
//Dota simbolu virkne s. Noskaidrot, vai k�ds simbols �aj� simbolu virkn� atk�rtojas p�c k�rtas.
//Piem�ram, simbolu virkn� �Hallo, World!� p�c k�rtas atk�rtojas simbols �l�. (Atbildei j�b�t � j� vai n�)
void char_repeats_in_a_row(char phrase[])
{
//     cout << "array is " << sizeof(phrase);
     // uzzinam masiva garumu
     // ! wrong: but only in the function where the array was allocated. 
//     int phrase_length = sizeof(phrase)/sizeof(char);
//       int phrase_length = strlen(phrase);

//     cout << "length is " << phrase_length;
     // ejam caur masivu; ja sobrid apskatamais simbols ir tads pats, ..
     // .. ka ieprieksejais, tad tas ir musu gadijums
//     cout << phrase[0];
//     for (int i = 0; i < phrase_length; i++)
//     {
//         cout << phrase[i];
//     }
     int i = 0;
     char curr_char, next_char;
     
     while(phrase[i] != '\0')
     {
         curr_char = phrase[i];
         next_char = phrase[i+1];
         
         if (curr_char == next_char)
         {
             cout << "Ja, simbols " << curr_char << " atkartojas pec kartas.";
             return;
         }
         i++;
     }
     cout << "Ne, simbolu, kas atkartojas, saja fraze nav";
}
//Vingrin�jums 2. (lab6.3b.cpp)
//Dota simbolu virkne s. Noskaidrot, vai k�ds simbols �aj� simbolu virkn� atk�rtojas.
//Piem�ram, simbolu virkn� �Hallo, World!� atk�rtojas simboli �l� un �o�. (Atbildei j�b�t � j� vai n�)
void char_repeats(char phrase[])
{
     
}

//Vingrin�jums 3. (lab6.3c.cpp)
//Dots int mas�vs arr[n].
//Noskaidrot, vai k�ds skaitlis �aj� mas�v� atk�rtojas.
//Piem�ram, mas�v�, {1,2,1,5,3} atk�rtojas skaitlis 1. (Atbildei j�b�t � j� vai n�)
bool int_repeats(int phrase[])
{
     return true;
}

int main()
{
    char s[1008];        
    cout << "Ievadiet frazi: ";
    cin >> s;
 
    char_repeats_in_a_row(s);
    char_repeats(s);

    cout << endl;
    system("pause");
    return 0;
}
