#include<iostream>
using namespace std;
#define N 4

void printSolution(int board[N][N]) {
    static int solutionCount = 0;
    cout << "solution:" << ++solutionCount << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // if 1 then printing Queen
            if (board[i][j] == 1) {
                cout << "Q" << (i + 1) << " ";
            } else {
                cout << "-- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[N][N], int row, int col) {
    // checking whether there is any other Queen placed in the same row(Horizonatlly)
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // checking whether there is any other Queen placed in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // checking whether there is any other Queen placed in the Lower left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}
void solveNQueens(int board[N][N], int col, int &solutions) {
    if (col >= N) {
        printSolution(board);
        solutions++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place queen
            solveNQueens(board, col + 1, solutions); // Recur to place rest of the queens
            board[i][col] = 0; // Backtrack
        }
    }
}
void nQueens(){
    int board[N][N] = {0};

    int solutions = 0;
    solveNQueens(board, 0, solutions);

    cout << "Total Solutions for " << N << "*" << N << " board is " << solutions << endl;
}

int main(){
    nQueens();
    return 0;
}