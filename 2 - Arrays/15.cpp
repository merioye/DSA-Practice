// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. 
// Find the missing element.
// Example 1:
// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4
// Example 2:
// Input:
// N = 10
// A[] = {6,1,2,8,3,4,7,10,5}
// Output: 9





#include<iostream>
using namespace std;


int missingNo(int arr[], int size){
    int sumOfArrayValues = 0;       // it will contain sum of all elements present in array
    int totalSum = 0;               // it will contain sum of all elements from 1 to size
    for(int i=1; i<=size; i++){
        if(i<size){
            sumOfArrayValues = sumOfArrayValues+arr[i-1];
        }
        totalSum = totalSum+i;
    }
    return totalSum-sumOfArrayValues;
}
int main(){
    int size = 8;
    int arr[] = {1, 2, 4, 6, 3, 7, 8};

    int no = missingNo(arr, size);
    cout<<"Missing no is: "<<no<<endl;
    return 0;
}