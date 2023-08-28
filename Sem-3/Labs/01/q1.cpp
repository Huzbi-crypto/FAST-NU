// Title: DSA-Lab - Lab-01 - Q1
// Huzefa Saifuddin (Huzbi) - 22K-5125

#include <iostream>
using namespace std;

class DynamicArray {
    int ncols;
    int* pointerOfDynamicArray;

    public:
    DynamicArray() {
        ncols = 0;
        pointerOfDynamicArray = 0;
    }

    DynamicArray( int arraySize ) {
        ncols = arraySize;
        pointerOfDynamicArray = new int[ ncols ];

        for ( int i = 0; i < ncols; i++ ) {
            int value;
            cout << "Enter an int value: ";
            cin >> value;
            pointerOfDynamicArray[ i ] = value;
        }
    }

    ~DynamicArray() {
        ncols = 0;
        pointerOfDynamicArray = 0;
        delete[] pointerOfDynamicArray;
    }

    void valueDisplay() {
        cout << "Value ";
        for ( int i = 0; i < ncols; i++ ) {
            cout << "[ " << pointerOfDynamicArray[ i ] << " ] ";
        }
        cout << endl;
    }
};

int main() {
    int arraySize;
    cout << "What size of array you're intializing: ";
    cin >> arraySize;

    DynamicArray obj( arraySize );

    obj.valueDisplay();

    obj.~DynamicArray();
    
    return 0;
}
