#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//Laboratorijas darbs 6.3. Vingrinâjumi par masîviem un simbolu virknçm
//Vingrinâjums 1. (lab6.3a.cpp)
//Dota simbolu virkne s. Noskaidrot, vai kâds simbols ðajâ simbolu virknç atkârtojas pçc kârtas.
//Piemçram, simbolu virknç „Hallo, World!” pçc kârtas atkârtojas simbols ‘l’. (Atbildei jâbût – jâ vai nç)
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
         
         cout << "curr_char is " << curr_char << endl;
         cout << "next_char is " << next_char << endl;         
         
         if (curr_char == next_char)
         {
             cout << "Ja, simbols " << curr_char << " atkartojas pec kartas.";
             return;
         }
         i++;
     }
     cout << "Ne, simbolu, kas atkartojas, saja fraze nav";
}
//Vingrinâjums 2. (lab6.3b.cpp)
//Dota simbolu virkne s. Noskaidrot, vai kâds simbols ðajâ simbolu virknç atkârtojas.
//Piemçram, simbolu virknç „Hallo, World!” atkârtojas simboli ‘l’ un ‘o’. (Atbildei jâbût – jâ vai nç)
void char_repeats(char phrase[])
{
     cout << "asdf";
     for (int i = 0; phrase[i] != '\0'; i++)
     {
//         cout << "checking " << phrase[i];
         
         for (int j = i+1; phrase[j] != '\0';  j++)
         {
//             cout << "; comparing with " << phrase[j];
             if (phrase[i] == phrase[j])
             {          
                 cout << "Ja, simbols " << phrase[i] << " atkartojas.";
                 return;
             }
         }
     }

     cout << "Ne, simbolu, kas atkartojas, saja fraze nav";     
}

//Vingrinâjums 3. (lab6.3c.cpp)
//Dots int masîvs arr[n].
//Noskaidrot, vai kâds skaitlis ðajâ masîvâ atkârtojas.
//Piemçram, masîvâ, {1,2,1,5,3} atkârtojas skaitlis 1. (Atbildei jâbût – jâ vai nç)
void int_repeats(int phrase[])
{
     for (int i = 0; phrase[i] != '\0'; i++)
     {
         for (int j = i+1; phrase[j] != '\0';  j++)
         {
             if (phrase[i] == phrase[j])
             {          
                 cout << "Ja, simbols " << phrase[i] << " atkartojas.";
                 return;
             }
         }
     }
     cout << "Ne, simbolu, kas atkartojas, saja fraze nav";    
}

int main()
{
//    char s[100];
//    cout << "Ievadiet frazi: ";
//    cin >> s;
    char s[] = "Halxo worldd";
 
    char_repeats_in_a_row(s);
    char_repeats(s);
    
    int i[] = {1, 2, 1, 5, 3};
    int_repeats(i);

    cout << endl;
    system("pause");
    return 0;
}
