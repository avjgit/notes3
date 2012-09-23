#include <iostream>
#include <fstream>
using namespace std;

string yes = "Yes";
string no = "No";
string correct = "Exit";
string response = "";

bool response_received(){
    fflush(stdout);
    cin >> response;
    return response == yes ||
           response == correct;
}
bool is_in_word(char c){
    cout << "*" << c << "*" << endl;
    return response_received();
}
bool is_subword(string substring){
    cout << substring << "*" << endl;
    return response_received();
}
bool is_word(string word){
    cout << word;
    return response_received();
}

int main()
{
    const int queries_limit = 150;
    int queries = 0;

    char alphabet [] =
    {'a', 'b', 'c', 'd', 'e', 'f',
     'g', 'h', 'i', 'j', 'k', 'l',
     'm', 'n', 'o', 'p', 'q', 'r',
     's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

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
        queries++;
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
