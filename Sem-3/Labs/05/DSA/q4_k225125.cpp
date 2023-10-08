// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA - Lab05 - Q4

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void InitBoard(int ***board, int n) {
    int **board;
    *board = new int*[n];

    for (int i = 0; i < n; i++) {
        (*board)[i] = new int[n];
    }

    return;
}

void FillKnightsBoard(int **board, int **kBoard, int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            kBoard[i][j] = board[i][j];
        }
    }
    return;
}

bool IsSafe(int **board, int boardSize, int row, int col) {
    if (row < 0 && row >= boardSize && col < 0 & col >= boardSize)
        return false;

    if (board[row][col] == 'K')
        return false;

    // movement of knight for left then up " ^ < < "
    int newRow = row + -2;
    int newCol = col + 1;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    // movement of knight for left then up " ^ ^ < "
    int newRow = row + -1;
    int newCol = col + 2;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    // movement of knight for right then up " > ^ ^ "
    int newRow = row + 1;
    int newCol = col + 2;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    // movement of knight for right then up " > > ^ "
    int newRow = row + 2;
    int newCol = col + 1;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    // movement of knight for right then down " > > _ "
    int newRow = row + 2;
    int newCol = col + -1;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    // movement of knight for right then down " > _ _ "
    int newRow = row + 1;
    int newCol = col + -2;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    // movement of knight for left then down " < _ _ "
    int newRow = row + -1;
    int newCol = col + -2;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    // movement of knight for left then down " < < _ "
    int newRow = row + -2;
    int newCol = col + -1;
    if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && board[newRow][newCol] == 'K')
        return false; 
    
    return true;

}

void SolveKnightsBoard(int row, int **board, int **kBoard, int boardSize) {
    if (row == ((boardSize * boardSize) / 2)) {
        FillKnightsBoard(board, kBoard, boardSize);
        return;
    }

    for (int i = 0; i < boardSize; i++) {
        if (IsSafe(board, boardSize, row, i)) {
            board[row][i] = 'K';
            SolveKnightsBoard(row + 1, board, kBoard, boardSize);

            board[row][i] = 0;
        }
    }

}

int** StartBoard(int boardSize) {
    // Initialize the chess board
    int **board;
    InitBoard(&board, boardSize);

    // Initialize the Queens board
    int **kBoard;
    InitBoard(&kBoard, boardSize);

    SolveKnightsBoard(0, board, kBoard, boardSize);

    return kBoard;

}

int main() {
    int boardSize;
    cout << "Enter the size of the chessboard: ";
    cin >> boardSize;

    int **kBoard = StartBoard(boardSize);

    // Print the solution
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << kBoard[i][j] << " ";
        }
        cout << endl;
    }

    // delete the dynamically allocated memory
    for (int i = 0; i < boardSize; i++) {
        delete[] kBoard[i];
    }
    delete[] kBoard;

    return 0;
}
