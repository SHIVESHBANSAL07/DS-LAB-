/*
Q8: Write a program to count the total number of distinct elements in an array of length n.
*/

#include <iostream>
using namespace std;

// Bubble sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // swap if out of order
            }
        }
    }
}

// Count distinct elements
int countDistinct(int arr[], int n) {
    int count = 1; // first element is distinct
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);
    cout << "Total distinct elements = " << countDistinct(arr, n) << endl;

    return 0;
}
