/*
Q5: Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(d) Upper Triangular Matrix.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int upper[n*(n+1)/2]; // store only upper part
    int k = 0;            // index for storage

    cout << "Enter elements (row major):\n"; // input in row-major form
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i <= j) upper[k++] = val; // keep only upper triangle
        }
    }

    cout << "\nThe matrix is:\n";
    k = 0; // reset index
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << upper[k++] << " "; // print stored element
            else
                cout << "0 ";              // lower part is zero
        }
        cout << endl;
    }

    return 0;
}
