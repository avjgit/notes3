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

// print out a question and get an input
int request(string question)
{
    int answer;
    cout << endl << question;
    cin >> answer;
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
    int *digits = new int[order+2];     // array to store number's digits; +1 cell for '\0'
    digits[order+1] = '\0';             // setting last element of the array
                                        // fill in array with digits
    while(order >= 0) digits[order--] = get_nth_order_digit(number, order);
    return digits;
}


int main()
{
    int number;
    // number = request("Enter positive integer to process: ");
    int removable;
    // removable = request("Enter digit you want to remove: ");
    number = 987654;

    // int order = number_order(number);   // order of a number (how long it is)
    // int *digits = new int[order+1];     // array to store number's digits; +1 cell for '\0'

    // // fill in array with digits
    // for (int i = order; i >= 0; i--)
    // {
    //     digits[i] = get_nth_order_digit(number, i);
    // }

    int *digits = int_to_array(number);
    // int digit = int_to_array(number);

    // output for debugging purposes
    // for (int i = 0; i <= 6; i++) cout << endl << "digit " << i << " is " << digits[i];
    int i = 0;
    while (digits[i] != '\0')
    {
        cout << endl << "digit " << i << " is " << digits[i];
        i++;
    }




    // int *output = new int [order];
    // int j = 0;
    // for (int i = 0; i <= order; i++)
    // {
    //     if (digits[i] != removable)
    //     {
    //         output[j] = digits[i];
    //         j++;
    //     }
    // }
    // output[j] = '\0';

    // int number_cleaned = 0;

    // while (j>0)
    // {
    //     j--;
    //     int m1 = output[j];
    //     int m2 = (int)pow(10, j);
    //     int mm = m1 * m2;
    //     number_cleaned += mm;
    //     cout << endl << "m1 is " << m1 << ", multiply with " << m2 << ", result: " << mm;
    //     cout << endl << "subsum so far - " << number_cleaned;
    //     // cout << endl << j-- << ": " << output[j];
    //     // cout << "to multiply with " << pow(10, j);
    //     // cout << "element is " << output[j] * pow(10, j);
    //     // number_cleaned += output[j] * (int)pow(10, j);
    //     // cout << endl << "subsum is " << number_cleaned;
    // }

    // cout << endl << number_cleaned;


    system("pause");
    return 0;
}
