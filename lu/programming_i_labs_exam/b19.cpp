// B19. Dots burts robežās no a līdz h un naturāls skaitlis n =< 8 . Piemēram, a2.
// Dotais pāris tiek uzskatīts par šaha galdiņa lauciņu, uz kura atrodas zirdziņš.
// Izdrukāt uz displeja šaha galdiņu,
// atzīmējot ar X tos lauciņus, kurus apdraud zirdziņš, bet pārējos ar 0.
#include "utils.h"

bool is_on_board(int dimension)
{
    const int size = 8; // chessboardsize
    return dimension >= 0 && dimension < size;
}

bool is_on_board(int *position)
{
    return is_on_board(position[0]) &&
           is_on_board(position[1]);
}

bool is_on_board(int file, int char_code)
{
    const int size = 8; // size of chessboard;
    return file >= char_code && file < char_code + size;
}

// converts input of 'a' to 0 (first file)
int to_file(int file)
{
    const int  uppercase = 'A'; // ASCII code for char 'A'
    const int  lowercase = 'a'; // ASCII code for char 'a'
    const int size = 8; // size of chessboard

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
// converts input of '1' to 1 (first file)
int to_rank(int rank)
{
    const int one_char = '1';
    return rank - one_char;
}

int* request_position2()
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

int main()
{
    const char knight  = 'K';
    const char capture = 'X';
    const char empty   = '.';

    const int  size    =   8; // chessboardsize
    const int  move1   =   1; // knights' move consists of one- and two-cell moves
    const int  move2   =   2;

    int moves[2] = {1, 2};
    int directions[2] = {-1, 1};

    char board[size][size];

    // print and initialize board
    for(int rank = size-1; rank >= 0; rank--)
        for(int file = 0; file < size ; file++)
            board[rank][file] = empty;

    int* position = request_position2();

    // file - chessboard column
    // rank - chessboard row

    int file = position[0];
    int rank = position[1];

    // int rank = 2-1;

    board[rank][file] = knight;

    int v_move;

    v_move = file + move2;
    if( is_on_board(v_move) )
    {
        board[rank + move1][v_move] = capture;
        board[rank - move1][v_move] = capture;
    }

    v_move = file - move2;
    if( is_on_board(v_move) )
    {
        board[rank + move1][v_move] = capture;
        board[rank - move1][v_move] = capture;
    }

    v_move = file + move1;
    if( is_on_board(v_move) )
    {
        board[rank + move2][v_move] = capture;
        board[rank - move2][v_move] = capture;
    }

    v_move = file - move1;
    if( is_on_board(v_move) )
    {
        board[rank + move2][v_move] = capture;
        board[rank - move2][v_move] = capture;
    }

    // print board
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


    system("pause");
    return 0;
}