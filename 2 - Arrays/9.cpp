// Find the Kth largest and Kth smallest number in an array.
// Sample Input: 3
//               9
//               1 2 3 4 5 9 6 33 19
// Sample Output: largest: 9
//                smallest: 3
// Here , K = 3 , 9 is the size of array :



#include<iostream>
using namespace std;


void sort(int arr[], int size){
    int temp;
    for(int i=0; i<size-1; i++){
        bool swapped = false;
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
    int size, nth;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++){
        cout<<"Enter element of array: ";
        cin>>arr[i];
    }

    cout<<"Enter the values of largest & smallest no to find: ";
    cin>>nth;

    sort(arr, size);
    printArray(arr, size);
    cout<<"largest: "<<arr[size-nth]<<endl;
    cout<<"smallest: "<<arr[nth-1]<<endl;

    return 0;
}