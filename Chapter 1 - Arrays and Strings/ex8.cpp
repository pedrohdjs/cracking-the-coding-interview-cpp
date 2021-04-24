#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

void printMatrix(vector<vector<int>>  m){
    int height = m.size();
    int width = m[0].size();
    for(int i = 0; i<height; i++){
        cout << "[";
        for(int j = 0; j<width-1; j++){
            cout << m[i][j] << ", ";
        }
        cout << m[i][width-1] << "]" << endl;
    }
    cout << endl;
}

void zeroLine(vector<vector<int>> &m, int line){
    int colums = m[0].size();
    for(int i = 0; i<colums; i++){
        m[line][i] = 0;
    }
}

void zeroColumn(vector<vector<int>> &m, int column){
    int lines = m.size();
    for(int i = 0; i<lines; i++){
        m[i][column] = 0;
    }
}

struct point{
    int x;
    int y;
    point(int i, int j): x(i), y(j) {};
};

//O(n*m) time, o(n+m) space
void zeroMatrix(vector<vector<int>> &m){
    int lines = m.size();
    if(!lines) return;
    int columns = m[0].size();
    
    vector<point> originalZeroes;

    for(int i = 0; i<lines; i++){
        for(int j = 0; j<columns; j++){
            if(m[i][j] == 0){
                originalZeroes.push_back(point(i,j));
            }
        }
    }

    unordered_set<int> zeroedLines;
    unordered_set<int> zeroedColumns;

    for(point p : originalZeroes){
        int i = p.x;
        int j = p.y;
        if (!zeroedLines.count(i)){
            zeroLine(m,i);
            zeroedLines.insert(i);
        }
        if (!zeroedColumns.count(j)){
            zeroColumn(m,j);
            zeroedColumns.insert(j);
        }

    }
}

int main(){
    vector<vector<int>>  m1({{1,2,3,4,5},
                            {5,6,0,8,1},
                            {9,0,11,12,4},
                            {13,14,15,16,2}});
    printMatrix(m1);
    zeroMatrix(m1);
    printMatrix(m1);


    return 0;
}