#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;

    cout<<"Enter the string: ";
    cin>>input;

    int len = input.length();

    for(int i = 0; i < len - 1; i++){
        bool flag = true;
        for(int j = 0; j < len - i - 1; j++){
            if (input[j] > input[j + 1]){
                flag = false;
                char temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
        if (flag) break;
    }
    cout<<"Sorted String: ";
    cout<<input;

    return 0;
}