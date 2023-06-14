// You are given an array of N+2 integer elements. All elements of the array are in range 1 
// to N. Also, all elements occur once except two numbers which occur twice. Find the two 
// repeating numbers.
// Example 1:

// Input:
// N = 4
// array[] = {1,2,1,3,4,3}
// Output: 1 3
// Explanation: In the given array, 
// 1 and 3 are repeated two times.
// Example 2:

// Input:
// N = 2
// array[] = {1,2,2,1}
// Output: 2 1
// Explanation: In the given array,
// 1 and 2 are repeated two times 
// and second occurence of 2 comes 
// before 1. So the output is 2 1.


#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdlib>
using namespace std;

// vector<int> twoRepeated(int arr[], int N){

//     vector<int> v;                // vector that will contain resultant elementts
//     unordered_map<int ,int> mp;  // map that will contain no as key and its count as value e.g 1:2

//     for(int i=0; i<N+2; i++){

//         mp[arr[i]]++;            // updating the count of element of array in map(if the element is not present in map then it will set element with count 1 else it will increment 1 in its value)

//         int count = mp[arr[i]];   // getting the count of current element of array from map
//         if(count>1){              // if count is greater than 1 means it is repeated then push to resultant vector
//             v.push_back(arr[i]);
//         }
//     }

//     return v;
// }


// The above solution is good but it uses extra space for map
// Here is a better solution
vector<int> twoRepeated(int arr[], int N){

    vector<int> v;

    for(int i=0;i<N+2;i++)
    {
        if(arr[abs(arr[i])]>0)
            arr[abs(arr[i])] *=-1;
        else
            v.push_back(abs(arr[i]));
    }

    return v;
}

int main(){

    int N = 4;
    int arr[] = {1,2,1,3,4,3};

    vector<int> res = twoRepeated(arr, N);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}


// Dry run of 2nd approach
// arr = {1,2,2,1}, N=2, v={}
// for loop will run for 0-3
// i=0
//     2>0 true
//     arr = {1,-2,2,1}
// i=1
//     2>0 true
//     arr = {1,-2,-2,1}
// i=2
//     -2>0 false
//     v = {2}
// i=3
//     -2>0 false
//     v = {2,1}