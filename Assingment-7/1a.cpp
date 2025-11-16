#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n){
    for(int i = 0; i <= n - 2; i++){
        int min = i;
        for(int j = i + 1; j <= n - 1; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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
 
    selectionSort(arr, n);
    
    delete []arr;

    return 0;
}