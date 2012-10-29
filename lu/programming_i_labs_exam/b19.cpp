// Student: Andrejs Jurcenoks aj05044
// Creation date: 2012/10/30

// REQUIREMENTS:
// B19. Dots burts robežās no a līdz h un naturāls skaitlis n =< 8 . Piemēram, a2.
// Dotais pāris tiek uzskatīts par šaha galdiņa lauciņu, uz kura atrodas zirdziņš.
// Izdrukāt uz displeja šaha galdiņu,
// atzīmējot ar X tos lauciņus, kurus apdraud zirdziņš, bet pārējos ar 0.
// -------------------------------------------------------------------------------

#include "utils.h"

const int size = 8; // size of a chessboard

// checks if this dimension is on board
// ranks 1..8 and files a..h are represented as 0..7
bool is_on_board(int dimension)
{
    return dimension >= 0 && dimension < size;
}

// checks if position is on board (a1 till h8 - [0][0] till [7][7])
bool is_on_board(int *position)
{
    return is_on_board(position[0]) &&
           is_on_board(position[1]);
}

bool is_on_board(int file, int char_code)
{
    return is_on_board(file - char_code);
}

// converts input of 'a' or 'A' to 0 (first file)
int to_file(int file)
{
    const int  uppercase = 'A'; // ASCII code for char 'A'
    const int  lowercase = 'a'; // ASCII code for char 'a'

    if (is_on_board(file, uppercase))
    {
        file -= uppercase;
    }
    else if (is_on_board(file, lowercase))
    {
        file -= lowercase;
    }
    return file;
}
// converts input of '1' to 0 (first rank)
int to_rank(int rank)
{
    const int one_char = '1';
    return rank - one_char;
}

int* position_string_to_array(string answer)
{
    int* position = new int[2];
    position[0] = to_file(answer[0]);
    position[1] = to_rank(answer[1]);
    return position;
}

int* request_position()
{
    int* position = new int[2];

    position[0] = -1; // filling with incorrect data to start loop
    position[1] = -1;

    string answer;

    while (!is_on_board(position))
    {
        print("Enter knight's position, from a1 to h8: ");
        cin >> answer;
        position[0] = to_file(answer[0]);
        position[1] = to_rank(answer[1]);

        if (!is_on_board(position))
        {
            print("You have entered incorrect data.");
        }
    }
    return position;
}

void print_chessboard(char board[8][8], int* position)
{
    int lowercase_a = 'a';
    char file = lowercase_a + position[0];
    int rank = position[1] + 1;

    cout << endl << "Fields captured by knight on "
        << file << rank << ":" <<endl;

    cout << endl;
    for(int rank = size-1; rank >= 0; rank--)
    {
        cout << rank+1 << "| ";
        for(int file = 0; file < size ; file++)
        {
            cout << board[rank][file] << " ";
        }
        cout << endl;
    }
    cout << "   _______________" << endl;
    cout << "   a b c d e f g h" << endl;
}

void b19(int* position)
{
    const char knight  = 'K';       // symbol of Knight
    const char capture = 'X';       // symbol of captured field
    const char empty   = '.';       // symbol of empty field
    int moves[2]       = {1, 2};    // length of knight's moves: one or two cells
    int directions[2]  = {-1, 1};   // direction of knight's moves: up/down in either dimension
    char board[size][size];         // our chessboard

    // initialize board; mark all squares as empty
    for(int rank = size-1; rank >= 0; rank--)
        for(int file = 0; file < size ; file++)
            board[rank][file] = empty;

    int file = position[0];             // file is a chessboard term for a column
    int rank = position[1];             // rank is a chessboard term for a row
    board[rank][file] = knight;         // mark knight's position on board

    //
    // the BIG loop for calculating knight's captured squares
    //
    // for each direction - up or down - for rank ..
    for (int rank_direction = 0; rank_direction <= 1; rank_direction++)
    {
        // .., and for each possible move - 1 or 2 cells, on rank..
        for (int rank_move = 0; rank_move <= 1; rank_move++)
        {
            // .., and for each possible direction for file:
            for (int file_direction = 0; file_direction <= 1; file_direction++)
            {
                // calculate move per file
                // (trick is, if you move knight ONE cell right, you can move just TWO cells up or down)
                int file_move = rank_move? moves[0] : moves[1];
                int file_captured = file + directions[file_direction] * file_move;
                int rank_captured = rank + directions[rank_direction] * moves[rank_move];

                if
                (
                    // if file and rank are on board (1..8)
                    is_on_board(file_captured) &&
                    is_on_board(rank_captured)
                )
                {
                    // then mark this square as captured
                    board[rank_captured][file_captured] = capture;
                }
            }
        }
    }
    print_chessboard(board, position);
}

void b19_manual()
{
    char repeat = 'y';
    while (repeat == 'y')
    {
        int* position = request_position(); // ask user where knight will be placed
        b19(position);
        repeat = request_chr("Would you like to repeat? y/n ");
    }
    print("Program is over. ");
}

int main()
{
    b19_manual();
    system("pause");
    return 0;
}
// test examples:

// input: a1
// displayed:
// 8 | . . . . . . . .
// 7 | . . . . . . . .
// 6 | . . . . . . . .
// 5 | . . . . . . . .
// 4 | . . . . . . . .
// 3 | . X . . . . . .
// 2 | . . X . . . . .
// 1 | K . . . . . . .
//     _______________
//     a b c d e f g h

// input: a8
// displayed:
// 8 | K . . . . . . .
// 7 | . . X . . . . .
// 6 | . X . . . . . .
// 5 | . . . . . . . .
// 4 | . . . . . . . .
// 3 | . . . . . . . .
// 2 | . . . . . . . .
// 1 | . . . . . . . .
//     _______________
//     a b c d e f g h

// input: h8
// displayed:
// 8 | . . . . . . . K
// 7 | . . . . . X . .
// 6 | . . . . . . X .
// 5 | . . . . . . . .
// 4 | . . . . . . . .
// 3 | . . . . . . . .
// 2 | . . . . . . . .
// 1 | . . . . . . . .
//     _______________
//     a b c d e f g h

// input: h1
// displayed:
// 8 | . . . . . . . .
// 7 | . . . . . . . .
// 6 | . . . . . . . .
// 5 | . . . . . . . .
// 4 | . . . . . . . .
// 3 | . . . . . . X .
// 2 | . . . . . X . .
// 1 | . . . . . . . K
//     _______________
//     a b c d e f g h

// input: d4
// displayed:
// 8 | . . . . . . . .
// 7 | . . . . . . . .
// 6 | . . X . X . . .
// 5 | . X . . . X . .
// 4 | . . . K . . . .
// 3 | . X . . . X . .
// 2 | . . X . X . . .
// 1 | . . . . . . . .
//     _______________
//     a b c d e f g h
