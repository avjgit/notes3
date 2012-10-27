// B19. Dots burts robežās no a līdz h un naturāls skaitlis n =< 8 . Piemēram, a2.
// Dotais pāris tiek uzskatīts par šaha galdiņa lauciņu, uz kura atrodas zirdziņš.
// Izdrukāt uz displeja šaha galdiņu,
// atzīmējot ar X tos lauciņus, kurus apdraud zirdziņš, bet pārējos ar 0.
#include "utils.h"

// checks if any dimension is on board
// ranks 1..8 and files a..h are represented as 0..7
bool is_on_board(int dimension)
{
    const int size = 8; // chessboardsize
    return dimension >= 0 && dimension < size;
}

// checks if position is on board (a1 till h8 - [0][0] till [7][7])
bool is_on_board_pointer(int *position)
{
    return is_on_board(position[0]) &&
           is_on_board(position[1]);
}

bool is_on_board(int file, int char_code)
{
    return is_on_board(file - char_code);
}

// converts input of 'a' to 0 (first file)
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

    while (!is_on_board_pointer(position))
    {
        print("Enter knight's position, from a1 to h8: ");
        cin >> answer;
        position[0] = to_file(answer[0]);
        position[1] = to_rank(answer[1]);

        if (!is_on_board_pointer(position))
        {
            print("You have entered incorrect data.");
        }
    }
    return position;
}

void print_chessboard(char board[8][8])
{
    const int  size    =   8; // chessboardsize
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

    // initialize board
    for(int rank = size-1; rank >= 0; rank--)
        for(int file = 0; file < size ; file++)
            board[rank][file] = empty;

    // file - chessboard column
    // rank - chessboard row
    int* position = request_position();
    int file = position[0];
    int rank = position[1];

    board[rank][file] = knight;

    // for (int rank_direction = 0; rank_direction <= 1; rank_direction++)
    // {
    //     for (int rank_move = 0; rank_move <= 1; rank_move++)
    //     {
    //         for (int file_direction = 0; file_direction <= 1; file_direction++)
    //         {
    //             int file_move = rank_move? moves[0] : moves[1];
    //             int file_captured = file + directions[file_direction] * file_move;
    //             int rank_captured = rank + directions[rank_direction] * moves[rank_move];

    //             if ( is_on_board(file_captured))
    //             {
    //                  board[rank_captured][file_captured] = capture;
    //             }

    //             cout << endl << "------";
    //             cout << endl << "rank_direction: " << rank_direction;
    //             cout << endl << "rank_move: " << moves[rank_move];
    //             cout << endl << "file_direction: " << file_direction;
    //             cout << endl << "file_move: " << file_move;

    //             cout << endl << "file_captured: " << file_captured + 1;
    //             cout << endl << "rank_captured: " << rank_captured + 1;

    //             // cout << endl << "directions[file_direction]: " << directions[file_direction];
    //             // cout << endl << "is_on_board(file_captured): " << is_on_board(file_captured);
    //             cout << endl;
    //             system("pause");
    //         }
    //     }
    // }

    int v_move;
    v_move = file + move2;
    cout << endl << "file 0 is " << file;
    if( is_on_board(v_move) )
    {
        board[rank + move1][v_move] = capture;
        board[rank - move1][v_move] = capture;
    }

    v_move = file - move2;
    cout << endl << "file 1 is " << file;
    cout << endl << "v_move is " << v_move;
    if( is_on_board(v_move) )
    {
        board[rank - move1][v_move] = capture;
        cout << endl << "file 1.1 is " << file;
        board[rank + move1][v_move] = capture;
        cout << endl << "file 1.2 is " << file;
        // board[rank - move1][v_move] = capture;
        // cout << "wtf";
        cout << endl << "file 1.3 is " << file;
    }

    v_move = file + move1;
    cout << endl << "file 2 is " << file;
    if( is_on_board(v_move) )
    {
        board[rank + move2][v_move] = capture;
        board[rank - move2][v_move] = capture;
    }

    v_move = file - move1;
    cout << endl << "file 3 is " << file;

    cout << "last v_move is " << v_move;
    if( is_on_board(v_move) )
    {
        cout << "hey, I'm inside" << endl;
        board[rank + move2][v_move] = capture;
        board[rank - move2][v_move] = capture;
    }

    // for (int file_direction = 0; file_direction <= 1; file_direction++)
    // {
    //     for (int file_move = 0; file_move < 1; file_move++)
    //     {
    //         v_move = file + directions[file_direction]*move2;
    //         if( is_on_board(v_move) )
    //         {
    //             board[rank + move1][v_move] = capture;
    //             board[rank - move1][v_move] = capture;
    //         }

    //         v_move = file + directions[file_direction]*move1;
    //         if( is_on_board(v_move) )
    //         {
    //             board[rank + move2][v_move] = capture;
    //             board[rank - move2][v_move] = capture;
    //         }
    //     }
    // }

    print_chessboard(board);

    system("pause");
    return 0;
}
