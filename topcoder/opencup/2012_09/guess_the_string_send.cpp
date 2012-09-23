#include <iostream>
#include <fstream>
using namespace std;

bool response(){
    fflush(stdout);
    string response = "";
    cin >> response;
    return response == "Yes"
        || response == "Exit";
}
bool is_in_word(char c){
    cout << "*" << c << "*" << endl;
    return response();
}
bool is_subword(string subword){
    cout << subword << "*" << endl;
    return response();
}
bool is_word(string word){
    cout << word;
    return response();
}

int main()
{
    char alphabet [] =
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // let's go through alphabet and ask about each char
    const int alphabet_size = 26;
    char subalphabet[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int subalphabet_size = 0;
    for (int i = 0; i < alphabet_size; i++)
    {
        if (is_in_word(alphabet[i]))
        {
            subalphabet[subalphabet_size]  = alphabet[i];
            subalphabet_size++;
        }
    }

    string previous_word = "";
    string current_word = "";

    for(int position = 0; position < 10; position++)
    {
        int i = 0;
        bool correct = false;
        previous_word = current_word;

        while(subalphabet[i] != 0 && !correct)
        {
            current_word += subalphabet[i];
            correct = is_subword(current_word);
            i++;
        }
        if (i == subalphabet_size && !correct){
            is_word(previous_word);
            return 0;
        }
    }
    is_word(current_word);
    return 0;
}
