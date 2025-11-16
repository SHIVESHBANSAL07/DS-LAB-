#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partitionFunction(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i < high){
            i++;
        }

        while(arr[j] > pivot && j > low){
            j--;
        }

        // For Descending
        // while (arr[i]>=pivot && i<high){
        //     i++;
        // }
        // while (arr[j]<pivot && j>low){
        //     j--;
        // }

        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;

}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pIndex = partitionFunction(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
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
 
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete []arr;

    return 0;
}