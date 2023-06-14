// Insertion sort


#include<iostream>
using namespace std;


void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void sort(int arr[], int size){
    int temp, j;
    for(int i=1; i<size; i++){
        temp = arr[i];
        for(j=(i-1); j>=0; j--){
            if(temp<arr[j]){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}


int main(){
    int arr[] = {10,3,9,2};

    sort(arr, 4);
    printArray(arr, 4);
    return 0;
}