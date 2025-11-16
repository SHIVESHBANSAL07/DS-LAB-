#include<iostream>
#include<queue>
using namespace std;
class Stack{
public:
    int size;
    queue<int>q;
    

    Stack(){
        size=0;
    }
    void push(int val){
        q.push(val);
        size++;
    }
    void pop(){
        int n=size;
        for(int i=1;i<n;i++){
            q.push(q.front());
            
            q.pop();
        }
        q.pop();
        
        
        
        size--;


    }
    void top(){
        for(int i=0;i<size-1;i++){
            
            q.push(q.front());
            q.pop();
        }
        int x=q.front();
        q.pop();
        cout<<x;
        q.push(x);

        

    }
     

};
int main(){
    Stack a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.top();
    a.pop();
    a.top();
    return 0;


}