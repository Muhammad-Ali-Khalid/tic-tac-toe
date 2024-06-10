// Tic-Tac-Toe Game in C++
// Muhammad Ali Khalid
#include <iostream>

using namespace std;

void display_board(char arr[3][3]);              // To display the grid of game
void player1_turn(char arr[3][3]);               // Allows player1 to enter its move
void player2_turn(char arr[3][3]);               // Allows player2 to enter its move
void game_decision(char arr[3][3], char symbol); // Decides who win the game
int main()
{
    char board[3][3];
    char num = '0';
    char sign;
    cout << "Player 1 sign: X" << endl;
    cout << "Player 2 sign: O" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ++num;
        }
    }
    int i = 1;
    display_board(board);
    while (i < 11)
    {
        if (i == 10)
        {
            cout << "Match Draw" << endl;
            exit(0);
        }
        if (i % 2 != 0)
        {
            player1_turn(board);
            display_board(board);
            sign = 'X';
        }
        if (i % 2 == 0)
        {
            player2_turn(board);
            display_board(board);
            sign = 'Y';
        }
        if (i >= 5)
            game_decision(board, sign);
        i++;
    }
    return 0;
}

void display_board(char arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << "    ";
        }
        cout << endl;
    }
    cout << "===========";
    cout << endl;
}

void player1_turn(char arr[3][3])
{
    char entry;
    bool checker = true;
    while (checker)
    {
        cout << "Enter your move player 1: ";
        cin >> entry;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (entry == arr[i][j])
                {
                    arr[i][j] = 'X';
                    checker = false;
                }
            }
        }
    }
}

void player2_turn(char arr[3][3])
{
    char entry;
    bool checker = true;
    while (checker)
    {
        cout << "Enter your move player 2: ";
        cin >> entry;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (entry == arr[i][j])
                {
                    arr[i][j] = 'O';
                    checker = false;
                }
            }
        }
    }
}

void game_decision(char arr[3][3], char symbol)
{
    if ((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) || (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) || (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]) || (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]) || (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]) || (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]) || (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))
    {
        if (symbol == 'X')
        {
            cout << "Player 1 wins" << endl;
            exit(0);
        }
        else
        {
            cout << "Player 2 wins" << endl;
            exit(0);
        }
    }
}
