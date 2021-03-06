#include "utils.h"

int number_order(const int number)
{
    const int base = 10;
    int order = 0;
    while (pow(base, order) <= number) order++;
    return --order;
}

int test()
{
    int x = 1;
    return x--;
}

bool is_incorrect(int *position)
{
    const int size = 8; // chessboardsize
    return position[0] < 0 || position[0] >= size
        || position[1] < 0 || position[1] >= size;
}

bool is_within_board(int file, int char_code)
{
    const int size = 8; // size of chessboard;
    return file >= char_code && file < char_code + size;
}
bool is_uppercase(int file)
{
    return is_within_board(file, 'A');
}
bool is_lowercase(int file)
{
    return is_within_board(file, 'a');
}

// converts input of 'a' to 0 (first file)
int to_file(int file)
{
    const int  upper_a = 'A'; // ASCII code for char 'A'
    const int  lower_a = 'a'; // ASCII code for char 'a'
    const int size = 8; // size of chessboard

    if (is_uppercase(file))
    {
        file -= upper_a;
    }
    else if (is_lowercase(file))
    {
        file -= lower_a;
    }
    return file;
}
// converts input of '1' to 1 (first file)
int to_rank(int rank)
{
    const int one_char = '1';
    return rank - one_char;
}

int* request_position()
{
    int* position = new int[2];

    position[0] = -1; // filling with incorrect data to start loop
    position[1] = -1;

    string answer;

    while (is_incorrect(position))
    {
        print("Enter position: ");
        cin >> answer;
        position[0] = to_file(answer[0]);
        position[1] = to_rank(answer[1]);

        if (is_incorrect(position))
        {
            print("You have entered incorrect data.");
        }
    }
    return position;
}

void mark_board(char* board)
{
    board[0] = 'marked';
}


int main()
{
    // int arr[5] = {};
    // cout << number_order(12345);
    // cout << test();

    // int* square  = request_position();

    // cout << "ok, square is " << square[0] << square[1];
    const int  uppercase = 'A'; // ASCII code for char 'A'

    // int test = 0;
    // int res = 15;

    // res = (test ? 1 : 0);

    // cout << res;

    // cout << endl << true;

    // int* temp_line = new int [1]; // fix to avoid compicated memory handling
    // delete[] temp_line;

    // string txt = "asdf";
    // txt += "qwe";
    // int d = 1;
    // char line_number[99];
    // itoa(d, line_number, 10);
    // // cout << d;
    // txt += line_number;
    // print(txt);

    // double d[1] = {1};
    // cout << d[0];

    int list[5];
    int amount = 0;
    list[amount++] = 999;
    cout << endl << list[0];
    cout << endl << amount;
    // cout << uppercase;

    system("pause");
    return 0;
}