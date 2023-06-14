// Move all the negative elements to one side of the array
// Sample Input: 6
//               -1 -3 3 -4 21 91
// Sample Output: -1 -3 -4 3 21 91



#include<iostream>
#include<vector>
using namespace std;


// void arrangeElements(int arr[], int size){
//     int j, temp;
//     for(int i=0; i<size; i++){
//         if(arr[i]>=0){
//             continue;
//         }

//         temp = arr[i];
//         for(j=(i-1); j>=0; j--){
//             if(arr[j]>=0){
//                 arr[j+1] = arr[j];
//             }else{
//                 break;
//             }
//         }
//         arr[j+1] = temp;
//     }
// }


// Slightly better time complexity but less memory efficient
void arrangeElements(int arr[], int size){
    vector<int> negatives, positives;
    int index = 0;

    for(int i=0; i<size; i++){
        if(arr[i]<0){
            negatives.push_back(arr[i]);
        }
        else{
            positives.push_back(arr[i]);
        }
    }
    for(int j=0; j<negatives.size(); j++){
        arr[index] = negatives[j];
        index++;
    }
    for(int k=0; k<positives.size(); k++){
        arr[index] = positives[k];
        index++;
    }
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int size;
    cout<<"Enter size of the array: ";
    cin>>size;

    int arr[size];
    for(int i=0; i<size; i++){
        cout<<"Enter element of the array: ";
        cin>>arr[i];
    }

    arrangeElements(arr, size);
    printArray(arr, size);
    return 0;
}