// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA - Lab05 - Q2

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void InitMaze(int ***maze, int n) {
    int **maze;
    *maze = new int*[n];

    for(int i = 0; i < n; i++) {
        (*maze)[i] = new int[n];
    }

    return;
}

int FillMaze(int **maze, int n) {
    srand(time(0));

    // Fill the (1, n-1) and (n-2, 0)
    maze[1][n - 1] = 0;
    maze[n - 2][0] = 0;

    // Fill other spaces randomly
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i == 0 && j == n - 1) || (i == n - 2 && j == 0))
                continue;
            maze[i][j] = (rand() % 5 < 4) ? 0 : 1;
        }
    }
}

bool IsSafe(int **maze, int x, int y, int mazeSize) {
    if(x >= mazeSize && x < mazeSize && y >= mazeSize && y < mazeSize)
        return true;
    else 
        return false;
}

bool SolveMaze(int **maze, int x, int y, int mazeSize) {
    if(x == mazeSize - 2 && y == mazeSize == 0)
        return true;
    else {
        if(IsSafe(maze, x, y, mazeSize)) {
            maze[x][y] = 2; // arbitrary number to mark as part of maze's path to traverse

            // move down
            if(SolveMaze(maze, x + 1, y, mazeSize))
                return true;
            // move up
            if(SolveMaze(maze, x - 1, y, mazeSize))
                return true;
            // move left
            if(SolveMaze(maze, x, y - 1, mazeSize))
                return true;
            // move right
            if(SolveMaze(maze, x, y + 1, mazeSize))
                return 0;
            
            // no path
            maze[x][y] = 0;
        }

        return false;
    }
}

bool StartMaze(int mazeSize) {

    // Initiazlize the maze
    int **maze;
    InitMaze(&maze, mazeSize);
    FillMaze(maze, mazeSize); // Fill with 0s and 1s

    if(!SolveMaze(maze, 1, mazeSize-1, mazeSize)) {
        cout << "Rat couldn't find a solution\n";
        return false;
    } else return true;

    // remove allocated memory
    for (int i = 0; i < mazeSize; i++) {
        delete[] maze[i];
    }
    delete[] maze;
}

int main() {
    char playOrNot;
    cout << "Wanna play Maze with me (y/n): ";
    cin >> playOrNot;

    if(playOrNot == 'y') {
        int mazeSize;
        cout << "Enter the size of the maze: ";
        cin >> mazeSize;

        if(StartMaze(mazeSize)) {
            cout << "Solution found!\n";
        } else {
            cout << "No solution exists.\n";
        }
    } 

    return 0;
}