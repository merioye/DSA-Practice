// Kadane's Algorithm
// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
// which has the maximum sum and return its sum.
// Example 1:
// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.

// Example 2:
// Input:
// N = 4
// Arr[] = {-1,-2,-3,-4}
// Output:
// -1
// Explanation:
// Max subarray sum is -1 of element (-1)




#include<iostream>
#include<climits>
using namespace std;



long long maxSumSubArray(int arr[], int n){
    
    long long maxSum = INT_MIN;
    long long arraySum = 0;

    for(int i=0; i<n; i++){
        arraySum = arraySum + arr[i];
        if(arraySum>maxSum){
            maxSum = arraySum;
        }

        if(arraySum<0){
            arraySum = 0;
        }
    }

    return maxSum;

}
int main(){
    
    int n = 5;
    int arr[] = {1,2,3,-2,5};

    long long res = maxSumSubArray(arr, n);
    cout<<res<<endl;

    return 0;
}




// Dry Run
 
// n = 5
// arr = {1,2,3,-2,5}

// maxSum = INT_MIN
// arraySum = 0

// => i = 0
// arraySum = 0 + 1 => 1
// 1 > INT_MIN => true maxSum = 1
// 1 < 0 => false

// => i = 1
// arraySum = 1 + 2 => 3
// 3 > 1 => true maxSum = 2
// 2 < 0 => false

// => i = 2
// arraySum = 3 + 3 => 6
// 6 > 2 => true maxSum = 6
// 6 < 0 => false

// => i = 3
// arraySum = 6 + (-2) => 4
// 4 > 6 => false
// 4 < 0 => false

// => i = 4
// arraySum = 4 + 5 => 9
// 9 > 6 => true maxSum = 9
// 9 < 0 => false



// Final Values
// maxSum = 9
// arraySum = 9


// return maxSum