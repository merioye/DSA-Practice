// Selection sort


#include<iostream>
using namespace std;


void sort(int arr[], int size){
    int minIndex, temp;
    for(int i=0; i<(size-1); i++){
        minIndex = i;
        for(int j=(i+1); j<size; j++){
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}


void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[] = {8,2,14,20,11,1};

    sort(arr, 6);
    printArray(arr, 6);
    return 0;
}