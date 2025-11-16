#include <iostream>
using namespace std;

int main(){
    char ch;
    int rows, columns;
    while (true)  {
        cout<<"Enter the size of the matrix (m x n): ";
        cin>>rows>>ch>>columns;
        
        if (rows != columns) {
            cout<<"The matrix must be a square matrix!"<<endl;
            continue;
        }

        int size = (rows * 3) - 2;
        int triDiagonalArray[size], k = 0;
        
        cout<<"Enter "<<size<<" tridiagonal elements in order: ";
        for(int i = 0; i < size; i++){
            cin>>triDiagonalArray[i];
        }
        
        k = 0; 
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if (i == j || i - j == 1 || j - i == 1) {
                    cout<<triDiagonalArray[k++]<<" ";
                }
                else {
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
        break;
    }

    return 0;
}
