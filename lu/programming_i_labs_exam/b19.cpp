// B19. Dots burts robežās no a līdz h un naturāls skaitlis n =< 8 . Piemēram, a2.
// Dotais pāris tiek uzskatīts par šaha galdiņa lauciņu, uz kura atrodas zirdziņš.
// Izdrukāt uz displeja šaha galdiņu,
// atzīmējot ar X tos lauciņus, kurus apdraud zirdziņš, bet pārējos ar 0.
#include "utils.h"

bool is_valid_move(int move)
{
    return move >= 0 && move < 8;
}

int* request_position()
{
    const int  upper_a = 'A'; // ASCII code for char 'A'
    const int  lower_a = 'a'; // ASCII code for char 'a'
    const int  size    =   8; // chessboardsize

    int* position = new int [2];

    int vertical = request_chr("Enter vertical: ");
    // int vertical = 'a';

    // check vertical input correctness
    if (vertical >= upper_a && vertical < upper_a + size)
    {
        vertical -= upper_a;
    }
    else if (vertical >= lower_a && vertical < lower_a + size)
    {
        vertical -= lower_a;
    }

    int horizontal = request_int("Enter horizontal: ") - 1;
    // int horizontal = 2-1;

    position[0] = vertical;
    position[1] = horizontal;

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
    for(int horizontal = size-1; horizontal >= 0; horizontal--)
        for(int vertical = 0; vertical < size ; vertical++)
            board[horizontal][vertical] = empty;

    int* position = request_position();
    int vertical = position[0];
    int horizontal = position[1];

    // int horizontal = 2-1;

    board[horizontal][vertical] = knight;

    int v_move;

    v_move = vertical + move2;
    if( is_valid_move(v_move) )
    {
        board[horizontal + move1][v_move] = capture;
        board[horizontal - move1][v_move] = capture;
    }

    v_move = vertical - move2;
    if( is_valid_move(v_move) )
    {
        board[horizontal + move1][v_move] = capture;
        board[horizontal - move1][v_move] = capture;
    }

    v_move = vertical + move1;
    if( is_valid_move(v_move) )
    {
        board[horizontal + move2][v_move] = capture;
        board[horizontal - move2][v_move] = capture;
    }

    v_move = vertical - move1;
    if( is_valid_move(v_move) )
    {
        board[horizontal + move2][v_move] = capture;
        board[horizontal - move2][v_move] = capture;
    }

    // print board
    for(int horizontal = size-1; horizontal >= 0; horizontal--)
    {
        cout << horizontal+1 << "| ";
        for(int vertical = 0; vertical < size ; vertical++)
        {
            cout << board[horizontal][vertical] << " ";
        }
        cout << endl;
    }
    cout << "   _______________" << endl;
    cout << "   a b c d e f g h" << endl;


    system("pause");
    return 0;
}