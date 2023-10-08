// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab06 - Q4

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateRandomNumbers(int arr[], int size) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    cout << "Array with random " << size <<  " integers generated.\n";

}

// Section for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Section for Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    return;
}

// Section for Quick Sort
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}
int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

// Section for Radix Sort
void radixSort(int arr[], int n) {
    
    int m = *max(arr, arr + n);

    for (int exp = 1; m/exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}
void countSort(int arr[], int n, int exp) {

    int output[n];
    int i;
    int count[10];

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[1000];
    int size = sizeof(arr) / sizeof(arr[0]);

    generateRandomNumbers(arr, size);

    mergeSort(arr, 0, 999);

    return 0;
}
