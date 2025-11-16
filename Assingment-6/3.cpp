#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int num){
        data = num;
        next = nullptr;
        prev = nullptr;
    }
};

int circularSize(Node *head){
    if(head == nullptr) return 0;
    Node *temp = head;
    int count = 0;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);
    return count;
}

int doublySize(Node *head){
    int count = 0;
    while(head != nullptr){
        count++;
        head = head->next;
    }
    return count;
}

int main(){
    Node *c1 = new Node(1);
    Node *c2 = new Node(2);
    Node *c3 = new Node(3);
    c1->next = c2;
    c2->next = c3;
    c3->next = c1;
    cout << "Circular size: " << circularSize(c1) << endl;

    Node *d1 = new Node(4);
    Node *d2 = new Node(5);
    Node *d3 = new Node(6);
    d1->next = d2;
    d2->prev = d1;
    d2->next = d3;
    d3->prev = d2;
    cout << "Doubly size: " << doublySize(d1) << endl;
    return 0;
}
