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
    vector<char> openedBrackets;                                

    for(int i=0; i<s.length(); i++){
        int bracket = s[i];

        if(bracket=='(' || bracket=='{' || bracket=='['){
            openedBrackets.push_back(s[i]);
        }
        else{                                  // if the bracket is either ),},]
            if(openedBrackets.empty()){        // since the current bracket is ) | } | ] and if the openedBrackets array is empty means there is no opening bracket present, hence the string is not balanced              
                return false;
            }

            char lastOpenedBracket = openedBrackets[openedBrackets.size()-1];

            if(bracket==')'){
                if(lastOpenedBracket=='('){     // if last opened bracket is same as this current closing bracket means it is correct, hence remove it and then look for its previously opened bracket
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

    if(openedBrackets.empty()){         // if there is still any opned bracket present means the its corresponding closing bracket is not found, hence the string is not balanced
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