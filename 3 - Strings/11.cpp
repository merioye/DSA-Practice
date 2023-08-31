#include<iostream>
#include<algorithm>
using namespace std;

// bool checkPalindrom(string s, int start, int end){
//     while(start<end){
//         if(s[start]==s[end]){
//             start++;
//             end--;
//         }
//         else{
//             return false;
//         }
//     }
//     return true;
// }

// // Time complexity is O(n2logn)
// string longestPalin(string str){
//     string longestPalindromicSubstring = "";
//     for(int i=0; i<str.length(); i++){
//         string s = "";
//         for(int j=i; j<str.length(); j++){
//             s = s + str[j];

//             bool isPalindrom = checkPalindrom(s, 0, s.length()-1);
//             if(isPalindrom && s.length()>longestPalindromicSubstring.length()){
//                 longestPalindromicSubstring = s;
//             }
//         }
//     }
//     return longestPalindromicSubstring;
// }



// It returns the length of palindromic substring
// It starts matching the letters from center by expanding letters around it
// It keeps on matching center's left and right letter
int expand_around_center(string str, int centerLeftIndex, int centerRightIndex){
    while(centerLeftIndex>=0 && centerRightIndex<str.length()){
        if(str[centerLeftIndex]!=str[centerRightIndex]){
            break;
        }
        centerLeftIndex--;
        centerRightIndex++;
    }
    return centerRightIndex-centerLeftIndex-1;
}

// Time complexity is O(n2)
string longestPalin(string str){
    if(str.length()<1){
        return "";
    }

    if(str.length()==1){
        return str;
    }

    int start = 0; // starting index of the longest palindromic substring
    int end = 0;   // ending index of the longest palindromic substring

    for(int i=0; i<str.length(); i++){
        int lenForEven = expand_around_center(str, i, i+1); // Length for two letters center
        int lenForOdd = expand_around_center(str, i, i);    // Length for single letter center
        int maxLength = max(lenForEven,lenForOdd);

        int prevLongestPalinLength = end-start +1;
        
        if(maxLength>prevLongestPalinLength){
            start = i - (maxLength-1)/2;
            end = i + maxLength/2;
        }
    }
    return str.substr(start, end-start+1);
}

int main(){
    string s = "aabb";
    cout<<longestPalin(s)<<endl;
    return 0;
}