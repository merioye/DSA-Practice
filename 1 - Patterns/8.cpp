/*

Print the following pattern
Take the no of rows from the user

1
2 2
3 3 3    For n=4
4 4 4 4

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
        while(j<i){
            cout<<i<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}