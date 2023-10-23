#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }

    // destructor
    ~Node() {
        int value = this -> data;
        if (this -> next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Deleted the node of value: " << value << endl;
    }
};

void print(Node* &head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* &head) {
    Node* temp = head;

    int len = 0;
    while (temp != NULL) {
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    // if the linked list is empty
    if (head == NULL) {
        // create a new node
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        // create a new node
        Node* temp = new Node(data);

        // insert the new node at the start
        temp -> next = head;
        head -> prev = temp;

        // update the head
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    // if the linked list is empty
    if (tail == NULL) {
        // create a new node
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        // create a new node
        Node* temp = new Node(data);

        // insert the new node at the end
        tail -> next = temp;
        temp -> prev = tail;

        // update the tail
        tail = temp;
    }
}

void insertAtPosition(int position, Node* &head, Node* &tail, int data) {
    // insert at start
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    // create a temp node
    Node* temp = head;

    // traverse the linked list
    int cnt = 1;
    while(cnt < position-1) {
        temp = temp -> next;
        cnt++;
    }

    // insert at the end
    if (temp -> next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    // create a new node to insert
    Node* nodeToInsert = new Node(data);

    // insert the node
    nodeToInsert -> next = temp -> next;
    nodeToInsert -> prev = temp;
    temp -> next = nodeToInsert;
    temp -> next -> prev = nodeToInsert;
}

void deleteAtPosition(int position, Node* &head, Node* &tail) {
    // delete the first node
    if (position == 1) {
        // create a temp node
        Node* temp = head;

        // update the head and delete the node
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }
    else {
        // delete other than the first node
        Node* current = head;
        Node* previous = NULL;

        // teaverse the linked list
        int cnt = 1;
        while (cnt < position) {
            previous = current;
            current = current -> next;
            cnt++;
        }

        // update the tail
        if (current -> next == NULL) {
            tail = previous;
        }

        // delete the last node
        current -> prev = NULL;
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    print(head);

    insertAtHead(head, tail, 20);
    print(head);

    insertAtHead(head, tail, 30);
    print(head);

    insertAtTail(head, tail, 25);
    print(head);

    insertAtPosition(4, head, tail, 35);
    print(head);

    deleteAtPosition(4, head, tail);
    print(head);

    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;
    cout << "Length of the doubly linked list is: " << getLength(head) << endl;
    return 0;
}