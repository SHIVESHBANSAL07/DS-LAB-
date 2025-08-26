/*
Q5: Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(b) Tri-diagonal Matrix.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int tri[3*n - 2]; // store 3 diagonals only
    int k = 0;        // index for tri[]

    cout << "Enter elements (row major):\n"; // input in row-major form
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i == j || i == j+1 || i == j-1) {
                tri[k++] = val; // store only tri-diagonal elements
            }
        }
    }

    cout << "\nThe matrix is:\n";
    k = 0; // reset index
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i == j+1 || i == j-1)
                cout << tri[k++] << " "; // print stored value
            else
                cout << "0 ";            // rest are zero
        }
        cout << endl;
    }

    return 0;
}
