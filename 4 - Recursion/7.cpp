// Quick sort

#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low, j = high;

    while(i<j){
        while(arr[i]<arr[pivot]){
            i++;
        }
        while(arr[j]>arr[pivot]){
            j--;
        }

        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[pivot];
    arr[pivot] = temp;
    return j;
}

void quickSort(int arr[], int low, int high){
    int partitionPoint = partition(arr, low, high);
    quickSort(arr, low, partitionPoint-1);
    quickSort(arr, partitionPoint+1, high);
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {55,3,2,8,10};
    int n = 5;

    printArray(arr, n);
    quickSort(arr, 0, n);
    printArray(arr, n);
    
    return 0;
}