// Given a string Str which may contains lowercase and uppercase chracters. The task is to remove all duplicate characters from the string and find the resultant string. The order of remaining characters in the output should be same as in the original string.

// Example 1:

// Input:
// Str = geeksforgeeks
// Output: geksfor
// Explanation: After removing duplicate
// characters such as e, k, g, s, we have
// string as "geksfor".
// Example 2:

// Input:
// Str = HappyNewYear
// Output: HapyNewYr
// Explanation: After removing duplicate
// characters such as p, e, a, we have
// string as "HapyNewYr".

#include<iostream>
#include<unordered_set>
using namespace std;

string removeDuplicates(string str) {

    unordered_set<char> s;                      // set to store characters of string
    string newString = "";

    for(int i=0; i<str.length(); i++){          // iterating over string to insert character into set and update value of newString
        if(!s.count(str[i])){                   // if count is 0 then only insert value in set and also append to newString(bcz if count is greater than 0 means the character already present in set and it is a duplicate character means it is already appended to newString so simply skip it)
            s.insert(str[i]);
            newString = newString + str[i];
        }

    }

    return newString;
}

int main(){
    string str = "geeksforgeeks";
    string res = removeDuplicates(str);
    cout<<res<<endl;
    return 0;
}