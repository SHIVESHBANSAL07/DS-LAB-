#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string input;

    cout<<"Enter the string: ";
    cin>>input;

    for (int i = 0; i < input.length(); i++){
        input[i] = tolower(input[i]);
    }

    cout<<"Input in lowercase: ";
    cout<<input;

    return 0;
}