#include <iostream>
using namespace std;

int main(){

    int SparseMatrix1[3][3] = {
        {0, 2, 3},
        {0, 0, 0},
        {1, 6, 7}
    };
    int SparseMatrix2[3][3] = {
        {1, 5, 3},
        {0, 8, 0},
        {14, 0, 0}
    };

    int zeroes1 = 0, non_zeroes1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(SparseMatrix1[i][j] == 0){
                zeroes1++;
            }
        }
    }
    non_zeroes1 = 9 - zeroes1;

    int compactMatrix1[non_zeroes1 + 1][3] = {
        {3, 3, zeroes1}
    };

    int k = 1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(SparseMatrix1[i][j] != 0){
                compactMatrix1[k][0] = i;
                compactMatrix1[k][1] = j;
                compactMatrix1[k][2] = SparseMatrix1[i][j];
                k++;
            }
        }
    }
    cout<<"Compact Matrix 1:\nR C V"<<endl;
    for(int i = 0; i < non_zeroes1 + 1; i++){
        for(int j = 0; j < 3; j++){
            cout<<compactMatrix1[i][j]<<" ";
        }
        cout<<"\n";
    }

    int zeroes2 = 0, non_zeroes2;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(SparseMatrix2[i][j] == 0){
                zeroes2++;
            }
        }
    }
    non_zeroes2 = 9 - zeroes2;

    int compactMatrix2[non_zeroes2 + 1][3] = {
        {3, 3, zeroes2}
    };

    k = 1;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(SparseMatrix2[i][j] != 0){
                compactMatrix2[k][0] = i;
                compactMatrix2[k][1] = j;
                compactMatrix2[k][2] = SparseMatrix2[i][j];
                k++;
            }
        }
    }
    cout<<"\nCompact Matrix 2:\nR C V"<<endl;
    for(int i = 0; i < non_zeroes2 + 1; i++){
        for(int j = 0; j < 3; j++){
            cout<<compactMatrix2[i][j]<<" ";
        }
        cout<<"\n";
    }

    if ((compactMatrix1[0][0] == compactMatrix2[0][0]) && 
        (compactMatrix1[0][1] == compactMatrix2[0][1])) {

        int result[non_zeroes1 + non_zeroes2 + 1][3];
        result[0][0] = compactMatrix1[0][0];
        result[0][1] = compactMatrix1[0][1];

        int i = 1, j = 1, k = 1;
        while (i <= non_zeroes1 && j <= non_zeroes2) {
            if (compactMatrix1[i][0] < compactMatrix2[j][0] ||
            (compactMatrix1[i][0] == compactMatrix2[j][0] && compactMatrix1[i][1] < compactMatrix2[j][1])) {

                result[k][0] = compactMatrix1[i][0];
                result[k][1] = compactMatrix1[i][1];
                result[k][2] = compactMatrix1[i][2];
                i++;
            }
            else if (compactMatrix2[j][0] < compactMatrix1[i][0] || (compactMatrix1[i][0] == compactMatrix2[j][0] && compactMatrix2[j][1] < compactMatrix1[i][1])) {
                result[k][0] = compactMatrix2[j][0];
                result[k][1] = compactMatrix2[j][1];
                result[k][2] = compactMatrix2[j][2];
                j++;
            }
            else {
                int sum = compactMatrix1[i][2] + compactMatrix2[j][2];
                if (sum != 0) {
                    result[k][0] = compactMatrix1[i][0];
                    result[k][1] = compactMatrix1[i][1];
                    result[k][2] = sum;
                }
                i++;
                j++;
            }
            k++;
        }

        while (i <= non_zeroes1) {
            result[k][0] = compactMatrix1[i][0];
            result[k][1] = compactMatrix1[i][1];
            result[k][2] = compactMatrix1[i][2];
            i++; k++;
        }

        while (j <= non_zeroes2) {
            result[k][0] = compactMatrix2[j][0];
            result[k][1] = compactMatrix2[j][1];
            result[k][2] = compactMatrix2[j][2];
            j++; k++;
        }

        result[0][2] = k - 1;

        cout << "\nResultant Compact Matrix after Addition:\nR C V\n";
        for (int x = 0; x < k; x++) {
            cout << result[x][0] << " " << result[x][1] << " " << result[x][2] << "\n";
        }
    }
    else {
        cout << "Addition is not possible with the given dimensions." << endl;
    }

    return 0;
}