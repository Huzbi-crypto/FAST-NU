// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab07 - Q3

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
        void push(char val) {
            // LOGIC: add to the top of the stack
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = top;
            top = newNode;
        }
        char pop() {
            // LOGIC: remove from the top of the stack
            char val = top->data;
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

bool checkBracketString(string testCase) {
    Stack s;

    // LOGIC: push opening brackets to stack, pop closing brackets from stack
    for (int i = 0; i < testCase.length(); i++) {
        if (testCase[i] == '(' || testCase[i] == '{' || testCase[i] == '[') {
            s.push(testCase[i]);
        } else if (testCase[i] == ')' && s.pop() == '(') {
            continue;
        } else if (testCase[i] == '}' && s.pop() == '{') {
            continue;
        } else if (testCase[i] == ']' && s.pop() == '[') {
            continue;
        } else {
            cout << "Invalid: Bracket unbalanced" << endl;
            return 0;
        }
    }

    // LOGIC: if stack is empty, then bracket is balanced
    if (s.isEmpty()) {
        cout << "Valid: Bracket balanced" << endl;
    } else {
        cout << "Invalid: Bracket unbalanced" << endl;
    }
}

int main() {

    string testCase = "({[]})";
    
    checkBracketString(testCase);

    string testCase2 = "({[})";

    checkBracketString(testCase2);

    return 0;
}