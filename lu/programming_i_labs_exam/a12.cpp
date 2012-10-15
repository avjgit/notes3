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

// print an array
void print(int* array, int size)
{
    cout << endl << "--------------";
    for (int i = 0; i <= size; i++) cout << endl << "element " << i << " is " << array[i];
}
void print(string text)
{
    cout << endl << text;
}

// print out a question and get an input
int request(string question)
{
    int answer = -1;
    while (answer < 0)
    {
        cout << endl << question;
        cin >> answer;
        if (answer <0)
            cout << "Your input was incorrect.";
    }
    return answer;
}

// gets order of a number (eg, for 98765 it'll return 4)
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
    const int base = 10;                                    // counting base (decimal)
    double order = pow(base, n);                            // on which order (eg, 100 or 10000) to search
    int upper_bound =  number/ (int)order;                  // with 98765 and n=2, gets 987
    int lower_bound = (number/ (int)(order * base)) * base; // with 98765 and n=2, gets 980
                                                            // complicated casting is because of issues with types
    // cout << endl << "for n " << n << ": ";
    // cout << endl << "foundation is " << order;           // output for debugging purposes
    // cout << endl << "upper bound is " << upper_bound;
    // cout << endl << "lower bound is " << lower_bound;
    // cout << endl << (upper_bound - lower_bound);
    return upper_bound - lower_bound;                       // with 98765 and n=2, returns 987-980
}

// splits number to array, according to order of each digit, counting from right
int* int_to_array(int number)
{
    int order = number_order(number);   // order of a number (how long it is)
    int *digits = new int[++order];     // array to store number's digits; +1 cell for '\0'
                                        // fill in array with digits
    while(order >= 0) digits[order--] = get_nth_order_digit(number, order);
    return digits;
}

// concatenates array to number
int array_to_int(int* array, int size)
{
    int number = 0;
    int base = 10;
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



int a12()
{
    char repeat = 'y';
    while (repeat == 'y')
    {
        int number    = request("Enter positive integer to process: ");
        int removable = request("Enter digit you want to remove: ");
        int order     = number_order(number);
        int* digits   = int_to_array(number);

        // clean a digit from a number
        int* digits_cleaned = new int[order+1];
        int new_order = 0;

        for(int i = 0; i <= order; i++)
        {
            if (digits[i] != removable)
            {
                digits_cleaned[new_order++] = digits[i];
            }
        }
        new_order--;

        int number_cleaned = array_to_int(digits_cleaned, new_order);

        cout << endl << "Result: " << number_cleaned << endl << endl;

        cout << endl << "Would you like to repeat? y/n ";
        cin >> repeat;
    }
    cout << endl << "Program is over." << endl;
}

int main()
{
    a12();

    system("pause");
    return 0;
}
