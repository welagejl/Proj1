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
/*
 * Function: Menu
 *
 * Displays the opening menu to the user to select the game mode
 * and begin the game
 *
 * parameters int x, int y for board size
 * return value: void
 */
void menu(int& x, int& y){
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
            switch (userChoice){
                case 'e':
                    x = 10;
                    y = 10;
                    cout << "begin";
                    break;
                case 'm':
                    x = 12;
                    y = 14;
                    break;
                case 'h':
                    x = 15;
                    y = 17;
                    break;
                case 'S':
                    x = 20;
                    y = 20;
                    break;
             }
        break;
        case 'o':
            cout << "There are no options";
            break;
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
int genBoard(int x, int y){
    const int xrow = x;
    const int ycol = y;
    int board[xrow][ycol];
    system("cls");
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            board[x][y] = 0;
            cout << board[xrow][ycol];
            if( j == y -1){
                cout << endl;
            }
        }
    }
    return board[x][y];
}
int main()
{
   int xsize, ysize;
   menu(xsize, ysize);
   genBoard(xsize,ysize);
   return 0;
}
