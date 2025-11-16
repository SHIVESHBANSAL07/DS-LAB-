#include <iostream>
using namespace std;

// Define node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert node at the end
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

// Function to count occurrences of a key
int countOccurrences(Node* head, int key) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    return count;
}


// Main function
int main() {
    Node* head = nullptr;

    // Create linked list: 1->2->1->2->1->3->1
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);
    insert(head, 3);
    insert(head, 1);

    cout << "Linked List: ";
    int key = 1;
    int count = countOccurrences(head, key);

    cout << "Key: " << key << endl;
    cout << "Occurrences: " << count << endl;

    return 0;
}
