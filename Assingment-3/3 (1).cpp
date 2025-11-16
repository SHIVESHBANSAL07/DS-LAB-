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
    bool isEmpty(){
        return top==-1;
    }
    char peek(){
        return arr[top];
    }
};

int main(){
    string exp;
    cout<<"Enter expression: ";
    cin>>exp;
    Stack st(exp.length());
    bool balanced = true;
    for(int i=0;i<exp.length();i++){
        char c = exp[i];
        if(c=='(' || c=='{' || c=='['){
            st.push(c);
        }
        else if(c==')' || c=='}' || c==']'){
            if(st.isEmpty()){
                balanced=false;
                break;
            }
            char t = st.pop();
            if((c==')' && t!='(') || (c=='}' && t!='{') || (c==']' && t!='[')){
                balanced=false;
                break;
            }
        }
    }
    if(!st.isEmpty()) balanced=false;
    cout<<(balanced?"Balanced":"Not Balanced");
    return 0;
}
