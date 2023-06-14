/*

Print the following pattern
Take the no of rows from the user

D
C D
B C D    For n=4
A B C D

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=0;
    while(i<n){
        int j=(n-i)-1;
        while(j<n){
            cout<<(char)(65+j)<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}