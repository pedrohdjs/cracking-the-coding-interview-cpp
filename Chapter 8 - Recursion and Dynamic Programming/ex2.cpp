#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//r stands for row and c stands for column
struct  point{
    int r;
    int c;
    point(int r, int c): r(r), c(c) {};
};

void printAnswer(vector<point> ans){
    if (!ans.size()) {
        cout << "No path was found" << endl << endl;
    }

    for (point p : ans){
        printf("[%d, %d]\n",p.r,p.c);
    }
    cout << endl;
}

//O(2^(r+c)) time, O(r+c) space
vector<point> findPath1(vector<vector<int>> maze, point p){
    int maxR = maze.size()-1;
    int maxC = maze[0].size()-1;

    vector<point> res;

    if (p.r > maxR || p.r > maxC){//Check boundaries
        return res; //Empty vector
    }
    else if (maze[p.r][p.c] == 1){//Check wall
        return res; //Empty vector
    }
    else if (p.r == maxR && p.c == maxC){//Found exit
        res.push_back(p);
        return res;
    }
    else{
        vector<point> rightPath = findPath1(maze,point(p.r,p.c+1));
        if (rightPath.size() > 0){ //Found a path going right
            rightPath.push_back(p);
            return rightPath;
        }

        vector<point> downPath = findPath1(maze,point(p.r+1,p.c));
        if (downPath.size() > 0){ //Found a path going down
            downPath.push_back(p);
            return downPath;
        }

        return res; //If the code runs up to this moment, no path was found for this point
    }
    
}

//Wrapper function
vector<point> findPath1(vector<vector<int>> maze){
    vector<point> res = findPath1(maze,point(0,0));
    reverse(res.begin(),res.end()); //The answer is formed in reverse order, so we reverse to the natural order.
    return res;
}

//O(r*c) cime, O(r+c) space, using memoization in order to prevent going through the same position twice
vector<point> findPath2(vector<vector<int>> maze, point p, vector<vector<bool>> &visited){
    int maxR = maze.size()-1;
    int maxC = maze[0].size()-1;

    vector<point> res;

    if (p.r > maxR || p.r > maxC){//Check boundaries
        return res; //Empty vector
    }
    else if (visited[p.r][p.c]){
        return res;
    }

    visited[p.r][p.c] = true; //Mark as visited


    if (maze[p.r][p.c] == 1){//Check wall
        return res; //Empty vector
    }
    else if (p.r == maxR && p.c == maxC){//Found exit
        res.push_back(p);
        return res;
    }
    else{
        vector<point> rightPath = findPath2(maze,point(p.r,p.c+1),visited);
        if (rightPath.size() > 0){ //Found a path going right
            rightPath.push_back(p);
            return rightPath;
        }

        vector<point> downPath = findPath2(maze,point(p.r+1,p.c),visited);
        if (downPath.size() > 0){ //Found a path going down
            downPath.push_back(p);
            return downPath;
        }

        return res; //If the code runs up to this moment, no path was found for this point
    }
}

//Wrapper function
vector<point> findPath2(vector<vector<int>> maze){
    int r = maze.size();
    int c = maze[0].size();
    vector<vector<bool>> visited(r,vector<bool>(c,false)); //Mark every point as not visited

    vector<point> res = findPath2(maze,point(0,0),visited);
    reverse(res.begin(),res.end()); //The answer is formed in reverse order, so we reverse to the natural order.
    return res;
}


int main(){
    vector<vector<int>> test1 = vector<vector<int>>( {{0,0,0,0,1},
                                                      {0,1,1,0,0},
                                                      {0,0,0,1,1},
                                                      {1,1,0,0,0}} );
    vector<point> res11 = findPath1(test1);
    vector<point> res12 = findPath1(test1);

    printAnswer(res11);
    printAnswer(res12);


    vector<vector<int>> test2 = vector<vector<int>>( {{0,0,0,0,1},
                                                      {1,1,1,0,0},
                                                      {0,0,0,1,1},
                                                      {1,1,0,0,0}} );
    vector<point> res21 = findPath1(test2);
    vector<point> res22 = findPath1(test2);

    printAnswer(res21);
    printAnswer(res22);



    return 0;
}