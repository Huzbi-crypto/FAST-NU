// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA - Lab05 - Q1

#include <iostream>
using namespace std;

int Fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    else return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    int n;
    
    cout << "Enter the sequence no. for Fibonacci Sequence: ";
    cin >> n;

    for(int i = 0; i <= n; i++) {
        cout << i << "th sequence: " << Fibonacci(i) << endl;
    }
    
    return 0;
}