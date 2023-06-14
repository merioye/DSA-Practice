/*

Print the following pattern
Take the no of rows from the user

1 1 1
2 2 2    For n=3
3 3 3

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=0;
        while(j<n){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}