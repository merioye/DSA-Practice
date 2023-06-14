// Find the minimum and maximum element in an array
// Sample Input:   5
//                 1 2 3 4 5
// Sample Output:  Max: 5
//                 Min: 1


#include<iostream>
using namespace std;


int min(int arr[], int size){
    int minimum = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]<minimum){
            minimum = arr[i];
        }
    }
    return minimum;
}

int max(int arr[], int size){
    int maximum = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]>maximum){
            maximum = arr[i];
        }
    }
    return maximum;
}


int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size] = {};
    for(int i=0; i<size; i++){
        cout<<"Enter element of array: ";
        cin>>arr[i];
    }
    
    cout<<"Min: "<<min(arr, size)<<endl;
    cout<<"Max: "<<max(arr, size)<<endl;
    return 0;
}