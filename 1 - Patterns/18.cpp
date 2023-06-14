/*

Print the following pattern
Take the no of rows from the user

A
B C    For n=4
C D E
D E F G

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
        while(j<=i){
            cout<<(char)(65+i+j)<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}