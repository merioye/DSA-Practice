// Given an number n. Find the number of occurrences of n in the array.
// Sample Input: 3
//               11
//               1 2 3 3 3 3 5 3 4 5 3
// Sample Output: 6
// Here n = 3 in the sample input , 11 is size of array and occurrence of 3 is 6 times in the given array


#include<iostream>
using namespace std;


int noOfOcc(int arr[], int size, int n){
    int noOfOcc = 0;
    for(int i=0; i<size; i++){
        if(arr[i]==n){
            noOfOcc++;
        }
    }
    return noOfOcc;
}

int main(){
    int size, n;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++){
        cout<<"Enter element of array: ";
        cin>>arr[i];
    }
    cout<<"Enter the no fo which occurrences to find: ";
    cin>>n;

    int res = noOfOcc(arr, size, n);
    cout<<n<<" is "<<res<<" times present in the array"<<endl;
    return 0;
}