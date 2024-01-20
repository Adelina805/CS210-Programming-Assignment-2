#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {

public:
    // Constructor
    TicTacToe() {
        /* Initialize defaults here */
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
    TicTacToe game;  // Create a TicTacToe object
    game.modifyGameBoard('X', 5);  // Example: Player 'X' makes a move at position 5
    game.printGameBoard();
    return 0;
}