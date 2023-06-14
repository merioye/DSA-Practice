// Given an array arr[] of size N and an element k. The task is to find all elements in array that 
// appear more than n/k times.
// Example 1:
// Input:
// N = 8
// arr[] = {3,1,2,2,1,2,3,3}
// k = 4
// Output: 2
// Explanation: In the given array, 3 and
//  2 are the only elements that appears 
// more than n/k times.

// Example 2:
// Input:
// N = 4
// arr[] = {2,3,3,2}
// k = 3
// Output: 2
// Explanation: In the given array, 3 and 2 
// are the only elements that appears more 
// than n/k times. So the count of elements 
// are 2.



#include<iostream>
#include<unordered_map>
using namespace std;


int countOccurence(int a[], int n, int k){

    unordered_map<int, int> mp;        // it will contain each distinct element along with its no of accorrences in array as key value
    int count = 0;                     // it will contain no of elements present in array with more than n/k occurrences
    int times = n/k;                   

    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }

    for(auto it:mp){
        if(it.second>times){          // if this element is occurred more than n/k times than increment the count
            count++;
        }
    }

    return count;
}

int main(){
    int n = 8;
    int a[] = {3,1,2,2,1,2,3,3};
    int k = 4;

    int res = countOccurence(a, n, k);
    cout<<res<<endl;

    return 0;
}