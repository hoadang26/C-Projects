// Program          : Tic Tac Toe
// Developer        : Hoa (Violet) Dang
// Date             : 05/12/2016
// Program Purpose  : This program will allow you to play Tic Tac Toe with a friend!

#include <iostream>
#include <algorithm>
using namespace std;
void Replay();

char matrix[3][3] = {'-','-','-','-','-','-','-','-','-'};
char player = 'X';

void DrawBoard()
//This function will draw out the Tic Tac Toe Board
{
    cout << "       " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << endl;
    cout << "     -----+-----+-----" << endl;
    cout << "       " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << endl;
    cout << "     -----+-----+-----" << endl;
    cout << "       " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << endl;
    cout << "     -----+-----+-----" << endl;
}

void Input()
//This function verifies that the player cannot override an his or opponent's choice
{
    int a;
    cout << "It's " << player << " turn. Pick a spot (in number from 1-9): ";
    cin >> a;
    if (a>0 and a<10)
    {
        a--;
        if (matrix[a/3][a%3] == 'X' || matrix[a/3][a%3] == 'O')
        {
            cout << "Pick a different spot" << endl;
            Input();
        }
        else
            matrix[a/3][a%3] = player;
    }
    else
    {
        cout << "Invalid Input. Please enter a number between 1-9"<<endl;
        Input();
    }
}

char Win()
//This function checks who the winner is
{
    if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    
    if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
        return 'X';
    if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
        return 'X';
    if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
        return 'X';
    
    if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
        return 'X';
    if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
        return 'X';
    
        //second player
    if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    
    if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
        return 'O';
    if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
        return 'O';
    if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
        return 'O';
    
    if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
        return 'O';
    if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
        return 'O';
    
    return '/';
}


void TogglePlayer()
//This function changes player from X to O and vice versa
{
    if (player == 'X')
        player = 'O';
    else
        player = 'X';
    
}

void ResetBoard()
//This function clear out the board
{
    for (int i =0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            matrix[i][j] = '-';
        }
    }
}

void PlayGame()
//This function execute other functions and allow the users to play game
{
    int n = 0;
    DrawBoard();
    while (1)
    {
        n++;
        Input();
        DrawBoard();
        if (Win() == 'X')
        {
            cout << "X wins!!" << endl;
            Replay();
        }
        else if (Win() == 'O')
        {
            cout << "O wins!!" << endl;
            Replay();
        }
        else if (Win() == '/' && n==9)
        {
            cout << "It's a draw!!" << endl;
            Replay();
        }
        TogglePlayer();
    }
}

void Replay()
//This function asks user if he wants to replay
{
    char a;
    cout << "Do you want to replay (Y/N)?";
    cin >> a;
    if (a=='Y')
    {
        ResetBoard();
        PlayGame();
    }
    else if (a=='N')
    {
        cout << "Thanks for playing!"<<endl;
        exit(0);
    }
    else
    {
        cout << "Invalid input, enter Y or N" <<endl;
        Replay();
    }
    
}

int main()
//Main function
{
    cout << "Let's play some Tic Tac Toe!!" << endl;
    PlayGame();
    return 0;
}