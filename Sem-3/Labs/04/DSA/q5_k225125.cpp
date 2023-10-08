// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// DSA - Lab#04 - Q5

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = nullptr;
    }
    Node(int data) {
        this->data = data;
        this->next = nullptr;
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
        if(this->head == nullptr) {
            this->head = this->tail= new Node(data);
            return;
        } else {
            Node *newNode = new Node(data);
            newNode->next = this->head;
            this->head = newNode;
            return;
        }
    }

    void insertAtTail(int data) {
        if(this->head == nullptr) {
            this->head = this->tail= new Node(data);
            this->tail->next = nullptr;
            return;
        } else {
            Node *newNode = new Node(data);
            this->tail->next = newNode;
            this->tail = newNode;
            this->tail->next = nullptr;
            return;
        }
    }

    void insertAfterNode(Node *node, int data) {
        if(node == nullptr) {
            cout << "Error: Node after which to insert is not found" << endl;
            return;
        } else {
            Node *newNode = new Node(data);
            newNode->next = node->next;
            node->next = newNode;
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

        do {
            if(temp != nullptr && temp->data == data) {
                temp->next = temp->next->next;
                // Check if node to be deleted is tail
                if(temp == this->tail) {
                    this->tail = temp;
                }
                return;
            }
            temp = temp->next;
        } while(temp != nullptr);

        if(temp == nullptr) {
            cout << "Error: Node to be deleted is not found" << endl;
            return;
        }

        // Check if node to be deleted is head
        if(temp == this->head) {
            this->head = temp->next;
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

    // creating a method to reverse the linked list
    void reverseList() {
        Node *current = this->head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while(current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
        this->tail = current;
    }

    ~LinkedList() {
        Node *temp = this->head;

        do {
            delete temp;
            temp = temp->next;
        } while (temp != nullptr);
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
    list.reverseList();
    
    return 0;
}