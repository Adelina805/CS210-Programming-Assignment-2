#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {

public:
    // constructor
    TicTacToe() {
    }

    // game board
    vector<vector<char> > gameBoard {
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'}
    };

    // print the game board
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

    // modify the game board
    void modifyGameBoard(char player, int position) {
        gameBoard[(position - 1) / 3][(position - 1) % 3] = player;
    }

    // check for win by comparing rows, columns, and diagonals
    bool checkGameWin() {
        for (int i = 0; i < 3; ++i) {
            // check rows
            if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) {
                return true;
            }
            // check columns
            if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) {
                return true;
            }
        }

        // check diagonal: "\"
        if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
            return true;
        }
        // check diagonal: "/"
        if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
            return true;
        }

        // no winner
        return false;
    }
};

int main() {
    // create a TicTacToe object
    TicTacToe game;

    // display initial text and board, create player and input variables
    cout << "TIC TAC TOE" << endl;
    char player = 'X';
    int position;

    // loop for 9 turns, switching between players and checking for game win
    for (int i = 0; i < 9; i++) {
        // print board
        game.printGameBoard();

        // prompt player and get input
        cout << "Player " << player << " Enter Position: ";
        cin >> position;

        // change board
        game.modifyGameBoard(player, position);

        // check if game has been won
        if (game.checkGameWin()) {
            game.printGameBoard();
            cout << "Player " << player << " Wins!!!" << endl;
            cout << "GAME OVER";
            return 0;
        }

        // change player, first checks if it's X's turn, if it is: change to O's, if it isn't: change to X
        player = (player == 'X') ? 'O' : 'X';
    }

    // if all 9 turns complete without a win, end defaults to a tie
    game.printGameBoard();
    cout << "Tie!!" << endl;
    cout << "GAME OVER";
    return 0;
}