#include <bits/stdc++.h>
using namespace std;

bool game_over = false; // Flag to check if the game is over

// check condition who wins
void check_condition(vector<vector<char>> &BOARD, string name1, string name2)
{
    for (int i = 0; i < 3; i++)
    {
        // check row for win
        if (BOARD[i][0] == BOARD[i][1] && BOARD[i][1] == BOARD[i][2])
        {
            if (BOARD[i][0] == 'X')
            {
                cout << name1 << " wins\n";
            }
            else // if (BOARD[i][0] == 'O')
            {
                cout << name2 << " wins\n";
            }
            game_over = true;
            return;
        }

        // check column for a win
        if (BOARD[0][i] == BOARD[1][i] && BOARD[1][i] == BOARD[2][i])
        {
            if (BOARD[0][i] == 'X')
            {
                cout << name1 << " wins\n";
            }
            else // if (BOARD[0][i] == 'O')
            {
                cout << name2 << " wins\n";
            }
            game_over = true;
            return;
        }
    }

    // for first diagonal
    if (BOARD[0][0] == BOARD[1][1] && BOARD[1][1] == BOARD[2][2])
    {
        if (BOARD[0][0] == 'X')
        {
            cout << name1 << " wins\n";
        }
        else // if (BOARD[0][0] == 'O')
        {
            cout << name2 << " wins\n";
        }
        game_over = true;
        return;
    }

    // for second diagonal
    if (BOARD[0][2] == BOARD[1][1] && BOARD[1][1] == BOARD[2][0])
    {
        if (BOARD[0][2] == 'X')
        {
            cout << name1 << " wins\n";
        }
        else // if (BOARD[0][2] == 'O')
        {
            cout << name2 << " wins\n";
        }
        game_over = true;
        return;
    }
}

// function for printing the tic tac board
void print(vector<vector<char>> &BOARD, string name1, string name2)
{
    system("cls");
    cout << "  ❌❌ TIC TAC TOE ⭕⭕  \n";
    cout << "---------------------\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "   " << BOARD[i][j] << "   ";
            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2)
            cout << "---------------------";
        cout << endl;
    }
}

// function for player move
void player_move(vector<vector<char>> &BOARD, string name, char symbol)
{
    int n;
    while (true)
    {
        cout << name << " enter your move  : ";
        cin >> n;
        if (n < 1 || n > 9)
        {
            cout << "Invalid move. Please try again.\n";
        }
        else if (BOARD[(n - 1) / 3][(n - 1) % 3] == 'X' || BOARD[(n - 1) / 3][(n - 1) % 3] == 'O')
        {
            cout << "This cell is already occupied. Please try again.\n";
        }
        else
        {
            BOARD[(n - 1) / 3][(n - 1) % 3] = symbol;
            break;
        }
    }
}

// function for the game loop
void loop(vector<vector<char>> &BOARD, string &name1, string &name2)
{
    for (int i = 1; i < 10 && !game_over; i++)
    {
        if (i % 2 != 0)
        {
            player_move(BOARD, name1, 'X');
        }
        else
        {
            player_move(BOARD, name2, 'O');
        }
        print(BOARD, name1, name2);
        check_condition(BOARD, name1, name2);
    }
    if (!game_over)
    {
        cout << "It's a draw\n";
    }
}

int main()
{
    system("cls"); // use for clear window
    cout << " ❌❌ TIC TAC TOE ⭕⭕";
    cout << endl;
    cout << endl;

    string name1, name2;

    cout << " Enter player 1 name: ";
    cin >> name1;

    cout << " Enter player 2 name: ";
    cin >> name2;

    while (true)
    {
        vector<vector<char>> BOARD = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        game_over = false; // Reset game_over flag for new game
        print(BOARD, name1, name2);
        loop(BOARD, name1, name2);

        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
        {
            break;
        }
    }
    return 0;
}
