/*
Q6: Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(a) Transpose of a matrix.
*/

#include <iostream>
using namespace std;

int main() {
    int m, n, nz;
    cout << "Enter rows, cols and non-zero count: ";
    cin >> m >> n >> nz;

    int mat[nz + 1][3];   // input matrix in triplet form
    mat[0][0] = m;        // rows
    mat[0][1] = n;        // cols
    mat[0][2] = nz;       // non-zeros

    cout << "Enter triplet form (row col value):\n";
    for (int i = 1; i <= nz; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }

    int trans[nz + 1][3]; // transpose matrix
    trans[0][0] = n;      // swapped rows
    trans[0][1] = m;      // swapped cols
    trans[0][2] = nz;     // non-zeros same

    int k = 1;
    for (int col = 0; col < n; col++) {   // scan column-wise
        for (int i = 1; i <= nz; i++) {
            if (mat[i][1] == col) {
                trans[k][0] = mat[i][1]; // new row
                trans[k][1] = mat[i][0]; // new col
                trans[k][2] = mat[i][2]; // same value
                k++;
            }
        }
    }

    cout << "\nTranspose in triplet form:\n";
    for (int i = 0; i <= nz; i++) {
        cout << trans[i][0] << " "
             << trans[i][1] << " "
             << trans[i][2] << endl;
    }

    return 0;
}
