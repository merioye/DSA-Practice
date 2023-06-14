/*

Print the following pattern
Take the no of rows from the user

A
B C    For n=4
D E F
G H I J

*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=1,j=0;
    while(i<=n){
        int k=0;
        while(k<i){
            cout<<(char)(65+j)<<" ";
            k++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}