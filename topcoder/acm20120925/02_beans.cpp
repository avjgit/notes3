#include <fstream>
#include <iostream>
using namespace std;

bool is_vowel(char c)
{
    char vowels[] = {'A', 'E', 'I', 'O', 'U', 'Y'};
    for(int i = 0; i < 6; i++)
    {
        if (vowels[i] == c)
        {
            return true;
        }
    }
    return false;
}
int main()
{

    string result = "";
    string vowels_substring  = "";
    char letter;
    ifstream input;
    ofstream output;


    input.open("bean.in");
    letter=input.get();
    while(input.good())
    {
        //cout << "current letter is " << letter << endl;
        //cout << vowels_substring << endl;

        if (letter != 'ÿ'){
            if (is_vowel(letter))
           {
                vowels_substring += letter;
                //result += letter;
            }
            else
            {
                if (vowels_substring != ""){
                    result += vowels_substring;
                    result += 'P';
                    result += vowels_substring;
                }
                result += letter;
                vowels_substring = "";
            }
        }
        letter=input.get();
    }

    if (vowels_substring != ""){
        result += vowels_substring;
        result += 'P';
        result += vowels_substring;
    }

    output.open("bean.out");
    output << result;
    input.close();
    output.close();
    return 0;
}

