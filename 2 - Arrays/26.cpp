// Given an array of positive integers. Find the length of the longest sub-sequence such that elements
// in the subsequence are consecutive integers, the consecutive numbers can be in any order.

// Example 1:
// Input:
// N = 7
// a[] = {2,6,1,9,4,5,3}
// Output:
// 6
// Explanation:
// The consecutive numbers here
// are 1, 2, 3, 4, 5, 6. These 6 
// numbers form the longest consecutive
// subsquence.

// Example 2:
// Input:
// N = 7
// a[] = {1,9,3,10,4,20,2}
// Output:
// 4
// Explanation:
// 1, 2, 3, 4 is the longest
// consecutive subsequence.



#include<iostream>
#include<algorithm>
using namespace std;


int findLongestConseqSubseq(int a[], int n){

    if(n==0)                     // if the array is empty means no consecutive sequence present
        return 0;

    sort(a, a+n);  

    int count=1, maxCount = 1;  // maxCount will contain maximum consecutive sequence value of whole array and count will contian of diffrent array parts 
    for(int i=1; i<n; i++){
        
        if(a[i]==a[i-1]){        // if previous and current element is equal then do nothing
            continue;
        }

        if(a[i]-1!=a[i-1]){      // if current element is not 1 greater than previous, means here consecutive sequence ends, then reseting count value to 1
            count = 1;
        }
        else{                     // else(means current element is exactly 1 greater than previous), it is continuing consecutive sequence, increment the value of value by 1
            count++;
        }

        if(count>maxCount)        // if count is greater than maxCount means there is another consecutive sequence present greater than maxCount's current sequence value then update it
            maxCount = count;
    }

    return maxCount;
}

int main(){
    int n = 7;
    int a[] = {2,6,1,9,4,5,3};

    int res = findLongestConseqSubseq(a, n);
    cout<<res<<endl;

    return 0;
}