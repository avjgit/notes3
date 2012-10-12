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

int number_order(const int base, const int number)
{
    int order = 0;
    while (pow(base, order) <= number) order++;
    return --order;
}

int main()
{
    int number;
    const int base = 10;
    cout << "Enter positive integer: ";
    // cin >> number;
    number = 12025;
    int order = number_order(base, number);
    int *digits = new int[order+1]; // array to store number's digits; +1 cell for '\0'

    while(order >= 0)
    {
        digits[order] = number/ (int)pow(base, order);
        order--;
    }

    system("pause");
    return 0;
}