// Find nth fibonacci number

#include<iostream>
using namespace std;

int findFibNo(int nth){
    if(nth==1){
        return 0;
    }
    if(nth==2 || nth==3){
        return 1;
    }

    return findFibNo(nth-1) + findFibNo(nth-2);
}

int main(){
    // print first 8 fibonacci numbers
    for(int i=1; i<=8; i++){
        cout<<findFibNo(i)<<" ";
    }
    cout<<endl;
    return 0;
}