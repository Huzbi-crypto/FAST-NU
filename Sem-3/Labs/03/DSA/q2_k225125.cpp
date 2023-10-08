// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab03 - Question 2

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
    Node* head;

    LinkedList() {
        head = NULL;
    }

    LinkedList( Node *n ) {
        head = n;
    }

    void appendNode( int node_data ) {
        Node *newNode = new Node();
        newNode->data = node_data;

        if ( head == NULL ) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while ( temp != NULL ) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};

int main() {

    return 0;
}