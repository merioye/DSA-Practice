/*

Print the following pattern
Take the no of rows from the user

* * * *
* * *      For n=4
* * 
*


*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=0;
    while(i<n){
        int k=i;
        while(k<n){
            cout<<"*"<<" ";
            k++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}