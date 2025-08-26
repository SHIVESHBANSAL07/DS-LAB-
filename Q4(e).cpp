/*
Q4(e): Write a program to convert a character from uppercase to lowercase.
*/

#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string in uppercase: ";
    cin.getline(str, 100); // Input string

    int i = 0;
    // Traverse each character
    while (str[i] != '\0') {
        // If character is uppercase letter
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32; // Convert to lowercase
        i++;
    }

    cout << "String in lowercase: " << str << endl; // Output result
    return 0;
}
