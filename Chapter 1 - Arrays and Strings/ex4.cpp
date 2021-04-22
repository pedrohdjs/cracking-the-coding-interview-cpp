#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

//O(n) time, O(n) space
bool palindromePermutation1(string s){
    unordered_map<char,int> charCounts;
    for(char c : s) if(c != ' ') charCounts[c]++;

    bool hasOddNumber = false;
    for(auto it = charCounts.begin(); it != charCounts.end(); it++){
        int currentCount = it->second;
        if(currentCount % 2 != 0){
            if (hasOddNumber) return false;
            else hasOddNumber = true;
        }
    }
    return true;
}

//O(n) time, O(n) space, but in one pass
bool palindromePermutation2(string s){
    unordered_map<char,int> charCounts;
    int oddCount = 0;
    for(char c : s){
        if(c == ' ') continue; 
        charCounts[c]++;
        if(charCounts[c] % 2 != 0) oddCount++;
        else oddCount--;
    }

    return oddCount <= 1;

}


int main(){
    cout << palindromePermutation1("batata") << endl;
    cout << palindromePermutation1("tact coa") << endl;
    cout << palindromePermutation1("asdsa") << endl << endl;;

    cout << palindromePermutation2("batata") << endl;
    cout << palindromePermutation2("tact coa") << endl;
    cout << palindromePermutation2("asdsa") << endl << endl;;


    return 0;
}