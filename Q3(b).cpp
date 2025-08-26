/*
Q3(b): Given an array of n-1 distinct integers in the range of 1 to n,
find the missing number in it in a sorted array using Binary Search.
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

    int low = 0, high = n - 2; // Last index in given array
    int missing = n; // Default if last number is missing

    while (low <= high) {
        int mid = (low + high) / 2; // Middle index

        if (arr[mid] == mid + 1) // Position matches value, search right half
            low = mid + 1;
        else { // Position mismatch, search left half
            missing = mid + 1;
            high = mid - 1;
        }
    }

    cout << "Missing number: " << missing << endl; // Print the missing number
    return 0;
}
