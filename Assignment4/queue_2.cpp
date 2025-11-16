#include<iostream>
using namespace std;
class Queue{
public:
    int arr[5];
    int front;
    int back; // rear
    int size;
    Queue(){
        front=0;
        back=0;
        size=0;
    }
    void push(int val){
        if(size==5){
            cout<<"Your Queue is full";
            return;
        }
        arr[back]=val;
        back++;
        size++;
    }

    void pop(){
        if(size==0){
            cout<<"Empty";
            return;
        }
        front++;
        size--;
    }
    int Front(){
        if(size==0){
            cout<<"Empty";
            return -1;
        }
        return arr[front];
    }

    int Back(){
        if(size==0){
            cout<<"Empty";
            return -1;
        }
        return arr[back-1];
    }
    bool empty(){
        if(size==0) return true;
        return false;
    }

    void display(){
        for(int i=front;i<back;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    Queue q; // in this way we are going to make our object
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    cout<<endl;
    cout<<q.Front();
    cout<<endl;
    cout<<q.Back();
    cout<<endl;
    q.pop();
    q.pop();
    cout<<q.empty(); // if 0 means false , 1 true
    
    return 0;


}