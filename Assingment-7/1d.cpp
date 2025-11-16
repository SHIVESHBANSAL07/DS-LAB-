#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int *temp = new int [high - low + 1];
    int left = low, right = mid + 1, index = 0;

    while(left <= mid && right <= high){
        if (arr[left] <= arr[right]){
            temp[index++] = arr[left++];
        }
        else {
            temp[index++] = arr[right++];
        }
    }

    while(left <= mid){
        temp[index++] = arr[left++];
    }

    while(right <= high){
        temp[index++] = arr[right++];
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }

    delete []temp;
}

void mergeSort(int arr[], int low, int high){
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];        
    }
 
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete []arr;

    return 0;
}