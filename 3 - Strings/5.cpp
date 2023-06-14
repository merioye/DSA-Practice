// Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other.

// Example 1:

// Input:a = geeksforgeeks, b = forgeeksgeeks
// Output: YES
// Explanation: Both the string have same characters with
//         same frequency. So, both are anagrams.
// Example 2:

// Input:a = allergy, b = allergic
// Output: NO
// Explanation: Characters in both the strings are 
//         not same, so they are not anagrams.


#include<iostream>
#include<unordered_map>
using namespace std;

bool checkAnagram(string a, string b){

    bool isAnagram = true;                    // by default setting isAnagram true
    unordered_map<char,int> mp;               // map that will store each distinct character of string 'a' as key and value as its count in string 'a'

    for(int i=0; i<a.length(); i++){          // storing each character of string 'a' with its count in map
        mp[a[i]]++;
    }  

    for(int j=0; j<b.length(); j++){           // looping over string b

        if(mp[b[j]]){                          // if element is present in map then execute the block

            mp[b[j]]--;                        // bcz one character is matched, after that we will look for next character of string b, so decrement the count of this particular character in map

            if(mp[b[j]]==0){                   // if the count of this particular character has become zero in map then erase it from the map so that next time if the same character is not present in map means b has more count of this character, hence b and a are not anagram
                mp.erase(b[j]);
            }
        }
        else{                                   // else means this character is not present in map(string a), hence the strings b and a are not anagram
            isAnagram = false;
            break;
        }
    } 

    return isAnagram;             
}

int main(){
    string a = "geeksforgeeks", b = "forgeeksgeeks";
    bool res = checkAnagram(a,b);
    cout<<res<<endl;
    return 0;
}