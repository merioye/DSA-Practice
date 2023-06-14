// Given two strings s1 and s2. The task is to check if s2 is a rotated version of the string 
// s1. The characters in the strings are in lowercase.

// Example 1:

// Input:
// geeksforgeeks
// forgeeksgeeks
// Output: 
// 1
// Explanation: s1 is geeksforgeeks, s2 is
// forgeeksgeeks. Clearly, s2 is a rotated
// version of s1 as s2 can be obtained by
// left-rotating s1 by 5 units.
 

// Example 2:

// Input:
// mightandmagic
// andmagicmigth
// Output: 
// 0
// Explanation: Here with any amount of
// rotation s2 can't be obtained by s1.

#include<iostream>
using namespace std;

bool areRotations(string s1,string s2)
{
    if(s1.length()!=s2.length()){           // if s1's length is not equal to s2's lenght means s2 does not have exact same characters hence s2 is not a rotation of s1(for rotation both strings should contain same characters but their order is not same)
        return false;
    }
    
    int s1Index = 0;                        // it will contain the index of character in s1 string from which s1 string is rotated(e.g s1=geeksfor and s2=forgeeks in thich case the s1 string is rotated from 'f' character hence it will contain 5) if string is correctly rotated else if string is not correctly rotated it will contain zero
    
    for(int i=0; i<s2.length(); i++){       // iterating over string s2 to find the index of character in s1 string from which s1 string is rotated
        
        if(s2[i]==s1[s1Index]){             // if the s2's character is equal to s1's character at s1Index means rotated string could start from this index, after that increment the value of s1Index to check for next character in s1 string
            s1Index++;
        }
        else{                               // else if s2's character is not equal to s1's character at s1Index                    
            if(s2[i]==s1[0]){               // if s2's current character is eual to s1's first character means rotated string could start from this hence set s1Index to  1 check for next character in s1
                s1Index = 1;
            }
            else{                           // else since the character is not equal and the character is not equal to first character of s1 means this was not a rotated string hence setting s1Index to 0 to check again for rotated string in remainign s2 string
                s1Index = 0;
            }
        }
    }
    
    if(s1Index==0){                         // if s1Index is equal to zero means there was no correct rotated string found in s1 hence return false(bcz if rotated string founds then s1Index will contain the the index of chracter from which s1 string is rotated not 0)
        return false;
    }
    
    int s2Index = 0;                        // bcz we found that s1 string is rotated at index s1Index, so we also need to check that the rotated string part of s1 string is present at the start of s2 string or not to completely verify that s2 is a rotated string of s1 or not

    for(int j=s1Index; j<s1.length(); j++){ // iterating over s1's rotated string part
        
        if(s1[j]!=s2[s2Index]){             // if at any point the s2's starting string is not equal to s1's rotated part of string means that s2 is not correctly rotated version of s1 hence return false
            return false;
        }
        else{                               // else means this current characters are same then check next character of s2 string with next character of s1's rotated string part
            s2Index++;
        }
    }
    
    return true;                            // if control reaches at this statement means all the characters in s1's rotated part is correctly present in s2's starting hence s2 is a correctly rotated version of s1
}

int main(){
    string s1 = "geeksforgeeks", s2 = "forgeeksgeeks";
    bool res = areRotations(s1, s2);
    cout<<res<<endl;
    return 0;
}