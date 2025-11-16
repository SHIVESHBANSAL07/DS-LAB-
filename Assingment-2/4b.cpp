#include <iostream>
#include <string>
using namespace std;

int main(){
    string input, reversed;

    cout<<"Enter the string: ";
    cin>>input;

    reversed.resize(input.length());

    for(int i = 0; i < input.length(); i++){
        reversed[i] = input[input.length() - i - 1];
    }

    cout<<"Reversed string: ";
    cout<<reversed;

    return 0;
}