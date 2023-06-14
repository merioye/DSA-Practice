// Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements 
// occurring more than once in the given array.
// Example 1:
// Input:
// N = 4
// a[] = {0,3,1,2}
// Output: -1

// Example 2:
// Input:
// N = 5
// a[] = {2,3,1,2,3}
// Output: 2 3 


#include<iostream>
#include<vector>
#include<map>
using namespace std;



void printArray(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

// vector<int> duplicates(int arr[], int size){
//     map<int, int> mp;
//     vector<int> v;
    
//     for(int i=0; i<size; i++){
//         mp[arr[i]]++;
//     }
    
//     for(auto it:mp){
//         if(it.second>1){
//             v.push_back(it.first);
//         }
//     }
    
//     if(v.size()==0){
//         v.push_back(-1);
//     }
    
//     return v;
// }



// Better solution
vector<int> duplicates(int arr[], int size){

    vector<int> v;
    
    for(int i=0; i<size; i++){
        int ind = arr[i]%size;
        arr[ind] = arr[ind] + size;
    }

    
    for(int j=0; j<size; j++){
        if((arr[j]/size)>=2){
            v.push_back(j);
        }
    }

    if(v.size()==0){
        v.push_back(-1);
    }
    
    return v;
}

int main(){
    int size = 8;
    int arr[] = {2,3,1,2,3,1,4,4};
    vector<int> dup = duplicates(arr, size);
    printArray(dup);
    return 0;
}