#include <iostream>
#include <string>
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
        arr[++top] = x;
    }
    int pop(){
        return arr[top--];
    }
};

int main(){
    string postfix;
    cout<<"Enter postfix: ";
    cin>>postfix;
    Stack st(postfix.length());
    for(int i=0;i<postfix.length();i++){
        char c = postfix[i];
        if(isdigit(c)){
            st.push(c-'0');
        }
        else{
            int b=st.pop();
            int a=st.pop();
            int res=0;
            if(c=='+') res=a+b;
            else if(c=='-') res=a-b;
            else if(c=='*') res=a*b;
            else if(c=='/') res=a/b;
            st.push(res);
        }
    }
    cout<<"Result: "<<st.pop();
    return 0;
}
