/*

Print the following pattern
Take the no of rows from the user

1 1 1 1
  2 2 2      For n=4
    3 3
      4


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
        while(j<=n){
            if(j<i){
                cout<<" "<<" ";
            }
            else{
                cout<<i<<" ";
            }
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}