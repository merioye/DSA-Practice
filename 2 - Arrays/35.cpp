// Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based 
// index of the first row that has the maximum number of 1's.

// Example 1:
// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).

// Example 2:

// Input: 
// N = 2, M = 2
// Arr[][] = {{0, 0}, {1, 1}}
// Output: 1
// Explanation: Row 1 contains 2 1's (0-based
// indexing).



#include<iostream>
#include<vector>
using namespace std;


// binary search to find first position of 1 in array if found else return -1
// int binarySearch(vector<int> v, int elm){

//     int start=0;
//     int end=v.size()-1;
//     int mid;
    
//     while(start<=end){

//         bool isSameElementPresentInLeft = false;
//         mid = start+(end-start)/2;

//         if(v[mid]==elm){
//             if(v[mid-1]==elm){                      // if element is found and its left element is also the same element, means it is not the first index of element we want to found
//                 end = mid-1;                        // Hence updating the value of end to search in left array bcz there is (1 OR more) elements present that we want to find
//                 isSameElementPresentInLeft = true;  // making isSameElementPresentInLeft to true so that the else part does not update the value of start(bcz by updating value of start the start may become greater than end and as a result the loop end, we did not found the element which is incorrect)
//             }
//             else{
//                 return mid;                         // else means this is the first occurrent of element we want to find then return the index
//             }
//         }
//         if(v[mid]>elm){
//             end = mid-1;
//         }
//         else{
//             if(!isSameElementPresentInLeft){
//                 start = mid+1;
//             }
//         }
//     }

//     return -1;
// }

// // Its time complexity is O(nlogn)
// int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
//     // code here
    
//     int index = -1;                                // it will contain index of row which has maximum 1's
//     int previous = m;                              // it will contain the indexof of first occurrent of 1 in previous row, by default it is set to last index of row
    
//     for(int i=0; i<n; i++){
//         int position = binarySearch(arr[i], 1);
//         if(position!=-1){                          // if element found then execute these statements
//             if(position<previous){                 // if the index returned by binarySearch algorithm is less that previous row index means it has more no of 1's in the row
//                 index = i;                         // setting the index to current rows index bcz it has more no of 1's as compared to previous row
//                 previous = position;               // hence update the value
//             }
//         }
//     }
    
//     return index;
// }



// better solution
// Its time complexity is O(n)
int rowWithMax1s(vector<vector<int>> arr, int n, int m){

    int index = -1;
    int r=0, c=m-1;             // setting row to first row index of matrix and column to last column index of matrix

    while(r<n && c>=0){         // while loop will execute untill either all rows are traversed or all columns are checked
        if(arr[r][c]==1){       
            index = r;          // setting index to to current row if elment at [r][c]th index is 1
            c--;                // and moving column a step back from its current position
        }
        else{
            r++;                // else miving row to next row
        }
    }
    
    return index;
}


int main(){
    int n = 4 , m = 4;
    vector<vector<int>> arr = {
           {0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}
    };

    int res = rowWithMax1s(arr, n, m);
    cout<<res<<endl;
    
    return 0;
}