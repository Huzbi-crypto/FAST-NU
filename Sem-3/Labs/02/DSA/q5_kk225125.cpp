// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab02 - Q5

#include <iostream>

using namespace std;

void insertionSort( int*& crates, int nElements ) {
    int i, key, j;
    for ( int i = 1; i < nElements; i++ ) {
        key = crates[ i ];
        j = i - 1;

        while (j >= 0 && crates[ j ] > key ) {
            crates[ j + 1 ] = crates[ j ];
            j--;
        }

        crates[ j + 1 ] = key;
    }

    return;
}

void valueDisplay( int*& array, int nElements ) {
    for ( int i = 0; i < nElements; i++ ) {
        cout << i + 1 << ". " << array[ i ] << endl;
    }
    cout << endl;
}

void makeArray( int*& array, int nElements) {
    cout << "Memory Allocation processed...\n";
    array = new int [ nElements ];
    return;
}

void assignArrayValues( int*& array, int nElements ) {
    cout << "Values assignment called...\n";
        int time;
    for ( int i = 0; i < nElements; i++ ) {
        cout << "Enter the time for the " << i + 1 << " crate: ";
        cin >> time;
        array[ i ] = time;
        cout << "Entered!\n";
    }
    return;
}

int main() {
    int* crates;

    cout << "Enter the total crates to be shipped: ";
    int nCrates;
    cin >> nCrates;

    makeArray(crates, nCrates); // dynamically allocating space for the crates array

    assignArrayValues(crates, nCrates); // assigning values to each index of crates array

    cout << "Your time for each crate's shipping: " << endl;
    valueDisplay(crates, nCrates); // displaying values before sorting

    insertionSort(crates, nCrates); // insertion sorting algorithm

    cout << "Sorted data:" << endl;
    valueDisplay(crates, nCrates); // displaying values after sorting

    delete[] crates;
    
    return 0;
}