/*

Print the following pattern
Take the no of rows from the user

* * * *
*     *
*     *     For n=5
*     *
* * * *


*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=4){
            if(i==1 || i==n){
                cout<<"*"<<" ";
            }
            else{
                if(j==1 || j==4){
                    cout<<"*"<<" ";
                }
                else{
                    cout<<" "<<" ";
                }
            }
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}