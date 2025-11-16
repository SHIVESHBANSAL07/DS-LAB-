#include <iostream>
#include <string>
using namespace std;

class Stack {
    int top;
    int capacity;
    char *arr;
    public:
    Stack(int size){
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }
    void push(char c){
        arr[++top] = c;
    }
    char pop(){
        return arr[top--];
    }
    char peek(){
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
};

int precedence(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    if(c=='^') return 3;
    return -1;
}

int main(){
    string infix;
    cout<<"Enter infix: ";
    cin>>infix;
    Stack st(infix.length());
    string postfix="";
    for(int i=0;i<infix.length();i++){
        char c = infix[i];
        if(isalnum(c)){
            postfix+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.isEmpty() && st.peek()!='('){
                postfix+=st.pop();
            }
            st.pop();
        }
        else{
            while(!st.isEmpty() && precedence(c)<=precedence(st.peek())){
                postfix+=st.pop();
            }
            st.push(c);
        }
    }
    while(!st.isEmpty()){
        postfix+=st.pop();
    }
    cout<<"Postfix: "<<postfix;
    return 0;
}
