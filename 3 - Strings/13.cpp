// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] 
// are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' 
// for exp = [(]).
// Note: The drive code prints "balanced" if function return true, otherwise it prints 
// "not balanced".

// Example 1:
// Input:
// {([])}
// Output: 
// true
// Explanation: 
// { ( [ ] ) }. Same colored brackets can form 
// balanced pairs, with 0 number of 
// unbalanced bracket.

// Example 2:
// Input: 
// ()
// Output: 
// true
// Explanation: 
// (). Same bracket can form balanced pairs, 
// and here only 1 type of bracket is 
// present and in balanced way.


#include<iostream>
#include<vector>
using namespace std;

bool isBalanced(string s){
    vector<char> openedBrackets;                                // it will conta

    for(int i=0; i<s.length(); i++){
        int bracket = s[i];

        if(bracket=='(' || bracket=='{' || bracket=='['){
            openedBrackets.push_back(s[i]);
        }
        else{
            if(openedBrackets.empty()){
                return false;
            }

            char lastOpenedBracket = openedBrackets[openedBrackets.size()-1];

            if(bracket==')'){
                if(lastOpenedBracket=='('){
                    openedBrackets.pop_back();
                }
                else{
                    return false;
                }
            }
            else if(bracket=='}'){
                if(lastOpenedBracket=='{'){
                    openedBrackets.pop_back();
                }
                else{
                    return false;
                }
            }
            else if(bracket==']'){
                if(lastOpenedBracket=='['){
                    openedBrackets.pop_back();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(openedBrackets.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    bool res = isBalanced("[()]{}{[()()]()}");
    if(res){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}