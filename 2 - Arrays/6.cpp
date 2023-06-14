// Check whether n is present in an array of size m or not.
// Input - n,m (Input number, size of array)
// - Take input n elements for the array
// Output -> true/false


#include<iostream>
using namespace std;


bool searchNo(int arr[], int size, int no){
    int start, end, mid;
    while(start<=end){
        mid = start + (end-start)/2;

        if(arr[mid]==no){
            return true;
        }
        if(arr[mid>no]){
            end = mid-1;
        }
        if(arr[mid]<no){
            start = mid+1;
        }
    }
    return false;
}

void sort(int arr[], int size){
    int temp, j;
    for(int i=1; i<size; i++){
        temp = arr[i];
        for(int j=i-1; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main(){
    int n, m;
    cout<<"Enter size of array: ";
    cin>>m;

    int arr[m];
    for(int i=0; i<m; i++){
        cout<<"Enter element of array: ";
        cin>>arr[i];
    }

    cout<<"Enter no to find in the array: ";
    cin>>n;

    sort(arr, m);
    int res = searchNo(arr, m, n);
    cout<<res<<endl;
    return 0;
}