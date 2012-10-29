// Student: Andrejs Jurcenoks aj05044
// Creation date: 2012/10/30

// REQUIREMENTS:
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
// -------------------------------------------

#include "utils.h"

// usage of global constant in production systems should be avoided
// used in this homework for clarity purposes
const int base = 10; // counting base (decimal)


// gets order of a number (eg, for 98765 it'll return 4)
int number_order(const int number)
{
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
    double order = pow(base, n);                            // on which order (eg, 100 or 10000) to search
    int upper_bound =  number/ (int)order;                  // with 98765 and n=2, gets 987
    int lower_bound = (number/ (int)(order * base)) * base; // with 98765 and n=2, gets 980
                                                            // complicated casting is because of issues with types
    return upper_bound - lower_bound;                       // with 98765 and n=2, returns 987-980
}

// splits number to array, according to order of each digit, counting from right
int* int_to_array(int number)
{
    int order = number_order(number);   // order of a number (how long it is)
    int *digits = new int[order+1];     // array to store number's digits
                                        // fill in array with digits
    while(order >= 0) digits[order--] = get_nth_order_digit(number, order);
    return digits;
}

// concatenates array to number
int array_to_int(int* array, int size)
{
    int number = 0;
    double order;
    for(int i = 0; i <= size; i++)
    {
        // casted in advance because of issues with casting "on the flight"
        order = pow(base, i);
        number += array[i] * (int)order;
        // cout << endl << "multiplied " << array[i] << " with " << order << ", got " << number;
    }
    return number;
}

// the function to solve a problem
// removes a digit from a number
int a12(int number, int removable)
{
    int  order  = number_order(number);     // order of a number (as power of 10; eg, for 12025 is 4)
    int* digits = int_to_array(number);     // splits a number to an array

    int* digits_cleaned = new int[order+1]; // result array to store number after removing certain digit
    int  new_order = 0;

    for(int i = 0; i <= order; i++)
    {
        // looping through numbers' digits;
        if (digits[i] != removable)
        {
            // if digit is not the one to be removed, then copying it to result array
            digits_cleaned[new_order++] = digits[i];
        }
    }
    new_order--;
    return array_to_int(digits_cleaned, new_order);
}

// function for manually input of data to function, which solves a problem
void a12_manual()
{
    int number;
    int removable;
    char repeat = 'y';
    while (repeat == 'y')
    {
        number    = request_int("Enter positive integer to process: ");
        removable = request_int("Enter digit you want to remove: ");
        cout << endl << "Result: " << a12(number, removable);
        repeat    = request_chr("Would you like to repeat? y/n ");
    }
    print("Program is over. ");
}

int main()
{
    // running automatic tests
    test( "9876/7",  986, a12( 9876, 7));
    test("12025/2",  105, a12(12025, 2));
    test("12025/0", 1225, a12(12025, 0));
    test(  "101/0",   11, a12(  101, 0));
    test(    "0/0",    0, a12(    0, 0));
    test(    "1/1",    0, a12(    1, 1));

    // running with user input
    a12_manual();

    system("pause");
    return 0;
}
