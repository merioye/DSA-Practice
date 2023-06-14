#include<iostream>
using namespace std;

bool checkPalindrom(string s, int start, int end){
    while(start<end){
        if(s[start]==s[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}

// Time complexity is O(n2logn)
string longestPalin(string str){
    string longestPalindromicSubstring = "";
    for(int i=0; i<str.length(); i++){
        string s = "";
        for(int j=i; j<str.length(); j++){
            s = s + str[j];

            bool isPalindrom = checkPalindrom(s, 0, s.length()-1);
            if(isPalindrom && s.length()>longestPalindromicSubstring.length()){
                longestPalindromicSubstring = s;
            }
        }
    }
    return longestPalindromicSubstring;
}

int main(){
    string s = "aaaabbaa";
    cout<<longestPalin(s)<<endl;
    return 0;
}