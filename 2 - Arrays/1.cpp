// Binary search

#include<iostream>
using namespace std;


int binarySearch(int arr[], int size, int noToFind){
    int startingIndex=0, endingIndex=size-1, mid;
    while(startingIndex<=endingIndex){
        mid = startingIndex + (endingIndex-startingIndex)/2;    // which is equal to (startingIndex+endingIndex)/2 but good for large values of startingIndex & endingIndex
        if(arr[mid]==noToFind){
            return mid;
        }
        if(arr[mid]>noToFind){
            endingIndex = mid-1;
        }
        if(arr[mid]<noToFind){
            startingIndex = mid+1;
        }
    }
    return -1;
}


int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++){
        cout<<"Enter "<<i<<" element of array: ";
        cin>>arr[i];
    }

    int noToFind;
    cout<<"Enter no to find in the arry: ";
    cin>>noToFind;

    int isPresent = binarySearch(arr, size, noToFind);
    if(isPresent==-1){
        cout<<noToFind<<" is not present in the array"<<endl;
    }
    else{
        cout<<noToFind<<" is present at index "<<isPresent<<" in the array"<<endl;
    }
    return 0;
}