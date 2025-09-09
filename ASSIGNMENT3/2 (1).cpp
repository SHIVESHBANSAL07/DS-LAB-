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
};

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    Stack st(s.length());
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    cout<<"Reversed: ";
    for(int i=0;i<s.length();i++){
        cout<<st.pop();
    }
    return 0;
}
