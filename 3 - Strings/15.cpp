// Given a string, we have to find out all its subsequences of it. A String is a 
// subsequence of a given String, that is generated by deleting some character of a 
// given string without changing its order.
// Examples: 
// Input : abc
// Output : a, b, c, ab, bc, ac, abc
// Input : aaa
// Output : a, a, a, aa, aa, aa, aaa

#include<iostream>
#include<vector>
using namespace std;

void printSubsequences(string s){
    vector<string> subsequences;

    for(int i=1; i<=s.length(); i++){
        string subsequence = "";
        for(int j=0; j<s.length(); j++){
            if(j==)
            if(subsequence.length()<i){
                subsequence = subsequence + s[j];
            }

            if(subsequence.length()==i){
                subsequences.push_back(subsequence);
            }
        }
    }
}

int main(){
    return 0;
}