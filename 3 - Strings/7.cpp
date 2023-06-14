// Given a string consisting of lowercase english alphabets. Find the repeated character present first in the string.

// Example 1:

// Input:
// S = "geeksforgeeks"
// Output: g
// Explanation: g, e, k and s are the repeating
// characters. Out of these, g occurs first. 
// Example 2:

// Input: 
// S = "abcde"
// Output: -1
// Explanation: No repeating character present.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function 
// firstRep() which takes the string S as input and returns the the first repeating character 
// in the string. In case there's no repeating character present, return '#'.

#include<iostream>
#include<unordered_map>
using namespace std;

char firstRep(string s){

    unordered_map<char,int> mp;             // map to store string characters as key and their count as value

    for(int i=0; i<s.length(); i++){        // inserting value in map
        mp[s[i]]++;
    }

    for(int i=0; i<s.length(); i++){        // looping over the string again to check first repeated character
        if(mp[s[i]]>1){                     // if the element has count greater than 1 means it is the first repeated character in string
            return s[i];
        }
    }

    return '#';                             // if in above loop no character has count greater than 1 means no there is no repeated element in string then return #
}

int main(){
    string str = "geeksforgeeks";
    char res = firstRep(str);
    cout<<res<<endl;
    return 0;
}