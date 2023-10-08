// Author: Huzefa Saifuddin (Huzbi) - 22K-5125
// Title: DSA Lab03 - Question 8

#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

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
    Node *head;

    LinkedList() {
        head = NULL;
    }

    LinkedList( Node *n ) {
        head = n;
    }

    void prependNode( int node_data ) {
        Node *newNode = new Node(node_data);

        newNode->next = head;

        head->next = newNode;
    }

    void appendNode( int node_data ) {
        Node *newNode = new Node(node_data);

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

    void insertAfterNode( int node_data, int newData ) {
        Node *newNode = new Node(newData);

        Node *temp = head;

        while ( temp != NULL && temp->data != node_data) {
            temp = temp->next;
        }

        if ( temp == NULL ) {
            cout << "Error: Node not found to insert after.\n";
        }
        else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Success: Node inserted.\n";
        }
    }

    void updateNode ( int old_node_data, int new_node_data ) {
        Node *temp = head;

        while ( temp != NULL && temp->data != old_node_data ) {
            temp = temp->next;
        }

        if ( temp != NULL ) {
            temp->data = new_node_data;
        }
        else {
            cout << "Error: No node found for the this data: " << old_node_data << endl;
        }
        
    }

    void deleteNode( int node_data ) {
        Node *temp = head;
        Node *prevNode = NULL;

        if ( temp != NULL & temp->data != node_data ) {
            head = temp->next;
            delete temp;
            return;
        }
        else {
            while( temp != NULL & temp->data != node_data ) {
                prevNode = temp;
                temp = temp->next;
            }
                if ( temp == NULL ) {
                    cout << "Error: data not found for the node.\n";
                    return;
                }
                delete temp;
            }
        }

    void oddEvenSeparator( Node **head_ptr ) {
        Node *lastNode = *head_ptr;
        Node *prevNode = NULL;
        Node *currentNode = *head_ptr;

        while ( lastNode->next != NULL ) {
            lastNode = lastNode->next;
        }

        Node *tempLastNode = lastNode;

        while ( ( currentNode->data % 2 != 0 ) && ( currentNode != lastNode ) ) {
            // move all odd nodes for the current even node
            tempLastNode->next = currentNode;
            currentNode = currentNode->next;
            tempLastNode->next->next = NULL;
            tempLastNode = tempLastNode->next;
        }

        if ( ( currentNode->data % 2 ) == 0 ) {
            *head_ptr = currentNode;

            while ( currentNode != lastNode ) {
                if ( ( currentNode->data % 2) == 0 ) {
                    prevNode = currentNode;
                    currentNode = currentNode->next;
                }
                else {
                    prevNode->next = currentNode->next;
                    currentNode->next = NULL;
                    tempLastNode->next = currentNode;
                    tempLastNode = currentNode;
                    currentNode = prevNode->next;
                }
            } 
        }

        else {
            prevNode = currentNode;
        }

        if ( tempLastNode != lastNode && ( lastNode->data % 2) != 0 ) {
            prevNode->next = lastNode->next;
            lastNode->next = NULL;
            tempLastNode->next = lastNode;
        }
        return;
    }

    void reverseList( Node **head_ptr ) {
        Node *prevNode = NULL;
        Node *currentNode = *head_ptr;
        Node *next;

        while ( currentNode != NULL ) {
            next = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = next;
        }

        *head_ptr = prevNode;
    }

    bool compareList( Node *half_head, Node *secondHalf_head ) {
        Node *temp1 = half_head;
        Node *temp2 = secondHalf_head;

        while( temp1 && temp2 ) {
            if ( temp1->data == temp2->data ) {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else {
                return false;
            }
        }

        if ( temp1 == NULL && temp2 == NULL ) {
            return true;
        }

        return false;
    }

    bool isPalindrome() {
        Node *slow = head;
        Node *fast = head;
        Node *prevSlow = head;
        Node *midNode = NULL;
        Node *secondHalf;
        bool result;

        if ( head != NULL && head->next != NULL ) {
            while ( fast != NULL && fast->next != NULL ) {
                fast = fast->next->next;
                prevSlow = slow;
                slow = slow->next;
            }

            if ( fast != NULL ) {
                midNode = slow;
                slow = slow->next;
            }

            secondHalf = slow;
            prevSlow->next = NULL;
            
            reverseList( &secondHalf );
            result = compareList( head, secondHalf );

            reverseList( &secondHalf );

            if ( midNode != NULL ) {
                prevSlow->next = midNode;
                midNode->next = secondHalf;
            }
            else {
                prevSlow->next = secondHalf;
            }
        }
        return result;
    }

    void printList() {
        Node *temp = head;

        while ( temp != NULL ) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    LinkedList list;

    list.appendNode(2);
    list.appendNode(4);
    list.appendNode(5);
    list.appendNode(6);

    list.prependNode(10);

    list.insertAfterNode(4, 15);

    list.updateNode(2, 8);

    list.deleteNode(8);

    list.oddEvenSeparator(&list.head);

    list.printList();

    list.isPalindrome();
    
    return 0;
}