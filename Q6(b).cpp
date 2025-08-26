/*
Q6: Write a program to implement the following operations on a Sparse Matrix,
assuming the matrix is represented using a triplet.
(b) Addition of two matrices.
*/

#include <iostream>
using namespace std;

// function to add two sparse matrices in triplet form
void addSparse(int A[][3], int B[][3], int result[][3]) {
    int i = 1, j = 1, k = 1;
    result[0][0] = A[0][0]; // rows
    result[0][1] = A[0][1]; // cols

    // merge triplets
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
            result[k][0] = A[i][0], result[k][1] = A[i][1], result[k++][2] = A[i++][2];
        else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1]))
            result[k][0] = B[j][0], result[k][1] = B[j][1], result[k++][2] = B[j++][2];
        else { // same position -> add values
            int sum = A[i][2] + B[j][2];
            if (sum != 0)
                result[k][0] = A[i][0], result[k][1] = A[i][1], result[k++][2] = sum;
            i++; j++;
        }
    }

    // copy remaining elements
    while (i <= A[0][2]) result[k][0] = A[i][0], result[k][1] = A[i][1], result[k++][2] = A[i++][2];
    while (j <= B[0][2]) result[k][0] = B[j][0], result[k][1] = B[j][1], result[k++][2] = B[j++][2];

    result[0][2] = k - 1; // total non-zero elements
}

int main() {
    int m, n, nzA, nzB;
    cout << "Enter rows, cols and non-zero count for A: ";
    cin >> m >> n >> nzA;
    int A[nzA + 1][3]; 
    A[0][0] = m; A[0][1] = n; A[0][2] = nzA;
    cout << "Enter triplet form for A (row col value):\n";
    for (int i = 1; i <= nzA; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter non-zero count for B: ";
    cin >> nzB;
    int B[nzB + 1][3]; 
    B[0][0] = m; B[0][1] = n; B[0][2] = nzB;
    cout << "Enter triplet form for B (row col value):\n";
    for (int i = 1; i <= nzB; i++) cin >> B[i][0] >> B[i][1] >> B[i][2];

    int result[nzA + nzB + 1][3]; // max possible size
    addSparse(A, B, result);      // call addition function

    cout << "\nResult in triplet form:\n";
    for (int i = 0; i <= result[0][2]; i++)
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;

    return 0;
}
