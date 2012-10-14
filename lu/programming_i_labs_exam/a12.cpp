#include <iostream>
#include <math.h>
using namespace std;
// Prasības:
// 01) Ievadot loģiski nepareizus datus, programmai jāizdod atbilstošs paziņojums.
// 02) Jābūt iespējai programmu izpildīt atkārtoti.
// Atrādot programmu, jāatrāda
// a) programmas teksts,
// b) testa piemēri,
// c) programma darbībā.
// Precīzākas prasības sk. Laboratorijas darbu noteikumos.
// A12. Dots naturāls skaitlis n.
// Izdrukāt skaitli, kurš iegūts no dotā skaitļa, izmetot ciparu k.
// (Piemēram, ja n=12025 un k=2, jāiegūst 105).
// Skaitļa dalīšana ciparos jāveic skaitliski.

int number_order(const int number)
{
    const int base = 10;
    int order = 0;
    while (pow(base, order) <= number) order++;
    return --order;
}

int main()
{
    int number;
    cout << "Enter positive integer to process: ";
    // cin >> number;
    number = 4321;
    int order = number_order(number);
    int *digits = new int[order+1]; // array to store number's digits; +1 cell for '\0'

    int current_order = order;
    int number_to_process = number;
    int foundation;
    int digit;
    // for(int i = 0; i <= order; i++)
    // {
    //     // number_to_process = number - number_to_process;
    //     // foundation = (int)pow(10, current_order);
    //     // digits[i] = number_to_process/ foundation;
    //     number_to_process = number - digits[i]*foundation;

    //     foundation = (int)pow(10, current_order);
    //     // digit = number_to_process/foundation;
    //     // number_to_process -= digit * foundation;
    //     cout << number_to_process;

    //     current_order--;
    // }

    foundation = (int)pow(10, current_order);

    digit = number_to_process/foundation;
    cout << endl << digit;

    number_to_process -= digit * foundation;
    cout << endl << number_to_process;

    current_order--;


    foundation = (int)pow(10, current_order);

    digit = number_to_process/foundation;
    cout << endl << digit;

    number_to_process -= digit * foundation;
    cout << endl << number_to_process;

    // for (int i = 0; i <= order; i++) cout << endl << "digit " << i+1 << " is " << digits[i];

    system("pause");
    return 0;
}
