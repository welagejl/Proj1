/*
 * Project Title:
 * - Minesweeper ... Redux
 * Description:
 * This program replicates the classic gamme of Minesweeper.
 * The user is asked to select from three different board sizes based
 * on the level of difficulty slected. The objective of the game is to not
 * lose all your lives and get blown up. In this process of selecting positions on the
 * board the board, the user must select the spots where they think the mine is.
 * Developers:
 * - Joe Welage - welagejl@mail.uc.edu
 * - Nick Arlinghaus- studentk@mail.uc.edu
 *
 * Help Received:
 *
 *
 * Special Instructions: // optional
 * N/A
 *
 * Developer comments: // Not optional
 * Developer 1: Joe Welage
 * I performed writing the code as well as testing and running it.
 * Developer 2:
 * Please describe what tasks you performed and what your learned from your experience
 */
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
const int S1 = 10;
const int S2 = 12;
const int S3 = 14;

/*
 * Function: Menu
 *
 * Displays the opening menu to the user to select the game mode
 * and begin the game
 *
 * parameters:
 * return value: int
 */
int menu(){

    char userChoice;

    cout << "\t\t Minesweeper ... REDUX" << endl;
    cout << "(s)tart" << endl;
    cout << "(i)nstructions" << endl;
    cout << "(e)xit" << endl;

    cin >> userChoice;
    switch (userChoice){
        case 's':
            system("cls");
            cout << "(e)asy 10 Mines" << endl;
            cout << "(m)edium 12 Mines" << endl;
            cout << "(h)ard 15 Mine" << endl;

            cin >> userChoice;
            if(userChoice == 'e'){
                return S1;
            }
            if(userChoice == 'm'){
                return S2;
            }
            if(userChoice == 'h'){
                    return S3;
            }
        break;
        case 'i':
            cout << "There will be a grid laid out with the x coordinates(rows)" << endl;
            cout << "and the y coordinates(col). It is up to you to guess where all the mines(9) will be." << endl;
            cout << "Once you find all the mines you will have to manually restart." << endl;
            cout << "An incorrect guess or picking a spot that has a mine will result in a loss of 1 of 7 lives." << endl;
            cout << "We'll start you off with easy mode.";
            return S1;
        case 'e':
            return 1;
    }
}
/*
 * Function: genBoard
 *
 * Generate the board the user will have to use based on the previous
 * selection of board size.
 *
 * parameters: int x(rows), int y(columns), int board[][S1](array for the board)
 * return value: void
 */
void genBoard(const int x, const int y, int board[][S1]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            board[i][j] = 0;
        }
    }
}
/*
 * Function: randspotgen
 *
 * Generates random values that are used for the placement of mines.
 *
 * parameters: int boardDim the number for which rand() is divided by
 * return value: int
 */
int randspotgen(int boardDim){
    return (rand() % boardDim);
}
/*
 * Function: hide
 *
 * Determines what value to display when the array dispBoard is displayed based on user input.
 *
 * parameters: int board[][S1], int userGuess[2]. The arrays for which values are aquired or displayed.
 * return value: int
 */
int hide(int board[][S1], int userGuess[2]){
    if(board[userGuess[0]][userGuess[1]] == 0){
        return 1;
    }
    else if(board[userGuess[0]][userGuess[1]] != 0 && board[userGuess[0]][userGuess[1]] != 9){
        return 2;
    }
    else{
        return 3;
    }
    return 0;
}
/*
 * Function: addNums
 *
 * Add numbers to the 3x3 area surrouding a mine(9). Each if statement makes
 * sure to check that the desired spot is not out of bounds in the array.
 *
 * parameters: int board[][S1](array for aquiring values, int xmine(row for mine), int ymine(col for mine)
 * , int row, int col
 * return value: void
 */
