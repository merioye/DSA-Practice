// Implement Linear search using recursion

#include<iostream>
using namespace std;

bool linearSearch(int arr[], int lastElemIndex, int elemToFind){

    if(lastElemIndex<0){
        return false;
    }

    if(arr[lastElemIndex]==elemToFind){
        return true;
    }

    linearSearch(arr, lastElemIndex-1, elemToFind);
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = 6, elemtoFind=5;
    bool isPresent = linearSearch(arr, n-1, elemtoFind);
    if(isPresent){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }
    return 0;
}