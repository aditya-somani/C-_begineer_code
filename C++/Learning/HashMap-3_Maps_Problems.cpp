/*

-1.Can you make the strings equal?
Given an array of strings. You can move any number of characters from one string to any other string any
number of times. You just have to make all of them equal.
Print “Yes” if you can make every string in the array equal by using any number of operations otherwise print
“No”.

->We will be making a map of char-frequency and cecking if my frequency is a multiple of my n(number of strings) or not
as it gives us the idea that for all strings to be equal atleast they should combined contain n or multiple of n characters that can be distributed. 

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool canMakeEqual(vector<string> &v){
    int n=v.size();
    unordered_map<char,int> na;
    for(auto str:v){
        for(auto c:str){
            na[c]++;
        }
    }
    for(auto ele:na){
        if((ele.second)%n!=0){
            return false;
        }
    }
    return true;
}

int main(){
    
    cout<<"Enter the size of string : ";
    int n;
    cin>>n;
    vector<string> v(n);
    cout<<"Enter the string : ";
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    canMakeEqual(v) ? cout<<"Yes":cout<<"No";
    return 0;
}

// Output:-
// Enter the size of string : 3
// Enter the string : wall wallah wallahah
// Yes

// Enter the size of string : 3
// Enter the string : college coll egecolle
// No

-Time compelexity:- O(N) where N-> no. of all characters
-Space compelexity :- O(N) ehre N-> no. of unique characters


-2.Check whether two Strings are anagram of each other. Return true if they are else return false.
An anagram of a string is another string that contains the same characters, only the order of characters can
be different. For example, “abcd” and “dabc” are an anagram of each other.

*/







