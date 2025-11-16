#include <iostream>
using namespace std;

class Node {
    public:
    char data;
    Node *next;
    Node *prev;
    Node(char ch){
        data = ch;
        next = nullptr;
        prev = nullptr;
    }
};

bool isPalindrome(Node *head){
    if(head == nullptr) return true;
    Node *end = head;
    while(end->next != nullptr) end = end->next;
    while(head != end && end->next != head){
        if(head->data != end->data) return false;
        head = head->next;
        end = end->prev;
    }
    return true;
}

int main(){
    Node *a = new Node('r');
    Node *b = new Node('a');
    Node *c = new Node('d');
    Node *d = new Node('a');
    Node *e = new Node('r');
    a->next = b; b->prev = a;
    b->next = c; c->prev = b;
    c->next = d; d->prev = c;
    d->next = e; e->prev = d;
    if(isPalindrome(a)) cout << "Palindrome";
    else cout << "Not Palindrome";
    return 0;
}
