// Find minimum and maximum element in array

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> findMinMax(int arr[], int n, int min, int max){
    if(n==0){
        vector<int> v = {min, max};
        return v; 
    }

    int arrayLastItem = arr[n-1];
    if(max < arrayLastItem){
        max = arrayLastItem;
    }   
    if(min > arrayLastItem){
        min = arrayLastItem;
    }

    return findMinMax(arr, n-1, min, max);
}
int main(){
    int arr[] = {3,5,22,4,2,11,-1,34};
    int n = 8, min = INT_MAX, max = INT_MIN;

    vector<int> res = findMinMax(arr, n, min, max);
    cout<<"Min is "<<res[0]<<" and Max is "<<res[1]<<endl;
    return 0;
}