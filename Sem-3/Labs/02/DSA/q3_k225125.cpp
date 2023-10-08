// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab02 - Q3

#include <iostream>

using namespace std;

void reverseInsertionSort( int elements[], int nElements ) {
    for ( int i = nElements - 2; i >= 0; i-- ) {
        int key = elements[ i ];
        int j = i + 1;

        while ( j < nElements && elements[ j ] > key ) {
            elements[ j - 1 ] = elements[ j ];
            j++;
        }

        elements[ j - 1 ] = key;
    }

    return;
}

void insertionSort( int elements[], int nElements ) {
    int key, j;

    for ( int i = 1; i <= nElements - 1; i++ ) {
        key = elements[ i ];
        j = i - 1;

        while ( elements[ j ] > key && j >= 0 ) {
            elements[ j + 1 ] = elements[ j ];
            j--;
        }

        elements[ j + 1 ] = key;
    }

    return;
}

void valueDisplay( int elements[], int nElements ) {
    for ( int i = 0; i < nElements; i++ ) {
        cout << "[ " << elements[ i ] << " ] ";
    }
    cout << endl;
}

int main() {
    int elements[] = {12, 34, 76, 23, 10, 5, 24};
    int nElements = sizeof(elements) / sizeof(elements[ 0 ]);

    cout << "Before Sorting:" << endl;
    valueDisplay(elements, nElements);
    
    cout << endl;

    cout << "After Sorting (Insertion Sort):" << endl;
    insertionSort(elements, nElements);
    valueDisplay(elements, nElements);

    cout << endl;

    cout << "After Sorting (Reverse Insertion Sort):" << endl;
    reverseInsertionSort(elements, nElements);
    valueDisplay(elements, nElements);

    return 0;
}