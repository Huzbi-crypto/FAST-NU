// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA - Lab#04 - Q2

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
    public:
    Node *head;
    Node *tail;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtHead(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = nullptr;

        if(this->head != nullptr) {
            this->head->prev = newNode;
        } else {
            this->tail = newNode;
        }
        this->head = newNode;
    }

    void insertAtTail(int data) {
        Node *newNode = new Node(data);
        newNode->next = nullptr;

        if(this->head != nullptr) {
            newNode->prev = this->tail;
            this->tail->next = newNode;
        } else {
            this->head = newNode;
            newNode->prev = nullptr;
        }
        this->tail = newNode;
    }

    void insertAfterNode(Node *node, int data) {
        if(node == nullptr) {
            cout << "Error: Node after which to insert is not found" << endl;
            return;
        } else {
            Node *newNode = new Node(data);
            newNode->next = node->next;
            node->next = newNode;
            newNode->prev = node;
            newNode->next->prev = newNode;
        }
    }

    void updateNode(int old_data, int new_data) {
        Node *temp = head;

        do {
            if(temp != nullptr && temp->data == old_data) {
                temp->data = new_data;
                return;
            }
            temp = temp->next;
        } while(temp != nullptr);

        if(temp == nullptr) {
            cout << "Error: Node to be deleted is not found" << endl;
            return;
        }
        
    }

    void deleteNode(int data) {
        Node *temp = head;

        // deletion of node in the middle
        while(temp != nullptr && temp->data != data) {
            temp = temp->next;
        }
        if(temp == nullptr && temp->data != data) {
            cout << "Error: Node to be deleted is not found" << endl;
            return;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }

        // deletion of node at the beginning
        if(temp == this->head) {
            this->head = temp->next;
            delete temp;
            return;
        }

        // deletion of node at the end
        if(temp == this->tail) {
            this->tail = temp->prev;
            delete temp;
            return;
        }
    }

    void printList() {
        Node *temp = this->head;
        
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != nullptr);

        cout << endl;
    }

    ~LinkedList() {
        Node *temp = head->next;
        
        do {
            delete temp;
            temp = temp->next;
        } while(temp != nullptr);
    }
};

int main() {
    LinkedList list;
    
    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAfterNode(list.head->next, 5);
    list.insertAfterNode(list.head->next, 6);
    list.insertAfterNode(list.head->next, 7);
    list.insertAfterNode(list.head->next, 8);
    list.updateNode(1, 10);
    list.deleteNode(2);
    list.printList();
    
    return 0;
}