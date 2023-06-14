// Write a program to reverse the array


#include<iostream>
using namespace std;


void reverse(int arr[], int size){
    int mid = 0 + (size-0)/2;
    int temp;
    for(int i=0; i<mid; i++){
        temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size] = {};
    for(int i=0; i<size; i++){
        cout<<"Enter element of array: ";
        cin>>arr[i];
    }

    reverse(arr, size);
    printArray(arr, size);
    return 0;
}