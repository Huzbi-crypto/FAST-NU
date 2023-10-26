// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab08 - Q3

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node {
    public:
    char data;
    Node *left;
    Node *right;
    Node(char data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


/*  LOGIC:
    *   If the character is an operand, push it onto the stack
    *   If the character is an operator, pop two operands from the stack, create a new node with the operator as the root and the two operands as the left and right children, 
    *   and push the new node onto the stack
    *   When the expression is over, the stack will contain only one node, which is the root of the tree
    *   Return the root
*/
Node *buildTree(string infix) {
    stack<Node *> st;
    // Iterate over the infix expression and build the tree accordingly
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            Node *right = st.top();
            st.pop();
            Node *left = st.top();
            st.pop();
            Node *root = new Node(infix[i]);
            root->left = left;
            root->right = right;
            st.push(root);
        } else {
            Node *node = new Node(infix[i]);
            st.push(node);
        }
    }
    return st.top();
}

// Inorder traversal of the tree
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Evaluate the expression tree
/*
    *   If the root is NULL, return 0
    *   If the root is a leaf node, return the value of the leaf node
    *   If the root is an operator, evaluate the left and right subtrees and return the result of the operation
    *   If the root is not an operator, return 0
    *   This function will be called recursively on the left and right subtrees
*/
int evaluate(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0';
    }
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    if (root->data == '+') {
        return left + right;
    } else if (root->data == '-') {
        return left - right;
    } else if (root->data == '*') {
        return left * right;
    } else if (root->data == '/') {
        return left / right;
    }
    return 0;
}

int main() {
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    Node *root = buildTree(infix);
    cout << "Inorder traversal of the expression tree: ";
    inorder(root);
    cout << endl;
    cout << "Result of the expression: " << evaluate(root) << endl;
    return 0;
}