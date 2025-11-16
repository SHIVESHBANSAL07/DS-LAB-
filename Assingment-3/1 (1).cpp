#include <iostream>
using namespace std;

class Stack {
    int top;
    int capacity;
    int *arr;
    public:
    Stack(int size){
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout<<"Element pushed successfully!\n";
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return;
        }
        cout<<"Popped: "<<arr[top--]<<"\n";
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == capacity - 1;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        for(int i = top; i >= 0; i--){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    void peek(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Top element: "<<arr[top]<<"\n";
    }
};

int main(){
    int size;
    cout<<"Enter stack size: ";
    cin>>size;
    Stack s(size);
    while(true){
        int choice;
        cout<<"1. PUSH\n2. POP\n3. isEmpty\n4. isFull\n5. DISPLAY\n6. PEEK\n7. EXIT\n> ";
        cin>>choice;
        if(choice==1){
            int val;
            cout<<"Enter element: ";
            cin>>val;
            s.push(val);
        }
        else if(choice==2){
            s.pop();
        }
        else if(choice==3){
            cout<<(s.isEmpty()?"True\n":"False\n");
        }
        else if(choice==4){
            cout<<(s.isFull()?"True\n":"False\n");
        }
        else if(choice==5){
            s.display();
        }
        else if(choice==6){
            s.peek();
        }
        else if(choice==7){
            break;
        }
        else{
            cout<<"Invalid input\n";
        }
    }
    return 0;
}
