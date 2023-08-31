// Find binary of a decimal number

#include<iostream>
using namespace std;

void printBinary(int n){
    if(n==1){
        cout<<'1';
        return;
    }
    if(n==0){
        cout<<'0';
        return;
    }

    printBinary(n/2);
    cout<<n%2;
}

int main(){
    int decimal = 45;
    printBinary(decimal);
    cout<<endl;
    return 0;
}