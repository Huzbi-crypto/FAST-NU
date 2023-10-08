// Title: DSA-Lab - Lab-01 - Q2
// Huzefa Saifuddin (Huzbi) - 22K-5125

#include <iostream>
using namespace std;

class DynamicArray {
    int ncols, nrows;
    int** pointerOfPointers;

    public:
    DynamicArray() {
        ncols = 0;
        nrows = 0;
        pointerOfPointers = 0;
    }

    DynamicArray( int rows, int cols ) {
        ncols = cols;
        nrows = rows;

        pointerOfPointers = new int* [ ncols ];

        for ( int i = 0; i < ncols; i++ ) {
            pointerOfPointers[ i ] = new int[ nrows ];
            
            for ( int j = 0; j < rows; j++ ) {
                int value;
                cout << "Enter an int value: ";
                cin >> value;
                pointerOfPointers[ i ][ j ] = value;
            }
        }
    }

    void valueDisplay() {
        cout << "2D Array" << endl;

        for ( int i = 0; i < ncols; i++ ) {
            cout << "Col: " << pointerOfPointers[ i ] << endl;
            for ( int j = 0; j < nrows; j++ ) {
                cout << "Row [ " << j << " ] " << pointerOfPointers[i][j] << endl;
            }
        }
    }

    ~DynamicArray() {
        ncols = 0;
        nrows = 0;

        for ( int i = 0; i < ncols; i++ ) {
            delete[] pointerOfPointers[i];
        }
        delete[] pointerOfPointers;
    }
};

int main() {
    int rows, cols;
    cout << "This is a 2D array.\nEnter the colums; ";
    cin >> cols;
    cout << "and rows; ";
    cin >> rows;

    DynamicArray obj( rows, cols );

    obj.valueDisplay();

    obj.~DynamicArray();

    return 0;
}
