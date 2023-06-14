// Given an array which consists of only 0, 1 and 2. Sort the array without
// using any sorting algorithm.
// Sample Input: 9
//               0 1 2 1 1 0 0 2 2
// Sample Output: 0 0 0 1 1 1 2 2 2
// Here, 9 is the size of array input by the user followed by the elements input



#include<iostream>
using namespace std;


void sort(int arr[], int size){
    int noOfZero=0, noOfOne=0, noOfTwo = 0;
    
    for(int i=0; i<size; i++){
        if(arr[i]==0) noOfZero++;
        else if(arr[i]==1) noOfOne++;
        else if(arr[i]==2) noOfTwo++;
    }

    for(int j=0; j<size; j++){
        if(j<noOfZero) arr[j]=0;
        else if(j<(noOfZero+noOfOne)) arr[j] = 1;
        else if(j<(noOfZero+noOfOne+noOfTwo)) arr[j] = 2;
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

    int arr[size];
    for(int i=0; i<size; i++){
        cout<<"Enter element of array: ";
        cin>>arr[i];
    }

    sort(arr, size);
    printArray(arr, size);
    return 0;
}