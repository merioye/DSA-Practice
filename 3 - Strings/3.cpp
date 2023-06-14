// Write	a	program	to	remove	all	whitespaces	in	a	given	string.	
// Example
// input: geeks for geeks
// output: geeksforgeeks


#include<iostream>
using namespace std;

string modifyString(string s){
    string newString = "";
    for(int i=0; i<s.length(); i++){
        if(s[i]==32){                      // if character is a space then skip it
            continue;
        }
        newString = newString+s[i];        // else concat it to resultant string
    }
    return newString;
}
int main(){
    string str = "geeks for geeks";
    string res = modifyString(str);
    cout<<res<<endl;
    return 0;
}