// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab02 - Q4

#include <iostream>

using namespace std;

void assignArrayValues( int useValues[], int assignValues[], int sizeOfArray ) {
    cout << "Values assignment called\n";
    for ( int i = 0; i < sizeOfArray; i++ ) {
        assignValues[ i ] = useValues[ i ];
    }
    return;
}

// bubble sort function to sort array
void bubbleSort( int numbers[], int nElements ) {
    cout << "Bubble Sort called\n";
    for ( int i = 0; i < nElements - 1; i++ ) {
        for ( int j = 0; j < nElements - 1 - i; j++ ) {
            if ( numbers[ j ] > numbers[ j + 1 ]) {
                int temp = 0;
                temp = numbers[ j ];
                numbers[ j ] = numbers[ j + 1 ];
                numbers[ j + 1 ] = temp;
            }
        }
    }

    return;
}

// finding the minimum sub array which can sort the total array
int minLengthSubArray( int numbers[], int nElements ) {
    int* tempArray;
    int s = 0;
    int e = 0;
    
    tempArray = new int[ nElements ];
    assignArrayValues(numbers, tempArray, nElements);
    bubbleSort(tempArray, nElements);

    for ( int i = 0; i < nElements; i++ ) {
        if ( numbers[ i ] != tempArray[ i ] ) {
            s = i;
            break;
        }
    }

    for ( int i = nElements - 1; i >= 0; i-- ) {
        if ( numbers[ i ] != tempArray[ i ] ) {
            e = i;
            break;
        }
    }

    delete [] tempArray;

    return ( e - s + 1 );
}

// function to show the elements in the array
void valueDisplay( int numbers[], int nElements ) {
    for ( int i = 0; i < nElements; i++ ) {
        cout << "[ " << numbers[ i ] << " ] ";
    }
    cout << endl;
}

int main() {
    int numbers[] = { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60 };
    int nElements = sizeof( numbers ) / sizeof( numbers[ 0 ] );

    cout << "The minimum sub-array length which will sort is: " << minLengthSubArray( numbers, nElements );

    return 0;
}