/*

Print the following pattern
Take the no of rows from the user

A B C
D E F   For n=3
G H I

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=0, j=0;
    while(i<n){
        int k=0;
        while(k<n){
            cout<<(char)(65+j)<<" ";
            k++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}