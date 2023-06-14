/*

Print the following pattern
Take the no of rows from the user

1
0 1
1 0 1      For n=5
0 1 0 1
1 0 1 0 1


*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of rows: ";
    cin>>n;

    int i=1, toPrint=1, startingNo=1;
    while(i<=n){
        int j=0;
        while(j<i){
            cout<<toPrint<<" ";
            if(toPrint==0){
                toPrint = 1;
            }
            else{
                toPrint = 0;
            }
            j++;
        }
        cout<<endl;
        if(startingNo==1){
            startingNo = 0;
            toPrint = 0;
        }
        else{
            startingNo = 1;
            toPrint = 1;
        }
        i++;
    }
    return 0;
}