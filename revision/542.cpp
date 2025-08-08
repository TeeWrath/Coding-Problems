#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int r = mat.size(); //row
            int c = mat[0].size(); //column
            vector<vector<int>> ans(r,vector<int>(c,-1));
            queue<pair<int,int>> q;

            // initial filling for ans vector
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(mat[i][j]==0){
                        ans[i][j] = 0;
                        q.push({i,j});
                    }
                }
            }

            while(!q.empty()){
                auto [i,j] = q.front();
                q.pop();

                vector<int> dRow = {-1,1,0,0};
                vector<int> dCol = {0,0,-1,1};

                for(int k=0;k<4;k++){
                    int nRow = i + dRow[k];
                    int nCol = j + dCol[k];

                    if(nRow >=0 && nCol >=0 && nRow < r && nCol < c && ans[nRow][nCol] == -1){
                        ans[nRow][nCol] = ans[i][j] + 1;
                        q.push({nRow,nCol});
                    }
                }
            }

            return ans;
        }
    };
    