#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {

public:
    // Constructor
    TicTacToe() {
    }

    // game board
    vector<vector<char> > gameBoard {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
    };

    // print game board
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Modify the game board
    void modifyGameBoard(char player, int position) {

    }

};

int main() {
    // Create a TicTacToe object
    TicTacToe game;

    // Display initial text and board, and create win and inputvariable
    cout << "TIC TAC TOE" << endl;
    game.printGameBoard();
    int win = 0;
    int userInput;

    // loop prompting the players and getting input
    while (win != 1) {
        // Player X stuff: prompt, modify, print
        cout << "Player X Enter Position: ";
        cin >> userInput;
        game.modifyGameBoard('X', userInput);
        game.printGameBoard();

        //add if statement for "Player X Wins!!, win = 1;

        // Player O stuff: prompt, modify, print
        cout << "Player O Enter Position: ";
        cin >> userInput;
        game.modifyGameBoard('O', userInput);
        game.printGameBoard();
        //add if statement for "Player O Wins!!, win = 0
    }
}