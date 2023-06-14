/*

Print the following pattern
Take the no of rows from the user

9 8 7
6 5 4  For n=3
3 2 1

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
            cout<<(n*n)-j<<" ";
            k++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}