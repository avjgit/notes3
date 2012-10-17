#include <iostream>
#include <math.h>
using namespace std;

// general utils, not specific to some problem

// prints the string
void print(string text)
{
    cout << endl << text;
}

// print an array
void print(int* array, int size)
{
    print("--------------");
    for (int i = 0; i <= size; i++)
        cout << endl << "element " << i << " is " << array[i];
}

// print out a question and get an input as integer
int request_int(string question)
{
    int answer = -1;
    while (answer < 0)
    {
        print(question);
        cin >> answer;
        if (answer <0) print("Your input was incorrect.");
    }
    return answer;
}
// print out a question and get an input as character
char request_chr(string question)
{
    char answer;
    print(question);
    cin >> answer;
    return answer;
}
