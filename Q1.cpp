#include <iostream>
using namespace std;

#define SIZE 100
int n = 0, a[SIZE];

void create(){
    cout << "Enter the number of elements of array: ";
    cin >> n;
    
    cout << "Enter the elements of array: ";
    for(int i =0; i<n; i++){
        cin >> a[i];
    }
}

void display(){
    if(n == 0){
        cout << "The array is empty.";
    }
    else{
        cout << "Array is: [";
        for(int i=0; i<n; i++){
            cout << a[i] << ", ";
        }
        cout << "\b\b]";
    }
}

void insert(){
    int x,y;
    cout << "Enter the index at which you want to insert the element(1 to " << n << "): ";
    cin >> x;
    cout << "Enter the value you want to insert: ";
    cin >> y;
    for (int i = n; i > x; i--) {
        a[i] = a[i - 1];
    }
    a[x] = y;
    n++;
}

void del(){
    int x;
    cout << "Enter the index of the element you wan to delete(1 to " << n << "): ";
    cin >> x;
    for(int i=x; i< n-1; i++){
        a[i] = a[i+1];
    }
    n--;
}

void linsearch(){
    int x;
    cout << "Enter the element you want to search for: ";
    cin >> x;
    for(int i=0; i<n; i++){
        if(a[i]==x){
            cout << "Value found at index " << i;
            return;
        }
    }
    cout << "Value not found.";
}

int main(){
    int choice;
    do {
        cout << "\n--- MENU ---\n"
             << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linsearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}