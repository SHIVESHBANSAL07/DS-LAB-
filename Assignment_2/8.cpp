#include <iostream>
using namespace std;

int main(){
    int size;
    
    cout << "Size of array: ";
    cin >> size;
    int array[size];

    for(int i = 0; i < size; i++){
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "Array created successfully!\n";

    int uniqueSize = 0;
    int uniqueArray[100];

    for(int i = 0; i < size; i++){
        bool exists = false;
        for(int j = 0; j < uniqueSize; j++){
            if(array[i] == uniqueArray[j]){
                exists = true;
                break;
            }
        }
        if(!exists){
            uniqueArray[uniqueSize] = array[i];
            uniqueSize++;
        }
    }

    cout << "No. of unique elements: ";
    cout << uniqueSize;

    return 0;
}
