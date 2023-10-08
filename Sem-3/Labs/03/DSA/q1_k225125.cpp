// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab03 - Question 1

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = NULL;
    }

    Node( int node_data ) {
        data = node_data;
        next = NULL;
    }  
};

class LinkedList {
    public:
    Node head;

    LinkedList() {
        head = NULL;
    }

    LinkedList( Node n ) {
        head = n;
    }
};

int main() {

    return 0;
}