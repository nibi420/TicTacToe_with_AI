// TicTacToe with Minmax by M.A - 2.cpp : This file contains the 'main' function. Program execution begins and ends there.

//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
using namespace std;

char board[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
int choice;
bool play = true;
int min_max_counter = 0;
int ahead_of_minimax_counter = 0;

int invalid_move = 0; // tells when an invalid move is selected by a player
char mark;

int stop = 0;           // intialized so that after the player wins the game, AI doesn't make a move and the game ends
int no_result_stop = 0; // Initialized so that if the board finishes and someone wins a game...so the message that game has tied doesn't appear

int computer_turn_number = 1;

string invalid_move_string_show = "";

void change_turn()
{
    if (mark == 'X')
    {
        mark = 'O';
    }

    else if (mark == 'O')
    {
        mark = 'X';
    }
}

void display_board_computer()
{

    cout << "TIC-TAC-TOE" << endl; //\t\t\t\t\t\t\t\t\t (Tic-Tac-Toe [INSTRUCTIONS])" << endl;
    // cout << "\t\t\t\t\t\t\t\t\t 1. The game is played on a grid\n\t\t\t\t\t\t\t\t\t that's 3 squares by 3 squares."<<endl;
    // cout << "\t\t\t\t\t\t\t\t\t 2. You are X, your friend (or the computer\n\t\t\t\t\t\t\t\t\t in this case) is O.Players take turns\n\t\t\t\t\t\t\t\t\t putting their marks in empty squares."<<endl;
    // cout << "\t\t\t\t\t\t\t\t\t 3. The first player to get 3 of her marks\n\t\t\t\t\t\t\t\t\t in a row(up, down,\n\t\t\t\t\t\t\t\t\t across, or diagonally) is the winner." << endl;
    // cout << "\t\t\t\t\t\t\t\t\t 4. When all 9 squares are full, the game is\n\t\t\t\t\t\t\t\t\t over.If no player has 3 marks in a row, the\n\t\t\t\t\t\t\t\t\t game ends in a tie." << endl;
    cout << "\t\t\t\t\tPlayer 1 [X]" << endl;
    cout << "\t\t\t\t\tCOMPUTER [O]" << endl;
    cout << endl;

    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "\t\t     |     |     " << endl;
}

void display_board()
{
    system("cls");
    cout << "TIC-TAC-TOE" << endl; //\t\t\t\t\t\t\t\t\t (Tic-Tac-Toe [INSTRUCTIONS])" << endl;
    // cout << "\t\t\t\t\t\t\t\t\t 1. The game is played on a grid\n\t\t\t\t\t\t\t\t\t that's 3 squares by 3 squares."<<endl;
    // cout << "\t\t\t\t\t\t\t\t\t 2. You are X, your friend (or the computer\n\t\t\t\t\t\t\t\t\t in this case) is O.Players take turns\n\t\t\t\t\t\t\t\t\t putting their marks in empty squares."<<endl;
    // cout << "\t\t\t\t\t\t\t\t\t 3. The first player to get 3 of her marks\n\t\t\t\t\t\t\t\t\t in a row(up, down,\n\t\t\t\t\t\t\t\t\t across, or diagonally) is the winner." << endl;
    // cout << "\t\t\t\t\t\t\t\t\t 4. When all 9 squares are full, the game is\n\t\t\t\t\t\t\t\t\t over.If no player has 3 marks in a row, the\n\t\t\t\t\t\t\t\t\t game ends in a tie." << endl;
    cout << "\t\t\t\t\tPlayer 1 [X]" << endl;
    cout << "\t\t\t\t\tPlayer 2 [O]" << endl;
    cout << endl;

    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
    cout << "\t\t     |     |     " << endl;
}

void player_turn()
{

    if (mark == 'X')
    {
        cout << "\n\n\t Player 1 [X] turn:";
    }

    if (mark == 'O')
    {
        cout << "\n\n\t Player 2 [O] turn:";
    }
    cin >> choice;
    /*if (choice != 1 || choice != 2 || choice != 3 || choice != 4 || choice != 5 || choice != 6 || choice != 7 || choice != 8 || choice != 9)
    {
        cout << "Invalid Input (Enter z to continue)" << endl;
        cin >> invalid_move_string_show;
    }*/

    switch (choice)
    {
    case 1:
    {
        if (board[0][0] != 'X' && board[0][0] != 'O')
        {
            board[0][0] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 2:
    {
        if (board[0][1] != 'X' && board[0][1] != 'O')
        {
            board[0][1] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 3:
    {
        if (board[0][2] != 'X' && board[0][2] != 'O')
        {
            board[0][2] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 4:
    {
        if (board[1][0] != 'X' && board[1][0] != 'O')
        {
            board[1][0] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 5:
    {
        if (board[1][1] != 'X' && board[1][1] != 'O')
        {
            board[1][1] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 6:
    {
        if (board[1][2] != 'X' && board[1][2] != 'O')
        {
            board[1][2] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 7:
    {
        if (board[2][0] != 'X' && board[2][0] != 'O')
        {
            board[2][0] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 8:
    {
        if (board[2][1] != 'X' && board[2][1] != 'O')
        {
            board[2][1] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    case 9:
    {
        if (board[2][2] != 'X' && board[2][2] != 'O')
        {
            board[2][2] = mark;
        }
        else
        {
            invalid_move = 1;
        }
        break;
    }
    default:
    {
        invalid_move = 1;
        break;
    }
    }
}

void win_game()
{
    // Horizontal
    // 1
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }

    // 2
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }

    // 3
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }

    // Vertical
    // 4
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }

    // 5
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }

    // 6
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }

    // Cross
    // 7
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }

    // 8
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        display_board();
        play = false;
        no_result_stop = 1;
    }
}

bool modified_win_check_for_X()
{
    // for X
    // for horizontal rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
        {
            return true;
        }
    }
    // for vertical rows
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
        {
            return true;
        }
    }

    // for diagonals
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    {
        return true;
    }
    if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
    {
        return true;
    }

    return false;
}
bool modified_win_check_for_O()
{
    //------------------------------
    // for O
    // for horizontal
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
        {
            return true;
        }
    }
    // for vertical
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
        {
            return true;
        }
    }

    // for diagonals
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    {
        return true;
    }
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
    {
        return true;
    }

    return false;
}

void win_check()
{
    // X

    // Horizontal
    // 1
    int x = 1;
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' && x == 1)
    {
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
        x = 0;
    }

    // 2
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' && x == 1)
    {
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
        x = 0;
    }

    // 3
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' && x == 1)
    {
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
        x = 0;
    }

    // Vertical
    // 4
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // 5
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // 6
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // Cross
    // 7
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // 8
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    //////////////////////O

    // Horizontal
    // 1
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }

    // 2
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }

    // 3
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }

    // Vertical
    // 4
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }

    // 5
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }

    // 6
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }

    // Cross
    // 7
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }

    // 8
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O' && x == 1)
    {
        x = 0;
        cout << "Player 2 [O] has won\nCongratulations!" << endl;
    }
}

