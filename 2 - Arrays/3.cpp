// Bubble sort



#include<iostream>
using namespace std;


void sort(int arr[], int size){
    int temp;
    bool swapped=false;
    for(int i=0; i<(size-1); i++){
        for(int j=0; j<(size-i-1); j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            return;
        }

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