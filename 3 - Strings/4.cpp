// Write	a	program	to	reverse	the	string	in	place.	
// Example 1:

// Input:
// s = Geeks
// Output: skeeG
// Example 2:

// Input:
// s = for
// Output: rof

#include<iostream>
using namespace std;

string reverseStr(string s){
    int i=0, j=s.length()-1;
    while(i<j){                            // Untill the i<j replace the value at s's ith index with s's jth index
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return s;
}
int main(){
    string str = "Geeks";
    string res = reverseStr(str);
    cout<<res<<endl;
    return 0;
}