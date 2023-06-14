/*

Print the following pattern
Take the no of rows from the user

1 2 3
4 5 6  For n=3
7 8 9

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=0, j=1;
    while(i<n){
        int k=0;
        while(k<n){
            cout<<j<<" ";
            k++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}