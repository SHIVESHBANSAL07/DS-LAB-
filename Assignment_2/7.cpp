#include <iostream>
using namespace std;

int main(){
    int size = 0;
    cout<<"Size of array: ";
    cin>>size;
    int array[size];
    for(int i = 0; i < size; i++){
        cout<<"Enter element "<< i+1 << ": ";
        cin>>array[i];
    }
    cout<<"Array created successfully!\n";

    cout<<"Array: ";
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";

    int inversions = 0;
    for(int i = 0; i < size - 1; i++){
        // bool flag = true;
        for(int j = i + 1; j < size; j++){
            if(array[i] > array[j]){
                inversions++;
                // flag = false;
                // int temp = array[j];
                // array[j] = array[j + 1];
                // array[j + 1] = temp;
            }
        }
        // if(flag == true) break;
    }

    cout<<"No. of inversions: ";
    cout<<inversions;

    return 0;
}