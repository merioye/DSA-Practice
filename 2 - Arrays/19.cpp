// Find the first non-repeating element in a given array arr of N integers.
// Note: Array consists of only positive and negative integers and not zero.
// Example 1:
// Input : arr[] = {-1, 2, -1, 3, 2}
// Output : 3
// Example 2:
// Input : arr[] = {1, 1, 1}
// Output : 0





#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


// Its time complexity is O(n*logn) and space complexity is O(n+n)
// int firstNonRepeatingNo(int arr[], int n){

//     unordered_map<int , int> m;    // it will store the frequency(count) of each distinct element present in array arr
//     vector<int> v;                 // it will store all elements that occurs once in the array arr


//     // storing count in the form of element:count in map i.e {-1:2, 2:2, 3:1}
//     for(int i=0; i<n; i++){      
//         m[arr[i]]++;
//     }

//     for(auto it:m){
//         // checking if the element has count '1'( means occurs in array only once ) then push it to vector v
//         if(it.second==1){
//             v.push_back(it.first);
//         }
//     }

//     sort(v.begin(), v.end());

//     for(int j=0; j<n; j++){
//         int isPresent = binary_search(v.begin(), v.end(), arr[j]);   // when binary_search algo returns true, means it is the first not-repeating element
//         if(isPresent){
//             return arr[j];
//         }
//     }

//     return 0;
// }


// Better solution its time complexity is O(n) and space complexity is O(n)
int firstNonRepeatingNo(int arr[], int size){

    unordered_map<int ,int> mp;             // It will contain array element as key and its count as value

    for(int i=0; i<size; i++){              // inserting values in map
        mp[arr[i]]++;
    }

    for(int i=0; i<size; i++){              // looping over array again to check for first non repeating element
        if(mp[arr[i]]==1){                  // if element count in map is 1 means it is the first non repeating element in array
            return arr[i];
        }
    }
    
    return 0;                               // if all elements in array are repeating then return 0
}

int main(){
    int size = 8;
    int arr[] = {8,-1, 2, -1, 3, 2, 1, 6};

    int no = firstNonRepeatingNo(arr, size);
    cout<<no<<endl;

    return 0;
}