void win_check_computer()
{
    // X

    // Horizontal
    // 1
    int x = 1; // initialized so that the code doesn't display win condition two times in special cases
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' && x == 1)
    {
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
        x = 0;
    }

    // 2
    if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' && x == 1)
    {
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
        x = 0;
    }

    // 3
    if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' && x == 1)
    {
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
        x = 0;
    }

    // Vertical
    // 4
    if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // 5
    if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // 6
    if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // Cross
    // 7
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    // 8
    if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X' && x == 1)
    {
        x = 0;
        cout << "Player 1 [X] has won\nCongratulations!" << endl;
    }

    //////////////////////O

    // Horizontal
    // 1
    if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }

    // 2
    if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }

    // 3
    if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }

    // Vertical
    // 4
    if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }

    // 5
    if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }

    // 6
    if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }

    // Cross
    // 7
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }

    // 8
    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O' && x == 1)
    {
        x = 0;
        cout << "Computer has won!" << endl;
    }
}

void invalid_move_checker()
{
    if (invalid_move == 1)
    {
        cout << "INVALID MOVE (Enter z to continue)" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> invalid_move_string_show;
        while (invalid_move_string_show != "z")
        {
            cout << "Enter z to continue" << endl;
            cin >> invalid_move_string_show;
        }
        invalid_move = 0;
        stop = 1;
    }
}

void no_result()
{

    if ((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][1] == 'X' || board[0][1] == 'O') && (board[0][2] == 'X' || board[0][2] == 'O') && (board[1][0] == 'X' || board[1][0] == 'O') && (board[1][1] == 'X' || board[1][1] == 'O') && (board[1][2] == 'X' || board[1][2] == 'O') && (board[2][0] == 'X' || board[2][0] == 'O') && (board[2][1] == 'X' || board[2][1] == 'O') && (board[2][2] == 'X' || board[2][2] == 'O'))
    {
        display_board();
        cout << "\n\n"
             << endl;
        cout << "Game  Tied" << endl;
        play = false;
    }
}

bool modified_no_result()
{
    if ((board[0][0] == 'X' || board[0][0] == 'O') && (board[0][1] == 'X' || board[0][1] == 'O') && (board[0][2] == 'X' || board[0][2] == 'O') && (board[1][0] == 'X' || board[1][0] == 'O') && (board[1][1] == 'X' || board[1][1] == 'O') && (board[1][2] == 'X' || board[1][2] == 'O') && (board[2][0] == 'X' || board[2][0] == 'O') && (board[2][1] == 'X' || board[2][1] == 'O') && (board[2][2] == 'X' || board[2][2] == 'O'))
    {
        return true;
    }
    return false;
}
//---------------------------------
int minSearch(); // Prototype declaration
int maxSearch(); // Prototype declaration

