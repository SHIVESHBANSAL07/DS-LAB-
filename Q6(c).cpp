/*
Q6: Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(c) Multiplication of two matrices.
*/

#include <iostream>
using namespace std;

// function to multiply two sparse matrices in triplet form
void multiplySparse(int A[][3], int nzA, int B[][3], int nzB, int result[][3], int m1, int n2) {
    int k = 1; // index for result

    // multiply elements
    for (int i = 1; i <= nzA; i++) {
        for (int j = 1; j <= nzB; j++) {
            if (A[i][1] == B[j][0]) {  // matching col-row
                int r = A[i][0];        // row in result
                int c = B[j][1];        // col in result
                int val = A[i][2] * B[j][2];

                // add if already exists
                bool found = false;
                for (int p = 1; p < k; p++) {
                    if (result[p][0] == r && result[p][1] == c) {
                        result[p][2] += val;
                        found = true;
                        break;
                    }
                }

                if (!found) { // new entry
                    result[k][0] = r;
                    result[k][1] = c;
                    result[k][2] = val;
                    k++;
                }
            }
        }
    }

    result[0][0] = m1;    // rows
    result[0][1] = n2;    // cols
    result[0][2] = k - 1; // non-zeros
}

int main() {
    int m1, n1, nz1;
    cout << "Enter rows, cols and non-zero count for A: ";
    cin >> m1 >> n1 >> nz1;

    int A[nz1 + 1][3];  // matrix A
    A[0][0] = m1; A[0][1] = n1; A[0][2] = nz1;
    cout << "Enter triplet form for A (row col value):\n";
    for (int i = 1; i <= nz1; i++)
        cin >> A[i][0] >> A[i][1] >> A[i][2];

    int m2, n2, nz2;
    cout << "Enter rows, cols and non-zero count for B: ";
    cin >> m2 >> n2 >> nz2;

    if (n1 != m2) {
        cout << "Multiplication not possible.\n";
        return 0;
    }

    int B[nz2 + 1][3];  // matrix B
    B[0][0] = m2; B[0][1] = n2; B[0][2] = nz2;
    cout << "Enter triplet form for B (row col value):\n";
    for (int i = 1; i <= nz2; i++)
        cin >> B[i][0] >> B[i][1] >> B[i][2];

    int result[nz1 * nz2 + 1][3]; // max size
    multiplySparse(A, nz1, B, nz2, result, m1, n2); // call function

    cout << "\nResult in triplet form:\n";
    for (int i = 0; i <= result[0][2]; i++)
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;

    return 0;
}
