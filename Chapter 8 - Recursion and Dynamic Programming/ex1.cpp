#include <iostream>
#include <unordered_map>

using namespace std;

//O(3^n) time, O(n) space. Kinda sucks.
int tripleStep1(int n){
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else return (tripleStep1(n-1)+tripleStep1(n-2)+tripleStep1(n-3));
}


//O(n) time, O(n) space. Now thaaaat's the stuff.
int tripleStep2(int n, unordered_map<int,int> &mem){
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else{
        //Value not computed yet
        if (mem.find(n) == mem.end()){
            mem[n] = tripleStep2(n-1,mem) + tripleStep2(n-2,mem) + tripleStep2(n-3,mem);
        }
        return mem[n];
    }
}

int main(){
    unordered_map<int,int> mem;
    cout << tripleStep2(35,mem) << endl;
    cout << tripleStep1(35) << endl;


    return 0;
}


/*
3+1
1+3
2+2
2+1+1
1+2+1
1+1+2
1+1+1+1
*/