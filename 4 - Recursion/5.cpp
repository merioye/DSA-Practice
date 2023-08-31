// Implement binary search using recursion

#include<iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int elemToFind){

    if(start>end){
        return false;
    }

    int mid = (start+end)/2;
    if(arr[mid]==elemToFind){
        return true;
    }
    if(arr[mid]>elemToFind){
        binarySearch(arr, start, mid-1, elemToFind);
    }else{
        binarySearch(arr, mid+1, end, elemToFind);
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6, elemtoFind=10;
    bool isPresent = binarySearch(arr, 0, n-1, elemtoFind);
    if(isPresent){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }
    return 0;
}