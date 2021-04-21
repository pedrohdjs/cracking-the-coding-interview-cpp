#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

//O(n) time, O(n) space
bool checkPermutation1(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    unordered_map<char, int> s1Count;
    unordered_map<char,int> s2Count;

    for(char c : s1) s1Count[c]++;
    for(char c : s2) s2Count[c]++;

    for(auto it = s1Count.begin(); it != s1Count.end(); it++){
        if(s2Count[it->first] != it->second) return false;
    }

    return true;
}

//O(n) time, O(n) space (half the space used in comparison to solution 1)
bool checkPermutation2(string s1, string s2){
    if(s1.size() != s2.size()) return false;
    unordered_map<char, int> s1Count;

    for(char c : s1) s1Count[c]++;

    for(char c : s2){
        s1Count[c]--;
        if (s1Count[c] < 0) return false;
    }

    return true;
}


int main(){
    cout << checkPermutation1("batata","barata") << endl;
    cout << checkPermutation2("batata","barata") << endl;


    cout << checkPermutation1("abcd","cdba") << endl;
    cout << checkPermutation2("abcd","cdba") << endl;


    cout << checkPermutation1("asdasdasd","dsadsadsa") << endl;
    cout << checkPermutation2("asdasdasd","dsadsadsa") << endl;


    cout << checkPermutation1("batataa","batata") << endl;
    cout << checkPermutation2("batataa","batata") << endl;

    return 0;
}