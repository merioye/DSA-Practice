// Given a string S, check if it is palindrome or not.

// Example 1:

// Input: S = "abba"
// Output: 1
// Explanation: S is a palindrome
// Example 2:

// Input: S = "abc" 
// Output: 0
// Explanation: S is not a palindrome

#include<iostream>
using namespace std;

bool isPalindrome(string s){
    int i=0, j=s.length()-1;
    while(i<j){
        if(s[i]==s[j]){                 // if the nth first and nth last characters are same measn the string is so far palindrome
            i++;
            j--;
        }
        else{                           // else if at any point the nth first and nth last character are not same means the string is not palindrome
            return false;
        }
    }
    return true;
}
int main(){
    string str = "aba";
    bool res = isPalindrome(str);
    cout<<res<<endl;
    return 0;
}