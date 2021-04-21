#include <bits/stdc++.h>
#include <unordered_set>

#define ALPHABET_SIZE 256
using namespace std;

//O(n) time, O(n) (debatable, tho, since seen will never have more than 256 elements) space
bool isUnique1(string s){
    unordered_set<char> seen; //this could be replaced by a bitset (or bit vector) of the size of the alphabet used

    if(s.size() > ALPHABET_SIZE) return false;

    for(char c : s){
        if(seen.count(c)) return false; 
        seen.insert(c);
    }

    return true;
}

//O(n) time, O(1) space
bool isUnique2(string s){
    bitset<ALPHABET_SIZE> seen;

    if(s.size() > ALPHABET_SIZE) return false;

    for(char c : s){
        if(seen[c]) return false; 
        seen[c] = true;
    }

    return true;
}

//Follow-up: "What if you cannot use any additional data structures?"

//O(nlogn) time, O(1) space
bool isUnique3(string s){
    sort(s.begin(),s.end());

    for(int i = 0; i<s.size()-1; i++){
        if(s[i+1] == s[i]) return false;
    }

    return true;
}

int main(){
    cout << isUnique1("batata") << endl;
    cout << isUnique2("batata") << endl;
    cout << isUnique3("batata") << endl;

    cout << isUnique1("amor") << endl;
    cout << isUnique2("amor") << endl;
    cout << isUnique3("amor") << endl;

    return 0;
}