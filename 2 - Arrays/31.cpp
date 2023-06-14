// Given an array arr[] denoting heights of N towers and a positive integer K.

// For each tower, you must perform exactly one of the following operations exactly once.

// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest 
// towers after you have modified each tower.

// You can find a slight modification of the problem here.
// Note: It is compulsory to increase or decrease the height by K for each tower. After 
// the operation, the resultant array should not contain any negative integers.
// Input:
// K = 2, N = 4
// Arr[] = {1, 5, 8, 10}
// Output:
// 5
// Explanation:
// The array can be modified as 
// {3, 3, 6, 8}. The difference between 
// the largest and the smallest is 8-3 = 5.



#include<iostream>
#include<algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k){

    sort(arr, arr+n);                      

    int minDiff = arr[n-1]-arr[0];

    for(int i=1; i<n; i++){
        
        if(arr[i]-k<0){
            continue;
        }

        int minimum = min(arr[0]+k, arr[i]-k);
        int maximum = max(arr[i-1]+k, arr[n-1]-k);

        minDiff = min(minDiff, maximum-minimum);
    }

    return minDiff;
}
int main(){

    int k = 2, n = 4;
    int arr[] = {1, 5, 8, 10};

    int result = getMinDiff(arr, n, k);
    cout<<result<<endl;

    return 0;
}


// Dry run
// k = 2, n = 4, arr = {1,5,9,10}
// after sort arr = {1,5,8,10}
// minDiff = 10-1 = 9

// i=1
//     (5-2)=3 < 0 false
//     minimum = min(3,3) = 3
//     maximum = max(3,8) = 8

//     minDiff = min(9,5) = 5

// after 1st iteration
// minDiff = 5

// i=2
//     (8-2)=6 < 0 false
//     minimum = min(3,6) = 3
//     maximum = max(7,8) = 8

//     minDiff = min(5,5) = 5

// after 2nd iteration
// minDiff = 5

// i=3
//     (10-2)=8 < 0 false
//     minimum = min(3,8) = 3
//     maximum = max(10,8) = 10

//     minDiff = min(5,10) = 5

// after 3rd iteration
// minDiff = 5

// And the loop ends

