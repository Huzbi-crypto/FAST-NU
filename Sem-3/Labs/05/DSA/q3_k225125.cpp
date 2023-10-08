// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA - Lab05 - Q3

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void InitBoard(int ***board, int n) {
    int **board;
    *board = new int*[n];

    for(int i = 0; i < n; i++) {
        (*board)[i] = new int[n];
    }

    return;
}

void FillKnightsBoard(int **board, int **qBoard, int boardSize) {
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            qBoard[i][j] = board[i][j];
        }
    }
    return;
}

bool IsSafe(int **board, int boardSize, int row, int col) {
    // check for colum
    int x = row;
    int y = col;
    while(x >= 0) {
        if(board[x][y] == 'Q')
            return false;
        x--;
    }
    
    // check for right diagonal
    int x = row;
    int y = col;
    while((x >= 0) && (y < boardSize)) {
        if(board[x][y] == 'Q')
            return false;
        x--;
        y++;
    }

    // check for left diagonal
    int x = row;
    int y = col;
    while((x >= 0) && (y >= 0)) {
        if(board[x][y] == 'Q')
            return false;
        x--;
        y--;
    }
}

void SolveKnightsBoard(int row, int **board, int **qBoard, int boardSize) {
    if(row == (boardSize - 1)) {
        FillKnightsBoard(board, qBoard, boardSize);
        return;
    }

    for(int i = 0; i < boardSize; i++) {
        if(IsSafe(board, boardSize, row, i)) {
            board[row][i] = 'Q';
            SolveKnightsBoard(row + 1, board, qBoard, boardSize);

            board[row][i] = 0;
        }
    }

}

int** StartBoard(int boardSize) {
    // Initialize the chess board
    int **board;
    InitBoard(&board, boardSize);

    // Initialize the Queens board
    int **qBoard;
    InitBoard(&qBoard, boardSize);

    SolveKnightsBoard(0, board, qBoard, boardSize);

    return qBoard;

}

int main() {
    // Ask the user for the size of the chessboard
    int boardSize;
    cout << "Enter the size of the chessboard: ";
    cin >> boardSize;

    int **qBoard = StartBoard(boardSize);

    // Print the solution
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << qBoard[i][j] << " ";
        }
        cout << endl;
    }

    // delete the dynamically allocated memory
    for (int i = 0; i < boardSize; i++) {
        delete[] qBoard[i];
    }
    delete[] qBoard;

    return 0;
}


