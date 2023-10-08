// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab06 - Q1

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateRandomNumbers(int arr[], int size, int min, int max) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % max) + min;
    }

    cout << "Array with random " << size <<  " integers generated.\n";

}

void countNumberOccurrences(int arr[], int size) {
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    int count9 = 0;
    int count10 = 0;

    for (int i = 0; i < size; i++) {
        switch (arr[i]) {
            case 1:
                count1 += 1;
                break;
            case 2:
                count2 += 1;
                break;
            case 3:
                count3 += 1;
                break;
            case 4:
                count4 += 1;
                break;
            case 5:
                count5 += 1;
                break;
            case 6:
                count6 += 1;
                break;
            case 7:
                count7 += 1;
                break;
            case 8:
                count8 += 1;
                break;
            case 9:
                count9 += 1;
                break;
            case 10:
                count10 += 1;
                break;
        }
    }

    // print the counts
    cout << "Count of 1: " << count1 << endl;
    cout << "Count of 2: " << count2 << endl;
    cout << "Count of 3: " << count3 << endl;
    cout << "Count of 4: " << count4 << endl;
    cout << "Count of 5: " << count5 << endl;
    cout << "Count of 6: " << count6 << endl;
    cout << "Count of 7: " << count7 << endl;
    cout << "Count of 8: " << count8 << endl;
    cout << "Count of 9: " << count9 << endl;
    cout << "Count of 10: " << count10 << endl;

}

// THIS SECTION IS FOR KTH LARGEST INPUT AND ITS OCCURRENCES
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int kthCountOccurrences(int arr[], int size, int kthLargest) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == kthLargest) {
            count += 1;        
        }
    }

    return count;
}
void kthLargestInput(int k, int arr[], int size) {
    bubbleSort(arr, size);

    int kthLargest;
    kthLargest = arr[k - 1];

    int kthCount;
    kthCount = kthCountOccurrences(arr, size, k);

    cout << "Kth Largest: " << kthLargest << endl;
    cout << "Kth Occurrences: " << kthCount << endl;
}

// THIS SECTION IS FOR SEARCHIN AND REPLACING A VALUE IN THE ARRAY
void replaceOccurrences(int array[], int size, int target, int replace) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            array[i] = replace;
        }
    }
}

int main() {
    int array[500];
    int size = sizeof(array) / sizeof(array[0]);
    
    // Generate random numbers in the array
    generateRandomNumbers(array, size, 1, 10);

    // Count occurrences
    countNumberOccurrences(array, size);

    // Sort the array and find the kth largest number and its occurrences
    bubbleSort(array, size);
    cout << "Enter the value for k: ";
    int k;
    cin >> k;
    kthLargestInput(k, array, size);

    // Replace occurrences of a number with a new number
    cout << "Enter the value to search for: ";
    int target;
    cin >> target;
    cout << "Enter the new value: ";
    int replace;
    cin >> replace;
    replaceOccurrences(array, size, target, replace);
    // Print the modified array
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }

    return 0;
}