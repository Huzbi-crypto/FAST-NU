// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// DSA - Lab#04 - Q4

#include <iostream>

using namespace std;

// A node for singly linked list
class NodeForSingly {
    public:
    int data;
    NodeForSingly* next;

    NodeForSingly() {
        this->data = 0;
        this->next = nullptr;
    }

    NodeForSingly(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// A node for doubly linked list
class NodeForDoubly {
    public:
    int data;
    NodeForDoubly* next;
    NodeForDoubly* prev;

    NodeForDoubly() {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    NodeForDoubly(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    // Node(int data, Node* next) {
    //     this->data = data;
    //     this->next = next;
    // }
};

// A singly linked list with no circular property
class SinglyLinkedList {
    public:
    NodeForSingly *head;
    NodeForSingly *tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtHead(int data) {
        if(this->head == nullptr) {
            this->head = this->tail= new NodeForSingly(data);
            return;
        } else {
            NodeForSingly *newNode = new NodeForSingly(data);
            newNode->next = this->head;
            this->head = newNode;
            return;
        }
    }

    void insertTail(int data) {
        if(this->head == nullptr) {
            this->head = this->tail= new NodeForSingly(data);
            return;
        } else {
            NodeForSingly *newNode = new NodeForSingly(data);
            this->tail->next = newNode;
            this->tail = newNode;
            return;
        }
    }

    void insertAfterNode(NodeForSingly *node, int data) {
        if(node == nullptr) {
            cout << "Error: Node after which to insert is not found" << endl;
            return;
        } else {
            NodeForSingly *newNode = new NodeForSingly(data);
            newNode->next = node->next;
            node->next = newNode;
        }
    }

    void updateNode(int old_data, int new_data) {
        NodeForSingly *temp = head;

        do {
            if(temp != nullptr && temp->data == old_data) {
                temp->data = new_data;
                return;
            }
            temp = temp->next;
        } while(temp != nullptr);

        if(temp == nullptr) {
            cout << "Error: Node to be updated is not found" << endl;
            return;
        }
        
    }

    void deleteNode(int data) {
        NodeForSingly *temp = head;

        do {
            if(temp != nullptr && temp->data == data) {
                temp->next = temp->next->next;
                // check if node to be deleted is tail
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
        NodeForSingly *temp = this->head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // creating an assignment operator overloading to convert a doubly linked list to a singly linked list
    SinglyLinkedList&  SinglyLinkedList::operator=(const DoublyLinkedList& list) {
        SinglyLinkedList newList;

        NodeForDoubly *temp = list.head;
        do {
            newList.insertTail(temp->data);
            temp = temp->next;
        } while(temp != list.head);

        return newList;
    }

    ~SinglyLinkedList() {
        NodeForSingly *temp = this->head;

        do {
            delete temp;
            temp = temp->next;
        } while (temp != nullptr);
    }
};

class DoublyLinkedList {
    public:
    NodeForDoubly *head;
    NodeForDoubly *tail;

    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insertAtHead(int data) {
        NodeForDoubly *newNode = new NodeForDoubly(data);
        newNode->next = this->head;
        newNode->prev = this->tail;

        if(this->head != nullptr) {
            this->head->prev = newNode;
        } else {
            this->tail = newNode;
        }
        this->head = newNode;
    }

    void insertAtTail(int data) {
        NodeForDoubly *newNode = new NodeForDoubly(data);
        newNode->next = this->head;
        newNode->prev = this->tail;

        if(this->head != nullptr) {
            this->tail->next = newNode;
            this->head->prev = newNode;
        } else {
            this->head = newNode;
            newNode->next = newNode;
        }
        this->tail = newNode;
    }

    void insertAfterNode(NodeForDoubly *node, int data) {
        if(node == nullptr) {
            cout << "Error: Node after which to insert is not found" << endl;
            return;
        } else {
            NodeForDoubly *newNode = new NodeForDoubly(data);
            newNode->next = node->next;
            node->next = newNode;
            newNode->prev = node;
            newNode->next->prev = newNode;
        }
    }

    void updateNode(int old_data, int new_data) {
        NodeForDoubly *temp = head;

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
        NodeForDoubly *temp = head;

        // deletion of node in the middle
        do {
            if(temp != nullptr && temp->data == data) {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;

        } while(temp != head);
        
        if(temp == nullptr && temp->data != data) {
            cout << "Error: Node to be deleted is not found" << endl;
            return;
        }

        // deletion of node at head
        if(temp == this->head) {
            this->head = temp->next;
            delete temp;
            return;
        }

        // deletion of node at tail
        if(temp == this->tail) {
            this->tail = temp->prev;
            delete temp;
            return;
        }
    }

    void printList() {
        NodeForDoubly *temp = this->head;
        
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
    }

    ~DoublyLinkedList() {
        NodeForDoubly *temp = head->next;
        
        do {
            delete temp;
            temp = temp->next;
        } while(temp != head);
    }
};

int main() {
    DoublyLinkedList list;
    
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

    SinglyLinkedList list2;
    list2 = list;

    list2.printList();
    
    return 0;
}