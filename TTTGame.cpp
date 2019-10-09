/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    TicTacToe play;
    int numPlayers;
    int row;
    int column;
    int temp;
    int randPlayer;

    cout << "Enter number of players (1 or 2):" << endl;
    cin >> numPlayers;
    while (numPlayers > 2 || numPlayers < 1) {
        cout << "Number of players must be 1 or 2" << endl;
    }
    if (numPlayers == 2) {
        cout << "Two Player Game." << endl;
        while (play.isBoardFull() == false && play.checkForWin() == false) {
            play.printBoard();
            if (play.getCurrentPlayerNumber() == 1) {
                cout << "Its player one's turn (x)" << endl;
                cout << "Please enter row, column: " << endl;
                cin >> row;
                cin >> column;
                while (row > 3 || column > 3 || row < 1 || column < 1) {
                    cout << "Row and column values must range from 1 to 3. Please re-enter." << endl;
                    cin >> row;
                    cin >> column;
                }
                temp = true;
                if (play.placeMark(row - 1, column - 1) == false) {
                    temp = false;
                }
                while (temp == false) {
                    temp = true;
                    cout << "Position already taken. Please enter a new one." << endl;
                    cin >> row;
                    cin >> column;
                    if (play.placeMark(row - 1, column - 1) == false) {
                        temp = false;
                    }
                }
                play.placeMark(row - 1, column - 1);
            }
            else {
                cout << "Its player two's turn (o)" << endl;
                cout << "Please enter row, column: " << endl;
                cin >> row;
                cin >> column;
                while (row > 3 || column > 3 || row < 1 || column < 1) {
                    cout << "Row and column values must range from 1 to 3. Please re-enter." << endl;
                    cin >> row;
                    cin >> column;
                }
                temp = true;
                if (play.placeMark(row - 1, column - 1) == false) {
                    temp = false;
                }
                while (temp == false) {
                    temp = true;
                    cout << "Position already taken. Please enter a new one." << endl;
                    cin >> row;
                    cin >> column;
                    if (play.placeMark(row - 1, column - 1) == false) {
                        temp = false;
                    }
                }
                play.placeMark(row - 1, column - 1);
            }
            play.changePlayer();
        }
        if (play.checkForWin() == true) {
            play.changePlayer();
            play.printBoard();
            cout << "Player " << play.getCurrentPlayerNumber() << " has won!" << endl;
        } else {
            play.printBoard();
            cout << "Draw" << endl;
        }
    }
    else{
        cout << "One Player Game." << endl;
        cout << "You are Player 1." << endl;

        srand(time(0));
        randPlayer = rand() % 2;
        if(randPlayer == 1){
            play.changePlayer();
        }

        while (play.isBoardFull() == false && play.checkForWin() == false) {
            if (play.getCurrentPlayerNumber() == 1) {
                play.printBoard();
                cout << "Its your turn (x)" << endl;
                cout << "Please enter row, column: " << endl;
                cin >> row;
                cin >> column;
                while (row > 3 || column > 3 || row < 1 || column < 1) {
                    cout << "Row and column values must range from 1 to 3. Please re-enter." << endl;
                    cin >> row;
                    cin >> column;
                }
                temp = true;
                if (play.placeMark(row - 1, column - 1) == false) {
                    temp = false;
                }
                while (temp == false) {
                    temp = true;
                    cout << "Position already taken. Please enter a new one." << endl;
                    cin >> row;
                    cin >> column;
                    if (play.placeMark(row - 1, column - 1) == false) {
                        temp = false;
                    }
                }
                play.placeMark(row - 1, column - 1);
            }

            else {
                cout << "Its player two's turn (o)" << endl;

                row = rand() % 3;
                column = rand() % 3;
                temp = true;
                if (play.placeMark(row - 1, column - 1) == false) {
                    temp = false;
                }
                while (temp == false) {
                    temp = true;
                    row = rand() % 3;
                    column = rand() % 3;

                    if (play.placeMark(row - 1, column - 1) == false) {
                        temp = false;
                    }
                }
                play.placeMark(row - 1, column - 1);
            }
            play.changePlayer();
        }
        if (play.checkForWin() == true) {
            play.changePlayer();
            play.printBoard();
            cout << "Player " << play.getCurrentPlayerNumber() << " has won!" << endl;
        } else {
            play.printBoard();
            cout << "Draw" << endl;
        }
    }
    TicTacToe();

    return 0;
}
