/*
Q7: Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an
inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to
count the number of inversions in an array.
*/

#include <iostream>
using namespace std;

// Count inversions
int countInversions(int arr[], int n) {
    int count = 0;  // inversion counter

    // Check pairs
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])  // out of order
                count++;
        }
    }
    return count;  // total inversions
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;  // input size

    int arr[n];  // declare array
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];  // input elements

    cout << "Number of inversions = " << countInversions(arr, n) << endl;
    return 0;
}
