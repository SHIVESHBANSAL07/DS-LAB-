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
        else {
            int diagonalArray[rows];
        
            for(int i = 0; i < rows; i++){
                cout<<"Enter the diagonal element at index [" << i << ", " << i << "]: ";
                cin>>diagonalArray[i];
            }
        
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < columns; j++){
                    if (i == j) {
                        cout<<diagonalArray[i]<<" ";
                    }
                    else {
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
            break;
        }
    }

    return 0;
}