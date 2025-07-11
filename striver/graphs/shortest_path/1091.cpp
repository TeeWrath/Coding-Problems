#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            if(grid[0][0] == 1)return -1;

            vector<vector<int>> distance(n,vector<int>(m,1e9));
            queue<pair<int,pair<int,int>>> q;
            pair<int,int> src = {0,0};
            pair<int,int> dest = {n-1,m-1};
            distance[src.first][src.second] = 1;
            q.push({1,{src.first,src.second}});

            vector<int> dRow = {1,-1,0,0,-1,-1,1,1};
            vector<int> dCol = {0,0,1,-1,-1,1,-1,1};
            while(!q.empty()){
                int row = q.front().second.first;
                int col = q.front().second.second;
                int dist = q.front().first;
                q.pop();

                for(int i=0; i<8; i++){
                    int nRow = row + dRow[i];
                    int nCol = col + dCol[i];
                    if(nRow < n && nCol < m && nRow >=0 && nCol >=0 && grid[nRow][nCol] == 0 && (dist + 1 < distance[nRow][nCol])){
                        distance[nRow][nCol] = dist+1;
                        if(make_pair(nRow,nCol) ==  dest)return distance[nRow][nCol];
                        q.push({distance[nRow][nCol], {nRow,nCol}});
                    }
                }
            }

            return -1;
        }
    };