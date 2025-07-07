#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            if(grid.empty()) return 0;
            int n = grid.size();
            int m = grid[0].size();
            // {{row,col},time}
            queue<pair<pair<int,int>,int>> q;
            int vis[n][m];
            int cntFresh = 0;
            // following iteration marks 2s and others as 0s
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 2){
                        vis[i][j] = 2;
                        q.push({{i,j},0});
                    }
                    else {
                        if(grid[i][j] == 1)cntFresh++;
                        vis[i][j] = 0;
                    }
                }
            }
            int maxTime =0;
            int dRow[] = {0,0,1,-1};
            int dCol[] = {1,-1,0,0};
            int cnt = 0;
            while(!q.empty()){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int time = q.front().second;
                maxTime = max(time,maxTime);
                q.pop();
                for(int i =0; i<4; i++){
                    int nRow = row + dRow[i];
                    int nCol = col + dCol[i];
                    if(nRow >=0 && nCol >=0 && nRow < n && nCol < m && vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1){
                        q.push({{nRow,nCol}, time + 1});
                        vis[nRow][nCol] = 2;
                        cnt++;
                    }
                }
            }
            if(cnt != cntFresh)return -1;

            return maxTime;
        }
    };