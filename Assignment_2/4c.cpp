#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string removeVowel(string input, int index){
    for(int i = index; i < input.length(); i++){
        input[i] = input[i + 1];
    }
    input.resize(input.length() - 1);
    return input;
}

int main(){
    
    string input;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    cout<<"Enter a string: ";
    cin>>input;

    for (int i = 0; i < input.length(); i++){
        input[i] = tolower(input[i]);
    }

    for (int i = 0; i < input.length(); i++){
        for (int j = 0; j < 5; j++){
            if (input[i] == vowels[j]) {
                // cout<<"Inner loop";
                input = removeVowel(input, i);
                i--;
                break;
            }
            // cout<<"Outer loop";
        }
    }
    cout<<"Input w/o vowels: ";
    cout<<input;

    return 0;
}

// H E L L O
// 0 1 2 3 4
// i = 1
// H L L O
// 0 1 2 3
// i = 3
// H L L
// 0 1 2