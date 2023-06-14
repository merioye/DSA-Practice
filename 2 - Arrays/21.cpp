// Given an array of distinct elements. Find the third largest element in it.
// Suppose you have A[] = {1, 2, 3, 4, 5, 6, 7}, its output will be 5 because it is the 3 largest 
// element in the array A.
// Example 1:
// Input:
// N = 5
// A[] = {2,4,1,3,5}
// Output: 3
// Example 2:
// Input:
// N = 2
// A[] = {10,2}
// Output: -1


#include<iostream>
#include<algorithm>
using namespace std;

int thirdLargest(int a[], int n){
    if(n<3){
        return -1;
    }
    sort(a, a+n);
    return a[n-3];
}

int main(){
    int size = 5;
    int a[] = {2,4,1,3,5};

    int res = thirdLargest(a, size);
    cout<<res<<endl;
    return 0;
}