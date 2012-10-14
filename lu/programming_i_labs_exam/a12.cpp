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


int get_nth_order_digit(const int number, int nth )
{
    return nth;
}
int main()
{
    int number;
    cout << "Enter positive integer to process: ";
    // cin >> number;
    number = 654321;
    int order = number_order(number);
    int *digits = new int[order+1]; // array to store number's digits; +1 cell for '\0'

    int current_order = order;
    int number_to_process = number;
    double foundation;
    int digit;

    // algorithm A
    // for (int i = 0; i <= order; i++)
    // {
    //     foundation = pow(10, current_order);
    //     cout << endl << "foundation is " << foundation;

    //     digit = number_to_process/foundation;
    //     cout << endl << "digit is " << digit;

    //     number_to_process -= digit*foundation;

    //     current_order--;
    // }

    // digit = get_nth_order_digit(number, 3)
    int n = 3;
    int upper_bound = number/ pow(10,n);
    cout << endl << upper_bound;
    int lower_bound = (int)(number/ pow(10,n+1)) * 10;
    cout << endl << lower_bound;



    // for (int i = 0; i <= order; i++)
    // {
    //     foundation = pow(10, current_order);
    //     cout << endl << "foundation is " << foundation;

    //     digit = number_to_process/foundation;
    //     cout << endl << "digit is " << digit;

    //     number_to_process -= digit*foundation;

    //     current_order--;
    // }

    // for (int i = 0; i <= order; i++) cout << endl << "digit " << i+1 << " is " << digits[i];

    system("pause");
    return 0;
}
