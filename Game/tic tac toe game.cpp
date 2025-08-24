#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'},
                     {'4','5','6'},
                     {'7','8','9'} };

void showBoard() {
    cout << "\n";
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << " " << board[i][j];
            if(j<2) cout << " |";
        }
        cout << endl;
        if(i<2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {
    // Rows and Columns
    for(int i=0; i<3; i++)
        if((board[i][0]==board[i][1] && board[i][1]==board[i][2]) ||
           (board[0][i]==board[1][i] && board[1][i]==board[2][i]))
            return true;

    // Diagonals
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2]) ||
       (board[0][2]==board[1][1] && board[1][1]==board[2][0]))
        return true;

    return false;
}

bool checkDraw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void getMove(char player) {
    int move;
    bool valid = false;
    do {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if(cin.fail() || move < 1 || move > 9) {
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Invalid input!\n";
            continue;
        }
        int row = (move-1)/3;
        int col = (move-1)%3;
        if(board[row][col]=='X' || board[row][col]=='O') {
            cout << "Cell already taken! Try again.\n";
        } else {
            board[row][col] = player;
            valid = true;
        }
    } while(!valid);
}

int main() {
    char player = 'X';
    cout << "Tic Tac Toe Game in C++\n";
    showBoard();

    while(true) {
        getMove(player);
        showBoard();

        if(checkWin()) {
            cout << "Player " << player << " wins!\n";
            break;
        }
        if(checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
