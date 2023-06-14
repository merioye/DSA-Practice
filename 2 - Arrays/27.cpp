// A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, 
// the task is to find the minimum element in it.
// Example 1
// Input:
// N = 5
// arr[] = {4 ,5 ,1 ,2 ,3}
// Output: 1
// Explanation: 1 is the minimum element inthe array.

// Example 2
// Input:
// N = 7
// arr[] = {10, 20, 30, 40, 50, 5, 7}
// Output: 5
// Explanation: Here 5 is the minimum element.


#include<iostream>
using namespace std;


int findMin(int a[], int n){

    int start=0;
    int end=(n-1);
    int mid;

    while(start<=end){
        
        mid = start + (end-start)/2;

        if(mid==0 || mid==n-1){              // if mid is equal to starting index or last index of array means the whole array is traversed and hence this is the minimum element
            return a[mid];
        }

        if(a[mid]<a[mid-1] && a[mid]<a[mid+1]){    // if mid element is less than its left & right elements means this is the minimum element(bcz the array is sorted and rotated, minimum element's left value will be greater and minimum element's right element will also be greater than its value)
            return a[mid];
        }

        if(a[start]>a[end] && a[mid]>a[end]){     // if the elements at index start & at index mid are greater than the elment at index end means the minimum elemetn must be present in right part of the array(bcz array is sorted and rotated)
            start = mid+1;
        }
        else{                                     // else the element will be in the left part of array
            end = mid-1;
        }
    }
}

int main(){
    int n = 7;
    int a[] = {10, 20, 30, 40, 50, 5, 7};

    int res = findMin(a, n);
    cout<<res<<endl;

    return 0;
}