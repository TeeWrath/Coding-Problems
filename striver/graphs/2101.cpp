#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    double calDistance(int x1, int x2, int y1, int y2)
    {
        return sqrtl((1LL * (x1 - x2) * (x1 - x2)) + (1LL * (y1 - y2) * (y1 - y2)));
    }

private:
    void dfs(int node, vector<int>& vis,int &cnt, vector<vector<int>>& adj){
        vis[node] = 1;
        cnt++;

        for(auto it: adj[node]){
            if(!vis[it])dfs(it,vis,cnt,adj);
        }
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();

        vector<vector<int>> adj(n);
        int maxBombs = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(i==j)continue;
                double dist = calDistance(bombs[i][0], bombs[j][0], bombs[i][1], bombs[j][1]);
                double d1 = bombs[i][2] * 1.0;
                double d2 = bombs[j][2] * 1.0;

                if (dist <= d1)
                {
                    adj[i].push_back(j);
                }
                if (dist <= d2)
                {
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++){
            int cnt=0;
            vector<int> vis(n,0);
            dfs(i,vis,cnt,adj);
            maxBombs = max(maxBombs,cnt);
        }

        return maxBombs;
    }
};