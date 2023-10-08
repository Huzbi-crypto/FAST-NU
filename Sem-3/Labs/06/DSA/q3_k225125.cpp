// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab06 - Q3

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Section for Sorting a 2D array
void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[i];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sort2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bubbleSort(arr[i], cols);
    }
}

// Section for Creating, Initializing, Deleting a 2D array
int** createAndInitializeArray(int rows, int cols) {
    srand(time(0));

    // Creating and initializing the 2D array
    int** arr = new int*[rows]; 
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols]; 
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 1000 + 1;
        }
    }
    return arr;
}
void deleteArray(int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}


int main() {
    
    int rows = 5;
    int cols = 10;
    int** arr = createAndInitializeArray(rows, cols);
    
    deleteArray(arr, rows);
    
    return 0;
}