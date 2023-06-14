/*

Print the following pattern
Take the no of rows from the user

1 2 3 4
1 2 3 4   For n=4
1 2 3 4
1 2 3 4

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
            cout<<n-j<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}