/* Class: TicTacToe
 * Author: [FINISH ME]
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {
    TicTacToe play; //declare object
    int numPlayers;
    int row;
    int column;
    int temp;
    int randPlayer;

    cout << "Enter number of players (1 or 2):" << endl;
    cin >> numPlayers;
    while (numPlayers > 2 || numPlayers < 1) {      //check for proper player input
        cout << "Number of players must be 1 or 2" << endl;
    }
    if (numPlayers == 2) {      //Enter 2 player game
        cout << "Two Player Game." << endl;
        while (play.isBoardFull() == false && play.checkForWin() == false) { //Check if game is still in progress
            play.printBoard();
            if (play.getCurrentPlayerNumber() == 1) { //player 1's turn
                cout << "Its player one's turn (x)" << endl;
                cout << "Please enter row, column: " << endl;
                cin >> row;
                cin >> column;
                while (row > 3 || column > 3 || row < 1 || column < 1) {   //Checks for correct input bounds
                    cout << "Row and column values must range from 1 to 3. Please re-enter." << endl;
                    cin >> row;
                    cin >> column;
                }
                //Checks if the chosen position is already filled
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
                play.placeMark(row - 1, column - 1);    //Places Mark
            }
            else {
                cout << "Its player two's turn (o)" << endl;    //Enter player 2's turn
                cout << "Please enter row, column: " << endl;
                cin >> row;
                cin >> column;
                while (row > 3 || column > 3 || row < 1 || column < 1) { //Checks to see in input is within bounds
                    cout << "Row and column values must range from 1 to 3. Please re-enter." << endl;
                    cin >> row;
                    cin >> column;
                }

                //Checks if the chosen position is already filled
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
                play.placeMark(row - 1, column - 1);    //Places mark
            }
            play.changePlayer();    //Switches turn
        }
        if (play.checkForWin() == true) {   //Determines if game ended due to win
            play.changePlayer();
            play.printBoard();
            cout << "Player " << play.getCurrentPlayerNumber() << " has won!" << endl;
        } else {    //If game ends in a draw
            play.printBoard();
            cout << "Draw" << endl;
        }
    }
    //Enter 1 player game
    else{
        cout << "One Player Game." << endl;
        cout << "You are Player 1." << endl;

        //Randomly select starting player
        srand(time(0));
        randPlayer = rand() % 2;
        if(randPlayer == 1){
            play.changePlayer();
        }

        while (play.isBoardFull() == false && play.checkForWin() == false) {    //Check if game is still in progress
            if (play.getCurrentPlayerNumber() == 1) {   //Enter player 1's turn
                play.printBoard();
                cout << "Its your turn (x)" << endl;
                cout << "Please enter row, column: " << endl;
                cin >> row;
                cin >> column;
                while (row > 3 || column > 3 || row < 1 || column < 1) {    //Checks for correct input bounds
                    cout << "Row and column values must range from 1 to 3. Please re-enter." << endl;
                    cin >> row;
                    cin >> column;
                }
                //Checks if the chosen position is already filled
                temp = true;
                if (play.placeMark(row - 1, column - 1) == false) {
                    temp = false;
                }
                while (temp == false) {
                    temp = true;
                    cout << "Position already taken. Please enter a new one." << endl;
                    cin.ignore();
                    cin >> row;
                    cin >> column;
                    if (play.placeMark(row - 1, column - 1) == false) {
                        temp = false;
                    }
                }
                play.placeMark(row - 1, column - 1);    //Places mark
            }

            else {
                cout << "Its player two's turn (o)" << endl;
                cin.ignore();
                //Randomly generate mark position
                row = rand() % 3+1;
                column = rand() %3 +1;

                //Checks if the chosen position is already filled
                temp = true;
                if (play.placeMark(row - 1, column - 1) == false) {
                    temp = false;
                }
                while (temp == false) {
                    temp = true;
                    row = rand() % 3 + 1;
                    column = rand() % 3 + 1;

                    if (play.placeMark(row - 1, column - 1) == false) {
                        temp = false;
                    }
                }
                play.placeMark(row - 1, column - 1);    //Places mark
            }
            play.changePlayer();    //Switch player turn
        }
        //Check if game ended in a win or a draw
        if (play.checkForWin() == true) {
            play.changePlayer();
            play.printBoard();
            cout << "Player " << play.getCurrentPlayerNumber() << " has won!" << endl;
        } else {
            play.printBoard();
            cout << "Draw" << endl;
        }
    }
    return 0;
}
