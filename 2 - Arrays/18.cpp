// Given an array arr[] of size n, find the first repeating element. The element should occurs more than 
// once and the index of its first occurrence should be the smallest.
// Example 1:
// Input:
// n = 7
// arr[] = {1, 5, 3, 4, 3, 5, 6}
// Output: 2
// Example 2:
// Input:
// n = 4
// arr[] = {1, 2, 3, 4}
// Output: -1





#include<iostream>
#include<climits>
#include<unordered_set>
#include<unordered_map>
using namespace std;


// int firstRepeatingNo(int arr[], int size){
    
//     unordered_set<int> s;
        
//     int firstRepeatNo = INT_MAX;

//     for(int i=0; i<size; i++){

//         int isPresent = s.count(arr[i]);
//         // if present means this is the first repeating element
//         if(isPresent==1){
//             firstRepeatNo = arr[i];
//             break;
//         }
//         s.insert(arr[i]);
//     }
    
//     int index;
//     // if firstRepeatingNo is equal to our initial value, then it means no repeating no is present
//     if(firstRepeatNo==INT_MAX){
//         index = -1;
//     }else{
//         for(int j=0; j<size; j++){
//             if(arr[j]==firstRepeatNo){
//                 index = j;
//                 break;
//             }
//         }
//     }
    
    
//     return index;
// }



// More cleaner solution
int firstRepeatingNo(int arr[], int size){    

    unordered_map<int, int> mp;
    int firstRepeatedNo = INT_MIN;

    for(int i=0; i<size; i++){
        mp[arr[i]]++;
        if(mp[arr[i]]>1){
            firstRepeatedNo = arr[i];
            break;
        }
    }

    for(int i=0; i<size; i++){
        if(arr[i]==firstRepeatedNo){
            return i;
        }
    }


    return -1;
}

int main(){
    int size = 17;
    int arr[] = {1, 2, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 3, 5, 1, 9};

    int no = firstRepeatingNo(arr, size);
    cout<<no<<endl;

    return 0;
}