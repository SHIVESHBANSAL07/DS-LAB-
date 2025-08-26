/*
Q4(a): Write a program to concatenate one string to another string.
*/

#include <iostream>
using namespace std;

int main() {
    char str1[100], str2[100];
    int i = 0, j = 0;

    cout << "Enter first string: ";
    cin.getline(str1, 100); // Input first string

    cout << "Enter second string: ";
    cin.getline(str2, 100); // Input second string

    // Move i to the end of first string
    while (str1[i] != '\0')
        i++;

    // Copy characters of second string to first
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }

    str1[i] = '\0'; // Add null character at the end

    cout << "Concatenated string: " << str1 << endl; // Output final string
    return 0;
}
