// Given a matrix of size r*c. Traverse the matrix in spiral form.
// Example 1:

// Input:
// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output: 
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10


// Approach
// => first traverse the outer rectanagle of the matrix 
// e.g in matrix  1  2  3  4
//                5  6  7  8
//                9 10 11 12
//               13 14 15 16
// in above matrix the outer rectangle is 1  2  3  4
//                                        5        8
//                                        9       12 
//                                       13 14 15 16
// start from 1 and reach till 5 in anticlockwise direction when 5 is reached then abandon this
// outer rectangle and traverse inner rectangle and so on
// in this case inner rectangle is  6  7
//                                 10 11
// start from 6 and reach till 10
// repeat this process untill all the elements are traversed

// => make rectangle first row's first element index as minRowIndex, last row's last element 
// index as maxRowIndex, first column's first element index as minColIndex, last column's last
// element index maxRowIndex (basically this is done the define the boundaries of the rectangle)
// which is currently being traversed.
// => make two variables rowIndex, colIndex which will contain the indexes of the next elment
// and conditionally update the value of these two variables depending on the boundary of
// rectangle (means when iteration starts move to right till the column's last element and when
// columns's last element reached then move down to reach last element of row and when last
// elment of row is reached then move to left till the last first element of last row and then
// move up before the first element of 1st row)
// => make a variable iterationCount and initialize it with zero, this variable is used to 
// update the values of minRowIndex, maxRowIndex, minColIndex, maxColIndex, rowIndex, colIndex
// when the outer rectangle is fully traversed, bcz when outer rectangle is fully traversed
// then we need to traverse the inner rectangle for that we need to update the values of 
// above variables according to the boundaries of new inner rectangle


#include<iostream>
#include<vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
{
    // code here 
    vector<int> v;                    
    
    int minRowIndex = 0;                           // rectangle's minimum row index(which is the index of row's first eement index)    
    int minColIndex = 0;                           // rectangle's minimum column index(which is the index of column's first element index)
    int maxRowIndex = r-1;                         // rectangle's maximum row index(which is the index row's last element index)
    int maxColIndex = c-1;                         // rectangle's maximum column index(which is the index of column's last element)
    
    int rowIndex=0;                                // it will contain the row index of the element to push in vector
    int colIndex=0;                                // it will contain the column index of the element to push in vector
    
    int iterationCount = 0;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            
            v.push_back(matrix[rowIndex][colIndex]);
            iterationCount++;
            
            if(rowIndex==minRowIndex && colIndex<maxColIndex){        // means that rectangle's first row is not fully traversed yet
                colIndex++;
            }
            else if(colIndex==maxColIndex && rowIndex<maxRowIndex){   // means that rectangle's last column is not fully traversed yet
                rowIndex++;
            }
            else if(rowIndex==maxRowIndex && colIndex>minColIndex){   // means that rectangles last row is not fully traversed yet
                colIndex--;
            }
            else if(colIndex==minColIndex && rowIndex>minRowIndex){   // means that rectangles first column is not fully traversed yet
                rowIndex--;
            }
            
            
            if(iterationCount==((maxColIndex-minColIndex+1)*2)+((maxRowIndex-minRowIndex-2+1)*2)){  // whtn the outer rectangle is fully traversed then update these values according the inner rectangle's boundaries
                minColIndex = minColIndex+1;
                minRowIndex = minRowIndex+1;
                maxRowIndex = maxRowIndex-1;
                maxColIndex = maxColIndex-1;
                colIndex = minColIndex;
                rowIndex = minRowIndex;
                iterationCount = 0;
            }
        }
    }
    
    return v;
}


int main(){
    int r = 4, c = 4;
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15,16}
    };

    vector<int> res = spirallyTraverse(matrix, r, c);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}