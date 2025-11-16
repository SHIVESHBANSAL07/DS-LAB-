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

class Circular {
    public:
    Node *head;
    Circular(){
        head = nullptr;
    }
};

void insertEnd(Circular &list, int num){
    Node *t = new Node(num);
    if(list.head == nullptr){
        list.head = t;
        t->next = list.head;
        return;
    }
    Node *temp = list.head;
    while(temp->next != list.head) temp = temp->next;
    temp->next = t;
    t->next = list.head;
}

void display(Circular &list){
    Node *temp = list.head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != list.head);
    cout << list.head->data << endl;
}

int main(){
    Circular list;
    int arr[] = {20,100,40,80,60};
    for(int i=0;i<5;i++) insertEnd(list,arr[i]);
    display(list);
    return 0;
}
