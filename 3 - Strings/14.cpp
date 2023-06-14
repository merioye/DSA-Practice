// Given a string, Find the 1st repeated word in a string

// Examples: 
// Input : "Ravi had been saying that he had been there"
// Output : had
// Input : "Ravi had been saying that"
// Output : No Repetition
// Input : "he had had he"
// Output : he

#include<iostream>
#include<unordered_map>
using namespace std;

string firstRepeatedWord(string s){
    unordered_map<string,int> wordsCount;                               // it will store the word as key and its count as value of each unique word present in the string

    int firstLetterIndex = 0;                                           // Index of first character of the word
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){                                                  // Checking if the character is a space (means the word is completed)
            string word = s.substr(firstLetterIndex,i-firstLetterIndex); // Getting the word value by suplying word's starting index and last index
            wordsCount[word]++;                                         // incrementing word count in map
            firstLetterIndex = i+1;                                     // moving the next index so that it points at the first index of next word

            if(mp[word]>1){                                             // checking if the word count is greater than 1 in map to find first repeated word
                return word;
            }
        }
    }
    return "No Repetition";
}

int main(){
    string res = firstRepeatedWord("Ravi had been saying that");
    cout<<res<<endl;
    return 0;
}