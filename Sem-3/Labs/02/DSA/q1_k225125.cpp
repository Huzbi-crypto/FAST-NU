// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab02 - Q1

#include <iostream>

using namespace std;

void bubbleSort( string strings[], int nElements ) {

    for ( int i = 0; i < nElements - 1; i++ ) {
        for ( int j = 0; j < nElements - 1 - i; j++ ) {
            if ( strings[ j ] > strings[ j + 1 ]) {
                string temp = "";
                temp = strings[ j ];
                strings[ j ] = strings[ j + 1 ];
                strings[ j + 1 ] = temp;
            }
        }
    }

    return;
}

void valueDisplay( string strings[], int nElements ) {
    for ( int i = 0; i < nElements; i++ ) {
        cout << "[ " << strings[ i ] << " ] ";
    }
    cout << endl;
}

int main() {
    string strings[] = { "hello", "world", "!" };
    int nElements = sizeof( strings ) / sizeof( strings[ 0 ] );

    cout << "Before Sorting" << endl;
    valueDisplay(strings, nElements);

    cout << "After Sorting" << endl;
    bubbleSort(strings, nElements);
    valueDisplay(strings, nElements);

    return 0;
}