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

        int size = (rows * (rows + 1)) / 2;
        int upperTriangular[size], k = 0;
        
        cout<<"Enter "<<size<<" upper triangular elements in order: ";
        for(int i = 0; i < size; i++){
            cin>>upperTriangular[i];
        }
        
        k = 0; 
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if (i == j || i > j) {
                    cout<<upperTriangular[k]<<" ";
                    k++;
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
