// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab07 - Q1

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class Stack {
    private:
        Node *top;
    public:
        Stack() {
            top = NULL;
        }
        void push(int val) {
            // LOGIC: add to the top of the stack
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = top;
            top = newNode;
        }
        int pop() {
            // LOGIC: remove from the top of the stack
            int val = top->data;
            Node *temp = top;
            top = top->next;
            delete temp;
            return val;
        }
        void peek() {
            cout << top->data << endl;
        }
        bool isEmpty() {
            return top == NULL;
        }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    s.peek();
    s.pop();
    cout << s.isEmpty() << endl; // if 1, then empty
    return 0;
}