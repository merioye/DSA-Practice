// Find GCD of two numbers

#include<iostream>
using namespace std;

int findGCD(int no1, int no2){
    if(no1==0){
        return no2;
    }
    if(no2==0){
        return no1;
    }

    if(no1>no2){
        return findGCD(no1%no2,no2);
    }
    else{
        return findGCD(no1,no2%no1);
    }
}

int main(){
    cout<<"GCD(15,8) = "<< findGCD(15,8)<<endl;
    return 0;
}