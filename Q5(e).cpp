/*
Q5: Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(e) Symmetric Matrix.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int sym[n*(n+1)/2]; // store one triangle (lower)
    int k = 0;          // index for storage

    cout << "Enter elements (row major):\n"; // input in row-major form
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i >= j) sym[k++] = val; // store only lower triangle
        }
    }

    cout << "\nThe matrix is:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << sym[k] << " ";       // print stored element
            } else {
                // fetch symmetric value from lower triangle
                int idx = (j*(j+1))/2 + i;   // formula to locate (j,i)
                cout << sym[idx] << " ";
            }
            if (i >= j) k++;
        }
        cout << endl;
    }

    return 0;
}
