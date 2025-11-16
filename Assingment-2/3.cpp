#include <iostream>
using namespace std;

int main(){

    int n = 6, sampleArray[] = {1, 2, 3, 4, 5};

    // Linear method
    bool found = false;
    for (int i = 0; i < n; i++){
        if(sampleArray[i] != (i + 1)){
            cout<<"Missing "<< i + 1 << " at index " << i <<endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Missing " << n << " at index " << n - 1 << endl;
    }

    // Binary Search Method
    int left = 0, right = n - 2, middle;

    while (left <= right){
        middle = (left + right) / 2;
        if (sampleArray[middle] == middle + 1){
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    cout<<"Missing " << left + 1 << " at index " << left <<endl;

    return 0;
}