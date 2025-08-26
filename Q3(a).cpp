/*
Q3(a): Given an array of n-1 distinct integers in the range of 1 to n,
find the missing number in it in a sorted array using Linear time.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n-1 << " sorted elements:\n";
    for (int i = 0; i < n-1; i++)
        cin >> arr[i];

    int totalSum = n * (n + 1) / 2; // Sum of numbers from 1 to n
    int arrSum = 0; // Store sum of given elements

    for (int i = 0; i < n-1; i++)
        arrSum += arr[i]; // Add each element to sum

    cout << "Missing number: " << totalSum - arrSum << endl; // Difference is missing number
    return 0;
}
