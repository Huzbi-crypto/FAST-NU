// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab02 - Q2

#include <iostream>

using namespace std;

class date {
    public:
    int year;
    int month;
    int day;

    date() {
        year = 0;
        month = 0;
        day = 0;
    }
};

void selectionSort( date dates[], int nElements ) {
    for ( int i = 0; i < nElements - 1; i++ ) {
        for ( int j = i + 1; j < nElements; j++ ) {
            if ( dates[ i ].year > dates[ j ].year) {
                date temp;
                temp = dates[ i ];
                dates[ i ] = dates[ j ];
                dates[ j ] = temp;
            }
            if ( dates[ i ].year == dates[ j ].year && dates[i].month > dates[j].month) {
                date temp;
                temp = dates[ i ];
                dates[ i ] = dates[ j ];
                dates[ j ] = temp;
            }
            if ( dates[ i ].year == dates[ j ].year && dates[i].month == dates[j].month && dates[i].day > dates[j].day) {
                date temp;
                temp = dates[ i ];
                dates[ i ] = dates[ j ];
                dates[ j ] = temp;
            }
        }
    }

    return;
}

void viewDates( date dates[], int nElements ) {
    for ( int i = 0; i < nElements; i++ ) {
        cout << "Date " << i + 1 << ": " << dates[ i ].day << "." << dates[ i ].month << "." << dates[ i ].year << endl;
    }
}

void getDates( date dates[], int nElements )  {
    for ( int i = 0; i < nElements; i++ ) {
        cout << "Enter day: ";
        cin >> dates[ i ].day;
        cout << "Enter month: ";
        cin >> dates[ i ].month;
        cout << "Enter year: ";
        cin >> dates[ i ].year;
    }
    return;
} 

int main() {
    date dates[ 5 ];
    int nElements = sizeof( dates ) / sizeof( dates[ 0 ] );

    getDates(dates, nElements); // getting dates

    viewDates( dates, nElements ); // before sorting

    cout << endl;

    selectionSort( dates, nElements ); // selection sort algorithm

    viewDates( dates, nElements ); // after sorting

    return 0;
}

