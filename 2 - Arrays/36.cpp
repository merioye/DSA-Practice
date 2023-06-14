// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median 
// of the matrix.
// Example 1:

// Input:
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]

// Output: 5

// Explanation:
// Sorting matrix elements gives us 
// {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

// Example 2:

// Input:
// R = 3, C = 1
// M = [[1], [2], [3]]
// Output: 2


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// its time complexity is O(r*c) and space complexity is also O(r*c)
int median(vector<vector<int>> matrix, int r, int c){
     
    vector<int> v;                       // creating vector that will contain all matrix elements in sorted order
    
    for(int i=0; i<r; i++){              // inserting elements of matrix in the vector
        for(int j=0; j<c; j++){
            v.push_back(matrix[i][j]);
        }
    }

    sort(v.begin(), v.end());            // sorting the vector so that I can find the median
    
    int isOdd = (r*c) & 1;               // checking is the total no of elements in matrix are odd or even
    
    int res;                             // it will contain median of matrix
    
    int mid = v.size()/2;                // it will contain the index of mid element( if isOdd is true then it will contain exact middle element index else if isOdd is false then there will be two join middle element and mid will contain second middle elements index)
    
    if(isOdd){                           // if no of elements in matrix is odd means the median of matrix will be the only single middle element of sorted array
        res = v[mid];                    // getting the middle element from set and assigning it to res
    }
    else{                                // else the median will be the addition of both shared middle elements
        res = v[mid-1]+v[mid];
    }
    
    return res;
}


int main(){
    int r = 3, c = 3;
    vector<vector<int>> matrix = {
        {1, 3, 5}, 
        {2, 6, 9}, 
        {3, 6, 9}
    };

    int res = median(matrix, r, c);
    cout<<res<<endl;

    return 0;
}