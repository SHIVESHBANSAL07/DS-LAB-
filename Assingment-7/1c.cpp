#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool flag = true;
        for(int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                flag = false;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (flag) break;
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
 
    bubbleSort(arr, n);
    
    delete []arr;

    return 0;
}