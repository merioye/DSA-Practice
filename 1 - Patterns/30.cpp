/*

Print the following pattern
Take the no of rows from the user

      *
    *   *
  *       *
*           *            For n=4
*           *
  *       *
    *   *
      *


*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=1, spaces=n-1;
    while(i<=n*2){
        int j=1;
        while(j<n*2){
            if(j==(spaces+1) || j==(((n*2)-1)-spaces)){
                cout<<"*"<<" ";
            }
            else{
                cout<<" "<<" ";
            }
            j++;
        }
        cout<<endl;
        if(i==n){
            spaces = 0;
        }
        else if(i<n){
            spaces--;
        }
        else{
            spaces++;
        }
        i++;
    }
    return 0;
}