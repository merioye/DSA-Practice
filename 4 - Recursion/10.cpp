// Check	if	a	number	is	Palindrome	or	not

#include<iostream>
using namespace std;

bool checkPalindrome(string& s, int start, int end){
    if(start>end){
        return true;
    }

    if(s[start]!=s[end]){
        return false;
    }

    checkPalindrome(s, start+1, end-1);
}

int main(){
    string s = "noon";
    bool res = checkPalindrome(s, 0, s.length()-1);
    cout<<"IsPalindrome: "<<res<<endl;
    return 0;
}