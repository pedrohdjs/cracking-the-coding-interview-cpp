#include <bits/stdc++.h>

using namespace std;

//Instead of the method "isSubstring", on C++, we may use string::find.

//O(n) time, O(n) space (for the substring)
bool isRotation1(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    
    //Find the first occurence of s1's first character in s2
    int startingIndex = 0;
    while(startingIndex < s1.size() && s2[startingIndex] != s1[0]) startingIndex++;
    //If this never happens, we may return false.

    //Check if the substring from the begining of s2 up to when s1 "starts" in s2 is a substring of s1 (s1's final characters, actually)
    if(s1.find(s2.substr(0,startingIndex)) == string::npos) return false;

    //Check if from now on s2 matches the beggining of s1
    for(int i = startingIndex; i<s2.size(); i++){
        if(s1[i-startingIndex] != s2[i]) return false;
    }

    return true;
}

//O(n) time, O(n) space. Less verbose, about the same amound of opperations but slighly more complex logic, perhaps
bool isRotation2(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    //If s2 is included in a string formed by s1 repeated twice
    return (string(s1+s1).find(s2) != string::npos);
}


int main(){
    cout << isRotation1("waterbottle","erbottlewat") << endl;
    cout << isRotation1("waterbottle","frbottlewat") << endl;
    cout << isRotation1("waterbottle","frbottlepat") << endl;
    cout << isRotation1("waterbottle","erbottlewet") << endl;
    cout << isRotation1("waterbottle","frbottlewat") << endl;
    cout << isRotation1("Damartskheba","tskhebaDamar") << endl << endl;

    cout << isRotation2("waterbottle","erbottlewat") << endl;
    cout << isRotation2("waterbottle","frbottlewat") << endl;
    cout << isRotation2("waterbottle","frbottlepat") << endl;
    cout << isRotation2("waterbottle","erbottlewet") << endl;
    cout << isRotation2("waterbottle","frbottlewat") << endl;
    cout << isRotation2("Damartskheba","tskhebaDamar") << endl << endl;
    return 0;
}