void addNums(int board[][S1], int xmine, int ymine, int row, int col){

    if(board[xmine][ymine+1] != 9 && xmine < row && xmine >= 0 && ymine +1< col && ymine +1 >= 0){
            board[xmine][ymine+1] +=1;
    }
    if(board[xmine+1][ymine] != 9 && xmine+1 < row && xmine+1 >= 0 && ymine < col && ymine >=0){
            board[xmine+1][ymine] +=1;
    }
    if(board[xmine][ymine-1] != 9 && xmine < row && xmine >= 0 && ymine-1 < col && ymine - 1 >= 0){
            board[xmine][ymine-1] +=1;
    }
    if(board[xmine-1][ymine] != 9 && xmine -1< row && xmine -1 >= 0 && ymine < col && ymine >= 0){
            board[xmine-1][ymine] +=1;
    }
    if(board[xmine+1][ymine+1] != 9 && xmine+1< row && xmine+1 >= 0 && ymine+1 < col && ymine+1 >= 0){
            board[xmine+1][ymine+1] +=1;
    }
    if(board[xmine-1][ymine-1] != 9 && xmine-1 < row && xmine-1 >= 0 && ymine -1 < col && ymine-1 >= 0){
            board[xmine-1][ymine-1] +=1;
    }
    if(board[xmine-1][ymine+1] != 9 && xmine-1 < row && xmine-1 >= 0 && ymine+1 < col && ymine+1 >= 0){
            board[xmine-1][ymine+1] +=1;
    }
    if(board[xmine+1][ymine-1] != 9 && xmine+1< row && xmine+1 >= 0 && ymine-1 < col && ymine -1 >= 0){
            board[xmine+1][ymine-1] +=1;
    }
}
/*
 * Function: placeMine
 *
 * Places mines onto the board array. This array then feeds into the array that is
 * actually displayed.
 *
 * parameters: int row, int col, int& xmine,int& ymine, int board[][S1]
 * return value: void
 */
void placeMine(int row, int col, int& xmine,int& ymine, int board[][S1]){
    if(row == S1){
        for(int i = 0; i < 10; i++){
            xmine = randspotgen(row);
            ymine = randspotgen(col);
            board[xmine][ymine] = 9;
            addNums(board, xmine, ymine, row, col);
            }
    }
    if(row == S2){
        for(int i = 0; i < 12; i++){
            xmine = randspotgen(row);
            ymine = randspotgen(col);
            board[xmine][ymine] = 9;
            addNums(board, xmine, ymine, row, col);
            }
    }
    if(row == S3){
        for(int i = 0; i < 15; i++){
            xmine = randspotgen(row);
            ymine = randspotgen(col);
            board[xmine][ymine] = 9;
            addNums(board, xmine, ymine, row, col);
            }
    }
}
/*
 * Function: guessMine
 *
 * Takes in user input so as to guess where a mine may be located.
 * This is similar to flagging a mine in the original Minesweeper game.
 *
 * parameters: int board[][S1], int dispBoard[][S1]
 * return value: bool
 */
bool guessMine(int board[][S1], int dispBoard[][S1]){
    int playerGuess[2];
    int x,y;

    char choice = 'n';

    cout << "Do you want to guess where a mine may be? (y|n): " << endl;
    cin >> choice;
    if(choice == 'y'){
        cout << "Enter coordinate guess x: " << endl;
        cin >> playerGuess[0];
        x = playerGuess[0] - 1;
        cout << "Enter coordinate guess y: " << endl;
        cin >> playerGuess[1];
        y = playerGuess[1] - 1;
        if(board[x][y] == 9){
            cout << "Found mine!" << endl;
            dispBoard[x][y] = board[x][y];
        }
        else{

            cout << "Not a mine! "  << endl;
            return 0;
        }

    }
    return 1;
}
/*
 * Function: disp
 *
 * Displays the dispBoard and takes in user input to guess a spot on the board array.
 * The hide function is then called to determine what was at the spot the user choose.
 *
 * parameters: int board[][S1], int dispBoard[][S1], int row
 * return value: bool
 */
