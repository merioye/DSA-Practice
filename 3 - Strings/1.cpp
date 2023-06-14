// Write a	basic program to take input(String)	from User and just print it.	

#include<iostream>
using namespace std;

int main(){
    string name;
    cout<<"Enter your name: ";
    getline(cin, name);

    cout<<"Your name is "<<name<<endl;

    return 0;
}

