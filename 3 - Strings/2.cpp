// Write	a	program	to	count	the	number	of	occurrences	of	each	character	
// in	the	string	and	print	it.	

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    string name = "Umair Saleem";
    unordered_map<char,int> mp;            // it will store the character and its count in string

    for(int i=0; i<name.length(); i++){    // looping over string 
        if(name[i]==' '){                  // if character is a space then skip it
            continue;
        }
        if(name[i]>64 && name[i]<91){      // if character is a uppercase alphabet then convert it to lowercase and then add to map
            mp[name[i]+32]++;
        }
        else{                              // else if character is a lowercase or special character then simpley add it as it is
            mp[name[i]]++;
        }
    }

    for(auto it:mp){
        cout<<it.first<<" occurres "<<it.second<<" times in the string"<<endl;
    }
    return 0;
}