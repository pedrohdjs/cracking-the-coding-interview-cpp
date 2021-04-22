#include <bits/stdc++.h>

using namespace std;

 
//O(n+k^2) time (k is the length of the answer) in java, O(n) amortized/O(n+k^2) worst case in C++. O(1) time
string compressedString1(string s){
    if(!s.size()) return s;
    
    string res = "";
    
    char current = s[0];
    int currentCount = 1;
    for(int i = 1; i<s.size(); i++){
        if(s[i] != current){
            res += current;
            res += to_string(currentCount);
            current = s[i];
            currentCount = 1;
        }
        else{
            currentCount++;
        }
    }
    res += current;
    res += to_string(currentCount);

    return (res.size() < s.size()) ? res : s;
}

int countCompressedSize(string s){
    int size = 0;

    int current = s[0];
    int currentCount = 1;

    for(int i = 1; i<s.size(); i++){
        if(s[i] != current){
            size += 1 + to_string(currentCount).size(); //the letter and the number
            current = s[i];
            currentCount = 1;
        }
        else{
            currentCount++;
        }
    }

    size += 1 + to_string(currentCount).size();

    return size;
}

//O(n) time, O(1) space
string compressedString2(string s){
    if(!s.size()) return s;

    int compressedSize = countCompressedSize(s);

    if(compressedSize > s.size()) return s;

    string res = "";
    res.reserve(compressedSize+1);
    
    char current = s[0];
    int currentCount = 1;
    for(int i = 1; i<s.size(); i++){
        if(s[i] != current){
            res += current;
            res += to_string(currentCount);
            current = s[i];
            currentCount = 1;
        }
        else{
            currentCount++;
        }
    }
    res += current;
    res += to_string(currentCount);

    return res;
}

int main(){
    cout << compressedString1("batata") << endl;
    cout << compressedString2("batata") << endl;

    cout << compressedString1("aaaaaaaaabcccccdddd") << endl;
    cout << compressedString2("aaaaaaaaabcccccdddd") << endl;

    cout << compressedString1("testtttttttttttttt") << endl;
    cout << compressedString2("testtttttttttttttt") << endl;

    return 0;
}