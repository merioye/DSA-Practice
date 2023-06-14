// Given an array, rotate the array by one position in clock-wise direction.
// Example 1:
// Input:
// N = 5
// A[] = {1, 2, 3, 4, 5}
// Output:
// 5 1 2 3 4
// Example 2:
// Input:
// N = 8
// A[] = {9, 8, 7, 6, 4, 2, 1, 3}
// Output:
// 3 9 8 7 6 4 2 1






#include<iostream>
using namespace std;

void rotate(int arr[], int n){
    int temp = arr[n-1];
    for(int i=(n-1); i>=0; i--){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n=5;
    int arr[n] = {1,2,3,4,5};

    rotate(arr, n);
    printArray(arr, n);
    return 0;
}