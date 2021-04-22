#include <bits/stdc++.h>

using namespace std;

void printCharVector(vector<char> v){
    for (char c : v) cout << c;
    cout << endl;
}

//O(n) time, O(1) space
vector<char> urlify (vector<char> &s){
    int j = s.size()-1;
    int i = j;
    while(s[i] == '\0') i--;

    while(i > 0){
        if(s[i] == ' '){
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        }
        else{
            s[j--] = s[i]; 
        }
        i--;
    }
    return s;
}

int main(){
    vector<char> test1({'o','i',' ', 't','u','d','o',' ','b','e','m','?','\0','\0','\0','\0'});
    printCharVector(test1);
    urlify(test1);
    printCharVector(test1);
    return 0;
}