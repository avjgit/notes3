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

// gets Nth digit from number, starting with 0, counting from right
// example get_nth_order_digit(98765, 2) = 7
// algorithm: to get "7" out of 98765,
// we can from 98700 substract 98000 and divide with 100;
// or from 987 substract 980
int get_nth_order_digit(const int number, int n )
{
    const int base = 10;                                   // counting base (decimal)
    int upper_bound = number/ pow(base,n);                 // with 98765 and n=2, gets 987
    int lower_bound = (int)(number/ pow(base,++n)) * base; // with 98765 and n=2, gets 980
    return upper_bound - lower_bound;                      // with 98765 and n=2, returns 987-980
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

    cout << get_nth_order_digit(number, 3);


    for (int i = order; i >= 0; i--)
    {
        digits[order-i] = get_nth_order_digit(number, i);
    }

    for (int i = 0; i <= order; i++) cout << endl << "digit " << i+1 << " is " << digits[i];

    system("pause");
    return 0;
}
