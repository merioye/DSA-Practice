// Create an Array of size 10 of integers. Take input from the user for these
// 10 elements and print the entire array after that.


#include<iostream>
using namespace std;


void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int size = 10;
    int arr[10] = {};

    for(int i=0; i<size; i++){
        cout<<"Enter element of array: ";
        cin>>arr[i];
    }

    printArray(arr, size);
    return 0;
}