// Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to 
// both the lists and return the list in sorted order. Duplicates may be there in the output list.

// Example1:
// Input:
// n = 5
// v1[] = {3, 4, 2, 2, 4}
// m = 4
// v2[] = {3, 2, 2, 7}
// Output:
// 2 2 3



#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;



void printVector(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


vector<int> commonElements(vector<int>v1,vector<int>v2){
    
    vector<int> v;                // it will contain common elements present in both the vectors
    unordered_map<int, int> mp;   // it will contain all the elemets of vector v1 as key their count as value

    for(int i=0; i<v1.size(); i++){
        mp[v1[i]]++;
    }

    for(int j=0; j<v2.size(); j++){

        auto it = mp.find(v2[j]);   // checking element is present in map

        if(it!=mp.end()){           // means element is present 
            v.push_back(it->first); // bcz v2[j] is present in v1(mp), hence pushing it into our vector
            if(it->second>1){       // if this element is present more than one in v1, then decrementing(removing first occurrence) that value bcz the same element should not be compared with other elements of v2
                mp[v2[j]]--;
            }
            else{                    // else removing the element from mp(v1), bcz the same element should not be compared with the other elements of v2
                mp.erase(it);
            }
        }
    }

    sort(v.begin(), v.end());        // sorting the final list of common elements
    
    return v;
    
}

int main(){
    vector<int> v1 = {3, 4, 2, 2, 4};
    vector<int> v2 = {3, 2, 2, 7};

    vector<int> comEls = commonElements(v1, v2);
    printVector(comEls);

    return 0;
}