/*

Print the following pattern
Take the no of rows from the user

A A A
B B B   For n=3
C C C

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=0;
    while(i<n){
        int j=0;
        while(j<n){
            cout<<(char)(65+i)<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}