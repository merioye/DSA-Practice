// Factorial of a number

#include<iostream>
using namespace std;


long factorial(int n){
    if(n==1){
        return 1;
    }

    return n * factorial(n-1);
}

int main(){
    long res = factorial(5);
    cout<<"5! => "<<res<<endl;
    return 0;
}