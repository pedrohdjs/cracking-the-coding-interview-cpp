#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>>  m){
    int n = m.size();
    for(int i = 0; i<n; i++){
        cout << "[";
        for(int j = 0; j<n-1; j++){
            cout << m[i][j] << ", ";
        }
        cout << m[i][n-1] << "]" << endl;
    }
    cout << endl;
}

/*
n = 3

[1, 2, 3]     [1, 4, 7]     [7, 4, 1]
[4, 5, 6] =>  [2, 5, 8]  => [8, 5, 2]
[7, 8, 9]     [3, 6, 9]     [9, 6, 3]

[0][0] => [0][2]
[0][1] => [1][2]
[0][2] => [2][2]

[1][0] => [0][1]
[1][1] => [1][1]
[1][2] => [2][1]

[2][0] => [0][0]
[2][1] => [1][0]
[2][2] => [2][0]
*/

//O(n^2) time, O(n^2) space;
vector<vector<int>> rotateMatrix1(vector<vector<int>> m){
    int n = m.size();
    vector<vector<int>> ans(n,vector<int>(n,0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans[j][n-1-i] = m[i][j];
        }
    }

    return ans;
}

//O(n^2) time, O(1) space;
vector<vector<int>> rotateMatrix2(vector<vector<int>> m){
    int n = m.size();

    //Transpose matrix (you should only iterate through the "left triangle"  or "right triangle" of the matrix to prevent the reverse swaps)
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            swap(m[i][j],m[j][i]);
        }
    }

    //Reverse lines
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n/2; j++){
            swap(m[i][j],m[i][n-1-j]);
        }
    }

    return m;
}

//Note: By now, i didn't implement Gayle's solution because i couldn't quite understand it very well yet.

int main(){
    vector<vector<int>>  m1({{1,2,3},
                            {4,5,6},
                            {7,8,9}});
    printMatrix(m1);
    printMatrix(rotateMatrix1(m1));
    printMatrix(rotateMatrix2(m1));


    vector<vector<int>>  m2({{1,2,3,4},
                            {5,6,7,8},
                            {9,10,11,12},
                            {13,14,15,16}});
    printMatrix(m2);
    printMatrix(rotateMatrix1(m2));
    printMatrix(rotateMatrix2(m2));

    return 0;
}