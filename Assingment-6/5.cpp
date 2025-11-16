#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int num){
        data = num;
        next = nullptr;
    }
};

bool isCircular(Node *head){
    if(head == nullptr) return false;
    Node *temp = head->next;
    while(temp != nullptr && temp != head){
        temp = temp->next;
    }
    return temp == head;
}

int main(){
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    a->next = b;
    b->next = c;
    c->next = a;
    if(isCircular(a)) cout << "Circular";
    else cout << "Not Circular";
    return 0;
}
