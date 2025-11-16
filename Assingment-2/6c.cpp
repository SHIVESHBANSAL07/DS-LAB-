#include <iostream>
using namespace std;

int main() {
    int sampleSparseMatrix1[3][3] = {
        {1, 2, 0},
        {7, 4, 0},
        {0, 0, 7}
    };

    int sampleSparseMatrix2[3][3] = {
        {0, 2, 3},
        {0, 0, 0},
        {1, 6, 7}
    };

    int zeroes1 = 0, non_zeroes1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sampleSparseMatrix1[i][j] == 0) zeroes1++;
        }
    }
    non_zeroes1 = 9 - zeroes1;

    int compactMatrix1[non_zeroes1 + 1][3];
    compactMatrix1[0][0] = 3;
    compactMatrix1[0][1] = 3;
    compactMatrix1[0][2] = non_zeroes1;

    int k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sampleSparseMatrix1[i][j] != 0) {
                compactMatrix1[k][0] = i;
                compactMatrix1[k][1] = j;
                compactMatrix1[k][2] = sampleSparseMatrix1[i][j];
                k++;
            }
        }
    }

    cout << "-----MATRIX 1-----\nR C V\n";
    for (int i = 0; i <= non_zeroes1; i++) {
        cout << compactMatrix1[i][0] << " "
             << compactMatrix1[i][1] << " "
             << compactMatrix1[i][2] << "\n";
    }

    int zeroes2 = 0, non_zeroes2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sampleSparseMatrix2[i][j] == 0) zeroes2++;
        }
    }
    non_zeroes2 = 9 - zeroes2;

    int compactMatrix2[non_zeroes2 + 1][3];
    compactMatrix2[0][0] = 3;
    compactMatrix2[0][1] = 3;
    compactMatrix2[0][2] = non_zeroes2;

    k = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sampleSparseMatrix2[i][j] != 0) {
                compactMatrix2[k][0] = i;
                compactMatrix2[k][1] = j;
                compactMatrix2[k][2] = sampleSparseMatrix2[i][j];
                k++;
            }
        }
    }

    cout << "\n-----MATRIX 2-----\nR C V\n";
    for (int i = 0; i <= non_zeroes2; i++) {
        cout << compactMatrix2[i][0] << " "
             << compactMatrix2[i][1] << " "
             << compactMatrix2[i][2] << "\n";
    }

    for (int i = 1; i <= non_zeroes2; i++) {
        int temp = compactMatrix2[i][0];
        compactMatrix2[i][0] = compactMatrix2[i][1];
        compactMatrix2[i][1] = temp;
    }

    cout << "\n---Transposed MATRIX 2---\nR C V\n";
    for (int i = 0; i <= non_zeroes2; i++) {
        cout << compactMatrix2[i][0] << " "
             << compactMatrix2[i][1] << " "
             << compactMatrix2[i][2] << "\n";
    }

    int product[25][3];
    int pIndex = 1;
    product[0][0] = compactMatrix1[0][0];
    product[0][1] = compactMatrix2[0][0];
    product[0][2] = 0;

    for (int i = 1; i <= non_zeroes1; i++) {
        for (int j = 1; j <= non_zeroes2; j++) {
            if (compactMatrix1[i][1] == compactMatrix2[j][1]) {
                product[pIndex][0] = compactMatrix1[i][0];
                product[pIndex][1] = compactMatrix2[j][0];
                product[pIndex][2] = compactMatrix1[i][2] * compactMatrix2[j][2];
                pIndex++;
            }
        }
    }

    product[0][2] = pIndex - 1;

    cout << "\n---Product---\nR C V\n";
    for (int i = 0; i < pIndex; i++) {
        cout << product[i][0] << " "
             << product[i][1] << " "
             << product[i][2] << "\n";
    }

    return 0;
}