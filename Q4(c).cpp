/*
Q4(c): Write a program to delete all the vowels from the string.
*/

#include <iostream>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100); // Input string

    int i = 0, j = 0;

    // Check each character
    while (str[i] != '\0') {
        char ch = str[i];
        // If not a vowel, keep it
        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            str[j] = ch;
            j++;
        }
        i++;
    }
    str[j] = '\0'; // End new string

    cout << "String without vowels: " << str << endl; // Output result
    return 0;
}
