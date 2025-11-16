#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};


void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}



// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next; 
        curr->next = prev;   
        prev = curr;         
        curr = next;         
    }

    return prev;
}


int main() {
    Node* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Original Linked List: ";

    head = reverseList(head);

    cout << "Reversed Linked List: ";

    return 0;
}
