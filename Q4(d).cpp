/*
Q4(d): Write a program to sort the strings in alphabetical order.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore(); // Clear newline from input buffer

    char str[50][100]; // Array to store strings

    // Input strings
    for (int i = 0; i < n; i++) {
        cout << "Enter string " << i + 1 << ": ";
        cin.getline(str[i], 100);
    }

    // Sort using simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int k = 0;
            // Compare character by character
            while (str[j][k] != '\0' && str[j + 1][k] != '\0' && str[j][k] == str[j + 1][k])
                k++;
            // If str[j] > str[j+1], swap them
            if (str[j][k] > str[j + 1][k]) {
                char temp[100];
                int t = 0;
                while (str[j][t] != '\0') { temp[t] = str[j][t]; t++; }
                temp[t] = '\0';

                t = 0;
                while (str[j + 1][t] != '\0') { str[j][t] = str[j + 1][t]; t++; }
                str[j][t] = '\0';

                t = 0;
                while (temp[t] != '\0') { str[j + 1][t] = temp[t]; t++; }
                str[j + 1][t] = '\0';
            }
        }
    }

    // Output sorted strings
    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++)
        cout << str[i] << endl;

    return 0;
}
