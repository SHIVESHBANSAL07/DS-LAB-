#include <iostream>
using namespace std;

int main(){
    int a[100], n=0;
    cout << "Enter the number of elemnts of array: ";
    cin >> n;
    cout << "Enter the elemts of the array: ";
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    cout << "Array before duplicate removal: [";
    for(int i =0; i<n; i++){
        cout << a[i] << ", ";
    }
    cout << "\b\b]";

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (a[i] == a[j]) {
                for (int k = j; k < n - 1; k++) {
                    a[k] = a[k + 1];
                }
                n--;
            } 
            else {
                j++;
            }
        }
    }
    
    cout << "Array after duplicate removal: [";
    for(int i =0; i<n; i++){
        cout << a[i] << ", ";
    }
    cout << "\b\b]";

    return 0;
}