void minimax(int &x, int &y)
{

    string p;
    // cout << "minimax is called" << endl;

    int k = 0;
    int o = 0;
    int score = numeric_limits<int>::max();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = 'O';
                // display_board_computer();

                int temp = maxSearch();
                ahead_of_minimax_counter++;
                // cout << " The code ran here " << ahead_of_minimax_counter << " times";
                // cout << " inside minimax ahead of  temp = maxSearch()" << endl;
                // cout << "Value of temp is:" << temp << endl;
                // cout << "Here score is :" << score << endl;

                if (temp < score)
                {
                    score = temp;
                    k = i;
                    o = j;
                }
                board[i][j] = '-';
            }
        }
    }
    x = k;
    y = o;
}

int maxSearch()
{
    min_max_counter++;
    // cout << "\n Counter: " << min_max_counter << endl;
    string p;
    // cout << "maxSearch() is called" << endl;

    if (modified_win_check_for_X())
    {
        // cout << "maxSearch() returns 100" << endl;

        return 100;
    }
    else if (modified_win_check_for_O())
    {
        // cout << "maxSearch() returns -100" << endl;

        return -100;
    }
    else if (modified_no_result())
    {
        // cout << "maxSearch() returns 0" << endl;

        return 0;
    }

    int score = numeric_limits<int>::min();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                board[i][j] = 'X';

                // display_board_computer();
                // cout << "Move made in maxSearch()" << endl;

                score = max(score, minSearch());
                board[i][j] = '-';
                // display_board_computer();
                // cout << "Move made in maxSearch()" << endl;
            }
        }
    }

    return score;
}

int minSearch()
{
    min_max_counter++;
    // cout << "\n Counter: " << min_max_counter << endl;
    string p;
    // cout << "minSearch() is called" << endl;

    if (modified_win_check_for_X())
    {
        // cout << "minSearch() returns 100" << endl;

        return 100;
    }
    else if (modified_win_check_for_O())
    {
        // cout << "minSearch() returns -100" << endl;

        return -100;
    }
    else if (modified_no_result())
    {
        // cout << "minSearch() returns 0" << endl;

        return 0;
    }

    int score = numeric_limits<int>::max();

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {

                board[i][j] = 'O';
                // display_board_computer();
                // cout << "Move made in minSearch()" << endl;

                score = min(score, maxSearch());
                board[i][j] = '-';
                // display_board_computer();
                // cout << "Move made in minSearch()" << endl;
            }
        }
    }

    return score;
}

void computer_turn()
{

    display_board_computer();
    string p;
    // cout << "Computer Turn is called" << endl;

    int m = 0;
    int n = 0;
    minimax(m, n);

    board[m][n] = 'O';
}

void print_tic_tac_toe()
{
    cout << " ______________ " << endl;
    cout << "        |      " << endl;
    cout << "        |      " << endl;
    cout << "        |  "
         << " o "
         << " "
         << "------"
         << " " << endl;
    cout << "        |  "
         << " | "
         << " "
         << "|     "
         << " " << endl;
    cout << "        |  "
         << " | "
         << " "
         << "|_____"
         << " " << endl;
}

//-------------------------------------

int main()
{
    print_tic_tac_toe();
    // MAIN MENU
    cout << "\t\t\t\tWELCOME TO TIC-TAC-TOE!" << endl;
    cout << "PLEASE SELECT:" << endl;
    cout << "   A - PLAY WITH AI " << endl;
    cout << "   B - 2 Players " << endl;
    string option = "";
    while (option != "A" && option != "B")
    {
        cout << "Please select 'A' or 'B' only:" << endl;
        cin >> option;
    }

    mark = 'X';

    // PLAYER vs COMPUTER
    if (option == "A")
    {
        while (play)
        {
            display_board_computer();

            player_turn();

            stop = 0;

            invalid_move_checker();

            if (modified_win_check_for_X())
            {
                cout << "Player has won" << endl;
                play = false;
                break;
            }
            if (modified_no_result())
            {
                display_board();
                play = false;
                break;
            }

            change_turn();

            if (stop == 0)
            {
                computer_turn();
            }
            change_turn();

            no_result();
            if (modified_win_check_for_O())
            {
                display_board_computer();
                cout << "Computer Won" << endl;
                play = false;
            }
        }
    }

    // 2 PLAYERS
    else if (option == "B")
    {
        while (play)
        {
            display_board();

            player_turn();
            change_turn();

            if (invalid_move == 1)
            {
                cout << "INVALID MOVE (Enter z to continue)" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> invalid_move_string_show;
                while (invalid_move_string_show != "z")
                {
                    cout << "Enter z to continue" << endl;
                    cin >> invalid_move_string_show;
                }
                change_turn();
                invalid_move = 0;
            }

            if (modified_win_check_for_X())
            {
                display_board();
                cout << "X has won" << endl;
                play = false;
            }

            if (modified_win_check_for_O())
            {
                display_board();
                cout << "O has won" << endl;
                play = false;
            }

            if (no_result_stop == 0)
            {
                no_result();
            }
        }
    }

    cout << endl;

    cout << "Game has ended" << endl;

    cout << "\t\t\t\t |GAME DEVELOPED BY:\n\t\t\t\t |MUNEEB AKMAL" << endl;
    cout << "THANK YOU FOR PLAYING!" << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
