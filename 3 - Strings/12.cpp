#include <iostream> 
#include <unordered_map>
using namespace std;

int longestRepeatingSubsequence(string str){
    unordered_map<string, int> mp;

    for(int i=0; i<str.length(); i++){
        string s = "";
        for(int j=i; j<str.length(); j++){
            s = s + str[j];
            mp[s]++;
        }
    }

    int longestLen = 0;
    for(auto it:mp){
        cout<<"First "<< it.first << "Second: "<< it.second<<endl;
        if(it.second>1 && it.first.length()>longestLen){
            longestLen = it.first.length();
        }
    }

    return longestLen;

}

int main(){
    string str = "axxxy";
    cout<< longestRepeatingSubsequence(str)<<endl;
    return 0;
}