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
    for(int i = 1; i <= y; i++){
        cout << i;
        if(i == y){
            cout << endl;
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            board[i][j] = 0;
        }
    }
}
int randspotgen(int boardDim){
    return (rand() % 10) + 1;
}

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
bool checkNums(int row, int xmine, int ymine){
    if(xmine <= row && ymine <= row){
        return true;
    }
    else{return false;}
}
void addNums(int board[][S1], int xmine, int ymine, int row){

    board[xmine][ymine+1] != 9 && checkNums(row,xmine ,ymine += 1) ? board[xmine][ymine] += 1: 0;
    board[xmine+1][ymine]!= 9 && checkNums(row,xmine +=1 ,ymine) ? board[xmine][ymine] += 1: 0;
    board[xmine][ymine-1]!= 9 && checkNums(row,xmine ,ymine -= 1) ? board[xmine][ymine] += 1: 0;
    board[xmine-1][ymine]!= 9 && checkNums(row,xmine -= 1 ,ymine) ? board[xmine][ymine] += 1: 0;
    board[xmine+1][ymine+1]!= 9 && checkNums(row,xmine += 1,ymine += 1)? board[xmine][ymine] += 1: 0;
    board[xmine-1][ymine-1]!= 9 && checkNums(row,xmine -=1,ymine -= 1)? board[xmine][ymine] += 1: 0;
    board[xmine-1][ymine+1]!= 9 && checkNums(row,xmine -=1 ,ymine += 1)? board[xmine][ymine] += 1: 0;
    board[xmine+1][ymine-1]!= 9 && checkNums(row,xmine +=1 ,ymine -=1)? board[xmine][ymine] += 1: 0;
}
/*bool searchNums(int board[][S1], int xmine, int ymine){
    bool stop[8] = {0,0,0,0,0,0,0,0};
    int end = 0;
    int i = 0;
    while(end == 0){
        board[xmine][ymine+i] == 0 && stop[0] == 0 ? cout << board[xmine][ymine +i]: stop[0] = 1;
        board[xmine+i][ymine] == 0 && stop[1] == 0 ? board[xmine+i][ymine] += 0: stop[1] = 1;
        board[xmine][ymine-i] == 0 && stop[2] == 0 ? board[xmine][ymine-i] += 0: stop[2] = 1;
        board[xmine-i][ymine] == 0 && stop[3] == 0 ? board[xmine-i][ymine] += 0: stop[3] = 1;
        board[xmine+i][ymine+i] == 0 && stop[4] == 0 ? board[xmine+i][ymine+i] += 0: stop[4] = 1;
        board[xmine-i][ymine-i] == 0 && stop[5] == 0 ? board[xmine-i][ymine-i] += 0: stop[5] = 1;
        board[xmine-i][ymine+i] == 0 && stop[6] == 0 ? board[xmine-i][ymine+i] += 0: stop[6] = 1;
        board[xmine+i][ymine-i] == 0 && stop[7] == 0 ? board[xmine+i][ymine-i] += 0: stop[7] == 1;
        if(stop[0] && stop[1] && stop[2] && stop[3] && stop[4] && stop[5] && stop[6] && stop[7]){
            end = 1;
        }
        else{ i += 1; }
    }
}
*/
void placeMine(int size, int& xmine,int& ymine, int board[][S1]){
    if(size == S1){
        for(int i = 0; i < 10; i++){
            xmine = randspotgen(size);
            ymine = randspotgen(size);
            board[xmine][ymine] = 9;
            addNums(board, xmine, ymine, size);
            }
    }


    /*else if (size == S2) {
        for(int i = 0; i < 20; i++){
            //if(hide() != true)
            board[randspotgen(x)][randspotgen(x)] = 9;
        }
    }
    else if (size == S3) {
        for(int i = 0; i < 35; i++){
            board[randspotgen(x)][randspotgen(x)] = 9;
        }
    }
    else if (size == S4) {
        for(int i = 0; i < 399; i++){
            board[randspotgen(x)][randspotgen(x)] = 9;
        }
    }*/
}

bool disp(int board[][S1], int dispBoard[][S1], int row){

    int playerGuess[2];
    int count = 1;
    cout << "Enter coordinate guess x" << endl;
    cin >> playerGuess[0];
    playerGuess[0] = playerGuess[0] - 1;
    cout << "Enter coordinate guess y" << endl;
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
                }

            }

        }

    }
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
    cout << board[playerGuess[0]][playerGuess[1]];
    return 1;
}
int main()
{
    srand(time(NULL));

    int xmine, ymine;
    char continuity = 'd';
    int choice = menu();
    if(choice == S1){
        int board[S1][S1];
        int dispBoard[S1][S1];
        for(int i = 0; i < S1; i++){
            for(int j = 0; j < S1; j++){
                dispBoard[i][j] = 0;
            }
        }
        genBoard(S1,S1, board);
        placeMine(S1, xmine, ymine, board);
        cout << "Press x to pause during the game." << endl;

        system("pause");
        while(continuity != 'x'){
            for(int i =0; i < S1; i++){
                for(int j = 0; j < S1;j++){
                    cout << board[i][j];
                    if(j == S1 - 1){cout << endl;}

                }
            }
            system("pause");
            bool game = disp(board,dispBoard, S1);

            if(game == 0){
                cout <<  "You lost.";
                exit(0);
            }
            else{
                cout << "c to continue";
                cin >> continuity;
            }
        }

    }
    if(choice == S2){
        int board[S2][S1];
        genBoard(S2,S1, board);
        placeMine(S2,xmine, ymine, board);
        system("pause");
        //disp(board, S2);
    }




   //genMine(xsize, ysize, genBoard(xsize,ysize));
   return 0;
}
