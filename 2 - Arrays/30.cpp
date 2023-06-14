// Given an unsorted array Arr of N positive and negative numbers. Your task is to create 
// an array of alternate positive and negative numbers without changing the relative order 
// of positive and negative numbers.
// Note: Array should start with a positive number.
// Example 1:

// Input: 
// N = 9
// Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
// Output:
// 9 -2 4 -1 5 -5 0 -3 2
// Explanation : Positive elements : 9,4,5,0,2
// Negative elements : -2,-1,-5,-3
// As we need to maintain the relative order of
// postive elements and negative elements we will pick
// each element from the positive and negative and will
// store them. If any of the positive and negative numbers
// are completed. we will continue with the remaining signed
// elements.The output is 9,-2,4,-1,5,-5,0,-3,2.



#include<iostream>
using namespace std;

void reArrangeArray(int arr[], int n){

    int noOfPositives = 0;                      // it will store number of positive elements present in the array
    int noOfNegatives = 0;                      // it will store number of positive elements present in the array

    // counting no of positive and negative elements
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            noOfNegatives++;
        }
        else{
            noOfPositives++;
        }
    }


    int positiveNumbers[noOfPositives] = {};         // it will contain all positive elements present in the array
    int negativeNumbers[noOfNegatives] = {};         // it will contain all positive elements present in the array
    int positiveIndex = 0;                           // it will contain the index of next position at which to push new positive number
    int negativeIndex = 0;                           // it will contain the index of next negative at which to push new negative number

    
    // pushing values to positive and negative arrays
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            negativeNumbers[negativeIndex] = arr[i];
            negativeIndex++;
        }
        else{
            positiveNumbers[positiveIndex] = arr[i];
            positiveIndex++;
        }
    }


    positiveIndex = 0;                              // resetting the value of positive index to 0 so that we start changing the elements in original array in the same order as were in original array
    negativeIndex = 0;                              // resetting the value of nagative index to 0 so that we start changing the elements in original array in the same order as were in original array


    for(int i=0; i<n; i++){
        if(noOfNegatives==0){                       // if noOfNegatives becomes zero means all negative elements have been added to original array then add positive remaining numbers to the end of array( since the all negative numbers have been added, the other remaining elements will be positives)
            arr[i] = positiveNumbers[positiveIndex];
            positiveIndex++;                        // incrementing postiveIndex so that next time next element is added to array
            noOfPositives--;                        // bcz one positive element has been added, so decrement noOfPositives to add in the array
            continue;                               // no need to check other conditions, bcz element has been added simply moves to next iteration
        }
        if(noOfPositives==0){                       // similarly if noOfPositives becomes zero means all positive elements have been added to original array then add remaining negative numbers to the end of array( since the all positive numbers have been added, the other remaining elements will be negatives)
            arr[i] = negativeNumbers[negativeIndex];
            negativeIndex++;                        // incrementing negativeIndex so that next time next element is added to array
            noOfNegatives--;                        // bcz one negative element has been added, so decrement noOfNegatives to add in the array
            continue;                               // no need to check other conditions, bcz element has been added simply moves to next iteration
        }

        if(i%2==0){                                 // if index is even then add positive no
            arr[i] = positiveNumbers[positiveIndex];
            positiveIndex++;                        // incrementing postiveIndex so that next time next element is added to array
            noOfPositives--;                        // bcz one positive element has been added, so decrement noOfPositives to add in the array
        }
        else{                                       // if index is even then add positive no
            arr[i] = negativeNumbers[negativeIndex];
            negativeIndex++;                        // incrementing negativeIndex so that next time next element is added to array
            noOfNegatives--;                        // bcz one negative element has been added, so decrement noOfNegatives to add in the array
        }
    }
}

int main(){
    int n = 9;
    int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};

    reArrangeArray(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}