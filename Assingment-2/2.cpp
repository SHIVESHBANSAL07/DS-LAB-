 #include <iostream>
using namespace std;
//                                                        
int main(){
    int size = 7;
    int array[size] = {64, 34, 25, 12, 22, 11, 90};

    int passes = 0;
    for(int i = 0; i < size - 1; i++){
        bool flag = true;
        passes++;
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

    cout<<"Sorted array: ";
    for(int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
    cout<<"No. of passes = "<<passes;

    return 0;
}