bool disp(int board[][S1], int dispBoard[][S1], int row){

    int playerGuess[2];
    int count = 1;
    int guessingMine;

    guessingMine = guessMine(board, dispBoard);
    if(guessingMine == 0){return 0;}

    cout << "Enter coordinate guess x: " << endl;
    cin >> playerGuess[0];
    playerGuess[0] = playerGuess[0] - 1;
    cout << "Enter coordinate guess y: " << endl;
    cin >> playerGuess[1];
    playerGuess[1] = playerGuess[1] - 1;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < S1; j++){
            if(i == playerGuess[0] && j == playerGuess[1]){
                if(hide(board, playerGuess) == 2){
                    dispBoard[i][j] = board[i][j];
                   }
                else if(hide(board, playerGuess) == 1){
                    dispBoard[i][j] = board[i][j];
                   }
                else if(hide(board, playerGuess) == 3){
                   dispBoard[i][j] = board[i][j];
                   cout << "Mine was hit!" << endl;
                   return 0;
                }
            }
        }
    }


    system("cls");
    cout << "\t";
    for(int i = 1; i <= S1; i++){
        cout << i << " ";
        if(i == S1){
            cout << endl;
        }
    }
    for(int i = 0; i < row; i++){
        cout << count << "\t";
        for(int j = 0; j < S1; j++){
            cout << dispBoard[i][j] << " ";
            if(j == S1 -1){cout << endl;}
        }
        count ++;
     }
    cout <<"Mines Near: " << board[playerGuess[0]][playerGuess[1]] << endl;
    return 1;
}
/*
 * Function: main()
 *
 * Combines all previous functions. The user can choose which game to play and if
 * they choose to reset, they can begin a new game. The three different if statments
 * represent the differet games.
 *
 * parameters:
 * return value: int
 */
int main()
{
    srand(time(NULL));

    int xmine, ymine;
    char continuity = 'd';
    int choice;
    int lives = 6;
    do{
        choice = menu();
        //easy
        if(choice == S1){
        int board[S1][S1];
        int dispBoard[S1][S1];
        for(int i = 0; i < S1; i++){
            for(int j = 0; j < S1; j++){
                dispBoard[i][j] = 0;
            }
        }
        genBoard(S1,S1, board);
        placeMine(S1, S1, xmine, ymine, board);
        cout << "Press x to restart when entering coordinates" << endl;

        system("pause"); //while loop continues game unless user decides to restart.
        while(continuity != 'x'){

            bool game = disp(board,dispBoard, S1);
            if(game == 0){
                lives --;
                if(lives == 0){
                    cout <<  "You lost.";
                    continuity = 'x';
                }
            }
            else{
                cout << "Continue?((y)es, x to restart)" << endl;
                cin >> continuity;
            }
        }
    }
        //medium
        if(choice == S2){
        int board[S2][S1];
        int dispBoard[S2][S1];
        for(int i = 0; i < S2; i++){
            for(int j = 0; j < S1; j++){
                dispBoard[i][j] = 0;
            }
        }
        genBoard(S2,S1, board);
        placeMine(S2, S1, xmine, ymine, board);
        cout << "Press x to restart when entering coordinates" << endl;

        system("pause");
        while(continuity != 'x'){

            bool game = disp(board,dispBoard, S2);
            if(game == 0){
                lives --;
                if(lives == 0){
                    cout <<  "You lost.";
                    continuity = 'x';
                }
            }
            else{
                cout << "Continue?((y)es, x to restart)" << endl;
                cin >> continuity;
            }
        }
    }
        //hard
        if(choice == S3){
        int board[S3][S1];
        int dispBoard[S3][S1];
        for(int i = 0; i < S3; i++){
            for(int j = 0; j < S1; j++){
                dispBoard[i][j] = 0;
            }
        }
        genBoard(S3,S1, board);
        placeMine(S3, S1, xmine, ymine, board);
        cout << "Press x to restart when entering coordinates" << endl;

        system("pause");
        while(continuity != 'x'){

            bool game = disp(board,dispBoard, S3);
            if(game == 0){
                lives --;
                if(lives == 0){
                    cout <<  "You lost.";
                    continuity = 'x';
                }
            }
            else{
                cout << "Continue?((y)es, x to restart)" << endl;
                cin >> continuity;
            }
        }
    }

    } while(choice != 1);
   return 0;
}
