/*
 * Project Title:
 * - Minesweeper Clone
 * Description:
 * This program replicates the classic gamme of Minesweeper.
 * The user is asked to select from four different board sizes based
 * on the level of difficulty slected. The objective of the game is to not
 * fins a mine and get blown up. In this process of seecting positions on the
 * board the board, the user must select the spots where they think the mine is.
 * Developers:
 * - Joe Welage - welagejl@mail.uc.edu
 * - Nick - studentk@mail.uc.edu
 *
 * Help Received:
 * - TA Name one
 * - Instructor
 * - Student X
 *
 * Special Instructions: // optional
 * - How to compile
 * - How to run it
 *
 * Developer comments: // Not optional
 * Developer 1:
 * Please describe what tasks you performed and what your learned from your experience
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
const int S4 = 20;
/*
 * Function: Menu
 *
 * Displays the opening menu to the user to select the game mode
 * and begin the game
 *
 * parameters int x, int y for board size
 * return value: void
 */
int menu(){

    char userChoice;

    cout << "\t\t Minesweeper" << endl;
    cout << "(s)tart" << endl;
    cout << "(o)ptions" << endl;
    cout << "(e)xit" << endl;

    cin >> userChoice;
    switch (userChoice){
        case 's':
            system("cls");
            cout << "(e)asy" << endl;
            cout << "(m)edium" << endl;
            cout << "(h)ard" << endl;
            cout << "(S)uper Hard" << endl;
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
            if(userChoice == 'S'){
                    return S4;
            }
        break;
        case 'o':
            cout << "There are no options";
            return 1;
        case 'e':
            exit(0);
    }
}
/*
 * Function: genBoard
 *
 * Generate the board the user will have to use based on the previous
 * selection of board size.
 *
 * parameters: int x, int y for board size
 * return value: int array
 */
void genBoard(const int x, const int y, int board[][S1]){

    int count = 0;

    system("cls");
    cout << "  ";
    for(int i = 1; i <= y; i++){
        cout << i;
        if(i == y){
            cout << endl;
        }
    }
    for(int i = 0; i < x; i++){
        cout << count << " ";
        for(int j = 0; j < y; j++){
            board[i][j] = 0;
            cout << board[i][j];
            if( j == y -1){
                cout << endl;
            }
        }
        count++;
    }
}
int randspotgen(int boardDim){
    return (rand() % boardDim) + 1;
}
void placeMine(const int x, int board[][S1]){
    if(x == S1){
        for(int i = 0; i < 10; i++){
            board[randspotgen(x)][randspotgen(x)] = 9;
        }
    }
    else if (x == S2) {
        for(int i = 0; i < 20; i++){
            board[randspotgen(x)][randspotgen(x)] = 9;
        }
    }
    else if (x == S3) {
        for(int i = 0; i < 35; i++){
            board[randspotgen(x)][randspotgen(x)] = 9;
        }
    }
    else if (x == S4) {
        for(int i = 0; i < 399; i++){
            board[randspotgen(x)][randspotgen(x)] = 9;
        }
    }
}
void disp(int board[][S1], int row){
    system("cls");
    int count = 0;
    cout << "  ";
    for(int i = 1; i <= row; i++){
        cout << i << " ";
        if(i == row){
            cout << endl;
        }
    }
    for(int i = 0; i < row; i++){
        cout << count << " ";
        for(int j = 0; j < S1; j++){
            cout <<" " <<  board[i][j];
            if(j == S1 - 1){ cout << endl;}
        }
        count ++;
    }
}
int main()
{
    int choice = menu();
    if(choice == S1){
        int board[S1][S1];
        genBoard(S1,S1, board);
        placeMine(S1, board);
        system("pause");
        disp(board, S1);
    }




   //genMine(xsize, ysize, genBoard(xsize,ysize));
   return 0;
}
