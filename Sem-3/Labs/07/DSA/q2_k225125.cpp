// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab07 - Q2

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Queue {
    private:
        Node *front;
        Node *rear;
    public:
        Queue() {
            front = NULL;
            rear = NULL;
        }
        void enqueue(int val) {
            // LOGIC: add to the end of the queue
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = NULL;
            // similar to head and tail's check in linked list
            if (front == NULL) {
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }
    int dequeue() {
        // LOGIC: remove from the front of the queue
        int val = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        return val;
    }
    void peek() {
        cout << front->data << endl;
    }
    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    cout << q.isEmpty() << endl; // if 1, queue is empty
    return 0;
}