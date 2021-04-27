#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

//O(n) time, O(1) space
int magicIndex1(vector<int> v){
    for(int i = 0; i<v.size(); i++){
        if(i==v[i]) return i;
    }
    return -1;
}

//O(logn) time, O(logn) space
int magicIndex2(vector<int> v, int lo, int hi){
    if (lo > hi) return -1;

    int mid = (lo+hi)/2;

    if(v[mid] == mid){
        return mid;
    }
    else if(v[mid] > mid){
        return magicIndex2(v,lo,mid-1);
    }
    else{ //if (v[mid] < mid)
        return magicIndex2(v,mid+1,hi);
    }
}

//wrapper function
int magicIndex2(vector<int> v){
    return magicIndex2(v,0,v.size()-1);
}

/*Follow up: we have to search at both sides since we can't be sure if the elements to the right are strictly bigger 
and the elements to the left are stricly smaller than mid. But we may skip some elements, since we know that v[i] == i
at the index we're looking for.
O(logn) time, O(logn) space */
int magicIndex3(vector<int> v, int lo, int hi){
    if (lo > hi) return -1;

    int mid = (lo+hi)/2;

    if(mid == v[mid]) return mid;

    //if v[mid] < mid-1, v[v[mid]] is where the magic index equal to v[mid] could be. Otherwise, we search for other possible magic indexes.
    int leftResult = magicIndex3(v,lo,min(mid-1,v[mid])); 
    if (leftResult != -1) return leftResult;

     //if v[mid] > mid+1, v[v[mid]] is where the magic index equal to v[mid] could be. Otherwise, we search for other possible magic indexes.
    int rightResult = magicIndex3(v,max(mid+1,v[mid]),hi); 
    return rightResult;
}

//wrapper function
int magicIndex3(vector<int>v){
    return magicIndex3(v,0,v.size()-1);

}

int main(){
    vector<int> test1 = vector<int>({-1,0,1,2,4,7,10,12});
    cout << magicIndex1(test1) << endl;
    cout << magicIndex2(test1) << endl;
    cout << magicIndex3(test1) << endl;


    vector<int> test2 = vector<int>({-1,0,1,2,3,4,5,7});
    cout << magicIndex1(test2) << endl;
    cout << magicIndex2(test2) << endl;
    cout << magicIndex3(test2) << endl;

    vector<int> test3 = vector<int>({-1,0,1,2,5,7,10,12});
    cout << magicIndex1(test3) << endl;
    cout << magicIndex2(test3) << endl;
    cout << magicIndex3(test3) << endl;

    vector<int> test4 = vector<int>({-10,-5,2,2,2,3,4,6,9,12,13});
    cout << magicIndex1(test4) << endl;
    cout << magicIndex2(test4) << endl;
    cout << magicIndex3(test4) << endl;

    return 0;
}