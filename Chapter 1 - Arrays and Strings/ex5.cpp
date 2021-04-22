#include <bits/stdc++.h>

using namespace std;

//Time O(n), space O(1)
int countDifferentChars(string s1, string s2){
    int differentCharacters = 0;

    for(int i = 0; i<s1.size(); i++){
        if(s1[i] != s2[i]) differentCharacters++;
    }

    return differentCharacters;
}

//Time O(n), space O(1)
bool isOneAddAway(string s1, string s2){
    if(s1.size() > s2.size()) swap(s1,s2);

    int firstMismatch = 0;
    while(firstMismatch<s1.size() && s1[firstMismatch]==s2[firstMismatch]) firstMismatch++;

    for(int i = firstMismatch; i<s1.size();i++){
        if(s1[i] != s2[i+1]) return false;
    }

    return true;
}

//Time O(n), space O(1)
bool isOneEditAway(string s1, string s2){
    if(s1.size()==s2.size()){
        return (countDifferentChars(s1,s2) <= 1);
    }

    //being "one remove away" or "one add away" is the same thing.
    if(s2.size() == s1.size()-1 || s1.size() == s2.size()-1){
        return isOneAddAway(s1,s2);
    }

    return false;
}

int main(){
    cout << isOneEditAway("batata","batata") << endl;
    cout << isOneEditAway("batata","btata") << endl;
    cout << isOneEditAway("batata","batrsa") << endl;
    cout << isOneEditAway("batataa","batrsa") << endl;
    cout << isOneEditAway("batata","batataaa") << endl << endl;;

    return 0;
}