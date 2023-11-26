// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab07 - Q4

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

// function to convert prefix to postfix
string prefixToPostfix(string prefix) {
    Stack s;
    string postfix = "";

    /* LOGIC: push operands to stack
    * when operator is encountered, pop two operands from stack
    * and append them to the operator
    * concatenate the result to the postfix string
    */
    for (int i = prefix.length() - 1; i >= 0; i--) {
        // if operand, push to stack
        if (prefix[i] >= '0' && prefix[i] <= '9') {
            s.push(prefix[i]);
        } else { // if operator, pop two operands from stack
            string op1 = "";
            op1 += s.pop();
            string op2 = "";
            op2 += s.pop();
            string temp = op1 + op2 + prefix[i];
            postfix += temp;
        }
    }

    return postfix;
}

int main() {

    string prefix = "+9*26";

    cout << prefixToPostfix(prefix) << endl; // 926*+

    return 0;
}