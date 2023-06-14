// Given two arrays a[] and b[] of size n and m respectively. 
// The task is to find union between these two arrays.
// Example 1:
// Input:
// 5 3
// 1 2 3 4 5
// 1 2 3
// Output: 
// 5


#include<iostream>
#include<unordered_set>
using namespace std;

int doUnion(int a1[], int n, int a2[], int m){

    unordered_set<int> s;

    for(int i=0; i<n; i++){
        s.insert(a1[i]);
    }

    for(int j=0; j<m; j++){
        s.insert(a2[j]);
    }

    return s.size();
}
int main(){
    int n = 5, m = 3;
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {1, 2, 3};

    int res = doUnion(a1, n, a2, m);
    cout<<res<<endl;

    return 0;
}
