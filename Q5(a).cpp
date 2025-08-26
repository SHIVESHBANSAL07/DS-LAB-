/*
Q5: Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int diag[n]; // store diagonal elements only

    cout << "Enter elements (row major):\n"; // input in row-major form
    for (int i = 0; i < n; i++) {
        cin >> diag[i]; // input only diagonal
    }

    cout << "\nThe matrix is:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " "; // diagonal
            else cout << "0 ";                  // non-diagonal
        }
        cout << endl;
    }

    return 0;
}
