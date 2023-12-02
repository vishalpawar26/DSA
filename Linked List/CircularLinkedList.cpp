#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // destructor
    ~Node () {
        int value = this -> data;

        // free memory
        if (this -> next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Deleted the node of value: " << value << endl;
    }
};

void insertNode (Node* &tail, int element, int data) {
    // empty linked list
    if (tail == NULL) {
        // create a new node
        Node* temp = new Node(data);
        tail = temp;
        temp -> next = temp;
    }
    else {
        // non-empty linked list
        Node* temp = tail;

        // traverse the linked list
        while (temp -> data != element) {
            temp = temp -> next;
        }

        // create a new node
        Node* node = new Node(data);
        node -> next = temp -> next;
        temp -> next = node;
    }
}

void deleteNode(Node* &tail, int element) {
    // empty list
    if (tail == NULL) {
        cout << "The list is empty!" << endl;
    }
    else {
        Node* prev = tail;
        Node* curr = prev -> next;

        // traverse the linked list
        while (curr -> data != element) {
            prev = curr;
            curr = curr -> next;
        }

        // delete the node
        prev -> next = curr -> next;

        // single node linked list
        if (curr == prev) {
            tail = NULL;
        }

        // >=2 linked list
        else if (tail == curr) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

void print(Node* &tail) {
    Node* temp = tail;

    if (tail == NULL) {
        cout << "Linked list is empty!" << endl;
        return;
    }

    // traverse the linked list
    do {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    while (temp != tail);

    cout << endl;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 1, 10);
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    print(tail);

    deleteNode(tail, 20);
    print(tail);

    return 0;
}