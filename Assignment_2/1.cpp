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
    
    cout<<"\nSorting the array..."<<endl;
    for(int i = 0; i < size - 1; i++){
        bool flag = true;
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j+1]){
                flag = false;
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if(flag == true) break;
    }

    cout<<"\nSorted Array: ";
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }

    int searchElement;

    cout<<"\n\nEnter the element to be searched: ";
    cin>>searchElement;

    cout<<endl;

    int left = 0, right = size - 1, middle;
    bool found = false;

    while (left <= right){
        middle = (left + right) / 2;
        if (array[middle] == searchElement){
            cout<<"Found at index "<< middle <<endl; 
            found = true;
            break;
        }
        else if (searchElement < array[middle]){
            right = middle - 1;
        }
        else {
            left = middle + 1;
        }
    }
    if (!found) {
        cout<<"\nElement not found!"<<endl;
    }

    return 0;
}