/*

Print the following pattern
Take the no of rows from the user

        * * * * *
      * * * * *
    * * * * *          For n=5
  * * * * *
* * * * *        


*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=1, spaces=n-1;
    while(i<=n){
        int j=1, starsCount=0;
        while(j<=((n*2)-1)){
            if(starsCount==n){
                cout<<" "<<" ";
            }
            else{
                if(j<=spaces){
                    cout<<" "<<" ";
                }
                else{
                    cout<<"*"<<" ";
                    starsCount++;
                }
            }
            j++;
        }
        cout<<endl;
        i++;
        spaces--;
    }
    return 0;
}