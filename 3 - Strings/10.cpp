// Given a String. Reverse each word in it where the words are separated by dots.

// Example 1:

// Input:
// S = "i.like.this.program.very.much"
// Output: 
// i.ekil.siht.margorp.yrev.hcum
// Explanation: 
// The words are reversed as
// follows:"i" -> "i","like"->"ekil",
// "this"->"siht","program" -> "margorp",
// "very" -> "yrev","much" -> "hcum".
// Example 2:

// Input: 
// S = "pqr.mno"
// Output: 
// rqp.onm
// Explanation: 
// The words are reversed as
// follows:"pqr" -> "rqp" ,
// "mno" -> "onm"


#include<iostream>
using namespace std;

string reverseWords (string s)
{
    
    int wordStartingIndex = 0;                      // it will contain starting index of the word to reverse
    
    for(int i=0; i<s.length(); i++){                // iterating over the string
        
        if(s[i]=='.' || i==s.length()-1){           // if the character is '.' OR the last character of the string means the word has ended we need to reverse that word
            
            int wordEndingIndex;                    // it will contain ending index of the word to reverse
            
            if(i==s.length()-1 && s[i]!='.'){       // if current character is last character of the string and not equal to '.' means this character is included in the word to be reversed so set wordEndingIndex to the index of the current character itself
                wordEndingIndex = i;
            }
            else{                                   // else means it is '.' hence word is ended but '.' will not be included in the word to be reversed so set wordEndingIndex to previous character's index
                wordEndingIndex = i-1;
            }
            
            while(wordStartingIndex<wordEndingIndex){           // loop to reverse the word in string by swapping the nth first and last characters of the string
                
                char temp = s[wordStartingIndex];               
                s[wordStartingIndex] = s[wordEndingIndex];
                s[wordEndingIndex] = temp;
                wordStartingIndex++;
                wordEndingIndex--;
                
            }
            
            wordStartingIndex = i+1;                            // setting starting index of next word to be reversed
        }
    }
    
    return s;                                                   // returning reversed string
    
}

int main(){
    string s = "i.like.this.program.very.much";
    string res = reverseWords(s);
    cout<<res<<endl;
    return 0;
}