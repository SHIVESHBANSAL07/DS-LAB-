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

class Circular {
    public:
    Node *head;
    Circular(){
        head = nullptr;
    }
};

class Doubly {
    public:
    Node *head;
    Doubly(){
        head = nullptr;
    }
};

void insertCircular(Circular &list, int num, int pos){
    Node *t = new Node(num);
    if(list.head == nullptr){
        list.head = t;
        t->next = t;
        return;
    }
    if(pos == 1){
        Node *temp = list.head;
        while(temp->next != list.head) temp = temp->next;
        temp->next = t;
        t->next = list.head;
        list.head = t;
        return;
    }
    Node *temp = list.head;
    int c = 1;
    while(c < pos - 1 && temp->next != list.head){
        temp = temp->next;
        c++;
    }
    t->next = temp->next;
    temp->next = t;
}

void deleteCircular(Circular &list, int num){
    if(list.head == nullptr) return;
    Node *temp = list.head;
    Node *prev = nullptr;
    do{
        if(temp->data == num){
            if(temp == list.head){
                Node *last = list.head;
                while(last->next != list.head) last = last->next;
                if(last == list.head){
                    delete list.head;
                    list.head = nullptr;
                    return;
                }
                last->next = list.head->next;
                list.head = list.head->next;
                delete temp;
                return;
            } else {
                prev->next = temp->next;
                delete temp;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    }while(temp != list.head);
}

void searchCircular(Circular &list, int num){
    if(list.head == nullptr) return;
    Node *temp = list.head;
    int pos = 1;
    do{
        if(temp->data == num){
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }while(temp != list.head);
    cout << "Not found" << endl;
}

void displayCircular(Circular &list){
    if(list.head == nullptr) return;
    Node *temp = list.head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != list.head);
    cout << list.head->data << endl;
}

void insertDoubly(Doubly &list, int num, int pos){
    Node *t = new Node(num);
    if(list.head == nullptr){
        list.head = t;
        return;
    }
    if(pos == 1){
        t->next = list.head;
        list.head->prev = t;
        list.head = t;
        return;
    }
    Node *temp = list.head;
    int c = 1;
    while(c < pos - 1 && temp->next != nullptr){
        temp = temp->next;
        c++;
    }
    t->next = temp->next;
    if(temp->next != nullptr) temp->next->prev = t;
    temp->next = t;
    t->prev = temp;
}

void deleteDoubly(Doubly &list, int num){
    if(list.head == nullptr) return;
    Node *temp = list.head;
    while(temp != nullptr && temp->data != num) temp = temp->next;
    if(temp == nullptr) return;
    if(temp->prev == nullptr) list.head = temp->next;
    else temp->prev->next = temp->next;
    if(temp->next != nullptr) temp->next->prev = temp->prev;
    delete temp;
}

void searchDoubly(Doubly &list, int num){
    Node *temp = list.head;
    int pos = 1;
    while(temp != nullptr){
        if(temp->data == num){
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
}

void displayDoubly(Doubly &list){
    Node *temp = list.head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Circular c;
    Doubly d;
    int ch, type, num, pos;
    while(true){
        cout << "1.Insert 2.Delete 3.Search 4.Display 5.Exit" << endl;
        cin >> ch;
        if(ch == 5) break;
        cout << "1.Circular 2.Doubly" << endl;
        cin >> type;
        switch(ch){
            case 1:
                cin >> num >> pos;
                if(type == 1) insertCircular(c,num,pos);
                else insertDoubly(d,num,pos);
                break;
            case 2:
                cin >> num;
                if(type == 1) deleteCircular(c,num);
                else deleteDoubly(d,num);
                break;
            case 3:
                cin >> num;
                if(type == 1) searchCircular(c,num);
                else searchDoubly(d,num);
                break;
            case 4:
                if(type == 1) displayCircular(c);
                else displayDoubly(d);
                break;
        }
    }
    return 0;
}
