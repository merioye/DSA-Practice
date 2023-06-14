/*

Print the following pattern
Take the no of rows from the user
And print that no of rows and colums with stars

****
****      For n=4
****
****

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=0,j=0;
    while(i<n){
        while(j<n){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
        j=0;
    }
    return 0;
}