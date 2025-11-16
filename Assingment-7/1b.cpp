#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n){
    for(int i = 0; i <= n - 1; i++){
        int j = i;
        while (j > 0 && (arr[j - 1] > arr[j])){
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }  
}

int main(){
    int n = 0;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];        
    }    
 
    insertionSort(arr, n);
    
    delete []arr;

    return 0;
}