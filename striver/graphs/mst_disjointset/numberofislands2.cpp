#include<bits/stdc++.h>
#include "disjoint_set.h"
using namespace std;

class Solution {
    private:
      bool isValid(int adjr,int adjc,int n,int m) {return adjr >=0 && adjc >=0 && adjr <n && adjc <m ;}
    public:
      vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int> ans;
        for(auto it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,-1,1};
            for(int i=0;i<4;i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                if(isValid(adjr,adjc,n,m)){
                    if(vis[adjr][adjc]==1){
                        int nodeNo = row*m + col;
                        int adjNode = adjr*m + adjc;
                        if(ds.findUltimateParent(nodeNo) != ds.findUltimateParent(adjNode)){
                            cnt--;
                            ds.unionBySize(nodeNo,adjNode);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
      }
  };
  