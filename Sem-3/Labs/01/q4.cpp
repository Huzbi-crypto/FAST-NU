// Title: DSA-Lab - Lab-01 - Q4
// Huzefa Saifuddin (Huzbi) - 22K-5125

#include <iostream>
using namespace std;

class DynamicJaggedArray {
    int ncols;
    int* nrows;
    int** pointerOfPointers;

    public:
    DynamicJaggedArray() {
        ncols = 0;
        nrows = 0;
        pointerOfPointers = 0;
    }

    DynamicJaggedArray( int cols ) {
        ncols = cols;
        nrows = new int[ ncols ];

        pointerOfPointers = new int* [ ncols ];
    }

    void setArray () {
        for ( int i = 0; i < ncols; i++ ) {
            cout << "Enter the row " << i << " size: ";
            cin >> nrows[ i ];

            pointerOfPointers[ i ] = new int[ nrows[ i ] ];
        } 
    }

    void storeValues () {
        for ( int i = 0; i < ncols; i++ ) {
            for ( int j = 0; j < nrows[ i ]; j++ ) {
                cout << "Enter an int value: ";
                int value;
                cin >> value;

                pointerOfPointers[ i ][ j ] = value;
            }
        }
    }

    void displayValues() {
        cout << "2D Jagged Array" << endl;

        for ( int i = 0; i < ncols; i++ ) {
            cout << "Col: " << pointerOfPointers[i] << endl;
            for ( int j = 0; j < nrows[ i ]; j++ ) {
                cout << "Row [ " << j << " ] " << pointerOfPointers[i][j] << endl;
            }
        }
    }

    // Safe array boundary check
    int &operator () ( int rowArrayIndex, int colArrayIndex ) {
        if ( rowArrayIndex < 0 || rowArrayIndex >= *nrows || colArrayIndex < 0 || colArrayIndex >= ncols ) {
            cout << "Boundary Error: Entered index value is out of bounds of the array size.\n";
            exit( 1 );
        }
    }

    ~DynamicJaggedArray() {
        ncols = 0;

        for ( int i = 0; i < ncols; i++ ) {
            delete[] pointerOfPointers[ i ];
        }
        delete[] pointerOfPointers;
        delete[] nrows;
    }
};

int main() {
    int cols;
    cout << "We are creating 2D Jagged Array.\nEnter your column size: ";
    cin >> cols;

    DynamicJaggedArray obj( cols );
    obj.setArray(); // Making the dynamic row sizes for each colum
    obj.storeValues();
    obj.displayValues();
    obj.~DynamicJaggedArray();

    return 0;
}
