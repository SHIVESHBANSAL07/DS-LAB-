#include <iostream>
using namespace std;

int index(int i, int j) {
    return (i * (i + 1)) / 2 + j;
};

int main() {
    char ch;
    int rows, columns;
    while (true) {
        cout << "Enter the size of the matrix (m x n): ";
        cin >> rows >> ch >> columns;

        if (rows != columns) {
            cout << "The matrix must be a square matrix!" << endl;
            continue;
        }

        int size = (rows * (rows + 1)) / 2;
        int symmetric[size];

        cout << "Enter " << size << " elements (lower triangular, row-wise): ";
        for (int i = 0; i < size; i++) {
            cin >> symmetric[i];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (i >= j) {
                    cout << symmetric[index(i, j)] << " ";
                } else {
                    cout << symmetric[index(j, i)] << " ";
                }
            }
            cout << endl;
        }
        break;
    }

    return 0;
}