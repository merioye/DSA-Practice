// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether 
// a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. 
// Example 1:

// Input:
// a1[] = {11, 1, 13, 21, 3, 7}
// a2[] = {11, 3, 7, 1}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

// Example 2:

// Input:
// a1[] = {1, 2, 3, 4, 5, 6}
// a2[] = {1, 2, 4}
// Output:
// Yes
// Explanation:
// a2[] is a subset of a1[]

// Example 3:

// Input:
// a1[] = {10, 5, 2, 23, 19}
// a2[] = {19, 5, 3}
// Output:
// No
// Explanation:
// a2[] is not a subset of a1[]


#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


// it's space complexity is O(n+m)
// string isSubset(int a1[], int a2[], int n, int m) {
    
//     if(n<m){                                 // if n is less than m means a2[] is larger than a1[] and hence cannot be subset of a1[]
//         return "No";
//     }
    
//     unordered_map<int, int> mp1;             // map to store elements and their count of array a1[]
//     unordered_map<int, int> mp2;             // map to store elements and their count of array a2[]
    
//     for(int i=0; i<n; i++){
        
//         mp1[a1[i]]++;                  
        
//         if(i<m){                             // bcz n>m, if i becomes greater or equal to m means a2[] elements has ended
//             mp2[a2[i]]++;
//         }
//     }
    
//     for(auto it:mp2){                        
//         int element = it.first;              // indivudual element of a2[]
//         int elementCount = it.second;        // count of element of a2[]
        
//         if(mp1[element]<elementCount){       // if the count of a2[]'s element is less than a1[]'s same element means a2[] is not a subset of a1[] as a resutl return with "No"
//            return "No"; 
//         }
//     }
    
//     return "Yes";                             // if the countrol reaches at this line means all elements of a2[] are present in a1[], hence a2[] is a subset of a1[]
// }


// it's space complexity is O(n)
string isSubset(int a1[], int a2[], int n, int m) {

    unordered_map<int, int> mp;                   // it will contain a1[]'s elements and their count

    for(int i=0; i<n; i++){
        mp[a1[i]]++;
    }

    for(int j=0; j<m; j++){
        if(mp.find(a2[j])==mp.end()){             // if the element not found means a2[] is not a subset of a1[]
            return "No";
        }
        mp[a2[j]]--;                              // bcz the element if found, decrementing the count of this element in map by 1

        if(mp[a2[j]]==0){                         // if this a2[]'s element's current count becomes zero then removing it from map so that in next iteration if a2[] has this element and it is not found in map hence a2[] is not a subset of a1[] 
            mp.erase(a2[j]);
        }
    }

    return "Yes";
}

int main(){
    int n = 6, m = 3;
    int a1[] = {1, 2, 3, 4, 5, 6};
    int a2[] = {1, 2, 4};

    cout<<isSubset(a1,a2,n,m)<<endl;

    return 0;
}