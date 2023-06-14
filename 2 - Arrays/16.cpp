// Given an array of N integers, and an integer K, find the number of pairs of elements in the array 
// whose sum is equal to K.
// Example 1:
// Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1} 
// Output: 2
// Example 2:
// Input:
// N = 4, K = 2
// arr[] = {1, 1, 1, 1}
// Output: 6





#include<iostream>
using namespace std;


int getPairsCount(int arr[], int size, int k){
    int count = 0;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i]+arr[j]==k){
                count++;
            }
        }
    }
    return count;
}
int main(){
    int size = 4, k = 2;
    int arr[] = {1, 1, 1, 1};

    cout<<getPairsCount(arr, size, k)<<endl;
    return 0;
}