/*
Q5: Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(c) Lower Triangular Matrix.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int lower[n*(n+1)/2]; // store only lower part
    int k = 0;            // index for storage

    cout << "Enter elements (row major):\n"; // input in row-major form
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i >= j) lower[k++] = val; // keep only lower triangle
        }
    }

    cout << "\nThe matrix is:\n";
    k = 0; // reset index
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << lower[k++] << " "; // print stored element
            else
                cout << "0 ";              // upper part is zero
        }
        cout << endl;
    }

    return 0;
}
