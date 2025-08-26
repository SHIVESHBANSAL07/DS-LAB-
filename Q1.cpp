/*
Q1: Implement the Binary search algorithm regarded as a fast search algorithm
with run-time complexity of O(log n) in comparison to the Linear Search.
*/

#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[50];
    cout << "Enter elements in sorted order:\n";
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1;
    bool found = false;

    // Binary Search Loop
    while(low <= high) {
        int mid = (low + high) / 2; // Find middle index

        if(arr[mid] == key) {       // If found
            cout << "Element found at position " << mid+1 << "\n";
            found = true;
            break;
        }
        else if(arr[mid] < key)     // Search right half
            low = mid + 1;
        else                        // Search left half
            high = mid - 1;
    }

    if(!found)
        cout << "Element not found\n";

    return 0;
}
