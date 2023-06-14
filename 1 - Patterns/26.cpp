/*

Print the following pattern
Take the no of rows from the user

      1
    1 2 1
  1 2 3 2 1       For n=4
1 2 3 4 3 2 1


*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=1, right=0;
    while(i<=n){
        int j=1, spaces=n-i;
        while(j<=(((n-1)+(n-1))+1)){
            if(j==n){
                cout<<i<<" ";
            }
            else if(j<n){
                if(j<=spaces){
                    cout<<" "<<" ";
                }
                else{
                    cout<<(j-spaces)<<" ";
                }
            }
            else if(j>n){
                if(j>=(n+i)){
                    cout<<" "<<" ";
                }
                else{
                    cout<<right<<" ";
                    right--;
                }
            }
            j++;
        }
        cout<<endl;
        right = i;
        i++;
    }
    return 0;
}