#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    // destructor
    ~Node() {
        int value = this -> data;

        // free the memory
        if (this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }

        cout << "Deleted the node of value " << value << endl;
    }
};

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

        // point it to the head
        temp -> next = head;

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


    // create a new node
    Node* temp = new Node(data);

    // point the tail to the new node
    tail -> next = temp;

    // update the tail
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
    // insert at the start
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    // create a temp node and asign it to the head
    Node* temp = head;

    // traverse the linked list to the index of position-1
    int cnt = 1;
    while (cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // insert at the end
    if (temp -> next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    // create a new node
    Node* nodeToInsert = new Node(data);

    // point the new node to the node at index of position
    nodeToInsert -> next = temp -> next;

    // point the node at the index of position-1 to the new node
    temp -> next = nodeToInsert;
}

void deleteAtPosition(int position, Node* &head, Node* &tail) {
    // delete the first node
    if (position == 1) {
        Node* temp = head;

        // update the head
        head = head -> next;

        // delete the head;
        temp -> next = NULL;
        delete temp;
    }
    else {
        // delete the node other than the first node
        Node* current = head;
        Node* previous = NULL;

        // traverse the linked list
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

        // delete the node
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

void deleteByValue(int value, Node* &head, Node* &tail) {
    // delete the first node
    if (value == head -> data) {
        Node* temp = head;

        // update the head
        head = head -> next;

        // delete the node
        temp -> next = NULL;
        delete temp;
    }
    else {
        // delete the node other than the first node
        Node* current = head;
        Node* previous = NULL;

        // traverse the linked list
        while (value != current -> data) {
            previous = current;
            current = current -> next;
        }

        // update the tail
        if (current -> next == NULL) {
            tail = previous;
        }

        // delete the node
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
    }
}

void print(Node* &head) {
    // create a temp node and asign it to the head
    Node* temp = head;

    // traverse the whole linked list
    while (temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 5);
    insertAtPosition(head, tail, 1, 45);
    insertAtPosition(head, tail, 5, 15);

    print(head);

    deleteAtPosition(5, head, tail);
    print(head);

    deleteByValue(5, head, tail);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    return 0;
}