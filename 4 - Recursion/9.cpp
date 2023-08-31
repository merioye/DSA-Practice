// Reverse	a	string	using	recursion

#include<iostream>
using namespace std;

void reverse(string& s, int start, int end){
    if(start>end){
        return;
    }

    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;

    reverse(s, start+1, end-1);
}

int main(){
    string s = "helloworld";
    reverse(s, 0, s.length()-1);
    cout<<"Reversed string is "<< s<<endl;
    return 0;
}