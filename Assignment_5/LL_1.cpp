#include<iostream>
using namespace std;
class Node{
public:
int val;
Node* next;
Node(int val){
    this->val=val;
    this->next=NULL;

}
};
class LinkedList{
public:
Node* head;
Node* tail;
int size;
LinkedList(){
    head=tail=NULL;
    size=0;

    
}
void insertAtHead(int val){
    Node* b=new Node(val);
    if(size==0){
        head=tail=b;
        size++;
    }
    else{
        b->next=head;
        head=b;
        size++;
    }
}
void insertAtTail(int a){
    if(size==0){
        Node* temp=new Node(a);
        head=tail=temp;
    }
    else{
        Node* temp=new Node(a);
        tail->next=temp;
        tail=temp;
        
    }
    size++;
}
void insertAtIdx(int idx,int val){
    if(idx>size || idx<0){
        cout<<"Invalid";
        return;
    }
    else if(idx==0){
        insertAtHead(val);
    }
    else if(idx==size){
        insertAtTail(val);

    }
    else{

        Node* temp=new Node(val);
        Node* t=head;
        for(int i=1;i<=idx-1;i++){
            t=t->next;

            
        }
        temp->next=t->next;
        t->next=temp;
        size++;

        
    }
}
int get_ele(int idx){
    if(idx>size || idx<0){
        cout<<"Invalid";
        return -1;
    }
    else if(idx==0){
        return head->val;
    }
    else if(idx==size){
        return tail->val;

    }
    else{
    Node* t=head;
    for(int i=1;i<=idx-1;i++){
        t=t->next;
    }
    return t->next->val;
}

}
void deleteAtHead(){
    if(size==0){
        cout<<"size is zero";
    }
    else{
        head=head->next;
        size--;
        cout<<&tail;
    }
}
void deleteAtTail(){
    Node* a=head;
    while(a->next!=tail){
        a=a->next;
    }
    a->next=NULL;
    tail=a;
    size--;
}
void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<endl;;
        temp=temp->next;
    }
    return;
    

}
};
void insert_end(Node* head,int v){
    Node* t=new Node(v);
    while(head->next){
        head=head->next;
    }
    head->next=t;
    return;


}
int main(){
    LinkedList ll;
    
    ll.insertAtTail(40);
    
    ll.insertAtTail(20);
    ll.insertAtHead(30);
    
    ll.insertAtIdx(1,50);
    ll.display();
    cout<<ll.size;
    cout<<endl;
    int a=ll.get_ele(2);
    cout<<a;
    ll.deleteAtHead();
    ll.display();
    cout<<endl;
    ll.deleteAtTail();
    ll.display();
    
    return 0;  
}