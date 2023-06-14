// Given an array arr of size n and an integer X. Find if there's a triplet in the array 
// which sums up to the given integer X.
// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in 
// the array sums up to 13.

// Example 2:

// Input:
// n = 5, X = 10
// arr[] = [1 2 4 3 6]
// Output:
// 1
// Explanation:
// The triplet {1, 3, 6} in 
// the array sums up to 10.


#include<iostream>
#include<algorithm>
using namespace std;

// It's time complexity is n2logn
// bool find3Numbers(int arr[], int size, int sum){

//     sort(arr, arr+size);                // sorting the array so that I can perform binary search on it

//     for(int i=0; i<size; i++){
//         for(int j=i+1; j<size; j++){
//             int thirdNoToFind = sum-arr[i]-arr[j];                           // It is the third number that is required to complete the triplet sum equal to sum variable(e.g thirdNoToFind=13-1-4=> which is equal to 8)
//             bool isPresent = binary_search(arr+j+1, arr+size, thirdNoToFind);   // Searching in remaining array from j+1-n, If at any iteration the third No that is required to complete triplet sum is found means there is triplet sum avaibale that is equal to sum value
//             if(isPresent){
//                 return true;
//             }
//         }
//     }

//     return false;
// }


// better solution it's time complexity is n2
bool find3Numbers(int arr[], int size, int sum){

    sort(arr, arr+size);

    for(int i=0; i<size; i++){
        
        int j = i+1;                                     // starting index of array in which to search for two numbers that could make the sum equal to sum value
        int k = size-1;                                  // ending index of array in which to search for two numbers that could make the sum equal to sum value
        while(j<k){
            if(arr[i]+arr[j]+arr[k]==sum) return true;   // if triplet sum is found then simply return
            else if(arr[i]+arr[j]+arr[k]>sum) k--;       // if the value of these three numbers is greater than sum then it means if the triplet sum is present then it can only be found in the left side bcz array is sorted, the lesser or equal values will be on the left side of array hence decreased the value of k
            else j++;                                    // if the value of these three numbers is not equal and greater than sum then it means if the triplet sum is present then it can only be found in the right side bcz array is sorted, the greater values will be on the right side of array hence increased the value of j
        }
    }

    return false;
}

int main(){
    int size = 6, sum = 13;
    int arr[] = {1, 4, 45, 6, 10, 8};

    bool res = find3Numbers(arr, size, sum);
    cout<<res<<endl;

    return 0;
}